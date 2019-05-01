/**
	Game.cpp
	Purpose: Create the base of the engine

	@author Iran Corrales Becerra
	@version 1.0 04/30/19
*/

#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "Components.h"
#include "Vector2D.h"
#include "Collision.h"

Map* map;
SDL_Renderer* Game::renderer = nullptr;
SDL_Event Game::event;
Manager manager;
auto& player(manager.addEntity());
auto& wall(manager.addEntity());

Game::Game()
{
	Game::cnt = 0;
	Game::isRunning = false;
}

Game::~Game()
{

}

/**
	Initialize the engine

	@param title set the title of the screen
	@param xpos
	@param ypos
	@param width
	@param height
	@param fullscreen
*/
void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystem Initialised..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Windows created" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}

	map = new Map();
	player.addComponent<TransformComponent>(2);
	player.addComponent<KeyboardController>();
	player.addComponent<SpriteComponent>("Assets/Sprites/Player.png");
	player.addComponent<ColliderComponent>();

	wall.addComponent<TransformComponent>(300.0f, 300.0f, 300, 20, 1);
	wall.addComponent<SpriteComponent>("Assets/Background/dirt.png");
	wall.addComponent<ColliderComponent>();
}

/**
	handle the user events
*/
void Game::handleEvents()
{
	SDL_PollEvent(&event);
	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		default:
			break;
	}
}

/**

*/
void Game::update()
{
	manager.refresh();
	manager.update();
	if (Collision::AABB(player.getComponent<ColliderComponent>().collider, 
		wall.getComponent<ColliderComponent>().collider))
	{ 
		player.getComponent<TransformComponent>().velocity * -1;
		std::cout << "Wall Hit!" << std::endl;
	}
}

/**

*/
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}

/**
	Free the game engine objects
*/
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}

