namespace Planar.Engine.Core.Log;

public interface ILogger
{
    void Log(string text);
    void Warn(string text);
    void Error(string text);
    void Success(string text);
}
