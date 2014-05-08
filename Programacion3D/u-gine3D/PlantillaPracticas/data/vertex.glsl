#version 330 core 

uniform mat4 MVP;
in vec3 vpos;
in vec4 vcolor;
out vec4 fcolor;

void main() {
	gl_Position = MVP * vec4(vpos, 1);
	fcolor = vcolor;
}