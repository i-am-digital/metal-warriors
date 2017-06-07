#include "target.h"
#include "robot.h"
#include "texture.h"
#include "surface.h"
#include "renderer.h"
#include "window.h"
#include "game.h"
#include "bullet.h"
#include "context.h"
#include <iostream>
#include <SDL.h>
#include <exception>
#include <cmath>

void game_main(std::string const& applicationPath)
{
	try
	{
		Context sdlContext;
		Window sdlWindow;
		Renderer sdlRenderer(sdlWindow);
		Surface tankSurface("tank-sprite.bmp");
		Surface bulletSurface("bullet.bmp");
		Texture tankTexture(sdlRenderer, tankSurface);
		Texture bulletTexture(sdlRenderer, bulletSurface);

		std::cout << "Hello from game" << std::endl;


		robot playerOne;
		target balloon;
		
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
					if (event.key.keysym.sym == SDLK_d && event.key.repeat == 0)
					{
						playerOne.startRotatingClockwise();
					}
					if (event.key.keysym.sym == SDLK_a && event.key.repeat == 0)
					{
						playerOne.startRotatingAnticlockwise();
					}
					if (event.key.keysym.sym == SDLK_f && event.key.repeat == 0)
					{
						playerOne.fire();
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
					if (event.key.keysym.sym == SDLK_d && event.key.repeat == 0)
					{
						playerOne.stopRotatingClockwise();
					}
					if (event.key.keysym.sym == SDLK_a && event.key.repeat == 0)
					{
						playerOne.stopRotatingAnticlockwise();
					}
					break;
				default:
					break;
				}
			}
			playerOne.service();
			sdlRenderer.clear();

			SDL_Rect tankLocation;
			tankLocation.x = playerOne.getX()-50;
			tankLocation.y = playerOne.getY()-50;
			tankLocation.w = 100;
			tankLocation.h = 100;

			SDL_Rect balloonLocation;
			balloonLocation.x = balloon.getX() - 50;
			balloonLocation.y = balloon.getY() - 50;
			balloonLocation.w = 100;
			balloonLocation.h = 100;

			SDL_RenderCopyEx(sdlRenderer.getRenderer(), tankTexture.getTexture(),
				nullptr, &tankLocation,playerOne.getRotation(),nullptr,SDL_FLIP_NONE);

			SDL_RenderCopy(sdlRenderer.getRenderer(), tankTexture.getTexture(),
				nullptr, &balloonLocation);

			sdlRenderer.setDrawingColour(0xFF, 0x00, 0x00);
			double radians = (playerOne.getRotation() * 2 * 3.142) / 360;
			int x2 = playerOne.getX() + (80 * sin(radians));
			int y2 = playerOne.getY() - (80 * cos(radians));
			sdlRenderer.drawLine(playerOne.getX(), playerOne.getY(), x2, y2);

			if (playerOne.playerBullet.getDisplayed())
			{
				SDL_Rect bulletLocation;
				bulletLocation.x = playerOne.playerBullet.getX() - 5;
				bulletLocation.y = playerOne.playerBullet.getY() - 5;
				bulletLocation.w = 10;
				bulletLocation.h = 10;
				SDL_RenderCopyEx(sdlRenderer.getRenderer(), bulletTexture.getTexture(),
					nullptr, &bulletLocation, playerOne.playerBullet.getRotation(), nullptr, SDL_FLIP_NONE);

			}
			sdlRenderer.present();

		}


		std::cout << "Bye from game" << std::endl;
	}
	catch (std::exception const&)
	{
		std::cout << "Something went wrong :(" << std::endl;
	}
}
