#include "stdafx.h"
#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* mainRenderer)
{
SDL_Surface* tempSurface = IMG_Load(texture);
SDL_Texture* tex = SDL_CreateTextureFromSurface(mainRenderer, tempSurface);
SDL_FreeSurface(tempSurface);

return tex;
}
