using System;
using System.Runtime.InteropServices;

namespace Planar.Engine.Core.Log;

public class Logger : ILogger, IDisposable
{
    private IntPtr _handle;

    public Logger()
    {
        _handle = Planar_Engine_Core_Log_Logger_construct();
    }

    ~Logger()
    {
        Dispose();
    }

    public void Dispose()
    {
        if (_handle != IntPtr.Zero)
        {
            Planar_Engine_Core_Log_Logger_destruct(_handle);
            _handle = IntPtr.Zero;
        }
    }

    public void Log(string text)
    {
        Planar_Engine_Core_Log_Logger_log(_handle, text);
    }

    public void Warn(string text)
    {
        Planar_Engine_Core_Log_Logger_warn(_handle, text);
    }

    public void Error(string text)
    {
        Planar_Engine_Core_Log_Logger_error(_handle, text);
    }

    public void Success(string text)
    {
        Planar_Engine_Core_Log_Logger_success(_handle, text);
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern IntPtr Planar_Engine_Core_Log_Logger_construct();

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_Logger_destruct(
        IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_Logger_log(
        IntPtr handle, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_Logger_warn(
        IntPtr handle, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_Logger_error(
        IntPtr handle, string text);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Log_Logger_success(
        IntPtr handle, string text);
}
