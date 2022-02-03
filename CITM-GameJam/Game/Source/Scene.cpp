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

	trencadis = app->tex->Load("Assets/trencadis.png");
	
	CreateRajola(iPoint(200, 200));
	CreateRajola(iPoint(400, 200));
	CreateRajola(iPoint(400, 400));
	CreateRajola(iPoint(200, 400));

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
	
	if (app->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		debug = !debug;
	
	if (hoveringRajola != nullptr) {
		app->render->DrawCircle(hoveringRajola->p.x, hoveringRajola->p.y, 2, 255, 255, 255, 255);
	}
	
	//Grabbing Rajola
	if (grabbing) {

		iPoint mp;
		app->input->GetMousePosition(mp.x, mp.y);

		grabbedRajola->p.x = mp.x - grabbedRajola->grabPosition.x;
		grabbedRajola->p.y = mp.y - grabbedRajola->grabPosition.y;

		if (app->input->GetMouseButtonDown(1) == KEY_DOWN) {
			grabbing = false;
		}

		grabbedRajola->a += app->input->GetMouseWheelMotion() * MOUSE_WHEEL_SENSITIVITY;
	}
	//Not grabbing Rajola
	else {
		//Check if any Rajola is clicking
		iPoint mp;
		app->input->GetMousePosition(mp.x, mp.y);
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

	return ret;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	//Draw all present Rajoles
	DrawRajoles();

	//Debug draw
	if (debug) 
		DebugDrawRajoles();
	
	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	//Need to clean up Rajoles list

	return true;
}

void Scene::CreateRajola(iPoint p)
{
	float f = ReRandomize() % 5 + 8;	//Random SCALE between .8 and 1.2

	int raj = ReRandomize() % (FilesRaj * ColumnesRaj);	//SPRITE RAJOLES -> 30 per fila, 24 per columna
	iPoint i = iPoint((raj / FilesRaj) * WH, (raj % FilesRaj) * WH);

	rajola* r = new rajola(p, i, ReRandomize() % 360, (f / 10.0f));
	Rajoles.add(r);
}

void Scene::DrawRajoles() {
	for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); currentRajola != nullptr; currentRajola = currentRajola->next) {
		SDL_Rect* rect = new SDL_Rect { currentRajola->data->sp.x, currentRajola->data->sp.x, WH, WH}; //Rajola w/h = 125
		app->render->DrawTexture(trencadis, currentRajola->data->p.x, currentRajola->data->p.y,
								rect, 1.0f, currentRajola->data->s, currentRajola->data->a);//, WH / 2, WH / 2);
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