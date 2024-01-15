namespace ThermostatProxyListener.Types;

internal record SetpointBound(Temperature UpperBound, Temperature LowerBound)
{
    public override string ToString() => $"Upper bound = {UpperBound}, Lower bound = {LowerBound}";
}
