#pragma once
#include "Components.h"
#include "SDL.h"
#include "TextureManager.h"
#include <map>

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:
	std::map<int, int> animations;
	int speed = 0;
	int frames = 1;
	int index = 0;


	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTexture(path);
		animations[1] = 1;
		animations[2] = 2;

		Play(1);
	}
	~SpriteComponent()
	{
		SDL_DestroyTexture(texture);
	}

	void setTexture(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
		destRect.w = destRect.h = 64;
		srcRect.w = transform->width;
		srcRect.h = transform->height;

	}

	void update() override
	{
		destRect.x = static_cast<int>(transform->position.x);
		destRect.y = static_cast<int>(transform->position.y);
		destRect.w = transform->width * transform->scale;
		destRect.h = transform->height * transform->scale;
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

	void Play(int animName)
	{
		frames = animations[animName];
		std::cout << frames << std::endl;
	}
};
