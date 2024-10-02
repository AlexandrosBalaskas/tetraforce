#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture, SDL_Renderer* ren)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}
void TextureManager::write(SDL_Renderer* ren, std::string texture, SDL_Rect rect)
{
	TTF_Font* font = TTF_OpenFont("assets/subfont.ttf", 20);
	SDL_Color color = { 0,0,255,255 };
	const char* t = texture.c_str();
	SDL_Surface* textSurface = TTF_RenderText_Solid(font, t, color);
	TTF_CloseFont(font);
	SDL_Texture* text = SDL_CreateTextureFromSurface(ren, textSurface);
	SDL_FreeSurface(textSurface);
	SDL_QueryTexture(text, NULL, NULL, &rect.w, &rect.h);
	SDL_RenderCopy(ren, text, NULL, &rect);
	SDL_DestroyTexture(text);
}