#pragma once
#include "game.h"

class TextureManager {

public:
	static SDL_Texture* LoadTexture(const char* fileName, SDL_Renderer* ren);
	static void write(SDL_Renderer* ren, std::string texture,SDL_Rect rect);
private:
	SDL_Rect textRect1;
}; 