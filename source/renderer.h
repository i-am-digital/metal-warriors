#ifndef RENDERER_H
#define RENDERER_H
#include "window.h"
#include <SDL.h>
#include <exception>

class Renderer
{
private:
	SDL_Renderer* renderer;
public:
	Renderer(Window& sdlWindow)
	{
		renderer = SDL_CreateRenderer(sdlWindow.getWindow(), -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer == nullptr)
		{
			throw std::exception();
		}
	}

	~Renderer()
	{
		SDL_DestroyRenderer(renderer);
	}
	SDL_Renderer* getRenderer()
	{
		return renderer;
	}

	void clear()
	{
		SDL_RenderClear(renderer);
	}

	void present()
	{
		SDL_RenderPresent(renderer);
	}
};

#endif