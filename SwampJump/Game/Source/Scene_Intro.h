#ifndef __SCENE_INTRO_H__
#define __SCENE_INTRO_H__

#include "Module.h"

struct SDL_Texture;

class Scene_Intro : public Module
{
public:

	Scene_Intro();

	// Destructor
	virtual ~Scene_Intro();

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

	bool LoadGameConfig(pugi::xml_node&, pugi::xml_node&, pugi::xml_node&);

	bool SaveGameConfig(pugi::xml_node&, pugi::xml_node&, pugi::xml_node&) const;

private:


};


#endif // __SCENE_INTRO_H__