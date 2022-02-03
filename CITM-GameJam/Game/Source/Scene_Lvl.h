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

	struct Mouse {
		int x, y;
	}mouse;

	int posOnClick;
	int posMap;
	int goodPosMap;

	int selectMap;

private:

	

};

class Button {
public:
	int x, y, w, h;

	Button() {}

	Button(int x, int y, int w, int h) {
		this->x = x;
		this->y = y;
		this->w = w;
		this->h = h;
	}

	bool DetectColision() {
		int mx, my;
		app->input->GetMousePosition(mx, my);
		return (mx > x && mx < (x + w) && my > y && my < (y + h));
	}
};

#endif // __SCENE_LVL_H__