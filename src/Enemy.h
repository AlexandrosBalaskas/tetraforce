#pragma once

#include "game.h"

class Enemy {

public:
	Enemy(int w, int h);
	~Enemy();
	void Update(int xarx, int yarx, float timetoStart, int xtel, int ytel, float timetoAccomplish, const char* texturesheet, SDL_Renderer* ren);
	void Update(float timetoStart, const char* texturesheet, SDL_Renderer* ren);
	void Update();
	void Render();
	void CreateProjectile1(SDL_Renderer* ren, int beginningTime);
	void CreateProjectile(SDL_Renderer* ren,int beginningTime);
	void UpdateProjectile(int xvel, int yvel);
	void UpdateProjectile(int xvel);
	void Collision(int times);
	float dt1;
	static bool disappearForlevel2;
	static int score;


private:
	int playerCollisions = 10;
	int collisions = 0;
	int time;
	int beginningTime;
	SDL_Rect camera3;
	bool disappear = false;
	bool disappearProjectile = false;
	bool disappearProjectile1 = false;
	bool disappearProjectile2 = false;
	bool disappearProjectile3 = false;
	float thesis1 = 0.0;
	float thesis = 0.0;
	float thesis2 = 0.0;
	float thesis3 = 0.0;
	float thesis4 = 0.0;
	float thesis5 = 0.0;
	int upOrdown = 1;
	SDL_Rect cameraEnemyProjectile;
	SDL_Rect cameraEnemyProjectile1;
	SDL_Rect cameraEnemyProjectile2;
	SDL_Rect cameraEnemyProjectile3;
	SDL_Texture* objProjectile = NULL;
	SDL_Texture* objProjectile1 = NULL;
	SDL_Texture* objProjectile2 = NULL;
	SDL_Texture* objProjectile3 = NULL;
	SDL_Texture* objTexture = NULL;
	SDL_Renderer* renderer;
};