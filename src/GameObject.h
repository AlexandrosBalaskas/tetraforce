#pragma once
#include "game.h"
class GameObject {

public:
	GameObject(const char* texturesheet, SDL_Renderer* ren);
	void CreateProjectile(SDL_Renderer* ren);
	void UpdateProjectile();
	~GameObject();
	void Update();
	void Render();
	float dt1;
	static SDL_Rect cameraProjectile;
	static SDL_Texture* objTexture1;
	static SDL_Rect cameraProjectile2;
	static SDL_Texture* objTexture2;
	static SDL_Rect camera2;
	static SDL_Rect cameraHealth;

private:

	int yvel = 0;
	int xvel = 0;
	float thesis1 = 0.0;
	float thesis2 = 0.0;
	SDL_Texture* objTexture;
	SDL_Renderer* renderer;
};