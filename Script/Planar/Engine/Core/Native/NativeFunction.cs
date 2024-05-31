using System;
using System.Runtime.InteropServices;

namespace Planar.Engine.Core.Native;

public static class NativeFunction
{
    [DllImport("kernel32.dll")]
    public static extern IntPtr LoadLibrary(string dllName);
}
