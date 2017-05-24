#ifndef TEXTURE_H
#define TEXTURE_H
#include <SDL.h>
#include "renderer.h"
#include "surface.h"
#include <exception>

class Texture
{
private:
	SDL_Texture* texture;
public:
	Texture(Renderer& sdlRenderer, Surface& sdlSurface)
	{
		texture = SDL_CreateTextureFromSurface(sdlRenderer.getRenderer(), sdlSurface.getSurface());
		if (texture == nullptr)
		{
			throw std::exception();
		}
	}

	~Texture()
	{
		SDL_DestroyTexture(texture);
	
	}

	SDL_Texture* getTexture()
	{
		return texture;
	}
};

#endif