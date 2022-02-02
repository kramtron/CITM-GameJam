#ifndef __SCENE_STARTMENU_H__
#define __SCENE_STARTMENU_H__

#include "Module.h"

struct SDL_Texture;

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

	bool LoadGameConfig(pugi::xml_node&, pugi::xml_node&, pugi::xml_node&);

	bool SaveGameConfig(pugi::xml_node&, pugi::xml_node&, pugi::xml_node&) const;

private:


};


#endif // __SCENE_STARTMENU_H__