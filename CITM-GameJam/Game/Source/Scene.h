#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "Rajola.h"
#include "Audio.h"
#include "p2List.h"
#include <chrono>
using namespace std;

struct SDL_Texture;

class ButtonScene {
public:
	int x, y, w, h;

	ButtonScene() {
		x = y = w = h = 0;
	}

	ButtonScene(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

public:
	bool DetectColision() {
		int mx, my;
		app->input->GetMousePosition(mx, my);
		return (mx > x && mx < (x + w) && my > y && my < (y + h));
	}

};

class Scene : public Module
{
public:

	Scene();

	// Destructor
	virtual ~Scene();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	// Called each loop iteration
	bool Update(float dt);

	// Called before all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// Create random rajola in coords
	void CreateRajola(iPoint p);
	void Enrajolar();
	void ClearRajoles();

	// Draw Rajoles
	void DrawRajoles();
	void DebugDrawRajoles();

	//Randomise
	int ReRandomize();
public:
	p2List<rajola*> Rajoles;
	SDL_Texture* trencadis = nullptr;
	SDL_Texture* brillibrilli = nullptr;
	SDL_Texture* mapa = nullptr;
	SDL_Texture* figura = nullptr;
	SDL_Texture* instruccions = nullptr;
	SDL_Texture* exitgame = nullptr;
	SDL_Texture* returnmenu = nullptr;

	bool grabbing = false;
	rajola* grabbedRajola = nullptr;
	rajola* hoveringRajola = nullptr;
	uint pieceFx;
	uint refreshFx;

	SDL_Rect cameraCollider;
	int screenshooting = 0;
	uint cameraFx;

	bool debug = false;

	int wheelSensitivity = 3;
	int wheelResetTimer = 0;

	int lvl_selected = 1;

	ButtonScene* extigame = nullptr;
	ButtonScene* returnMenu = nullptr;

};

#endif // __SCENE_H__