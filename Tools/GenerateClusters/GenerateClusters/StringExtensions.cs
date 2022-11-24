using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenerateClusters;

public static class StringExtensions
{
    public static string ToUpperFirst(this string self)
    {
        return self.Substring(0, 1).ToUpper() + self.Substring(1);
    }
}