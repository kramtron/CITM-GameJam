#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Scene_Intro.h"
#include "Scene_Logo.h"
#include "Scene_END.h"
#include "Scene_Win.h"
#include "Map.h"
#include "Animation.h"
#include "ModuleEnemy.h"
#include "ModuleScore.h"


#include "Defs.h"
#include "Log.h"

Scene::Scene() : Module()
{
	name.Create("scene");
}

// Destructor
Scene::~Scene()
{}

// Called before render is available
bool Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;


	return ret;
}

// Called before the first frame
bool Scene::Start()
{
	if(app->scene_logo->active == true)
		active = false;


	
	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{


	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	bool ret = true;
	

	return ret;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;


	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

//Carga la posicion del personaje NO SE USA EN ESTE CODIGO
bool Scene::LoadState(pugi::xml_node& configRenderer)
{


	return true;
}

bool Scene::LoadPlayerData(pugi::xml_node& playerData) {



	return true;
}
bool Scene::LoadScene1Data(pugi::xml_node& scene1Data) {



	return true;
}
//Guarda la posicion del personaje NO SE USA EN ESTE CODIGO
bool Scene::SaveState(pugi::xml_node& playerData) const
{
	

	return true;
}
bool Scene::SaveScene1State(pugi::xml_node& scene1Data) const {

	

	return true;
}
//Dibuja los colliders
void Scene::DebugDraw()
{
	
}







