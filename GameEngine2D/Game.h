#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "AssetManager.h"
#include "Window.h"
#include <iostream>
#include <vector>
#include <string>

class AssetManager;
class ColliderComponent;

class Game
{
public:
	Game(Window& window);
	~Game();

	void init();
	void handleEvents();
	void update();
	void render();
	void clean();
	bool running() const { return isRunning; };

	static SDL_Event event;
	static bool isRunning;
	static SDL_Rect camera;
	static AssetManager* assets;
	enum groupLables : std::size_t
	{
		groupMap,
		groupPlayers,
		groupColliders,
		groupProjectiles
	};

private:
	int cnt;	
	Window *gameWindow = nullptr;
};

