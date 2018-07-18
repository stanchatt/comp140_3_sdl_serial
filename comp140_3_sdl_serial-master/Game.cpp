#include "stdafx.h"
#include "Game.h"
#include <iostream>
#include "TextureManager.h"
#include "GameObject.h"

using std::cout;



/*
* Constructor - not used in this case
*
*/
Game::Game()
{
	
}

/*
	Decontructor - also not used in this case
*/
Game::~Game()
{
}

/*
* init - used to initialise and setup SDL
* Return true if everything is successful
*/
bool Game::init(const char * title, int xpos, int ypos, int width, int height, int flags)
{
	// initialise SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		cout << "SDL init success \n";

		// Create a window
		mainWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

		// if window succesful..
		if (mainWindow != 0) {
			cout << "Window creation success \n";

			// create renderer
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, 0);

			// if renderer successful...
			if (mainRenderer != 0) {
				cout << "Renderer creation success \n";
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
			}
			else {
				cout << "renderer failed \n";
				return false;
			}
		}
		else {
			cout << "window failed \n";
			return false;
		}

	}
	else {
		cout << "SDL fail \n";
		return false;
	}

	isRunning = true;
	cout << "SDL init success \n";

	//spawn lanes
	lanes = new GameObject("assets/lanes.png", mainRenderer, -1, 0);

	//initialise Game Object - BMD
	player = new GameObject("assets/car.png", mainRenderer, 0, 0);
	
	//spawn box
	box = new GameObject("assets/box.png", mainRenderer, 50, 50);

	return true;
}

void Game::render()
{
	// set background color
	SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255);
	
		
	// clear previous frame
	SDL_RenderClear(mainRenderer);

	// draw to the screen here!
	SDL_Surface* surface = IMG_Load("assets/lanes.png");
	SDL_Texture* texture = SDL_CreateTextureFromSurface(mainRenderer, surface);
	SDL_FreeSurface(surface);

	SDL_Rect destination;
	destination.x = 0;
	destination.y = 0;
	destination.w = 680;
	destination.h = 480;

	SDL_RenderCopy(mainRenderer, texture, NULL, &destination);

	lanes->Render();
	player->Render();
	box->Render();

	// render new frame
	SDL_RenderPresent(mainRenderer);
}

/*
* update - Process all variables !in charge of anything to do with rendering
*
*/
void Game::update()
{
	lanes->Update();
	player->Update();
	box->Update();

}

/*
* handleEvents - Poll Events and uses switch case to process specific events
*
*/
void Game::handleEvents()
{
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		default:
			break;
		}

	}
}

/*
* clean - Clean up SDL and close the port
*
*/
void Game::clean()
{	
	//Delete player
	if (player)
	{
		delete player;
		player = nullptr;
	}
	cout << "Cleaning SDL \n";
	SDL_DestroyWindow(mainWindow);
	SDL_DestroyRenderer(mainRenderer);
	SDL_Quit();
}


