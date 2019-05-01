#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* fileName, SDL_Renderer* renderer, int x, int y)
{
	GameObject::renderer = renderer;
	objTexture = TextureManager::LoadTexture(fileName, renderer);

	xpos = x; 
	ypos = y;
}

void GameObject::Update()
{
	xpos++;
	ypos++;
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

void GameObject::Renderer()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}