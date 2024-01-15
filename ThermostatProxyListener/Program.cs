using ThermostatProxyListener;

var statusHandler = new ThermostatProxyStatusHandler();

statusHandler.Updated += (_, e) =>
{
    Console.Clear();

    foreach (
        var parameter in statusHandler
            .Parameters.AllParameters.Where(p => p.Value != null)
            .OrderBy(p => p.Parameter.ToString().ToLowerInvariant())
    )
    {
        Console.Write($"{parameter.Parameter}: {parameter.Value} (");
        if (
            parameter.LastResponseType == MessageType.READ_ACK
            || parameter.LastResponseType == MessageType.WRITE_ACK
        )
            Console.Write(parameter.LastResponseType);
        else
            WithColor(ConsoleColor.Red, () => Console.Write(parameter.LastResponseType));
        Console.Write(")");

        if (DateTime.Now - parameter.LastUpdated < TimeSpan.FromSeconds(10))
            WithColor(ConsoleColor.Blue, () => Console.Write(" *"));

        Console.WriteLine();

        void WithColor(ConsoleColor color, Action action)
        {
            var oldColor = Console.ForegroundColor;
            Console.ForegroundColor = color;
            action();
            Console.ForegroundColor = oldColor;
        }
    }

    //Console.WriteLine();
    //Console.WriteLine($"T: {e.Request}");
    //Console.WriteLine($"B: {e.Response}");
};

await using (var client = new ThermostatProxyMQTTClient(statusHandler))
{
    await client.Connect();

    Console.WriteLine("Listening...");
    Console.ReadLine();
}
