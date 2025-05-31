#version 330 core

in vec3 figureColor;
in vec2 textureCoordinates;

out vec4 color;

uniform sampler2D renderTexture;

void main()
{
	color = texture(renderTexture, textureCoordinates) * vec4(figureColor, 1.0f);
}
