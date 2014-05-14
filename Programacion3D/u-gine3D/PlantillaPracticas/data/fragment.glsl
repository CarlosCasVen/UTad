#version 330 core

uniform	sampler2D texSampler;
in vec2 ftex;
out vec4 fcolor;

void main()
{
	fcolor = texture2D(texSampler, ftex);
}