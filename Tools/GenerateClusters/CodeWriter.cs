using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateClusters;

public class CodeWriter
{
    private bool _hadIndent;
    private int _indent;
    private readonly StringBuilder _sb = new();

    public void Indent()
    {
        _indent++;
    }

    public void UnIndent()
    {
        _indent--;
    }

    public void Write(string format)
    {
        Write(format, Array.Empty<object>());
    }

    public void Write(string format, params object[] args)
    {
        if (!_hadIndent && _indent > 0)
        {
            _sb.Append(new string(' ', _indent * 4));
            _hadIndent = true;
        }

        if (args.Length > 0)
        {
            format = string.Format(format, args);
        }

        _sb.Append(format);
    }

    public void WriteLine()
    {
        _hadIndent = false;
        _sb.Append(Environment.NewLine);
    }

    public void WriteLine(string format)
    {
        WriteLine(format, Array.Empty<object>());
    }

    public void WriteLine(string format, params object[] args)
    {
        Write(format, args);
        WriteLine();
    }

    public override string ToString()
    {
        return _sb.ToString();
    }

    public void WriteRaw(string validation)
    {
        _sb.Append(validation);
    }
}
