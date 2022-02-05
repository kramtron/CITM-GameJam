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

	Button* butt1 = nullptr;
	Button* butt2 = nullptr;

	SDL_Texture* UPC = nullptr;
	SDL_Texture* fig1 = nullptr;
	SDL_Texture* fig2 = nullptr;
	SDL_Texture* fig3 = nullptr;
	SDL_Texture* fig4 = nullptr;
	SDL_Texture* fig5 = nullptr;
	SDL_Texture* fig6 = nullptr;
	SDL_Texture* fig7 = nullptr;
	SDL_Texture* fig8 = nullptr;
	SDL_Texture* fig9 = nullptr;
	SDL_Texture* fig10 = nullptr;
	SDL_Texture* fig11 = nullptr;
	SDL_Texture* fig12 = nullptr;

	SDL_Texture* fondo = nullptr;


private:

	

};

#endif // __SCENE_LVL_H__