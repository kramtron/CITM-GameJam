#ifndef __APP_H__
#define __APP_H__

#include "Module.h"
#include "List.h"

#include "PugiXml/src/pugixml.hpp"

#include <chrono>

#define CONFIG_FILENAME		"config.xml"
#define SAVE_STATE_FILENAME "save_game.xml"

// Modules
class Window;
class Input;
class Render;
class Textures;
class Audio;
class Scene_Logo;
class Scene_StartMenu;
class Scene;
class Scene_Lvl;
class Scene_Win;

class App
{
public:

	// Constructor
	App(int argc, char* args[]);

	// Destructor
	virtual ~App();

	// Called before render is available
	bool Awake();

	// Called before the first frame
	bool Start();

	// Called each loop iteration
	bool Update();

	// Called before quitting
	bool CleanUp();

	// Add a new module to handle
	void AddModule(Module* module);

	// Exposing some properties for reading
	int GetArgc() const;
	const char* GetArgv(int index) const;
	const char* GetTitle() const;
	const char* GetOrganization() const;

    // L02: DONE 1: Create methods to request Load / Save
	void LoadGameRequest();//Es LoadGameRequest
	void SaveGameRequest() const;
	void SetDt(float t) {
		this->dt = t;
	}
private:

	// Load config file
	// NOTE: It receives config document
	pugi::xml_node LoadConfig(pugi::xml_document&) const;
	//Load Save_game file
	pugi::xml_node LoadGame_Data(pugi::xml_document&) const;


	// Call modules before each loop iteration
	void PrepareUpdate();

	// Call modules before each loop iteration
	void FinishUpdate();

	// Call modules before each loop iteration
	bool PreUpdate();

	// Call modules on each loop iteration
	bool DoUpdate();

	// Call modules after each loop iteration
	bool PostUpdate();

	// Load / Save
	bool LoadGame();
	bool SaveGame();

public:

	// Modules
	Window* win;
	Input* input;
	Render* render;
	Textures* tex;
	Audio* audio;
	Scene_Logo* scene_logo;
	Scene_StartMenu* scene_startmenu;
	Scene* scene;
	Scene_Lvl* scene_lvl;
	Scene_Win* scene_win;

	bool pause = false;
	
	//chrono
	std::chrono::time_point<std::chrono::steady_clock, std::chrono::duration<_int64, std::ratio<1, 1000000000>>>
		timer;

private:

	int argc;
	char** args;
	SString title;
	SString organization;

	List<Module *> modules;

	// L01: DONE 2: Create new variables from pugui namespace
	// NOTE: Redesigned LoadConfig() to avoid storing this variables
	pugi::xml_document configFile;
	pugi::xml_document configFile2;
	pugi::xml_node config;
	


	pugi::xml_document configSaveGame;
	


	uint frames;
	float dt;

	mutable bool saveGameRequested;
	bool loadGameRequested;
};

extern App* app;

#endif	// __APP_H__