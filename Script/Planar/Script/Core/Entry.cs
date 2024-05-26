using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core;
using Planar.Engine.Core.Log;

namespace Planar.Script.Core;

public class Entry
{
    public static void Main()
    {
        TerminalLogger.Log("Script", "Planar Script (" +
            RuntimeInformation.FrameworkDescription + ")");

        Application application = new();

        if (!application.Init())
        {
            TerminalLogger.Error("Script", "Application init failed");
            Console.ReadLine();

            return;
        }

        application.Run();
    }
}
