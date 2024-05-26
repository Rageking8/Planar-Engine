using System;
using System.Runtime.InteropServices;

namespace Planar.Engine.Core.Log;

public static class TerminalLogger
{
    public static void Log(string name, string text)
    {
        Planar_Engine_Core_Log_TerminalLogger_log(name, text);
    }

    public static void Warn(string name, string text)
    {
        Planar_Engine_Core_Log_TerminalLogger_warn(name, text);
    }

    public static void Error(string name, string text)
    {
        Planar_Engine_Core_Log_TerminalLogger_error(name, text);
    }

    public static void Success(string name, string text)
    {
        Planar_Engine_Core_Log_TerminalLogger_success(name, text);
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_TerminalLogger_log(
        string name, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_TerminalLogger_warn(
        string name, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_TerminalLogger_error(
        string name, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_TerminalLogger_success(
        string name, string text);
}
