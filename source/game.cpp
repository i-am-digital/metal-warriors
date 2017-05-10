#include "game.h"
#include <iostream>
#include <SDL.h>
#include "Windows.h"

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
		Sleep(5000);

		SDL_DestroyWindow(window);
	}

	SDL_Quit();

}