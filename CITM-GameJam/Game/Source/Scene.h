#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "Rajola.h"
#include "p2List.h"

struct SDL_Texture;

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

	// Draw Rajoles
	void DrawRajoles();
	void DebugDrawRajoles();

public:
	p2List<rajola*> Rajoles;
	SDL_Texture* trencadis = nullptr;
	bool grabbing = false;
	rajola* grabbedRajola = nullptr;
};

#endif // __SCENE_H__