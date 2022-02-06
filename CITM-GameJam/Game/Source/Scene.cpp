#include "App.h"
#include "Input.h"
#include "Textures.h"
#include "Audio.h"
#include "Render.h"
#include "Window.h"
#include "Scene.h"
#include "Scene_StartMenu.h"
#include "Scene_Logo.h"
#include "Scene_Lvl.h"
#include "Scene_Win.h"
#include "Animation.h"

#include "time.h"
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

	active = false;

	//Load Audio
	cameraFx = app->audio->LoadFx("Assets/Audio/cameraFlash.wav");
	pieceFx = app->audio->LoadFx("Assets/Audio/woodClick.wav");
	refreshFx = app->audio->LoadFx("Assets/Audio/pieceRefresh.wav");

	//Load Images
	trencadis = app->tex->Load("Assets/trencadis.png");
	brillibrilli = app->tex->Load("Assets/brillitu.png");
	mapa = app->tex->Load("Assets/scenemap.png");
	instruccions = app->tex->Load("Assets/instruccions.png");
	exitgame = app->tex->Load("Assets/exit.png");
	returnmenu = app->tex->Load("Assets/returnmenu.png");

	switch (lvl_selected) {
	case 1:
		figura = app->tex->Load("Assets/fig1.png");
		break;
	case 2:
		figura = app->tex->Load("Assets/fig2.png");
		break;
	case 3:
		figura = app->tex->Load("Assets/fig3.png");
		break;
	case 4:
		figura = app->tex->Load("Assets/fig4.png");
		break;
	case 5:
		figura = app->tex->Load("Assets/fig5.png");
		break;
	case 6:
		figura = app->tex->Load("Assets/fig6.png");
		break;
	case 7:
		figura = app->tex->Load("Assets/fig7.png");
		break;
	case 8:
		figura = app->tex->Load("Assets/fig8.png");
		break;
	case 9:
		figura = app->tex->Load("Assets/fig9.png");
		break;
	case 10:
		figura = app->tex->Load("Assets/fig10.png");
		break;
	case 11:
		figura = app->tex->Load("Assets/fig11.png");
		break;
	case 12:
		figura = app->tex->Load("Assets/fig12.png");
		break;
	case 0:
		figura = app->tex->Load("Assets/fig0.png");
		break;
	}
	
	Enrajolar();

	cameraCollider = { 750, 700, 100, 80 };

	extigame = new ButtonScene(240, 825, 105, 50);
	returnMenu = new ButtonScene(35, 825, 130, 50);

	return true;
}

// Called each loop iteration
bool Scene::PreUpdate()
{
	//Restart hovering Rajola
	hoveringRajola = nullptr;

	return true;
}

// Called each loop iteration
bool Scene::Update(float dt)
{
	bool ret = true;
	
	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		debug = !debug;
	
	//Refresh Rajoles
	if (app->input->GetMouseButtonDown(3) == KEY_DOWN) {
		app->audio->PlayFx(refreshFx);
		ClearRajoles();
		Enrajolar();
		grabbing = false;
	}
	
	iPoint mp;
	app->input->GetMousePosition(mp.x, mp.y);

	//Grabbing Rajola
	if (grabbing) {
		grabbedRajola->p.x = mp.x - grabbedRajola->grabPosition.x;
		grabbedRajola->p.y = mp.y - grabbedRajola->grabPosition.y;

		if (app->input->GetMouseButtonDown(1) == KEY_DOWN) {
			grabbing = false;
			app->audio->PlayFx(pieceFx);
		}

		//Mouse Wheel sensitivity escalation
		grabbedRajola->a += app->input->GetMouseWheelMotion() * wheelSensitivity;
		if (app->input->GetMouseWheelMotion() != 0) {
			wheelSensitivity++;
		}

		if (wheelResetTimer <= 0) {
			wheelSensitivity = 3;
			wheelResetTimer = 500;
		}
		else {
			wheelResetTimer--;
		}
	}
	//Not grabbing Rajola
	else {
		//Check if any Rajola is clicking
		bool clicked = false;
		for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); (currentRajola != nullptr) && (!grabbing); currentRajola = currentRajola->next) {
			//Mouse hover detection
			if (currentRajola->data->DetectCollision(mp)) {
				//Hovering
				hoveringRajola = currentRajola->data;

				//Hoverning and clicking
				if (app->input->GetMouseButtonDown(1) == KEY_DOWN) {
					if (currentRajola->data->DetectGrab(mp)) {
						grabbedRajola = currentRajola->data;
						grabbedRajola->setGrab(true);
						clicked = true;
					}
				}
			}
		}
		if (clicked) {
			grabbing = true;
			hoveringRajola = nullptr;
		}
	}

	//screenshot
	if (app->input->GetMouseButtonDown(1) == KEY_DOWN && mp.x > cameraCollider.x && mp.x < (cameraCollider.x + cameraCollider.w) && 
											 mp.y > cameraCollider.y && mp.y < (cameraCollider.y + cameraCollider.h)) {
		app->render->screenshot = true;
		screenshooting = 50;
		app->audio->PlayFx(cameraFx);
	}


	if (extigame->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
		{
			ret = false;
		}
	}

	if (returnMenu->DetectColision())
	{
		if (app->input->GetMouseButtonDown(1))
		{
			active = false;
			app->scene_startmenu->active = true;
		}
	}

	return ret;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	//Draw map
	app->render->DrawTexture(mapa, 0, 0);

	//Draw figura
	app->render->DrawTexture(figura, 0, 0);

	//Draw Instruccions
	app->render->DrawTexture(instruccions, 700, 820);

	//Draw all present Rajoles
	DrawRajoles();

	//Draw BrilliBrilli
	if(hoveringRajola != nullptr)
		app->render->DrawTexture(brillibrilli, hoveringRajola->p.x, hoveringRajola->p.y, NULL, 1.0f, hoveringRajola->s);

	//Debug draw
	if (debug) {
		DebugDrawRajoles();

		//Draw Camera Rectangle
		app->render->DrawRectangle(cameraCollider, 0, 0, 255, 100);
	}

	//app->render->DrawRectangle(SDL_Rect{397, 160, 820, 600}, 0, 200, 0, 100);

	//Screenshot Flash
	if (screenshooting == 0)
		app->render->screenshotCheck = true;
	else
		app->render->screenshotCheck = false;

	if (screenshooting > 0) {
		app->render->DrawRectangle(SDL_Rect{ 0, 0, 1600, 900}, 255, 255, 255, (150 / screenshooting) + 105);
		screenshooting--;
	}
	
	//app->render->DrawRectangle({ 240,825,105,50 }, 255, 255, 255);
	//app->render->DrawRectangle({ 35,825,130,50 }, 255, 255, 255);
	app->render->DrawTexture(exitgame, -50, 550, NULL, NULL, 0.6);
	app->render->DrawTexture(returnmenu, 0, 190, NULL, NULL, 0.8);

	return true;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	//Need to clean up Rajoles list
	Rajoles.clear();

	trencadis = nullptr;
	brillibrilli = nullptr;
	mapa = nullptr;
	figura = nullptr;
	instruccions = nullptr;
	grabbedRajola = nullptr;
	hoveringRajola = nullptr;

	return true;
}

void Scene::ClearRajoles() {
	for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); currentRajola != nullptr; currentRajola = currentRajola->next) {
		iPoint p = currentRajola->data->p;
		if ((p.x < 360 && p.x > 120 && p.y > 200 && p.y < 700) || (p.x < 1460 && p.x > 1220 && p.y > 200 && p.y < 700)) {
			Rajoles.del(currentRajola);
		}
	}
}

void Scene::Enrajolar() {
	//Left container
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 6; ++j) {
			CreateRajola(iPoint(70 * i + 200, 70 * j + 240));	//espaiat entre rajoles 70, posició 200, 240
		}
	}

	//Right container
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 6; ++j) {
			CreateRajola(iPoint(70 * i + 1300, 70 * j + 240));
		}
	}
}

void Scene::CreateRajola(iPoint p)
{
	float f = ReRandomize() % 5 + 5;	//Random SCALE between .5 and .9

	//SPRITE RAJOLES -> 30 per fila, 24 per columna
	iPoint i = iPoint((ReRandomize() % FilesRaj) * WH, (ReRandomize() % ColumnesRaj) * WH);

	rajola* r = new rajola(p, i, ReRandomize() % 360, (f / 10.0f));
	Rajoles.add(r);
}

void Scene::DrawRajoles() {
	for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); currentRajola != nullptr; currentRajola = currentRajola->next) {
		SDL_Rect* rect = new SDL_Rect { currentRajola->data->sp.x + 10, currentRajola->data->sp.y + 10, WH - 20, WH -20 }; //Rajola w/h = 125
		app->render->DrawTexture(trencadis, currentRajola->data->p.x, currentRajola->data->p.y,
								rect, 1.0f, currentRajola->data->s, currentRajola->data->a);
		delete rect;
	}
}

void Scene::DebugDrawRajoles() {
	//COLLIDERS
	for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); (currentRajola != nullptr) && (!grabbing); currentRajola = currentRajola->next) {
		SDL_Rect rect = { currentRajola->data->p.x + (WH / 2 * currentRajola->data->s) - currentRajola->data->c,
							currentRajola->data->p.y + (WH / 2 * currentRajola->data->s) - currentRajola->data->c,
							currentRajola->data->c*2, currentRajola->data->c*2 };
		app->render->DrawRectangle(rect, 255, 0, 0, 100);
		app->render->DrawCircle(currentRajola->data->p.x + WH/2 * currentRajola->data->s, currentRajola->data->p.y + WH/2 * currentRajola->data->s, 2, 0, 0, 255);
	}
}

int Scene::ReRandomize() {
	srand(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now() - app->Timer).count());
	return rand();
}