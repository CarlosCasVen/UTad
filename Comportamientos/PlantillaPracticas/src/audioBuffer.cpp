#include "../include/audioBuffer.h"
#include "../include/file.h"
#include <AL/al.h>

#define BLOCK_SIZE_TO_SKIP 8

AudioBuffer::AudioBuffer(const String& filename)
{
    this->filename = filename;
    alBuffer = 0;
    File audioFile( filename, FILE_READ );
    char text[5];
    text[4] = '\0';
 
    //RIFF
    audioFile.ReadBytes( text, 4 );
    if( String( text ) != "RIFF" ) return;
    audioFile.Seek( audioFile.Pos() + 4 );

    //WAVE
    audioFile.ReadBytes( text, 4 );
    if( String( text ) != "WAVE" ) return;
    
    //FMT
    audioFile.ReadBytes( text, 4 );
    if( String( text ) != "fmt " ) return;
    audioFile.Seek( audioFile.Pos() + 4 ); //skip subChunkSize y audioFormat

    short audioFormat = audioFile.ReadInt16();
    short channels = audioFile.ReadInt16();
    int sampleRate = audioFile.ReadInt();

    audioFile.Seek( audioFile.Pos() + BLOCK_SIZE_TO_SKIP ); // salta hasta ParamsSize o data 

    if( audioFormat != 16 && audioFormat != 1 ) audioFile.Seek( audioFile.ReadInt16() + audioFile.Pos() );
    
    while( ( String( text ) != "data" ) )
    {
        audioFile.ReadBytes( text, 4 );    
        if( String( text ) != "data" )
        {
            audioFile.Seek( audioFile.ReadInt() + audioFile.Pos() );
        }
    }

    int bufferSize = audioFile.ReadInt();
    char* buffer = (char*) malloc( bufferSize );
    audioFile.ReadBytes( buffer, bufferSize );
    alGenBuffers( 1, &alBuffer );
    alBufferData( alBuffer, channels == 1 ? AL_FORMAT_MONO16 : AL_FORMAT_STEREO16, buffer, bufferSize, sampleRate );

    free( buffer );
}


AudioBuffer::~AudioBuffer(void)
{
    alDeleteBuffers( 1,	&alBuffer );	
}