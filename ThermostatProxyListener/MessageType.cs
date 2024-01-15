namespace ThermostatProxyListener;

internal enum MessageType : byte
{
    /*  Master to Slave */
    READ_DATA = 0B000,
    READ = READ_DATA, // for backwared compatibility
    WRITE_DATA = 0B001,
    WRITE = WRITE_DATA, // for backwared compatibility
    INVALID_DATA = 0B010,
    RESERVED = 0B011,

    /* Slave to Master */
    READ_ACK = 0B100,
    WRITE_ACK = 0B101,
    DATA_INVALID = 0B110,
    UNKNOWN_DATA_ID = 0B111
};
