#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_Intro.h"
#include "Scene_Logo.h"
#include "Scene_END.h"
#include "Scene.h"
#include "Map.h"

#include "Defs.h"
#include "Log.h"

Scene_END::Scene_END() : Module()
{
	name.Create("scene_end");
}

// Destructor
Scene_END::~Scene_END()
{}

// Called before render is available
bool Scene_END::Awake()
{
	LOG("Loading END");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene_END::Start()
{
	
	

	return true;
}

// Called each loop iteration
bool Scene_END::PreUpdate()
{
	return true;

}

// Called each loop iteration
bool Scene_END::Update(float dt)
{
	bool ret = true;




	

	return ret;
}

// Called each loop iteration
bool Scene_END::PostUpdate()
{
	bool ret = true;
	
	

	return ret;
}

// Called before quitting
bool Scene_END::CleanUp()
{
	

	return true;
}


void Scene_END::DebugDraw()
{

}