#include "Map.h"
#include "TextureManager.h"

int lvl1[20][20] = {
	{ 0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,2,2,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};

Map::Map()
{
	dirt = TextureManager::LoadTexture("assets/Background/dirt.png");
	grass = TextureManager::LoadTexture("assets/Background/grass.png");
	water = TextureManager::LoadTexture("assets/Background/water.png");
	LoadMap(lvl1);
	src.x = 0;
	src.y = 0;
	src.w = 32;
	src.h = 32;

	dest.x = 0;
	dest.y = 0;
	dest.w = 32;
	dest.h = 32;
}

void Map::DrawMap()
{
	int type = 0;
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 20; column++)
		{
			type = map[row][column];
			dest.x = column * 32;
			dest.y = row * 32;
			switch (type)
			{
			case 0:
				TextureManager::Draw(water, src, dest);
				break;
			case 1:
				TextureManager::Draw(grass, src, dest);
				break;
			case 2:
				TextureManager::Draw(dirt, src, dest);
				break;
			default:
				break;
			}
		}
	}
}

void Map::LoadMap(int arr[20][20])
{
	for (int row = 0; row < 20; row++)
	{
		for (int column = 0; column < 20; column++)
		{
			map[row][column] = arr[row][column];
		}
	}
}