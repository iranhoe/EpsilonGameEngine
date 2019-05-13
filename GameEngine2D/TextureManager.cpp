#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* fileName)
{
	SDL_Surface *tempSurface = IMG_Load(fileName);
	if (!tempSurface)
	{
		std::cerr << "Failed to create surface." << std::endl;
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(Window::renderer, tempSurface);
	if (!texture)
	{
		//std::cerr << "Failed to create texture." << std::endl;
	}
	SDL_FreeSurface(tempSurface);

	return texture;
}

void TextureManager::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest, SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(Window::renderer, texture, &src, &dest, NULL, NULL, flip);
}
