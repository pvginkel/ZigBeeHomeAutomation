using NUnit.Framework;

namespace GenerateClusters.Test;

[TestFixture]
public class TestFixture
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
