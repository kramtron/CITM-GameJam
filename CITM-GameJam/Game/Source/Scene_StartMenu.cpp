#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_StartMenu.h"
#include "Scene.h"
#include "Rajola.h"

#include "Defs.h"
#include "Log.h"

Scene_StartMenu::Scene_StartMenu() : Module()
{
	name.Create("scene_startmenu");
}

// Destructor
Scene_StartMenu::~Scene_StartMenu()
{}

// Called before render is available
bool Scene_StartMenu::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene_StartMenu::Start()
{


	return true;
}

// Called each loop iteration
bool Scene_StartMenu::PreUpdate()
{



	return true;
}

// Called each loop iteration
bool Scene_StartMenu::Update(float dt)
{
	bool ret = true;
	app->input->GetMousePosition(mouse.x, mouse.y);
	app->render->DrawCircle(800,450,400,255, 0, 0);
	//Vector para ver si el mouse est� dentro del circulo
	iPoint vector = iPoint((mouse.x - 800), (mouse.y - 450));
	//Calcula la distancia del vector
	distance = (vector.x * vector.x) + (vector.y * vector.y);
	//En caso de estar dentro de la distancia del circulo activa el if
	if(400*400>distance){
		//Cuando pulsas el boton izquierdo destruyes el circulo
		if (app->input->GetMouseButtonDown(1)) {
			app->render->DrawCircle(800, 450, 400, 255, 255, 0);
			destroyCircle = true;
		}

	}
	LOG("mouse x: %d,  mouse y: %d", mouse.x, mouse.y);
	return ret;
}

// Called each loop iteration
bool Scene_StartMenu::PostUpdate()
{
	bool ret = true;

	

	return ret;
}

// Called before quitting
bool Scene_StartMenu::CleanUp()
{
	LOG("Freeing scene");

	return true;
}


void Scene_StartMenu::DebugDraw()
{
	
}
