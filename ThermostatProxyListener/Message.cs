using System.Globalization;

namespace ThermostatProxyListener;

internal record Message(MessageType Type, MessageId Id, ushort PayloadU16, MessageStatus Status)
{
    public static Message? Parse(string data)
    {
        if (data.Length == 0)
            return null;

        var parts = data.Split(':');
        var value = uint.Parse(parts[0], NumberStyles.HexNumber);
        if (value == 0)
            return null;
        var status = int.Parse(parts[1]);

        var type = (value >> 28) & 0b111;
        var id = (value >> 16) & 0xff;
        var payload = (ushort)(value & 0xffff);

        return new Message((MessageType)type, (MessageId)id, payload, (MessageStatus)status);
    }

    public float PayloadFloat =>
        (PayloadU16 & 0x8000) != 0 ? -(0x10000L - PayloadU16) / 256.0f : PayloadU16 / 256.0f;
    public short PayloadS16 => unchecked((short)PayloadU16);

    public byte PayloadHBU8 => (byte)((PayloadU16 >> 8) & 0xff);
    public byte PayloadLBU8 => (byte)(PayloadU16 & 0xff);

    public override string ToString() =>
        $"Type = {Type}, Id = {Id}, Payload = {PayloadU16:x4}, Status = {Status}";
}
