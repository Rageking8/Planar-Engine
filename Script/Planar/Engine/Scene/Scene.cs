using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core;

using static Planar.Engine.Core.Utils.ResourceUtils;

namespace Planar.Engine.Scene;

public class Scene : IDisposable
{
    public IntPtr Handle { get; private set; }

    public Scene(Application application, string resourceName)
    {
        Handle = Planar_Engine_Scene_Scene_construct(application.Handle,
            ExtractSceneName(resourceName), ReadResource(resourceName));
    }

    ~Scene()
    {
        Dispose();
    }

    public void Dispose()
    {
        if (Handle != IntPtr.Zero)
        {
            Planar_Engine_Scene_Scene_destruct(Handle);
            Handle = IntPtr.Zero;
        }
    }

    private string ExtractSceneName(string resourceName)
    {
        return resourceName[(resourceName[..resourceName.
            LastIndexOf('.')].LastIndexOf('.') + 1)..^12];
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern IntPtr Planar_Engine_Scene_Scene_construct(
        IntPtr application, string scene_name, string asset_string);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void Planar_Engine_Scene_Scene_destruct(
        IntPtr handle);
}
