using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core;
using Planar.Engine.Core.Log;

namespace Planar.Script.Core;

public class Entry
{
    public static void Main()
    {
        Logger logger = new();
        logger.Log("Planar Script (" +
            RuntimeInformation.FrameworkDescription + ")");

        Application application = new();

        if (!application.Init())
        {
            logger.Error("Application init failed");
            Console.ReadLine();

            return;
        }

        application.Run();
    }
}
