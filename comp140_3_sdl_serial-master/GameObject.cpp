#include "stdafx.h"
#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* texturesheet, SDL_Renderer* mainRenderer, int x, int y)
{
	renderer = mainRenderer;
	objTexture = TextureManager::LoadTexture(texturesheet, mainRenderer);

	xpos = x;
	ypos = y;

}

GameObject::~GameObject()
{
	//Not surte if you are deleting Object texture in the Texture Manager- BMD
}


void GameObject::Update()
{

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}


void GameObject::Render()
{
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}