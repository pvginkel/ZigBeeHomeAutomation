using ThermostatProxyListener;

var statusHandler = new ThermostatProxyStatusHandler();

statusHandler.Updated += (_, _) =>
{
    Console.Clear();

    foreach (
        var parameter in statusHandler
            .Parameters.AllParameters.Where(p => p.Value != null)
            .OrderBy(p => p.Parameter.ToString().ToLowerInvariant())
    )
    {
        Console.Write($"{parameter.Parameter}: {parameter.Value}");
        if (DateTime.Now - parameter.LastUpdated < TimeSpan.FromSeconds(10))
        {
            var color = Console.ForegroundColor;
            Console.ForegroundColor = ConsoleColor.Blue;
            Console.Write(" *");
            Console.ForegroundColor = color;
        }
        Console.WriteLine();
    }
};

await using (var client = new ThermostatProxyMQTTClient(statusHandler))
{
    await client.Connect();

    Console.WriteLine("Listening...");
    Console.ReadLine();
}
