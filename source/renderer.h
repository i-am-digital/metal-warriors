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
	
	Renderer(Renderer const&) = delete;
	Renderer& operator=(Renderer const&) = delete;

	SDL_Renderer* getRenderer()
	{
		return renderer;
	}

	void clear()
	{
		SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(renderer);
	}

	void present()
	{
		SDL_RenderPresent(renderer);
	}

	void setDrawingColour(unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha = 0xFF)
	{
		SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	}

	void drawLine(int x1, int y1, int x2, int y2)
	{
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
};

#endif