using System;
using System.Runtime.InteropServices;

using Planar.Engine;
using Planar.Engine.Math;
using Planar.Engine.Asset;
using Planar.Engine.Graphics;

using static Planar.Engine.Core.Utils.ResourceUtils;

namespace Planar.Engine.Core;

public class Application : IDisposable
{
    public IntPtr Handle { get; private set; }

    private ApplicationAsset _applicationAsset;

    public Application()
    {
        _applicationAsset = new(ReadResource("Application"));
        Handle = Planar_Engine_Core_Application_construct(
            _applicationAsset.GetWindowName(),
            _applicationAsset.GetWindowSize(),
            _applicationAsset.GetMaximizeWindow(),
            _applicationAsset.GetGraphicsAPI());
    }

    ~Application()
    {
        Dispose();
    }

    public void Dispose()
    {
        if (Handle != IntPtr.Zero)
        {
            Planar_Engine_Core_Application_destruct(Handle);
            Handle = IntPtr.Zero;
        }
    }

    public bool Init()
    {
        return Planar_Engine_Core_Application_init(Handle);
    }

    public void Run()
    {
        Planar_Engine_Core_Application_run(Handle);
    }

    public Scene.Scene CreateScene(string resourceName)
    {
        return new(this, resourceName);
    }

    public void LoadScene(Scene.Scene scene)
    {
        Planar_Engine_Core_Application_load_scene(Handle, scene.Handle);
    }

    public AssetDatabase GetAssetDatabase()
    {
        return new(Planar_Engine_Core_Application_get_asset_database(
            Handle));
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

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private extern static void Planar_Engine_Core_Application_load_scene(
        IntPtr handle, IntPtr scene);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private extern static IntPtr
        Planar_Engine_Core_Application_get_asset_database(IntPtr handle);
}
