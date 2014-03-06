#include "../include/bone.h"
#include "../include/glinclude.h"
#include "../include/image.h"
#include "../include/math.h"
#include "../include/renderer.h"

Bone::Bone() {
    this->id = "id";
    this->image = NULL;
    this->pivotX = 0;
    this->pivotY = 0;
    this->handleX = 0;
    this->handleY = 0;
    currentX = currentY = currentRotation = 0;
    currentScaleX = currentScaleY = 1;
}

Bone::Bone(const String& id, Image* image, double pivotX, double pivotY, double handleX, double handleY) {
    this->id = id;
	this->image = image;
	this->pivotX = pivotX;
	this->pivotY = pivotY;
	this->handleX = handleX;
	this->handleY = handleY;
	currentX = currentY = currentRotation = 0;
    currentScaleX = currentScaleY = 1;
}

const Bone* Bone::FindChild(const String &id) const {
    // Buscamos en los hijos del hueso
    for ( uint32 i = 0; i < children.Size(); i++ )
        if ( children[i].GetID() == id )
            return &children[i];

	// Si no, en toda su descendencia
    for ( uint32 i = 0; i < children.Size(); i++ ) {
        const Bone* bone = children[i].FindChild(id);
		if ( bone != NULL )
			return bone;
	}

	// No se ha encontrado
    return NULL;
}

Bone* Bone::FindChild(const String &id) {
    // Buscamos en los hijos del hueso
    for ( uint32 i = 0; i < children.Size(); i++ )
        if ( children[i].GetID() == id )
            return &children[i];

    // Si no, en toda su descendencia
    for ( uint32 i = 0; i < children.Size(); i++ ) {
        Bone* bone = children[i].FindChild(id);
        if ( bone != NULL )
            return bone;
    }

    // No se ha encontrado
    return NULL;
}

const Frame* Bone::FindFrame(uint32 id) const {
    for ( uint32 i = 0; i < frames.Size(); i++ )
        if ( frames[i].GetId() == id )
            return &frames[i];
	return NULL;
}

void Bone::TranslationForFrame(int32 f, double* x, double* y) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL ) {
		*x = frame->GetTranslationX();
		*y = frame->GetTranslationY();
	} else if ( prevFrame != NULL  &&  nextFrame != NULL ) {
		*x = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetTranslationX(), nextFrame->GetTranslationX());
		*y = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetTranslationY(), nextFrame->GetTranslationY());
	} else {
		*x = *y = 0;
	}
}

double Bone::RotationForFrame(int32 f) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL )
		return frame->GetRotation();
	else if ( prevFrame != NULL  &&  nextFrame != NULL )
		return WrapValue(Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetRotation(), nextFrame->GetRotation()), 360);
	else
		return 0;
}

void Bone::ScaleForFrame(int32 f, double* x, double* y) const {
    const Frame* frame = NULL, * prevFrame = NULL, * nextFrame = NULL;
	GetFrame(f, &frame, &prevFrame, &nextFrame);

	if ( frame != NULL ) {
		*x = frame->GetScaleX();
		*y = frame->GetScaleY();
	} else if ( prevFrame != NULL  &&  nextFrame != NULL ) {
		*x = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetScaleX(), nextFrame->GetScaleX());
		*y = Interpolate(f, prevFrame->GetId(), nextFrame->GetId(), prevFrame->GetScaleY(), nextFrame->GetScaleY());
	} else {
		*x = *y = 0;
	}
}

void Bone::Update(int32 currentFrame) {
	// TAREA: Implementar la especificacion del enunciado
	TranslationForFrame( currentFrame, &currentX, &currentY );
	currentRotation = RotationForFrame( currentFrame );
	ScaleForFrame( currentFrame, &currentScaleX, &currentScaleY );

	for( unsigned int i = 0; i < children.Size(); i++ )
	{
		children[i].Update( currentFrame );
	}
}

void Bone::Render() {
	// TAREA: Implementar la especificacion del enunciado
	glPushMatrix();
	glTranslated( currentX, currentY , 0 );
	glRotated(currentRotation, 0, 0, -1 );

	if( image )
	{
		image->SetHandle( (int32) ( handleX * image->GetWidth() ) , (int32) ( handleY * image->GetHeight() ) );
		Renderer::Instance().DrawImage( image, 0, 0, 0, image->GetWidth() * currentScaleX, image->GetHeight() * currentScaleY );
		glTranslated( pivotX * image->GetWidth(), pivotY * image->GetHeight(), 0 );
	}
	
	for( unsigned int i = 0; i < children.Size(); i++ )
	{
		children[i].Render();
	}

	glPopMatrix();
}

void Bone::GetFrame(int32 f, const Frame** frame, const Frame** prevFrame, const Frame** nextFrame) const {
	*frame = NULL;
	*prevFrame = NULL;
	*nextFrame = NULL;
    for ( uint32 i = 0; i < frames.Size(); i++ ) {
        if ( frames[i].GetId() == f )
            *frame = &frames[i];
        if ( frames[i].GetId() < f  &&  (*prevFrame == NULL  ||  (*prevFrame)->GetId() < frames[i].GetId()) )
            *prevFrame = &frames[i];
        if ( frames[i].GetId() > f  &&  (*nextFrame == NULL  ||  (*nextFrame)->GetId() > frames[i].GetId()) )
            *nextFrame = &frames[i];
	}
}

double Bone::Interpolate(int32 id, int32 prevId, int32 nextId, double prevVal, double nextVal) const {
	// TAREA: Implementar la especificacion del enunciado
	double fraction =   ( nextVal - prevVal ) * ( id - prevId ) / ( nextId - prevId ) * 1.0;
	return ( prevVal + fraction ) *1.0;
}
