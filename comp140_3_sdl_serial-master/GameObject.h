#pragma once
#include "Game.h"


class GameObject
{
public:
	GameObject(const char* texturesheet, SDL_Renderer* ren, int x, int y);
	~GameObject();

	void UpdatePlayer();
	void UpdateBox();
	void Render();
	int xpos = 0;
	int ypos = 0;
	int BoxXpos = 550;
	int BoxTopLane = 50;
	int BoxMidLane = 150;
	int BoxBotLane = 350;
	int RandomLane;

	void RandomSpawn();

	bool IsActive = false;

private:

	
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer* renderer;

};