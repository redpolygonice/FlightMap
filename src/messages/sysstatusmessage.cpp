#include "sysstatusmessage.h"

namespace message
{

SysStatusMessage::SysStatusMessage(const device::DevicePtr &device)
	: IMessage(device)
{
}

void SysStatusMessage::execute()
{
	if (_direction == IMessage::Direction::FromDevice)
	{
		_state = IMessage::State::Progress;
		_device->telebox()->lock();
		_device->telebox()->voltage_battery = std::any_cast<unsigned short>(_params["voltage_battery"]);
		_device->telebox()->current_battery = std::any_cast<short>(_params["current_battery"]);
		_device->telebox()->drop_rate_comm = std::any_cast<unsigned short>(_params["drop_rate_comm"]);
		_device->telebox()->errors_comm = std::any_cast<unsigned short>(_params["errors_comm"]);
		_device->telebox()->battery_remaining = std::any_cast<char>(_params["battery_remaining"]);
		_device->telebox()->unlock();
		_state = IMessage::State::Done;
	}
}

}
