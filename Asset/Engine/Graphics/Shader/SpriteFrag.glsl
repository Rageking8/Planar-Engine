#version 460 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D sprite;

layout(location = 3) uniform vec2 tile_factor;

void main()
{
    FragColor = texture(sprite, TexCoords * tile_factor);
}
