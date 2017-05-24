#ifndef SURFACE_H
#define SURFACE_H
#include <SDL.h>
#include <exception>
#include <string>
#include <iostream>

class Surface
{
private:
	SDL_Surface* surface;

public:
	Surface(std::string imagePath)
	{
		surface = SDL_LoadBMP(imagePath.c_str());
		if (surface == nullptr)
		{
			std::cout << "Unable to load surface" << std::endl;

			throw std::exception();
		}
	}

	~Surface()
	{
		SDL_FreeSurface(surface);
	}

	SDL_Surface* getSurface()
	{
		return surface;
	}

};


#endif 
