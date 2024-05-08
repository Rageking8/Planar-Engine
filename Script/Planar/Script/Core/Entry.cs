using Planar.Engine.Core.Log;

namespace Planar.Script.Core;

public class Entry
{
    public static void Main()
    {
        Logger logger = new();
        logger.Log("Log from native!");
        logger.Warn("Warn from native!");
        logger.Error("Error from native!");
        logger.Success("Success from native!");
    }
}
