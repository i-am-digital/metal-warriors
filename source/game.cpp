#include "robot.h"
#include "texture.h"
#include "surface.h"
#include "renderer.h"
#include "window.h"
#include "game.h"
#include "context.h"
#include <iostream>
#include <SDL.h>
#include <exception>

void game_main(std::string const& applicationPath)
{
	try
	{
		Context sdlContext;
		Window sdlWindow;
		Renderer sdlRenderer(sdlWindow);
		Surface tankSurface("tank-sprite.bmp");
		Texture tankTexture(sdlRenderer, tankSurface);

		std::cout << "Hello from game" << std::endl;


		robot playerOne;
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
					if (event.key.keysym.sym == SDLK_w && event.key.repeat == 0)
					{
						playerOne.startMovingForward();
					}
					if (event.key.keysym.sym == SDLK_s && event.key.repeat == 0)
					{
						playerOne.startMovingBackward();
					}
					break;
				case SDL_KEYUP:
					if (event.key.keysym.sym == SDLK_w  && event.key.repeat == 0)
					{
						playerOne.stopMovingForward();
					}
					if (event.key.keysym.sym == SDLK_s && event.key.repeat == 0)
					{
						playerOne.stopMovingBackward();
					}
					break;
				default:
					break;
				}
			}
			playerOne.service();
			sdlRenderer.clear();

			SDL_Rect tankLocation;
			tankLocation.x = playerOne.getX();
			tankLocation.y = playerOne.getY();
			tankLocation.w = 100;
			tankLocation.h = 100;

			SDL_RenderCopy(sdlRenderer.getRenderer(), tankTexture.getTexture(), nullptr, &tankLocation);
			sdlRenderer.present();
		}


		std::cout << "Bye from game" << std::endl;
	}
	catch (std::exception const&)
	{
		std::cout << "Something went wrong :(" << std::endl;
	}
}
