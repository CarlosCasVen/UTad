#version 330 core 


uniform mat4 MVP;
in vec3 vpos;
in vec2 vuv;
out vec2 fuv;

void main() {
	gl_Position = MVP * vec4(pos, 1);
	fuv = vuv;
}