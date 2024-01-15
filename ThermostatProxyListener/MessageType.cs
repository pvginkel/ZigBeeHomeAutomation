namespace ThermostatProxyListener;

internal enum MessageType : byte
{
    /*  Master to Slave */
    READ_DATA = 0B000,
    WRITE_DATA = 0B001,
    INVALID_DATA = 0B010,
    RESERVED = 0B011,

    /* Slave to Master */
    READ_ACK = 0B100,
    WRITE_ACK = 0B101,
    DATA_INVALID = 0B110,
    UNKNOWN_DATA_ID = 0B111
};
