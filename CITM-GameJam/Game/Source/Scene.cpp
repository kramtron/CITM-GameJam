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
	

	return ret;
}

// Called each loop iteration
bool Scene::PostUpdate()
{
	bool ret = true;

	DrawRajoles();

	return ret;
}

// Called before quitting
bool Scene::CleanUp()
{
	LOG("Freeing scene");

	return true;
}

void Scene::CreateRajola(iPoint p)
{
	srand(time(NULL));
	float f = rand() % 5 + 8;
	iPoint i = iPoint(rand() % 30 * 125, rand() % 24 * 125);	//SPRITE RAJOLES -> 30 per fila, 60 per columna, widht/height = 200
	rajola* r = new rajola(p, i, rand() % 360, (f / 10.0f));
	Rajoles.add(r);
}

void Scene::DrawRajoles() {
	for (p2List_item<rajola*>* currentRajola = Rajoles.getFirst(); currentRajola != nullptr; currentRajola = currentRajola->next) {
		SDL_Rect* rect = new SDL_Rect { currentRajola->data->sp.x, currentRajola->data->sp.x, 125, 125}; //Rajola w/h = 125
		app->render->DrawTexture(trencadis, currentRajola->data->p.x, currentRajola->data->p.y, rect, 1.0f, currentRajola->data->s,
			currentRajola->data->a , currentRajola->data->p.x + (125/2), currentRajola->data->p.y + (125 / 2));
	}
}