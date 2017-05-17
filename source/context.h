#ifndef CONTEXT_H
#define CONTEXT_H

#include <SDL.h>
#include <iostream>
#include <exception>

class Context
{
public:
	Context()
	{
		if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
		{
			std::cout << "Unable to initialise SDL" << std::endl;
			throw std::exception();
		}
	}

	~Context()
	{
		SDL_Quit();
	}
};

#endif