using System.Reflection;

namespace Planar.Engine.Core.Utils;

public static class AssemblyUtils
{
    static public string GetAssemblyVersion()
    {
        return Assembly.GetExecutingAssembly().GetName().
            Version.ToString();
    }
}
