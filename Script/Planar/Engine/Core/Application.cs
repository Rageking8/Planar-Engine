using System;
using System.Runtime.InteropServices;

using Planar.Engine.Math;
using Planar.Engine.Graphics;

namespace Planar.Engine.Core;

public class Application : IDisposable
{
    private IntPtr _handle;

    public Application(string windowName = "Application",
        Size2D<int>? windowSize = null, bool maximize = false,
        SupportedGraphicsAPI graphicsAPI = SupportedGraphicsAPI.OPENGL_4_6)
    {
        Size2D<int> newWindowSize = windowSize ?? new(1280, 720);
        _handle = Planar_Engine_Core_Application_construct(windowName,
            newWindowSize, maximize, graphicsAPI);
    }

    ~Application()
    {
        Dispose();
    }

    public void Dispose()
    {
        if (_handle != IntPtr.Zero)
        {
            Planar_Engine_Core_Application_destruct(_handle);
            _handle = IntPtr.Zero;
        }
    }

    public bool Init()
    {
        return Planar_Engine_Core_Application_init(_handle);
    }

    public void Run()
    {
        Planar_Engine_Core_Application_run(_handle);
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern IntPtr Planar_Engine_Core_Application_construct(
        string window_name, Size2D<int> window_size,
        [MarshalAs(UnmanagedType.I1)] bool maximize,
        SupportedGraphicsAPI graphics_api);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Core_Application_destruct(
        IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    [return: MarshalAs(UnmanagedType.I1)]
    private extern static bool Planar_Engine_Core_Application_init(
        IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private extern static void Planar_Engine_Core_Application_run(
        IntPtr handle);
}
