using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core;
using Planar.Engine.Core.Log;

using static Planar.Engine.Core.Utils.ResourceUtils;

namespace Planar.Engine.Asset;

public class AssetDatabase
{
    private IntPtr _handle;

    public AssetDatabase(IntPtr handle)
    {
        _handle = handle;
    }

    public void LoadSprite(string name, string asset, byte[] sprite)
    {
        Planar_Engine_Asset_AssetDatabase_load_sprite(_handle,
            name, asset, sprite, (nuint)sprite.Length);
    }

    public void LoadAudio(string name, string asset, byte[] audio)
    {
        Planar_Engine_Asset_AssetDatabase_load_audio(_handle,
            name, asset, audio, (nuint)audio.Length);
    }

    public void LogAllAssets()
    {
        foreach (string asset in GetResourceNames())
        {
            TerminalLogger.Log("Asset", "Found asset '" + asset + "'");
        }
    }

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void
        Planar_Engine_Asset_AssetDatabase_load_sprite(IntPtr handle,
        string name, string asset, byte[] sprite, nuint length);

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void
        Planar_Engine_Asset_AssetDatabase_load_audio(IntPtr handle,
        string name, string asset, byte[] audio, nuint length);
}
