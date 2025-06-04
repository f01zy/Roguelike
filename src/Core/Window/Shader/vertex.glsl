#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 coordinates;
layout (location = 2) in vec3 color;

out vec2 textureCoordinates;
out vec3 figureColor;

uniform mat4 transform;
uniform mat4 projection;

void main()
{
    gl_Position = projection * transform * vec4(position, 1.0);
    textureCoordinates = vec2(coordinates.x, coordinates.y);
    figureColor = color;
}
