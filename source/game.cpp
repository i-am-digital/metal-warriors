#include "game.h"
#include <iostream>
#include <SDL.h>

void game_main()
{
	std::cout << "Hello from game" << std::endl;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0)
	{
		std::cout << "Unable to initialise SDL" << std::endl;
		return;
	}

	SDL_Window* window = SDL_CreateWindow("Metal Warriors",
		10, 100, 640, 480, SDL_WINDOW_SHOWN);

	if (window != nullptr)
	{
		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (renderer != nullptr)
		{
			bool isRunning = true;
			while (isRunning)
			{
				SDL_Event event;
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
					case SDL_QUIT:
						isRunning = false;
						break;
					case SDL_KEYDOWN:
						if (event.key.keysym.sym == SDLK_ESCAPE)
						{
							isRunning = false;
						}
						break;
					default:
						break;
					}
				}

				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
			}

			SDL_DestroyRenderer(renderer);
		}

		SDL_DestroyWindow(window);
	}

	SDL_Quit();

}