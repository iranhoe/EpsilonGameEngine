#include "Window.h"
#include "SDL_Image.h"
#include <iostream>

SDL_Renderer* Window::renderer = nullptr;

Window::Window(const std::string& title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	_closed = !init();
}

Window::~Window()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

void Window::pollEvents(SDL_Event &event)
{
	switch (event.type)
	{
	case SDL_QUIT:
		std::cout << "Event close" << std::endl;
		_closed = true;
		break;
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_a:
			std::cout << "You clicked \'A\'" << std::endl;
			break;
		}
		break;
	case SDL_MOUSEMOTION:
		std::cout << event.motion.x << ", " << event.motion.y << std::endl;
		break;
	case SDL_MOUSEBUTTONDOWN:
		std::cout << "You clicked a button on you mouse" << std::endl;
		break;
	case SDL_MOUSEBUTTONUP:
		std::cout << "You release a button on you mouse" << std::endl;
		break;
	default:
		break;
	}
}

void Window::render() const
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 200, 255);
	SDL_RenderPresent(renderer);
	SDL_RenderClear(renderer);
}

bool Window::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL." << std::endl;
		return false;
	}

	/*if (SDL_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		std::cerr << "Failed to initialize SDL_Image." << std::endl;
		return false;
	}*/

	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, 
		_height,
		0);
	if (_window == nullptr)
	{
		std::cerr << "Failed to create window." << std::endl;
		return false;
	}

	renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr)
	{
		
		std::cerr << "Failed to create renderer." << std::endl;
		return false;
	}

	return true;
}
