#ifndef __SCENE_LVL_H__
#define __SCENE_LVL_H__

#include "Module.h"

struct SDL_Texture;

class Scene_Lvl : public Module
{
public:

	Scene_Lvl();

	// Destructor
	virtual ~Scene_Lvl();

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

	void DebugDraw();


private:

	

};


#endif // __SCENE_LVL_H__