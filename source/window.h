#ifndef WINDOW_H
#define WINDOW_H
#include <SDL.h>
#include <exception>

class Window
{
private:
	SDL_Window* window;

public:
	Window()
	{
		window = SDL_CreateWindow("Metal Warriors",
			10, 100, 640, 480, SDL_WINDOW_SHOWN);

		if (window == nullptr)
		{
			throw std::exception();
		}
	}
	~Window()
	{
		SDL_DestroyWindow(window);
	}
	SDL_Window* getWindow()
	{
		return window;
	}
};


#endif 
