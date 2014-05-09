#include "../include/renderer.h"
#include "../lib/glew/glew.h"
#include "../lib/glfw/glfw.h"

#define VERTEX_SHADER_PATH "data/vertex.glsl"
#define FRAGMENT_SHADER_PATH "data/fragment.glsl"

// stb_image.c:
extern "C" uint8 *stbi_load(char const *filename, int *x, int *y, int *comp, int req_comp);

Ptr<Renderer> Renderer::instance = NULL;

Renderer::Renderer() {
   
   /* defaultProgram = CreateBuffer();

    CreateVertexShader  ( VERTEX_SHADER_PATH   );
    CreateFragmentShader( FRAGMENT_SHADER_PATH );

    AttachShader( GL_VERTEX_SHADER  , defaultProgram );
    AttachShader( GL_FRAGMENT_SHADER, defaultProgram );

    if( !LinkProgram( defaultProgram ) )
    {
        String s = GetProgramError();
        FreeProgram( defaultProgram );
        FreeShader ( defaultProgram );
        return;
    }

    UseProgram( defaultProgram );*/

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
    
    GLuint      shader      = 0;
    GLint       error       = 0;
    const char* string      = source.ToCString();
    char       log[1024];

    glCreateShader ( GL_VERTEX_SHADER );
    glShaderSource ( shader , 1, ( const GLchar** ) &string, NULL );
    glCompileShader( shader );
    glGetShaderiv  ( shader, GL_COMPILE_STATUS, &error );  

    if( error == GL_FALSE )
    {
        glGetShaderInfoLog( shader, sizeof(log), NULL, ( GLchar* ) log);
        FreeShader        ( shader ); 

        programError = String( log );
        return 0;
    }
	
    return shader;
}

uint32 Renderer::CreateFragmentShader(const String& source) {

    GLuint      shader      = 0;
    GLint       error       = 0;
    const char* string      = source.ToCString();
    char        log[1024];

    glCreateShader( GL_FRAGMENT_SHADER );
    glShaderSource ( shader , 1, ( const GLchar** ) &string, NULL );
    glCompileShader( shader );
    glGetShaderiv  ( shader, GL_COMPILE_STATUS, &error );  

    if( error == GL_FALSE )
    {
        glGetShaderInfoLog( shader, sizeof(log), NULL, ( GLchar* ) log);
        FreeShader        ( shader ); 

        programError = String( log[0] );
        return 0;
    }
	
    return shader;
}

void Renderer::FreeShader(uint32 shader) {
    glDeleteShader( shader );
}

uint32 Renderer::CreateProgram() {
   return static_cast<uint32>( glCreateProgram() );
	
}

void Renderer::FreeProgram(uint32 program) {
    glDeleteProgram( program );
}

void Renderer::AttachShader(uint32 program, uint32 shader) {
    glAttachShader( program, shader );
}

bool Renderer::LinkProgram(uint32 program) {

    GLint result = 0;
    char log[ 1024 ];
    
    glLinkProgram ( program );
    glGetProgramiv( program, GL_LINK_STATUS, &result );

    if( result == GL_FALSE )
    {
        glGetProgramInfoLog( program, sizeof( log ), NULL, log );
        programError = String( log );
        FreeProgram( program );

        return false;
    }

    return true;
}

void Renderer::UseProgram(uint32 program) {
    uint32 aux = program;

    if( program == 0 ) 
    {
        glUseProgram( defaultProgram );
        aux = defaultProgram;
    }
    else
    {
        glUseProgram( program );
    }

    mvpLoc          = glGetUniformLocation( defaultProgram, "MPV"         );
    texSamplerLoc   = glGetUniformLocation( defaultProgram, "texSampler"  );
    vposLoc         = glGetUniformLocation( defaultProgram, "vpos"        );
    vtexLoc         = glGetUniformLocation( defaultProgram, "vtex"        );
    
    //glEnableVertexAttribArray( texSamplerLoc    );
    glUniform1d              ( texSamplerLoc, 0 );
}

const String& Renderer::GetProgramError() {
	return programError;
}