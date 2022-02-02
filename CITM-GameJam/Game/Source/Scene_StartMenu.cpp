#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_StartMenu.h"
#include "Scene.h"

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
