#include "../include/camera.h"
#include "../include/scene.h"
#include "../include/renderer.h"
#include "../include/screen.h"

//---------------------------------
//
//---------------------------------
Ptr<Camera> Camera::Create()
{
    return Ptr<Camera>( new Camera( ) );
}
//---------------------------------
//
//---------------------------------
int32 Camera::GetViewportX() const
{
    return vx;
}
//---------------------------------
//
//---------------------------------
int32 Camera::GetViewportY() const
{
    return vy;
}
//---------------------------------
//
//---------------------------------
uint16 Camera::GetViewportWidth() const
{
    return vw;
}
//---------------------------------
//
//---------------------------------
uint16 Camera::GetViewportHeight() const
{
    return vh;
}
//---------------------------------
//
//---------------------------------
void Camera::SetViewport(int32 x, int32 y, uint16 w, uint16 h)
{
    vx = x;
    vy = y;
    vw = w;
    vh = h;
}
//---------------------------------
//
//---------------------------------
void Camera::SetOrtho(float left, float right, float bottom, float top, float near, float far)
{
	projMatrix.SetIdentity();
    projMatrix.SetOrtho( left, right, bottom, top, near, far );
}
//---------------------------------
//
//---------------------------------
void Camera::SetFrustum(float left, float right, float bottom, float top, float near, float far)
{
	projMatrix.SetIdentity();
    projMatrix.SetFrustum( left, right, bottom, top, near, far );
}
//---------------------------------
//
//---------------------------------
void Camera::SetPerspective(float fov, float ratio, float near, float far)
{
	projMatrix.SetIdentity();
    projMatrix.SetPerspective( fov, ratio, near, far );
}
//---------------------------------
//
//---------------------------------
float Camera::GetRed() const
{
    return color[0];
}
//---------------------------------
//
//---------------------------------
float Camera::GetGreen() const
{
    return color[1];
}
//---------------------------------
//
//---------------------------------
float Camera::GetBlue() const
{
    return color[2];
}
//---------------------------------
//
//---------------------------------
void Camera::SetColor(float red, float green, float blue)
{
    color[0] = red;
    color[1] = green;
    color[2] = blue;
}
//---------------------------------
//
//---------------------------------
bool Camera::UsesTarget() const
{
    return usesTarget;
}
//---------------------------------
//
//---------------------------------
void Camera::SetUsesTarget(bool usesTarget)
{
    this->usesTarget = usesTarget;
}
//---------------------------------
//
//---------------------------------
const Vector3& Camera::GetTarget() const
{
    return target;
}
//---------------------------------
//
//---------------------------------
Vector3& Camera::GetTarget()
{
    return target;
}
//---------------------------------
//
//---------------------------------
const Matrix4& Camera::GetProjection() const
{
    return projMatrix;
}
//---------------------------------
//
//---------------------------------
const Matrix4& Camera::GetView() const
{
    return viewMatrix;
}
//---------------------------------
//
//---------------------------------
void Camera::Prepare()
{
    viewMatrix.SetIdentity();

	Vector3 trgt = (usesTarget) ? target : GetPosition() + GetRotation() * Vector3(0,0,-1);
	
	viewMatrix.LookAt(GetPosition(), trgt, Vector3(0,1,0));

	Renderer::Instance()->SetViewport(vx,vy,vw,vh);

	Renderer::Instance()->ClearColorBuffer(color[0], color[1], color[2]);
	Renderer::Instance()->ClearDepthBuffer();
    
}
//---------------------------------
//
//---------------------------------
Camera::Camera()
{
	vx = vy = 0;
	usesTarget = false;
	vw = Screen::Instance()->GetWidth ();
	vh = Screen::Instance()->GetHeight();
}
//---------------------------------
//
//---------------------------------
Camera::~Camera()
{
}