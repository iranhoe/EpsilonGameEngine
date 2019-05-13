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
#include "AssetManager.h"


Map* map;
Manager manager;
AssetManager* Game::assets = new AssetManager(&manager);
SDL_Event Game::event;
SDL_Rect Game::camera = { 0, 0, 800, 640 };
bool Game::isRunning = false;
auto& player(manager.addEntity());

Game::Game(Window &window)
{
	gameWindow = &window;
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
void Game::init()
{
	isRunning = true;

	assets->AddTexture("terrain", "Assets/Tiles/terrain_ss.png");
	assets->AddTexture("player", "Assets/Sprites/Player_Anims.png");
	assets->AddTexture("projectile", "Assets/Sprites/proj.png");

	map = new Map("terrain", 3, 32);
	map->LoadMap("Assets/Maps/map.map", 25, 20);
	player.addComponent<TransformComponent>(800.0f, 640.0f, 32, 32, 4);
	player.addComponent<SpriteComponent>("player", true);
	player.addComponent<KeyboardController>();
	player.addComponent<ColliderComponent>("player");
	player.addGroup(groupPlayers);

	assets->CreateProjectile(Vector2D(600, 600), Vector2D(2, 0), 200, 2, "projectile");
	assets->CreateProjectile(Vector2D(600, 620), Vector2D(2, 0), 200, 2, "projectile");
	assets->CreateProjectile(Vector2D(400, 600), Vector2D(2, 1), 200, 2, "projectile");
	assets->CreateProjectile(Vector2D(600, 600), Vector2D(2, -1), 200, 2, "projectile");
}

auto& tiles(manager.getGroup(Game::groupMap));
auto& players(manager.getGroup(Game::groupPlayers));
auto& colliders(manager.getGroup(Game::groupColliders));
auto& projectiles(manager.getGroup(Game::groupProjectiles));

/**
	handle the user events
*/
void Game::handleEvents()
{
	if(SDL_PollEvent(&event))
	{
		gameWindow->pollEvents(event);
	}
}

/**

*/
void Game::update()
{
	SDL_Rect playerCol = player.getComponent<ColliderComponent>().collider;
	Vector2D playerPos = player.getComponent<TransformComponent>().position;

	manager.refresh();
	manager.update();

	for (auto& c : colliders)
	{
		SDL_Rect cCol = c->getComponent<ColliderComponent>().collider;
		if (Collision::AABB(cCol, playerCol))
		{
			player.getComponent<TransformComponent>().position = playerPos;
		}
	}

	for (auto& p : projectiles)
	{
		if (Collision::AABB(player.getComponent<ColliderComponent>().collider, 
			p->getComponent<ColliderComponent>().collider))
		{
			p->destroy();
		}
	}

	camera.x = player.getComponent<TransformComponent>().position.x - 400;
	camera.y = player.getComponent<TransformComponent>().position.y - 320;

	if (camera.x < 0) { camera.x = 0; }
	if (camera.y < 0) { camera.y = 0; }
	if (camera.x > camera.w) { camera.x = camera.w; }
	if (camera.y > camera.h) { camera.y = camera.h; }
}

/**

*/
void Game::render()
{
	gameWindow->render();
	/*SDL_RenderClear(Window::renderer);
	for (auto& t : tiles)
	{
		t->draw();
	}

	for (auto& p : players)
	{
		p->draw();
	}

	for (auto& p : projectiles)
	{
		p->draw();
	}

	SDL_RenderPresent(Window::renderer);*/
}

