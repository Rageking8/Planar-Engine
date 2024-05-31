using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core.Log;

using static Planar.Engine.Core.Native.NativeFunction;
using static Planar.Engine.Core.Utils.ResourceUtils;

namespace Planar.Engine.Core;

public class Entry
{
    public static void Main()
    {
        LoadLibrary(WriteDllToTemp(ImportConstants.PlanarEngineDLL));

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
