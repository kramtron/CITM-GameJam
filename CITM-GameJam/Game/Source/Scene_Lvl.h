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
	SDL_Rect r;

	Button(SDL_Rect r) {
		this->r = r;
	}

	Button(int x, int y, int w, int h) {
		r.x = x;
		r.y = y;
		r.w = w;
		r.h = h;
	}

	bool DetectColision() {
		iPoint m;
		app->input->GetMousePosition(m.x, m.y);
		return (m.x > r.x && m.x < (r.x + r.w) && m.y > r.y && m.y < (r.y + r.h));
	}
};

#endif // __SCENE_LVL_H__