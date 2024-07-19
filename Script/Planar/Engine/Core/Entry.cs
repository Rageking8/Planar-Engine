using System;
using System.IO;
using System.Reflection;
using System.Collections.Generic;
using System.Runtime.InteropServices;

using Planar.Engine;
using Planar.Engine.Asset;
using Planar.Engine.Core.Log;

using static Planar.Engine.Core.Utils.ResourceUtils;
using static Planar.Engine.Core.Native.NativeFunction;

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

        string[] allAssets = Assembly.GetEntryAssembly().
            GetManifestResourceNames();
        for (int i = 0; i < allAssets.Length; ++i)
        {
            TerminalLogger.Log("Asset", "Found asset '" +
                allAssets[i] + "'");
        }

        List<string> sceneAssets =
            GetResourceNamesByExtension(".planarscene");
        Scene.Scene mainScene = application.CreateScene(sceneAssets[0]);
        application.LoadScene(mainScene);

        List<string> spriteAssets =
            GetResourceNamesByExtension(".planarsprite");
        HashSet<string> pngAssets =
            new(GetResourceNamesByExtension(".png"));

        AssetDatabase assetDatabase = application.GetAssetDatabase();

        foreach (string sprite in spriteAssets)
        {
            string current = Path.ChangeExtension(sprite, ".png");

            if (pngAssets.Contains(current))
            {
                string name = current[..^4];
                name = name[(name.LastIndexOf('.') + 1)..];
                assetDatabase.LoadSprite(name, ReadResource(sprite),
                    ReadResourceBytes(current));
            }
        }

        application.Run();
    }
}
