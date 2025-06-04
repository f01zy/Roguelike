#version 330 core

in vec2 textureCoordinates;
in vec3 figureColor;

out vec4 color;

uniform sampler2D renderTexture;
uniform bool useTexture;

void main()
{
	if (useTexture) {
    color = texture(renderTexture, textureCoordinates);
  } else {
    color = vec4(figureColor, 1.0f);
  }
}
