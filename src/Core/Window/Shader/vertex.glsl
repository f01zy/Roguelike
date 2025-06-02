#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 coordinates;

out vec2 textureCoordinates;

uniform mat4 transform;
uniform mat4 projection;

void main()
{
    gl_Position = projection * transform * vec4(position, 1.0);
    textureCoordinates = vec2(coordinates.x, coordinates.y);
}
