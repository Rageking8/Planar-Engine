using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core.Log;

namespace Planar.Script.Core;

public class Entry
{
    public static void Main()
    {
        Logger logger = new();
        logger.Log("Planar Script (" +
            RuntimeInformation.FrameworkDescription + ")");

        Console.ReadLine();
    }
}
