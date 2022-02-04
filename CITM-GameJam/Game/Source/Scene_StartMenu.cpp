#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene_StartMenu.h"
#include "Scene.h"
#include "Scene_Lvl.h"
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
	active = false;

	playMode1 = new Button(255, 255, 275, 100);
	playMode2 = new Button(625, 255, 275, 100);
	options = new Button(1000, 255, 275, 100);
	exit = new Button(425, 500, 275, 100);
	credits = new Button(800, 500, 275, 100);
	
	exitCredits = new Button(175, 175, 50, 50);
	exitSettings = new Button(175, 175, 50, 50);

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
	if (destroyCircle == false) {
		app->render->DrawCircle(800, 450, 400, 255, 0, 0);
	}
	//Vector para ver si el mouse está dentro del circulo
	iPoint vector = iPoint((mouse.x - 800), (mouse.y - 450));
	//Calcula la distancia del vector
	distance = (vector.x * vector.x) + (vector.y * vector.y);
	//En caso de estar dentro de la distancia del circulo activa el if
	if(400*400>distance&&destroyCircle==false){
		//Cuando pulsas el boton izquierdo destruyes el circulo
		if (app->input->GetMouseButtonDown(mouse.left) == KEY_DOWN) {
			//Aqui va la activacion de la animación de como se destruye el trencadis
			destroyCircle = true;
		}

	}
	if (destroyCircle) {
		//Aquí va la animación de la destruccion del trencadis

		//quan acabi l'animació s'activa el menu
		endAnimation = true;
		if(exitCount != 0)
		exitCount--;
	}
	//Se necesita un if que active el menu cuando un bool que te indique que la animación esté terminada esté en true
	//A partir de ese punto se activa el menu
	if (endAnimation == true && creditsMenu == false && settingsMenu == false)
	{
		if (playMode1->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				active = false;
				app->scene_lvl->active = true;
			}
		}

		if (playMode2->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{

			}
		}

		if (options->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				endAnimation = false;
				settingsMenu = true;
			}
		}

		if (exit->DetectColision() && exitCount == 0)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				ret = false;
			}
		}

		if (credits->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				endAnimation = false;
				creditsMenu = true;
			}
		}
	}

	if (creditsMenu == true)
	{
		if (exitCredits->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				creditsMenu = false;
				endAnimation = true;
			}
		}
	}

	if (settingsMenu == true)
	{
		if (exitSettings->DetectColision())
		{
			if (app->input->GetMouseButtonDown(1) == KEY_DOWN)
			{
				settingsMenu = false;
				endAnimation = true;
			}
		}
	}

	LOG("mouse x: %d,  mouse y: %d", mouse.x, mouse.y);
	return ret;
}

// Called each loop iteration
bool Scene_StartMenu::PostUpdate()
{
	bool ret = true;

	//menu principal
	if (endAnimation == true)
	{
		//Play1
		app->render->DrawRectangle({255,255,275,100},255,255,255);	
		//Play2
		app->render->DrawRectangle({625,255,275,100},255,255,255);
		//options
		app->render->DrawRectangle({ 1000,255,275,100 }, 255, 255, 255);
		//exit
		app->render->DrawRectangle({ 425,500,275,100 }, 255, 255, 255);
		//credtis
		app->render->DrawRectangle({ 800,500,275,100 }, 255, 255, 255);
	}

	//credits
	if (creditsMenu == true)
	{
		//Menu Fondo
		app->render->DrawRectangle({ 100,100,1400,700 }, 255, 255, 255);
		//return menu
		app->render->DrawRectangle({ 175,175,50,50 }, 125, 125, 125);

	}

	//settings
	if (settingsMenu == true)
	{
		//Setting fondo
		app->render->DrawRectangle({ 100,100,1400,700 }, 255, 255, 255);
		//return menu
		app->render->DrawRectangle({ 175,175,50,50 }, 125, 125, 125);

		//slider vol
		app->render->DrawRectangle({ 450,250,900,25 }, 125, 125, 125);
		//sliderBall vol
		app->render->DrawRectangle({ 900,225,75,75 }, 125, 125, 125);

		//slider fx
		app->render->DrawRectangle({ 450,475,900,25 }, 125, 125, 125);
		//sliderBall fx
		app->render->DrawRectangle({ 900,450,75,75 }, 125, 125, 125);

		//check fullscreen
		app->render->DrawRectangle({ 800,650,125,125 }, 125, 125, 125);
	}

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
