using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using NUnit.Framework;

namespace GenerateClusters;

[TestFixture]
public class Fixture
{
    [Test]
    public void GenerateClusters()
    {
        new Generator().GenerateClusters();
    }

    [Test]
    public void GenerateReadersWriters()
    {
        new Generator().GenerateReadersWriters();
    }

    [Test]
    public void GenerateAttributes()
    {
        new Generator().GenerateAttributes();
    }
}
