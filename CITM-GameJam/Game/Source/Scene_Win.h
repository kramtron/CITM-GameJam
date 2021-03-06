#ifndef __SCENE_WIN_H__
#define __SCENE_WIN_H__

#include "Module.h"

struct SDL_Texture;

class Scene_Win : public Module
{
public:

	Scene_Win();

	// Destructor
	virtual ~Scene_Win();

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


#endif // __SCENE_WIN_H__