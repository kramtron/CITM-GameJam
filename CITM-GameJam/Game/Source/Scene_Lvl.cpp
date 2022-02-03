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

	app->input->GetMousePosition(mouse.x, mouse.y);

	if ((mouse.x >= 50 && mouse.x <= 300) && (mouse.y >= 750 && mouse.y <= 850))
	{
		if(app->input->GetMouseButtonDown(1))
		{
		active = false;
		app->scene_logo->active = true;
		}
	}

	if (mouse.y >= 175 && mouse.y <= 625)
	{		
		if (posMap <= 5100 && posMap >= -5100)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				posOnClick = mouse.x-posMap;
			}

			if (app->input->GetMouseButtonDown(1) == KEY_REPEAT)
			{
				posMap = mouse.x - posOnClick;
			}		
		}
		else if (posMap <= 5075)
		{
			posMap += 1;
		}
		else if (posMap >= -5075)
		{
			posMap -= 1;
		}
	}

	/*
	if (posMap < -4550)
		selectMap = 0;
	else if (posMap <= -3850 && posMap >= 3250)
		selectMap = 1;
	else if (posMap <= -3125 && posMap >= -2525)
		selectMap = 2;
	else if (posMap <= -2400 && posMap >= -1800)
		selectMap = 3;
	else if (posMap <= -1675 && posMap >= -1075)
		selectMap = 4;
	else if (posMap <= -950 && posMap >= -350)
		selectMap = 5;
	else if (posMap <= -225 && posMap >= 375)
		selectMap = 6;
	else if (posMap <= 500 && posMap >= 1100)
		selectMap = 7;
	else if (posMap <= 1225 && posMap >= 1825)
		selectMap = 8;
	else if (posMap <= 1950 && posMap >= 2550)
		selectMap = 9;
	else if (posMap <= 2675 && posMap >= 3275)
		selectMap = 10;
	else if (posMap <= 3400 && posMap >= 4000)
		selectMap = 11;
	else if (posMap <= 4125 && posMap >= 4725)
		selectMap = 12;
	else if (posMap <= 4850 && posMap >= 5450)
		selectMap = 13;
	else if (posMap > 5600)
		selectMap = 14;

	LOG("Mapa Selected %d", selectMap);
	*/

	return ret;
}

// Called each loop iteration
bool Scene_Lvl::PostUpdate()
{
	bool ret = true;
	app->render->DrawRectangle({ -4550 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -3825 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -3100 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -2375 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -1650 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -925 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ -200 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 525 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 1250 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 1975 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 2700 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 3425 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 4150 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 4875 + posMap,225,550,350 }, 255, 255, 255);
	app->render->DrawRectangle({ 5600 + posMap,225,550,350 }, 255, 255, 255);


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