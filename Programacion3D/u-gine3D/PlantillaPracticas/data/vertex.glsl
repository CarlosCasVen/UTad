#version 330 core

uniform	mat4 MVP;
in vec3 vpos;
in vec2 vtex;
out vec2 ftex;

void main()
{
	gl_Position	= MVP * vec4(vpos, 1);
	ftex = vtex;
}