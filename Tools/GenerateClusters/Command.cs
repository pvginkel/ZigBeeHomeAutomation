using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateClusters;

public class Command
{
    public int Id { get; }
    public string Name { get; }
    public Command Response { get; }
    public List<(string DataType, string TypeName, string Name)> Parameters { get; } = new();

    public Command(int id, string name, Command response)
    {
        Id = id;
        Name = name;
        Response = response;
    }
}
