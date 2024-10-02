#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class Game
{
public:
	Game();
	~Game();
	void initialise();
	void handleEvents();
	void update();
	void render();
	void clean();
	void levels();
	bool running() { return isRunning; }
	static float dt;
	static int yvel;
	static int xvel;
	static bool projectile;
	static bool projectile2;
	static SDL_Window* window;
	SDL_Texture* text;
	std::string highscore;

private:
	int score = 0;
	bool isRunning = false;
	SDL_Renderer* renderer;
	SDL_Rect  textRect;
	SDL_Rect camera1;
	//SDL_Rect camera2;
	float thesis = 0.0;
	float thesis1 = 0.0;
	int prevstart = 0;
	const int FPS = 60;
	const int framedelay = 1000 / FPS;
	Uint32 framestart;
	int frametime;
	int xpos = 0;
	bool level2 = false;
	float timeForlevel2;
};
