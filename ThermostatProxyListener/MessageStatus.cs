namespace ThermostatProxyListener;

internal enum MessageStatus : byte
{
    OTRS_NONE,
    OTRS_SUCCESS,
    OTRS_INVALID,
    OTRS_TIMEOUT
}
