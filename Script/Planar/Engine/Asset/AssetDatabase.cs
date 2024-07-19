using System;
using System.Runtime.InteropServices;

using Planar.Engine.Core;

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

    [DllImport(ImportConstants.PlanarEngineDLL)]
    private static extern void
        Planar_Engine_Asset_AssetDatabase_load_sprite(IntPtr handle,
        string name, string asset, byte[] sprite, nuint length);
}
