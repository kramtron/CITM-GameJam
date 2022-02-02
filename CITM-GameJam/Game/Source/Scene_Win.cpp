#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_StartMenu.h"
#include "Scene_Logo.h"
#include "Scene_Lvl.h"
#include "Scene_Win.h"
#include "Scene.h"

#include "Defs.h"
#include "Log.h"

Scene_Win::Scene_Win() : Module()
{
	name.Create("scene_win");
}

// Destructor
Scene_Win::~Scene_Win()
{}

// Called before render is available
bool Scene_Win::Awake()
{
	LOG("Loading END");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene_Win::Start()
{
	



	return true;
}

// Called each loop iteration
bool Scene_Win::PreUpdate()
{
	return true;

}

// Called each loop iteration
bool Scene_Win::Update(float dt)
{
	bool ret = true;

	

	return ret;
}

bool Scene_Win::PostUpdate()
{
	return true;
}

// Called before quitting
bool Scene_Win::CleanUp()
{
	LOG("Freeing scene");

	return true;
}


void Scene_Win::DebugDraw()
{

}


