#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <vector>

//forward decleration of Game Object - BMD
class GameObject;

class Game
{
public:
	Game();
	~Game();

	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void handleEvents();
	void clean();

	bool running() { return isRunning; };

private:
	
	SDL_Window* mainWindow;
	SDL_Renderer* mainRenderer;

	bool isRunning;
	//lanes pointer
	GameObject* lanes;

	//Player Pointer -BMD
	GameObject* player;

	//box pointer
	GameObject* boxtop;
	GameObject* boxmid;
	GameObject* boxbot;

	float StartTime;
	float CurrentTime;
	float LastTime;
	float Time;
	float SpawnTime;

	std::vector<GameObject*> Boxes;

	bool spawned = false;
};

