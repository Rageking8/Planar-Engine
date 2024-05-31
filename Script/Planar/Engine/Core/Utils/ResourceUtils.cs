using System;
using System.IO;
using System.Reflection;

using static Planar.Engine.Core.Utils.AssemblyUtils;

namespace Planar.Engine.Core.Utils;

public static class ResourceUtils
{
    public static string WriteDllToTemp(string dllName)
    {
        string assemblyName = GetAssemblyName();
        string dllPath = Path.Combine(Path.GetTempPath(),
            assemblyName + "." + GetAssemblyVersion(), dllName);

        WriteResourceToFilePath(assemblyName + ".Engine." + dllName,
            dllPath);

        return dllPath;
    }

    public static void WriteResourceToFilePath(string resourceName,
        string filePath)
    {
        resourceName = resourceName.Replace(" ", "_");
        string parentDir = Directory.GetParent(filePath).FullName;
        if (!Directory.Exists(parentDir))
        {
            Directory.CreateDirectory(parentDir);
        }

        using (var resource = Assembly.GetEntryAssembly().
            GetManifestResourceStream(resourceName))
        {
            using (var file = new FileStream(filePath, FileMode.Create))
            {
                resource.CopyTo(file);
            }
        }
    }
}
