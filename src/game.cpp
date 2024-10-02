#include "game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Enemy.h"
#include <iostream>
#include <string>

SDL_Texture* playerTex;
GameObject* player;
float Game::dt = 0.0;
int Game::xvel = 0.0;
int Game::yvel = 0.0;
bool Game::projectile;
bool Game::projectile2;
Enemy* enemy1;
Enemy* enemy2;
Enemy* enemy3;
Enemy* enemy4;
Enemy* enemy5;
Enemy* enemy6;
Enemy* enemy7;
Enemy* enemy8;
Enemy* enemy9;
Enemy* enemy10;
Enemy* enemy11;
Enemy* enemy12;
Enemy* enemy13;
Enemy* enemy14;
Enemy* enemy15;
Enemy* enemy16;
Enemy* enemy17;
Enemy* enemy18;
Enemy* enemy19;
SDL_Window* Game::window;

Game::Game()
{
    camera1.y = 0;
    camera1.x = 0;
    camera1.w = 1280;
    camera1.h = 720;
    textRect.x = 0;
    textRect.y = 0;
    textRect.w = 100;
    textRect.h = 20;
}

Game::~Game()
{}

void Game::initialise()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        window = SDL_CreateWindow("Tetraforce", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
        SDL_RenderClear(renderer);
        isRunning = true;
    }
    
    if (TTF_Init() < 0)
    {
        std::cout << "Error:" << TTF_GetError() << std::endl;
    }
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        std::cout << "Error:" << Mix_GetError() << std::endl;
    }
    playerTex = TextureManager::LoadTexture("assets/star.png", renderer);
    player = new GameObject("assets/player.png", renderer);
    enemy1 = new Enemy(40, 40);
    enemy2 = new Enemy(40, 40);
    enemy3 = new Enemy(40, 40);
    enemy4 = new Enemy(40, 40);
    enemy5 = new Enemy(40, 40);
    enemy6 = new Enemy(40, 40);
    enemy7 = new Enemy(50, 50);
    enemy8 = new Enemy(50, 50);
    enemy9 = new Enemy(50, 50);
    enemy10 = new Enemy(50, 50);
    enemy11 = new Enemy(50, 50);
    enemy12 = new Enemy(70, 70);
    enemy13 = new Enemy(70, 70);
    enemy14 = new Enemy(70, 70);
    enemy15 = new Enemy(70, 70);
    enemy16 = new Enemy(200, 200);
    enemy17 = new Enemy(70, 70);
    enemy18 = new Enemy(70, 70);
    enemy19 = new Enemy(70, 70);
}
void Game::handleEvents()
{
    framestart = SDL_GetTicks();
    dt = (framestart - prevstart) / 1000.0f;
    prevstart = framestart;
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            isRunning = false;
            break;
        }
        if (event.type == SDL_KEYDOWN)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                yvel = -5;
                break;
            case SDLK_DOWN:
                yvel = 5;
                break;
            case SDLK_LEFT:
                xvel = -5;
                break;
            case SDLK_RIGHT:
                xvel = 5;
                break;
            case SDLK_z:
                projectile = true;
                break;
            case SDLK_x:
                projectile2 = true;
                break;
            default:
                break;
            }
        }
        if (event.type == SDL_KEYUP)
        {
            switch (event.key.keysym.sym)
            {
            case SDLK_UP:
                yvel = 0;
                break;
            case SDLK_DOWN:
                yvel = 0;
                break;
            case SDLK_LEFT:
                xvel = 0;
                break;
            case SDLK_RIGHT:
                xvel = 0;
                break;
            case SDLK_z:
                projectile = false;
                break;
            case SDLK_x:
                projectile2 = false;
                break;
            default:
                break;
            }
        }
    }
}
  
void Game::update()
{
    player->Update();
    enemy1->Update(1280, 300, 2, 600, 1, 4, "assets/enemy1.png", renderer);
    enemy1->Update(600, 1, 4, 600, 300, 5, "assets/enemy1.png", renderer);
    enemy2->Update(1280, 300, 2.3, 600, 1, 4.3, "assets/enemy1.png", renderer);
    enemy2->Update(600, 1, 4.3, 600, 250, 5.3, "assets/enemy1.png", renderer);
    enemy3->Update(1280, 300, 2.6, 600, 1, 4.6, "assets/enemy1.png", renderer);
    enemy3->Update(600, 1, 4.6, 600, 200, 5.3, "assets/enemy1.png", renderer);
    enemy4->Update(1280, 300, 2, 600, 650, 4, "assets/enemy1.png", renderer);
    enemy4->Update(600, 650, 4, 600, 350, 5, "assets/enemy1.png", renderer);
    enemy5->Update(1280, 300, 2.3, 600, 650, 4.3, "assets/enemy1.png", renderer);
    enemy5->Update(600, 650, 4.3, 600, 400, 5.3, "assets/enemy1.png", renderer);
    enemy6->Update(1280, 300, 2.6, 600, 650, 4.6, "assets/enemy1.png", renderer);
    enemy6->Update(600, 650, 4.6, 600, 450, 5.3, "assets/enemy1.png", renderer);
    enemy7->Update(1280, 600, 4.6, 600, 600, 6, "assets/enemy2.png", renderer);
    enemy7->Update(600, 600, 18, 600, 800, 21, "assets/enemy2.png", renderer);
    enemy8->Update(1280, 660, 4.6, 600, 660, 6, "assets/enemy2.png", renderer);
    enemy8->Update(600, 660, 16, 600, 800, 17, "assets/enemy2.png", renderer);
    enemy9->Update(1280, 1, 4.6, 600, 1, 6, "assets/enemy2.png", renderer);
    enemy9->Update(600, 1, 17, 600, 780, 20, "assets/enemy2.png", renderer);
    enemy10->Update(1280, 61, 4.6, 600, 61, 6, "assets/enemy2.png", renderer);
    enemy10->Update(600, 61, 18, 600, 780, 20, "assets/enemy2.png", renderer);
    /*enemy1->Update(2, "assets/enemy1.png", renderer);
    enemy2->Update(3, "assets/enemy1.png", renderer);
    enemy3->Update(3, "assets/enemy1.png", renderer);
    enemy4->Update(3, "assets/enemy1.png", renderer);
    enemy5->Update(3, "assets/enemy1.png", renderer); */
   // enemy12->Update2(1280, 200, 22.3, 500, 1, 24.3, "assets/enemy2.png", renderer);
   // enemy12->Update2(500, 1, 24.3, -80, 300, 25.3, "assets/enemy2.png", renderer);
    //enemy13->Update2(1280, 300, 22.6, 500, 650, 24.6, "assets/enemy2.png", renderer);
    //enemy13->Update2(500, 650, 24.6, -80, 200, 25.6, "assets/enemy2.png", renderer);
    //enemy14->Update2(1000, -70, 23, 800, 100, 25, "assets/enemy1.png", renderer);
    //enemy14->Update2(800, 100, 25, -80, 650, 26, "assets/enemy1.png", renderer);
    //enemy15->Update2(1000, 800, 22.3, 1000, 550, 23.3, "assets/enemy1.png", renderer);
    //enemy15->Update2(1000, 550, 23.3, -180, 150, 24.3, "assets/enemy1.png", renderer);
    enemy16->Update(1280, 200, 20, 900, 200, 23, "assets/enemy1.png", renderer);
    enemy16->Update();
    player->CreateProjectile(renderer);
    player->UpdateProjectile();
    enemy1->CreateProjectile(renderer,5000);
    enemy2->CreateProjectile(renderer,5000);
    enemy3->CreateProjectile(renderer,5000);
    enemy4->CreateProjectile(renderer,5500);
    enemy5->CreateProjectile(renderer,5500);
    enemy6->CreateProjectile(renderer,5500);
    enemy7->CreateProjectile(renderer,6000);
    enemy8->CreateProjectile(renderer,6000);
    enemy9->CreateProjectile(renderer,6500);
    enemy10->CreateProjectile(renderer,6500);
    enemy16->CreateProjectile1(renderer, 14000);
    enemy1->UpdateProjectile(150);
    enemy2->UpdateProjectile(150);
    enemy3->UpdateProjectile(150);
    enemy4->UpdateProjectile(150);
    enemy5->UpdateProjectile(150);
    enemy6->UpdateProjectile(150);
    enemy7->UpdateProjectile(200);
    enemy8->UpdateProjectile(200);
    enemy9->UpdateProjectile(200);
    enemy10->UpdateProjectile(200);
    enemy16->UpdateProjectile(600, 50);
    enemy1->Collision(1);
    score = score + Enemy::score;
    enemy2->Collision(1);
    score = score + Enemy::score;
    enemy3->Collision(1);
    score = score + Enemy::score;
    enemy4->Collision(1);
    score = score + Enemy::score;
    enemy5->Collision(1);
    score = score + Enemy::score;
    enemy6->Collision(1);
    score = score + Enemy::score;
    enemy7->Collision(2);
    score = score + Enemy::score;
    enemy8->Collision(2);
    score = score + Enemy::score;
    enemy9->Collision(2);
    score = score + Enemy::score;
    enemy10->Collision(2);
    score = score + Enemy::score; 
    enemy16->Collision(16);
    score = score + Enemy::score;
    enemy12->Collision(2);
    enemy13->Collision(2);
    enemy14->Collision(1);
    enemy15->Collision(1);    
    thesis = thesis + (dt * 30);
    thesis1 = thesis1 + (dt * 60);
    if (thesis > 1.0)
    {
        camera1.x = camera1.x + int(thesis);
        thesis = thesis - int(thesis);
    }
    if (thesis1 > 1.0)
    {
        xpos = xpos - int(thesis1);
        thesis1 = thesis1 - int(thesis1);
    }
    if (camera1.x >= 2560)
    {
        camera1.x = 0;
    }

}
void Game::render()
{
    int i, j;
    SDL_RenderCopy(renderer, playerTex, &camera1, NULL);
    for (i = 0; i < 1280; i = i + 150)
    {
        for (j = 0; j < 720; j = j + 130)
        {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            if (i + xpos < 0)
            {
                SDL_RenderDrawPoint(renderer, i + xpos + 1280, j);
            }
            else
            {
                SDL_RenderDrawPoint(renderer, i + xpos, j);

            }
        }
    }

    if (xpos < -1280)
    {
        xpos = 0.0;
        for (i = 0; i < 1280; i = i + 150)
        {
            for (j = 0; j < 720; j = j + 130)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderDrawPoint(renderer, i + xpos, i);
            }
        }
    }
    player->Render();
    enemy1->Render();
    enemy2->Render();
    enemy3->Render();
    enemy4->Render();
    enemy5->Render();
    enemy6->Render();
    enemy7->Render();
    enemy8->Render();
    enemy9->Render();
    enemy10->Render();
    enemy12->Render();
    enemy13->Render();
    enemy14->Render();
    enemy15->Render();
    enemy16->Render();
    highscore = "Highscore    " + std::to_string(score);
    TextureManager::write(renderer, highscore,textRect);
    SDL_RenderPresent(renderer);
    frametime = SDL_GetTicks() - framestart;
   // if (framedelay > frametime)
   //     SDL_Delay(framedelay - frametime);
}
void Game::clean()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    IMG_Quit();
    SDL_Quit();
    TTF_Quit();
    Mix_Quit();
}
void Game::levels()
{
    if (enemy1->disappearForlevel2 == true && enemy2->disappearForlevel2 == true && enemy3->disappearForlevel2 == true && enemy4->disappearForlevel2 == true && enemy5->disappearForlevel2 == true && enemy6->disappearForlevel2 == true &&    enemy7->disappearForlevel2 == true && enemy8->disappearForlevel2 == true && enemy9->disappearForlevel2 == true &&  enemy10->disappearForlevel2 == true)
    {
        level2 = true;
        timeForlevel2 = SDL_GetTicks()/1000;
        enemy1->disappearForlevel2 = false;
        enemy2->disappearForlevel2 = false;
        enemy3->disappearForlevel2 = false;
        enemy4->disappearForlevel2 = false;
        enemy5->disappearForlevel2 = false;
        enemy6->disappearForlevel2 = false;
        enemy7->disappearForlevel2 = false;
        enemy8->disappearForlevel2 = false;
        enemy9->disappearForlevel2 = false;
        enemy10->disappearForlevel2 = false;
    }
}