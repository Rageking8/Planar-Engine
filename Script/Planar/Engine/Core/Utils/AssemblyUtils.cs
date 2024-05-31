using System.Reflection;

namespace Planar.Engine.Core.Utils;

public static class AssemblyUtils
{
    static public string GetAssemblyName()
    {
        return Assembly.GetEntryAssembly().GetName().Name;
    }

    static public string GetAssemblyVersion()
    {
        return Assembly.GetEntryAssembly().GetName().
            Version.ToString();
    }
}
