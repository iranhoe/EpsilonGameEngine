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

	static SDL_Event event;
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

