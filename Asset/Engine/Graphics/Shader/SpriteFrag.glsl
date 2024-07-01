#version 460 core

in vec2 TexCoords;
out vec4 FragColor;

uniform sampler2D sprite;

void main()
{
    FragColor = texture(sprite, TexCoords);
}
