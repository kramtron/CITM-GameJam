#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_Intro.h"
#include "Scene_Logo.h"
#include "ModuleEnemy.h"
#include "ModuleScore.h"
#include "Map.h"
#include "p2List.h"
#include "Scene.h"
#include <time.h>

#include "Defs.h"
#include "Log.h"

ModuleEnemy::ModuleEnemy() : Module()
{
	name.Create("ModuleEnemy");
}

// Destructor
ModuleEnemy::~ModuleEnemy()
{}

MeleEnemic::MeleEnemic() {

}
MeleEnemic::~MeleEnemic() {

}
// Called before render is available
bool ModuleEnemy::Awake()
{
	LOG("Loading Logo");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool ModuleEnemy::Start()
{
	//randomizador
	

	return true;
}

// Called each loop iteration
bool ModuleEnemy::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool ModuleEnemy::Update(float dt)
{
	bool ret = true;
	

	return true;
}

	

// Called each loop iteration
bool ModuleEnemy::PostUpdate()
{
	bool ret = true;

	

	return ret;
}

// Called before quitting
bool ModuleEnemy::CleanUp()
{
	LOG("Freeing scene");

	

	return true;
}


void ModuleEnemy::DebugDraw()
{

}

bool ModuleEnemy::LoadMeleEnemicSpawn(pugi::xml_node& configMeleEnemicSpawn) {

	

	return true;
}

bool ModuleEnemy::LoadEnemicsData(pugi::xml_node& enemicsData) {


	return true;
}

bool ModuleEnemy::SaveState(pugi::xml_node& configEnemicSpawn) const {


	return true;
}


