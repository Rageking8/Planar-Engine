# CameraController2D

Controls the behaviour of the 2D camera.

## Fields

| Name            | Type                | Description                                                                                |
| --------------- | ------------------- | ------------------------------------------------------------------------------------------ |
| Mode            | Enum                | Either free or track.                                                                      |
| HorizontalSpeed | Vector2             | Only applicable in free mode. Represents the left and right speed for the camera movement. |
| VerticalSpeed   | Vector2             | Only applicable in free mode. Represents the up and down speed for the camera movement.    |
| Transform       | Transform Reference | Only applicable in track mode. Transform component used for tracking.                      |
| HorizontalLerp  | Float               | Only applicable in track mode. Lerp factor in the horizontal direction.                    |
| VerticalLerp    | Float               | Only applicable in track mode. Lerp factor in the vertical direction.                      |

## See also

[Camera2D](Camera2D.md)
