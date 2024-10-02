#include "GameObject.h"
#include "TextureManager.h"

SDL_Rect GameObject::cameraProjectile;
SDL_Texture* GameObject::objTexture1;
SDL_Rect GameObject::cameraProjectile2;
SDL_Texture* GameObject::objTexture2;
SDL_Rect GameObject::camera2;
SDL_Rect GameObject::cameraHealth;

GameObject::GameObject(const char* texturesheet, SDL_Renderer* ren)
{
    objTexture1 == NULL;
    objTexture2 == NULL;
	renderer = ren;
	objTexture = TextureManager::LoadTexture(texturesheet, ren);
    camera2.y = 300;
    camera2.x = 80;
    camera2.w = 40;
    camera2.h = 40;
    cameraHealth.x = 5;
    cameraHealth.y = 30;
    cameraHealth.w = 100;
    cameraHealth.h = 25;
}

void GameObject::CreateProjectile(SDL_Renderer* ren)
{
    if (Game::projectile && objTexture1 == NULL)
        {
            objTexture1 = TextureManager::LoadTexture("assets/ball1.png", ren);
            cameraProjectile.x = camera2.x + camera2.w;
            cameraProjectile.y = camera2.y + 19;
            cameraProjectile.w = 20;
            cameraProjectile.h = 3;
        }
    if (Game::projectile2 && objTexture2 == NULL)
        {
            objTexture2 = TextureManager::LoadTexture("assets/ball1.png", ren);
            cameraProjectile2.x = camera2.x + camera2.w;
            cameraProjectile2.y = camera2.y + 19;
            cameraProjectile2.w = 20;
            cameraProjectile2.h = 3;
        }
    
}

void GameObject::UpdateProjectile()
{
    thesis2 = thesis2 + (Game::dt * 700);
    cameraProjectile.x += int(thesis2);
    cameraProjectile2.x += int(thesis2);
    thesis2 -= int(thesis2);
    if (cameraProjectile.x >= 1280 - cameraProjectile.w)
    {
        objTexture1 = NULL;
    }
    if (cameraProjectile2.x >= 1280 - cameraProjectile2.w)
    {
        objTexture2 = NULL;
    }
}

void GameObject::Update()
{
    dt1 = Game::dt;
    xvel = Game::xvel;
    yvel = Game::yvel;
	if (xvel == 5)
    {
        thesis1 = thesis1 + (4 * dt1 * 150);
        camera2.x = camera2.x + int(thesis1);
        thesis1 = thesis1 - int(thesis1);
    }
    if (xvel == -5)
    {
        thesis1 = thesis1 + (-6 * dt1 * 150);
        camera2.x = camera2.x + int(thesis1);
        thesis1 = thesis1 - int(thesis1);
    }
    if (yvel == 5 || yvel == -5)
    {
        thesis1 = thesis1 + (yvel * dt1 * 150);
        camera2.y = camera2.y + int(thesis1);
        thesis1 = thesis1 - int(thesis1);
    }
    if (camera2.x < 1)
        camera2.x = 1;
    if (camera2.y < 0)
        camera2.y = 0;
    if (camera2.y > 680)
        camera2.y = 680;
    if (camera2.x > 1240)
        camera2.x = 1240;

}

void GameObject::Render()
{   
    SDL_Surface* health;
    health = SDL_CreateRGBSurface(0, 200, 20, 32, 0, 0, 0, 0);
    SDL_FillRect(health, &cameraHealth, SDL_MapRGB(health->format,0, 0,0));
    SDL_RenderFillRect(renderer, &cameraHealth);
    SDL_FreeSurface(health);
	SDL_RenderCopy(renderer, objTexture, NULL, &camera2); 
    SDL_RenderCopy(renderer, objTexture1, NULL, &cameraProjectile);
    SDL_RenderCopy(renderer, objTexture2, NULL, &cameraProjectile2);
}