#pragma once
#include "Components.h"
#include "Vector2D.h"

class TransformComponent : public Component
{
public:
	Vector2D position;
	Vector2D velocity;
	int speed = 3;
	int height = 32;
	int width = 32;
	int scale = 1;

	TransformComponent()
	{
		position.Zero();
	}

	TransformComponent(int scl)
	{
		position.x = 400;
		position.y = 320;
		scale = scl;
	}

	TransformComponent(float x, float y)
	{
		position.x = x;
		position.y = y;
	}

	TransformComponent(float x, float y, int h, int w, int scl)
	{
		position.x = x;
		position.y = y;
		height = h;
		width = w;
		scale = scl;
	}

	void init() override
	{
		velocity.x = 0;
		velocity.y = 0;
	}

	void update() override
	{
		position.x += velocity.x * speed;
		position.y += velocity.y * speed;
	}
};