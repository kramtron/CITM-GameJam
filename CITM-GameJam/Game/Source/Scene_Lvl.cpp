#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_StartMenu.h"
#include "Scene_Logo.h"
#include "Scene_Lvl.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"

Scene_Lvl::Scene_Lvl() : Module()
{
	name.Create("scene_lvl");
}

// Destructor
Scene_Lvl::~Scene_Lvl()
{}

// Called before render is available
bool Scene_Lvl::Awake()
{
	LOG("Loading END");
	bool ret = true;


	return ret;
}

// Called before the first frame
bool Scene_Lvl::Start()
{
	active = false;

	

	return true;
}

// Called each loop iteration
bool Scene_Lvl::PreUpdate()
{
	return true;

}

// Called each loop iteration
bool Scene_Lvl::Update(float dt)
{
	bool ret = true;


	return ret;
}

// Called each loop iteration
bool Scene_Lvl::PostUpdate()
{
	bool ret = true;
	app->render->DrawRectangle({ -200,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 525,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 1250,225,550,350 }, 255, 255, 255);




	app->render->DrawRectangle({ 50,750,250,100 }, 255, 255, 255);
	

	return ret;
}

// Called before quitting
bool Scene_Lvl::CleanUp()
{
	

	return true;
}


void Scene_Lvl::DebugDraw()
{

}