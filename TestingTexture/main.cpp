#include "Game.h"
#include <iostream>

Game* g_game = 0;
const int FPS = 60;
const int Delay_time = 1000.0f / FPS;

int main(int argc, char* args[])
{
    Uint32 frameStart, frameTime;

    std::cout << "Game init attempt...\n";

    if (Game::Instance()->init("Chapter 1", 100, 100, 800, 640, false)){
        std::cout << "game init success!\n";
        while (Game::Instance()->running()){
            frameStart = SDL_GetTicks();
            Game::Instance()->handleEvents();
            Game::Instance()->update();
            Game::Instance()->render();

            frameTime = SDL_GetTicks() - frameStart;
            std::cout << "FPS: " << FPS << std::endl;
            if (frameTime < Delay_time){
                SDL_Delay((int)Delay_time - frameTime);
            }
        }
    } else {
        std::cout << "Game init failure - " << SDL_GetError() << "\n";
        return -1;
    }
    std::cout << "Game closing...\n";
    Game::Instance()->clean();

    return 0;

    return 0;
}