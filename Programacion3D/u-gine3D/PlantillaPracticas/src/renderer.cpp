#include "../include/renderer.h"
#include "../lib/glew/glew.h"
#include "../lib/glfw/glfw.h"

// stb_image.c:
extern "C" uint8 *stbi_load(char const *filename, int *x, int *y, int *comp, int req_comp);

Ptr<Renderer> Renderer::instance = NULL;

Renderer::Renderer() {
}

void Renderer::Setup3D() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_SCISSOR_TEST);
	glEnable(GL_TEXTURE_2D);
	glDepthFunc(GL_LEQUAL);
}

void Renderer::SetMVP(const float* m) {
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixf(m);
}

void Renderer::SetViewport(int x, int y, int w, int h) {
	glViewport(x, y, w, h);
	glScissor(x, y, w, h);
}

void Renderer::ClearColorBuffer(float r, float g, float b) {
	glClearColor(r, g, b, 1);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::ClearDepthBuffer() {
	glClear(GL_DEPTH_BUFFER_BIT);
}

uint32 Renderer::LoadTexture(const String& filename, uint32& width, uint32& height) {
	// Load bitmap
	int w, h, c;
	uint8* buffer = stbi_load(filename.ToCString(), &w, &h, &c, 4);
	if ( !buffer ) return 0;
	width = w;
	height = h;

	// Flip lines
	uint8* newBuffer = (uint8*)malloc(width*height*4);
	int line = 0;
	for ( int y = height-1; y >= 0; y-- ) {
		memcpy(&newBuffer[line*width*4], &buffer[y*width*4], width*4);
		line++;
	}
	free(buffer);
	buffer = newBuffer;

	// Create GL texture
	GLuint handle;
	glGenTextures(1, &handle);
	glBindTexture(GL_TEXTURE_2D, handle);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, buffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	// Unload bitmap
	free(buffer);

	return handle;
}

void Renderer::FreeTexture(uint32 tex) {
	glDeleteTextures(1, &tex);
}

void Renderer::BindTexture(uint32 tex) {
	glBindTexture(GL_TEXTURE_2D, tex);
}

uint32 Renderer::CreateBuffer() {
	uint32 buffer;
	glGenBuffers(1, &buffer);
	return buffer;
}

void Renderer::FreeBuffer(uint32 buffer) {
	glDeleteBuffers(1, &buffer);
}

void Renderer::BindVertexBuffer(uint32 buffer) {
	glBindBuffer(GL_ARRAY_BUFFER, buffer);
}

void Renderer::BindIndexBuffer(uint32 buffer) {
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
}

void Renderer::SetVertexBufferData(const void* data, uint32 dataSize) {
	glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_DYNAMIC_DRAW);
}

void Renderer::SetIndexBufferData(const void* data, uint32 dataSize) {
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void Renderer::DrawBuffer(uint32 numIndices, int coordsOffset, int texCoordsOffset, uint16 stride) {
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);
	glVertexPointer(3, GL_FLOAT, stride, (const void*)coordsOffset);
	glTexCoordPointer(2, GL_FLOAT, stride, (const void*)texCoordsOffset);
	glDrawElements(GL_TRIANGLES, numIndices, GL_UNSIGNED_SHORT, 0);
}

uint32 Renderer::CreateVertexShader(const String& source) {
	return 0;
}

uint32 Renderer::CreateFragmentShader(const String& source) {
	return 0;
}

void Renderer::FreeShader(uint32 shader) {
}

uint32 Renderer::CreateProgram() {
	return 0;
}

void Renderer::FreeProgram(uint32 program) {
}

void Renderer::AttachShader(uint32 program, uint32 shader) {
}

bool Renderer::LinkProgram(uint32 program) {
	return false;
}

void Renderer::UseProgram(uint32 program) {
}

const String& Renderer::GetProgramError() {
	return programError;
}