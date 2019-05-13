#pragma once

#include <string>
#include <SDL.h>

class Window {
public:
	Window(const std::string& title, int width, int height);
	~Window();

	void pollEvents(SDL_Event& event);
	void render() const;
	inline bool isClosed() const { return _closed; }
	static SDL_Renderer* renderer;

private:
	std::string _title;
	int _width = 800;
	int _height = 600;
	bool _closed = false;
	SDL_Window* _window = nullptr;

	bool init();
};