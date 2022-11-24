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
    public void GeneratGenerateReadersWriterseReaders()
    {
        new Generator().GenerateReadersWriters();
    }

    [Test]
    public void GenerateAttributeAccessors()
    {
        new Generator().GenerateAttributeAccessors();
    }

    [Test]
    public void GenerateClusterAttributeAccessors()
    {
        new Generator().GenerateClusterAttributeAccessors();
    }
}
