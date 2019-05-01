#pragma once
#include "Game.h"

class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer* renderer, int x, int y);

	void Update();
	void Renderer();

private:
	int xpos;
	int ypos;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;
};