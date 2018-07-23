#include "stdafx.h"
#include "GameObject.h"
#include "TextureManager.h"
#include <stdlib.h>
#include <time.h>

#include <iostream>
using namespace std;

GameObject::GameObject(const char* texturesheet, SDL_Renderer* mainRenderer, int x, int y)
{
	renderer = mainRenderer;
	objTexture = TextureManager::LoadTexture(texturesheet, mainRenderer);

	xpos = 0;
	ypos = 0;

}

GameObject::~GameObject()
{
	//Not surte if you are deleting Object texture in the Texture Manager- BMD
}

void GameObject::UpdatePlayer()
{	xpos++;
	ypos++;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}


/*
void GameObject::UpdateBox()
{

	BoxXpos--;
	BoxTopLane;
	BoxMidLane;
	BoxBotLane;
	
	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = BoxXpos;
	destRect.y = BoxTopLane;

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}
*/

void GameObject::UpdateBox()
{
	if (IsActive == true)
	{
		BoxXpos--; 
		if (BoxXpos < 0) 
		{
			IsActive = false;
			RandomSpawn();
		}
	}
		srcRect.h = 32;
		srcRect.w = 32;
		srcRect.x = 0;
		srcRect.y = 0;

		destRect.x = BoxXpos;
		destRect.y = ypos;

		destRect.w = srcRect.w * 2;
		destRect.h = srcRect.h * 2;
}

void GameObject::Render()
{
	if (IsActive == true) 
	{
		SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
	}
}

void GameObject::RandomSpawn()
{
	IsActive = true;

	RandomLane = rand() %3 +1;
	if (RandomLane == 1)
	{
		//destRect.y = BoxTopLane;
		ypos = BoxTopLane;
	}
	if (RandomLane == 2)
	{
		//destRect.y = BoxMidLane;
		ypos = BoxMidLane;
	}
	if (RandomLane == 3)
	{
		//destRect.y = BoxBotLane;
		ypos = BoxBotLane;
	}

	cout << RandomLane;
	BoxXpos = 550;
}

