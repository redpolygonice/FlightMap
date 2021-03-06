// MESSAGE RADIO support class

#pragma once

namespace mavlink {
namespace ardupilotmega {
namespace msg {

/**
 * @brief RADIO message
 *
 * Status generated by radio.
 */
struct RADIO : mavlink::Message {
    static constexpr msgid_t MSG_ID = 166;
    static constexpr size_t LENGTH = 9;
    static constexpr size_t MIN_LENGTH = 9;
    static constexpr uint8_t CRC_EXTRA = 21;
    static constexpr auto NAME = "RADIO";


    uint8_t rssi; /*<  Local signal strength. */
    uint8_t remrssi; /*<  Remote signal strength. */
    uint8_t txbuf; /*< [%] How full the tx buffer is. */
    uint8_t noise; /*<  Background noise level. */
    uint8_t remnoise; /*<  Remote background noise level. */
    uint16_t rxerrors; /*<  Receive errors. */
    uint16_t fixed; /*<  Count of error corrected packets. */


    inline std::string get_name(void) const override
    {
            return NAME;
    }

    inline Info get_message_info(void) const override
    {
            return { MSG_ID, LENGTH, MIN_LENGTH, CRC_EXTRA };
    }

    inline std::string to_yaml(void) const override
    {
        std::stringstream ss;

        ss << NAME << ":" << std::endl;
        ss << "  rssi: " << +rssi << std::endl;
        ss << "  remrssi: " << +remrssi << std::endl;
        ss << "  txbuf: " << +txbuf << std::endl;
        ss << "  noise: " << +noise << std::endl;
        ss << "  remnoise: " << +remnoise << std::endl;
        ss << "  rxerrors: " << rxerrors << std::endl;
        ss << "  fixed: " << fixed << std::endl;

        return ss.str();
    }

    inline void serialize(mavlink::MsgMap &map) const override
    {
        map.reset(MSG_ID, LENGTH);

        map << rxerrors;                      // offset: 0
        map << fixed;                         // offset: 2
        map << rssi;                          // offset: 4
        map << remrssi;                       // offset: 5
        map << txbuf;                         // offset: 6
        map << noise;                         // offset: 7
        map << remnoise;                      // offset: 8
    }

    inline void deserialize(mavlink::MsgMap &map) override
    {
        map >> rxerrors;                      // offset: 0
        map >> fixed;                         // offset: 2
        map >> rssi;                          // offset: 4
        map >> remrssi;                       // offset: 5
        map >> txbuf;                         // offset: 6
        map >> noise;                         // offset: 7
        map >> remnoise;                      // offset: 8
    }
};

} // namespace msg
} // namespace ardupilotmega
} // namespace mavlink
