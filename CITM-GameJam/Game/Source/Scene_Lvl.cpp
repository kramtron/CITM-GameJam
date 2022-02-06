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

	UPC = app->tex->Load("Assets/fig0.png");
	fig1 = app->tex->Load("Assets/fig1.png");
	fig2 = app->tex->Load("Assets/fig2.png");
	fig3 = app->tex->Load("Assets/fig3.png");
	fig4 = app->tex->Load("Assets/fig4.png");
	fig5 = app->tex->Load("Assets/fig5.png");
	fig6 = app->tex->Load("Assets/fig6.png");
	fig7 = app->tex->Load("Assets/fig7.png");
	fig8 = app->tex->Load("Assets/fig8.png");
	fig9 = app->tex->Load("Assets/fig9.png");
	fig10 = app->tex->Load("Assets/fig10.png");
	fig11 = app->tex->Load("Assets/fig11.png");
	fig12 = app->tex->Load("Assets/fig12.png");

	fondo = app->tex->Load("Assets/mapselect.png");


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

	if (butt1->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
		{
			active = false;
			app->scene_startmenu->active = true;
		}
	}

	if (mouse.y >= 175 && mouse.y <= 625)
	{		
		if (posMap <= 4313 && posMap >= -4387)
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
		else if (posMap <= 4313)
		{
			posMap += 1;
		}
		else if (posMap >= -4387)
		{
			posMap -= 1;
		}
	}

	
	if (posMap >= -4749 && posMap <= -4025)
		selectMap = 0;
	else if (posMap >= -4024 && posMap <= -3300)
		selectMap = 12;
	else if (posMap >= -3299 && posMap <= -2575)
		selectMap = 11;
	else if (posMap >= -2574 && posMap <= -1850)
		selectMap = 10;
	else if (posMap >= -1849 && posMap <= -1125)
		selectMap = 9;
	else if (posMap >= -1124 && posMap <= -400)
		selectMap = 8;
	else if (posMap >= -399 && posMap <= 325)
		selectMap = 7;
	else if (posMap >= 326 && posMap <= 1050)
		selectMap = 6;
	else if (posMap >= 1051 && posMap <= 1775)
		selectMap = 5;
	else if (posMap >= 1776 && posMap <= 2500)
		selectMap = 4;
	else if (posMap >= 2501 && posMap <= 3225)
		selectMap = 3;
	else if (posMap >= 3226 && posMap <= 3950)
		selectMap = 2;
	else if (posMap >= 3951 && posMap <= 4675)
		selectMap = 1;


	if (butt2->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
		{
			app->scene->CleanUp();
			app->scene->lvl_selected = selectMap;
			app->scene->Start();

			active = false;
			app->scene->active = true;
		}
	}

	return ret;
}

// Called each loop iteration
bool Scene_Lvl::PostUpdate()
{
	bool ret = true;

	//Draw Map selected
	app->render->DrawTexture(fondo, 0, 0);

	//app->render->DrawRectangle({ 500,205,600,390 }, 255, 255, 255);
	//app->render->DrawRectangle({ 505,210,590,380 }, 0, 0, 0);

	//Draw Maps
	/*app->render->DrawRectangle({ -3825 + posMap,225,550,350 }, 255, 255, 255);
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
	app->render->DrawRectangle({ 4875 + posMap,225,550,350 }, 255, 255, 255);*/

	app->render->DrawTexture(fig1, -3950 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig2, -3225 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig3, -2500 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig4, -1775 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig5, -1050 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig6, -325 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig7, 400 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig8, 1125 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig9, 1850 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig10, 2575 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig11, 3300 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(fig12, 4025 + posMap, 200, NULL, NULL, 0.5);
	app->render->DrawTexture(UPC, 4750 + posMap, 200, NULL, NULL, 0.5);



	//Draw return menu
	//app->render->DrawRectangle({ 50,750,250,100 }, 255, 255, 255);

	//Draw Play
	//app->render->DrawRectangle({ 1300,750,250,100 }, 255, 255, 255);
	

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