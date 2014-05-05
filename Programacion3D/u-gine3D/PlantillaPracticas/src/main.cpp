#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")
//#include "../include/u-gine.h"
//#include "../include/matrix4.h"
//#include "../include/quat.h"
#include "../include/screen.h"
#include "../lib/glfw/glfw.h"
#define FULLSCREEN false

int main(int argc, char* argv[]) {
	if ( FULLSCREEN)	Screen::Instance()->Open(Screen::Instance()->GetDesktopWidth(), Screen::Instance()->GetDesktopHeight(), true);
	else				Screen::Instance()->Open(800, 600, false);

	//Ptr<Mesh> mesh = ResourceManager::Instance()->LoadMesh("data/box.msh");

	/*Ptr<Camera> camera = Camera::Create();
	camera->SetPerspective(45, float(Screen::Instance()->GetWidth()) / Screen::Instance()->GetHeight(), 0.001f, 1000.0f );
	camera->SetUsesTarget(true);
	camera->GetPosition() = Vector3(0, 1, 3);
	camera->SetColor(1, 1, 1);
	Scene::Instance()->AddEntity(camera.UpCast<Entity>());
*/
	//Ptr<Model> model = Model::Create(mesh);
	//Scene::Instance()->AddEntity(model.UpCast<Entity>());

	float angle = 0;
	while ( Screen::Instance()->IsOpened() && !Screen::Instance()->IsKeyPressed(GLFW_KEY_ESC) ) {
		/*angle += 32 * Screen::Instance()->GetElapsed();
		model->GetRotation().SetEuler(Vector3(0, angle, 0));

		Scene::Instance()->Update(Screen::Instance()->GetElapsed());
		Scene::Instance()->Render();
*/
		Screen::Instance()->Refresh();
	}
	
	//float values[16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
	//Matrix4 test( values );

	//Matrix4 m = test.Transposed();
	//int x =1;
	return 0;
}