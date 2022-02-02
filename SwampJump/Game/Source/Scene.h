#ifndef __SCENE_H__
#define __SCENE_H__

#include "Module.h"
#include "Animation.h"

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

	void DebugDraw();

	void DrawDecorations();

	void ObeliskMenuController();
	
	

	bool SaveState(pugi::xml_node&) const;
	bool SaveScene1State(pugi::xml_node&) const;

	


	//Number, digit number, position X, position Y, number separation, scale.
	void FontDraw(int score, int n, int posX, int posY, int separacio, float scale);



private:
	
};

#endif // __SCENE_H__