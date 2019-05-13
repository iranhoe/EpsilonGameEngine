#include "Window.h"
#include "Game.h"

Game* game = nullptr;

int main(int argc, char *argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	Window gameWindow("Game engine", 800, 640);
	game = new Game(gameWindow);
	game->init();
	while (!gameWindow.isClosed())
	{
		frameStart = SDL_GetTicks();
		game->handleEvents();
		game->update();
		game->render();
		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}
	std::cout << "game window is closed " << gameWindow.isClosed() << std::endl;
	return 0;
}