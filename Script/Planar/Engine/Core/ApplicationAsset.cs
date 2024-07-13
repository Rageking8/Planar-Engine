using System;
using System.Runtime.InteropServices;

using Planar.Engine.Math;
using Planar.Engine.Graphics;

namespace Planar.Engine.Core;

public class ApplicationAsset : IDisposable
{
    private IntPtr _handle;

    public ApplicationAsset(string assetString)
    {
        _handle = Planar_Engine_Core_ApplicationAsset_construct();
        Planar_Engine_Core_ApplicationAsset_load(_handle, assetString);
    }

    ~ApplicationAsset()
    {
        Dispose();
    }

    public void Dispose()
    {
        if (_handle != IntPtr.Zero)
        {
            Planar_Engine_Core_ApplicationAsset_destruct(_handle);
            _handle = IntPtr.Zero;
        }
    }

    public string GetWindowName()
    {
        return Marshal.PtrToStringAnsi(
            Planar_Engine_Core_ApplicationAsset_get_window_name(_handle));
    }

    public Size2D<int> GetWindowSize()
    {
        return Planar_Engine_Core_ApplicationAsset_get_window_size(_handle);
    }

    public bool GetMaximizeWindow()
    {
        return Planar_Engine_Core_ApplicationAsset_get_maximize_window(
            _handle);
    }

    public SupportedGraphicsAPI GetGraphicsAPI()
    {
        return Planar_Engine_Core_ApplicationAsset_get_graphics_api(_handle);
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern IntPtr
        Planar_Engine_Core_ApplicationAsset_construct();

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void
        Planar_Engine_Core_ApplicationAsset_destruct(IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void
        Planar_Engine_Core_ApplicationAsset_load(IntPtr handle,
        string asset_string);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern IntPtr
        Planar_Engine_Core_ApplicationAsset_get_window_name(IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern Size2D<int>
        Planar_Engine_Core_ApplicationAsset_get_window_size(IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    [return: MarshalAs(UnmanagedType.I1)]
    private extern static bool
        Planar_Engine_Core_ApplicationAsset_get_maximize_window(
        IntPtr handle);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern SupportedGraphicsAPI
        Planar_Engine_Core_ApplicationAsset_get_graphics_api(IntPtr handle);
}
