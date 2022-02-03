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

	butt1 = new Button(50, 750, 250, 100);
	butt2 = new Button(1300, 750, 250, 100);

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
	
	if (butt2->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
		{

			active = false;
			app->scene->active = true;
		}
	}	
	
	if (butt1->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
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

	
	if (posMap <= -5075)
		selectMap = 0;
	else if (posMap >= -4900 && posMap <= -4350)
		selectMap = 1;
	else if (posMap >= -4180 && posMap <= -3630)
		selectMap = 2;
	else if (posMap >= -3455 && posMap <= -2900)
		selectMap = 3;
	else if (posMap >= -2730 && posMap <= -2175)
		selectMap = 4;
	else if (posMap >= -2000 && posMap <= -1450)
		selectMap = 5;
	else if (posMap >= -1280 && posMap <= -725)
		selectMap = 6;
	else if (posMap >= -555 && posMap <= 0)
		selectMap = 7;
	else if (posMap >= 170 && posMap <= 725)
		selectMap = 8;
	else if (posMap >= 900 && posMap <= 1450)
		selectMap = 9;
	else if (posMap >= 1625 && posMap <= 2175)
		selectMap = 10;
	else if (posMap >= 2345 && posMap <= 2890)
		selectMap = 11;
	else if (posMap >= 3070 && posMap <= 3625)
		selectMap = 12;
	else if (posMap >= 3790 && posMap <= 4345)
		selectMap = 13;
	else if (posMap >= 4500)
		selectMap = 14;

	return ret;
}

// Called each loop iteration
bool Scene_Lvl::PostUpdate()
{
	bool ret = true;

	//Draw Map selected
	app->render->DrawRectangle({ 500,205,600,390 }, 255, 255, 255);
	app->render->DrawRectangle({ 505,210,590,380 }, 0, 0, 0);

	//Draw Maps
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

	//Draw return menu
	app->render->DrawRectangle({ 50,750,250,100 }, 255, 255, 255);

	//Draw Play
	app->render->DrawRectangle({ 1300,750,250,100 }, 255, 255, 255);
	

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