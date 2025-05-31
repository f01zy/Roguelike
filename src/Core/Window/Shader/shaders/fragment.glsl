#version 330 core

in vec3 figureColor;
out vec4 color;

void main()
{
	color = vec4(figureColor, 1.0f);
}
