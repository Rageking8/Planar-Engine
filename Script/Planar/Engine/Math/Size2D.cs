using System.Numerics;
using System.Runtime.InteropServices;

namespace Planar.Engine.Math;

[StructLayout(LayoutKind.Sequential)]
public struct Size2D<T> where T : INumber<T>
{
    public Size2D(T width, T height)
    {
        this.width = width;
        this.height = height;
    }

    public T width;
    public T height;
}
