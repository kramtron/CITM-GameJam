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

	playMode1 = new Button(700, 440, 200, 75);
	exit = new Button(700, 550, 200, 75);
	credits = new Button(700, 650, 200, 60);
	
	exitCredits = new Button(175, 175, 50, 50);

	animMenu = app->tex->Load("Assets/menuAnimation.png");
	menu = app->tex->Load("Assets/Menu.png");
	menuFondo = app->tex->Load("Assets/fondo_menu.png");

	menuAnimation.Empty();
	for (int j = 0; j < 8; ++j) {
		for (int i = 0; i < 8; ++i) {
			menuAnimation.PushBack({ i * 1600, j * 900, 1600, 900 });
		}
	}
	menuAnimation.speed = 0.005f;
	menuAnimation.loop = false;

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
	/*if (destroyCircle == false) {
		app->render->DrawCircle(800, 450, 400, 255, 0, 0);
	}*/

	//Vector para ver si el mouse está dentro del circulo
	iPoint vector = iPoint((mouse.x - 800), (mouse.y - 450));

	//Calcula la distancia del vector
	distance = (vector.x * vector.x) + (vector.y * vector.y);

	//En caso de estar dentro de la distancia del circulo activa el if
	if(400*400>distance && menuAnimation.HasFinished() == false){

		//Cuando pulsas el boton izquierdo destruyes el circulo
		if (app->input->GetMouseButtonDown(mouse.left) == KEY_DOWN) {
			//Aqui va la activacion de la animación de como se destruye el trencadis
			destroyCircle = true;
		}
	}

	if (menuAnimation.HasFinished()) {
		//quan acabi l'animació s'activa el menu
		endAnimation = true;
		if(exitCount != 0)
		exitCount--;
	}

	//A partir de ese punto se activa el menu
	if (endAnimation == true && creditsMenu == false)
	{
		if (playMode1->DetectColision() && exitCount == 0)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_UP)
			{
				exitCount = 10;
				active = false;
				app->scene_lvl->active = true;
			}
		}

		if (exit->DetectColision() && exitCount == 0)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_UP)
			{
				ret = false;
			}
		}

		if (credits->DetectColision() && exitCount == 0)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_UP)
			{
				exitCount = 10;
				endAnimation = false;
				creditsMenu = true;
			}
		}
	}

	if (creditsMenu == true)
	{
		//return menu
		if (exitCredits->DetectColision() && exitCount == 0)
		{
			if (app->input->GetMouseButtonDown(1) == KEY_UP)
			{
				exitCount = 10;
				creditsMenu = false;
				endAnimation = true;
			}
		}
	}

	return ret;
}

// Called each loop iteration
bool Scene_StartMenu::PostUpdate()
{
	bool ret = true;

	//Animation
	if(destroyCircle)
		menuAnimation.Update();
	app->render->DrawTexture(animMenu, 0, 0, &menuAnimation.GetCurrentFrame());


	//menu principal
	if (endAnimation == true)
	{

		//Play1
		//app->render->DrawRectangle({700,650,200,60},0,0,0);	
		//exit
		/*app->render->DrawRectangle({ 425,500,275,100 }, 255, 255, 255);
		//credtis
		app->render->DrawRectangle({ 800,500,275,100 }, 255, 255, 255);*/
		app->render->DrawTexture(menuFondo, 0, 0);
		app->render->DrawTexture(menu, 0, 0);
	}

	//credits
	if (creditsMenu == true)
	{
		//Menu Fondo
		app->render->DrawRectangle({ 100,100,1400,700 }, 255, 255, 255);
		//return menu
		app->render->DrawRectangle({ 175,175,50,50 }, 125, 125, 125);

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
