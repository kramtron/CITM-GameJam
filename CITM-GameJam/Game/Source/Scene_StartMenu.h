#ifndef __SCENE_STARTMENU_H__
#define __SCENE_STARTMENU_H__

#include "Module.h"

struct SDL_Texture;

class Button {
public:
	int x, y, w, h;

	Button() {
		x = y = w = h = 0;
	}

	Button(int x, int y, int w, int h) {
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

class Scene_StartMenu : public Module
{
public:

	Scene_StartMenu();

	// Destructor
	virtual ~Scene_StartMenu();

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


	bool loadPreConfig = true;

	struct Mouse{
		int x, y;
		int left = 1;
		int right = 3;
	}mouse;

	float distance;

	bool destroyCircle = false;
	bool endAnimation = false;
	bool creditsMenu = false;
	bool settingsMenu = false;

	Button* playMode1 = nullptr;
	Button* playMode2 = nullptr;
	Button* options = nullptr;
	Button* exit = nullptr;
	Button* credits = nullptr;

	Button* exitCredits = nullptr;
	Button* exitSettings = nullptr;

private:

	

};


#endif // __SCENE_STARTMENU_H__