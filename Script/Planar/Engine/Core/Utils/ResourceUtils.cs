using System;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Collections.Generic;

using static Planar.Engine.Core.Utils.AssemblyUtils;

namespace Planar.Engine.Core.Utils;

public static class ResourceUtils
{
    public static Stream GetResourceStream(string resourceName)
    {
        return Assembly.GetEntryAssembly().
            GetManifestResourceStream(resourceName);
    }

    public static string[] GetResourceNames()
    {
        return Assembly.GetEntryAssembly().GetManifestResourceNames();
    }

    public static List<string> GetResourceNamesByExtension(
        string extension)
    {
        return GetResourceNames().Where(name =>
            name.EndsWith(extension)).ToList();
    }

    public static string WriteDllToTemp(string dllName)
    {
        string assemblyName = GetAssemblyName();
        string dllPath = Path.Combine(Path.GetTempPath(),
            assemblyName + "." + GetAssemblyVersion(), dllName);

        WriteResourceToFilePath(assemblyName + ".Engine." + dllName,
            dllPath);

        return dllPath;
    }

    public static string ReadResource(string resourceName)
    {
        using (var resource = GetResourceStream(resourceName))
        using (var reader = new StreamReader(resource))
        {
            return reader.ReadToEnd();
        }
    }

    public static byte[] ReadResourceBytes(string resourceName)
    {
        using (var resource = GetResourceStream(resourceName))
        {
            byte[] bytes = new byte[resource.Length];
            resource.Read(bytes, 0, bytes.Length);

            return bytes;
        }
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

        using (var resource = GetResourceStream(resourceName))
        using (var file = new FileStream(filePath, FileMode.Create))
        {
            resource.CopyTo(file);
        }
    }
}
