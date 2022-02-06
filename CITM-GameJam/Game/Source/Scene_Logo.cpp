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
#include "Animation.h"

#include "Defs.h"
#include "Log.h"

Scene_Logo::Scene_Logo() : Module()
{
	name.Create("scene_logo");
}

// Destructor
Scene_Logo::~Scene_Logo()
{}

// Called before render is available
bool Scene_Logo::Awake()
{
	LOG("Loading Logo");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool Scene_Logo::Start()
{
	intro = app->tex->Load("Assets/IntroAnimation.png");
	app->audio->PlayMusic("Assets/Audio/backgroundMusic.ogg");

	introAnimation.Empty();
	for (int j = 0; j < 3; ++j) {
		for (int i = 0; i < 8; ++i) {
			introAnimation.PushBack({ i * 1600, j * 900, 1600, 900 });
		}
	}
	
	introAnimation.speed = 0.005f;
	introAnimation.loop = false;

	return true;
}

// Called each loop iteration
bool Scene_Logo::PreUpdate()
{
	return true;
}

// Called each loop iteration
bool Scene_Logo::Update(float dt)
{
	bool ret = true;

	if (introAnimation.HasFinished()) {
		active = false;
		app->scene_startmenu->active = true;
	}

	return ret;
}

// Called each loop iteration
bool Scene_Logo::PostUpdate()
{
	bool ret = true;

	app->render->DrawTexture(intro, 0, 0, &introAnimation.GetCurrentFrame());
	introAnimation.Update();

	return ret;
}

// Called before quitting
bool Scene_Logo::CleanUp()
{
	LOG("Freeing scene");
	
	introAnimation.Reset();
	intro = nullptr;

	return true;
}


void Scene_Logo::DebugDraw()
{

}