#include "Enemy.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "game.h"

bool Enemy::disappearForlevel2 = false;
int Enemy::score = 0;

Enemy::Enemy(int w, int h)
{
    camera3.w = w;
    camera3.h = h;
    camera3.y = NULL;
    camera3.x = NULL;
}

void Enemy::Collision(int times)
{
    score = 0;
    if (GameObject::cameraProjectile.x + GameObject::cameraProjectile.w >= camera3.x &&
        GameObject::cameraProjectile.y + GameObject::cameraProjectile.h >= camera3.y &&
        camera3.x + camera3.w >= GameObject::cameraProjectile.x &&
        camera3.y + camera3.h >= GameObject::cameraProjectile.y)
    {
        collisions = collisions + 1;
        if (times == collisions)
        {
            score = 50;
            SDL_DestroyTexture(objTexture);
            camera3.x = -100;
            SDL_DestroyTexture(GameObject::objTexture1);
            GameObject::objTexture1 = NULL;
            disappear = true;
            disappearForlevel2 = true;
            Mix_Music* metal = Mix_LoadMUS("assets/metal.mp3");
            Mix_PlayMusic(metal, 0);
        }
        if (!Mix_PlayingMusic())
        {
            Mix_Music* wood = Mix_LoadMUS("assets/wood.mp3");
            Mix_PlayMusic(wood, 0);
        }
        GameObject::cameraProjectile.x = 2000;
        disappearProjectile = true;
    }
    if (GameObject::cameraProjectile2.x + GameObject::cameraProjectile2.w >= camera3.x &&
        GameObject::cameraProjectile2.y + GameObject::cameraProjectile2.h >= camera3.y &&
        camera3.x + camera3.w >= GameObject::cameraProjectile2.x &&
        camera3.y + camera3.h >= GameObject::cameraProjectile2.y)
    {
        collisions = collisions + 1;
        if (times == collisions)
        {
            score = 50;
            SDL_DestroyTexture(objTexture);
            camera3.x = -100;
            SDL_DestroyTexture(GameObject::objTexture2);
            GameObject::objTexture2 = NULL;
            disappear = true;
            Mix_Music* metal = Mix_LoadMUS("assets/metal.mp3");
            Mix_PlayMusic(metal, 0);
        }
        if (!Mix_PlayingMusic())
        {
            Mix_Music* wood = Mix_LoadMUS("assets/wood.mp3");
            Mix_PlayMusic(wood, 0);
        }
        GameObject::cameraProjectile2.x = 2000;
        disappearProjectile = true;
    }
    if (GameObject::camera2.x + GameObject::camera2.w >= cameraEnemyProjectile.x &&
        GameObject::camera2.y + GameObject::camera2.h >= cameraEnemyProjectile.y &&
        cameraEnemyProjectile.x + cameraEnemyProjectile.w >= GameObject::camera2.x &&
        cameraEnemyProjectile.y + cameraEnemyProjectile.h >= GameObject::camera2.y)
    {
        Mix_Music* glass = Mix_LoadMUS("assets/glass.mp3");
        Mix_PlayMusic(glass, 0);
        playerCollisions = playerCollisions - 1;
        GameObject::cameraHealth.w = GameObject::cameraHealth.w - 10;
        //SDL_DestroyTexture(objProjectile);
        //SDL_DestroyWindow(Game::window);
        disappearProjectile = true;
    }
    if (GameObject::camera2.x + GameObject::camera2.w >= cameraEnemyProjectile1.x &&
        GameObject::camera2.y + GameObject::camera2.h >= cameraEnemyProjectile1.y &&
        cameraEnemyProjectile1.x + cameraEnemyProjectile1.w >= GameObject::camera2.x &&
        cameraEnemyProjectile1.y + cameraEnemyProjectile1.h >= GameObject::camera2.y)
    {
        Mix_Music* glass = Mix_LoadMUS("assets/glass.mp3");
        Mix_PlayMusic(glass, 0);
        playerCollisions = playerCollisions - 1;
        GameObject::cameraHealth.w = GameObject::cameraHealth.w - 10;
        //SDL_DestroyTexture(objProjectile);
        //SDL_DestroyWindow(Game::window);
        disappearProjectile1 = true;
    }
    if (GameObject::camera2.x + GameObject::camera2.w >= cameraEnemyProjectile2.x &&
        GameObject::camera2.y + GameObject::camera2.h >= cameraEnemyProjectile2.y &&
        cameraEnemyProjectile2.x + cameraEnemyProjectile2.w >= GameObject::camera2.x &&
        cameraEnemyProjectile2.y + cameraEnemyProjectile2.h >= GameObject::camera2.y)
    {
        Mix_Music* glass = Mix_LoadMUS("assets/glass.mp3");
        Mix_PlayMusic(glass, 0);
        playerCollisions = playerCollisions - 1;
        GameObject::cameraHealth.w = GameObject::cameraHealth.w - 10;
        //SDL_DestroyTexture(objProjectile);
        //SDL_DestroyWindow(Game::window);
        disappearProjectile2 = true;
    }
    if (GameObject::camera2.x + GameObject::camera2.w >= cameraEnemyProjectile3.x &&
        GameObject::camera2.y + GameObject::camera2.h >= cameraEnemyProjectile3.y &&
        cameraEnemyProjectile3.x + cameraEnemyProjectile3.w >= GameObject::camera2.x &&
        cameraEnemyProjectile3.y + cameraEnemyProjectile3.h >= GameObject::camera2.y)
    {
        Mix_Music* glass = Mix_LoadMUS("assets/glass.mp3");
        Mix_PlayMusic(glass, 0);
        playerCollisions = playerCollisions - 1;
        GameObject::cameraHealth.w = GameObject::cameraHealth.w - 10;
        //SDL_DestroyTexture(objProjectile);
        //SDL_DestroyWindow(Game::window);
        disappearProjectile3 = true;
    }
    if (GameObject::camera2.x + GameObject::camera2.w >= camera3.x &&
        GameObject::camera2.y + GameObject::camera2.h >= camera3.y &&
        camera3.x + camera3.w >= GameObject::camera2.x &&
        camera3.y + camera3.h >= GameObject::camera2.y)
    {
        //SDL_DestroyWindow(Game::window);
    }
    if (GameObject::cameraHealth.w < 0)
    {
        SDL_DestroyWindow(Game::window);
    }
}

void Enemy::Update(int xarx, int yarx, float timetoStart, int xtel, int ytel, float timetoAccomplish, const char* texturesheet, SDL_Renderer* ren)
{
    if (disappear == false)
    {
        time = SDL_GetTicks();
        if (time >= timetoStart * 1000)
        {
            if (objTexture == NULL)
            {
                objTexture = TextureManager::LoadTexture(texturesheet, ren);
                renderer = ren;
            }
            if (camera3.x == NULL)
            {
                camera3.x = xarx;
            }
            if (camera3.y == NULL)
            {
                camera3.y = yarx;
            }

            dt1 = Game::dt;
            thesis += dt1 * (xarx - xtel) / (timetoAccomplish - timetoStart);
            thesis1 += dt1 * (yarx - ytel) / (timetoAccomplish - timetoStart);
            camera3.y = camera3.y - int(thesis1);
            camera3.x = camera3.x - int(thesis);
            thesis = thesis - int(thesis);
            thesis1 = thesis1 - int(thesis1);
            if (camera3.x <= xtel)
            {
                camera3.x = xtel;
            }
            if (yarx - ytel > 0)
            {

                if (camera3.y <= ytel)
                    camera3.y = ytel;
            }
            if (yarx - ytel < 0)
            {
                if (camera3.y >= ytel)
                    camera3.y = ytel;
            }
        }
    }
}

void Enemy::Update(float timetoStart, const char* texturesheet, SDL_Renderer* ren)
{
    if (disappear == false)
    {
        time = SDL_GetTicks();
        if (time >= timetoStart * 1000)
        {
            if (objTexture == NULL)
            {
                objTexture = TextureManager::LoadTexture(texturesheet, ren);
                renderer = ren;
            }
            if (camera3.x == NULL)
            {
                camera3.x = 1280;
            }
            if (camera3.y == NULL)
            {
                camera3.y = rand() % 680;
            }

            dt1 = Game::dt;
            thesis += dt1 * 300;
            thesis1 += dt1 * (GameObject::camera2.y - camera3.y);
            camera3.y = camera3.y + int(thesis1);
            camera3.x = camera3.x - int(thesis);
            thesis = thesis - int(thesis);
            thesis1 = thesis1 - int(thesis1);
           
        }
    }
}

void Enemy::Update()
{
        if (disappear == false)
        {
                if (camera3.x <=901)
                {
                    dt1 = Game::dt;
                    thesis4 += dt1 * 150;
                    if (camera3.y < 20)
                    {
                        upOrdown = 1;
                    }
                    if (camera3.y > 500)
                    {
                        upOrdown = -1;
                    }
                    camera3.y = camera3.y + int(thesis4)*upOrdown;
                    thesis4 = thesis4 - int(thesis4);
                }
        }
}


void Enemy::Render()
{
    if (disappear == false)
    {
        // SDL_RenderCopy(renderer, objTexture, NULL, &camera3);
        // SDL_RenderCopy(renderer, objProjectile, NULL, &cameraEnemyProjectile);
        // SDL_RenderCopy(renderer, objProjectile1, NULL, &cameraEnemyProjectile1);
        // SDL_RenderCopy(renderer, objProjectile2, NULL, &cameraEnemyProjectile2);
        // SDL_RenderCopy(renderer, objProjectile3, NULL, &cameraEnemyProjectile3);
    }
}

void Enemy::CreateProjectile(SDL_Renderer* ren,int beginningTime)
{
    if (disappear == false)
    {
        if (SDL_GetTicks() >= beginningTime && objProjectile == NULL)
        {
            objProjectile = TextureManager::LoadTexture("assets/ball2.png", ren);
            cameraEnemyProjectile.x = camera3.x;
            cameraEnemyProjectile.y = camera3.y+20;
            cameraEnemyProjectile.w = 18;
            cameraEnemyProjectile.h = 3;
        }
    }
}

void Enemy::UpdateProjectile(int xvel)
{
    thesis2 = thesis2 + (Game::dt * xvel);
    thesis5 = thesis5 + (Game::dt * (GameObject::camera2.y-cameraEnemyProjectile.y));
    cameraEnemyProjectile.x -= int(thesis2);
    cameraEnemyProjectile.y += int(thesis5);
    thesis2 -= int(thesis2);
    thesis5 -= int(thesis5);
    if ((cameraEnemyProjectile.x <= 0 && disappear == false && objTexture!=NULL)|| (disappearProjectile == true))
    {
        cameraEnemyProjectile.x = camera3.x;
        cameraEnemyProjectile.y = camera3.y+20;
        if (disappearProjectile)
            disappearProjectile = false;
    }
}

void Enemy::CreateProjectile1(SDL_Renderer* ren, int beginningTime)
{
    if (disappear == false)
    {
        if (SDL_GetTicks() >= beginningTime && objProjectile1 == NULL)
        {
            objProjectile1 = TextureManager::LoadTexture("assets/ball2.png", ren);
            cameraEnemyProjectile1.x = camera3.x;
            cameraEnemyProjectile1.y = camera3.y+90;
            cameraEnemyProjectile1.w = 9;
            cameraEnemyProjectile1.h = 9;
        }
        if (SDL_GetTicks() >= beginningTime && objProjectile2 == NULL)
        {
            objProjectile2 = TextureManager::LoadTexture("assets/ball2.png", ren);
            cameraEnemyProjectile2.x = camera3.x;
            cameraEnemyProjectile2.y = camera3.y+70;
            cameraEnemyProjectile2.w = 9;
            cameraEnemyProjectile2.h = 9;
        }
        if (SDL_GetTicks() >= beginningTime && objProjectile3 == NULL)
        {
            objProjectile3 = TextureManager::LoadTexture("assets/ball2.png", ren);
            cameraEnemyProjectile3.x = camera3.x;
            cameraEnemyProjectile3.y = camera3.y+110;
            cameraEnemyProjectile3.w = 9;
            cameraEnemyProjectile3.h = 9;
        }
    }
}

void Enemy::UpdateProjectile(int xvel, int yvel)
{
    thesis2 = thesis2 + (Game::dt * xvel);
    thesis3 = thesis3 + (Game::dt * yvel);
    cameraEnemyProjectile2.x -= int(thesis2);
    cameraEnemyProjectile2.y -= int(thesis3);
    cameraEnemyProjectile1.x -= int(thesis2);
    cameraEnemyProjectile3.x -= int(thesis2);
    cameraEnemyProjectile3.y += int(thesis3);
    thesis2 -= int(thesis2);
    thesis3 -= int(thesis3);
    if (cameraEnemyProjectile1.x <= 0 || disappearProjectile1==true)//&& disappear == false && objTexture != NULL)
    {
        cameraEnemyProjectile1.x = camera3.x;
        cameraEnemyProjectile1.y = camera3.y+90;
        if (disappearProjectile1)
            disappearProjectile1 = false;
    }
    if (cameraEnemyProjectile3.x <= 0 || disappearProjectile3==true)
    {
        cameraEnemyProjectile3.x = camera3.x;
        cameraEnemyProjectile3.y = camera3.y+110;
        if (disappearProjectile3)
            disappearProjectile3 = false;
    }
    if (cameraEnemyProjectile2.x <= 0 || disappearProjectile2==true)
    {
        cameraEnemyProjectile2.x = camera3.x;
        cameraEnemyProjectile2.y = camera3.y+70;
        if (disappearProjectile2)
            disappearProjectile2 = false;
    }
}