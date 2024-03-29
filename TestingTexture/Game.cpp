//
// Created by Halvor Moe on 13/04/2022.
//

#include <iostream>
#include <vector>
#include "Game.h"
#include "TextureManager.h"

Game* Game::s_pInstance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    // attempt to initialize SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        int flags = 0;
        if(fullscreen)
        {
            flags = SDL_WINDOW_FULLSCREEN;
        }

        std::cout << "SDL init success\n";
        // init the window
        m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);

        if(m_pWindow != 0) // window init success
        {
            std::cout << "window creation success\n";
            m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);

            if(m_pRenderer != 0) // renderer init success
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(m_pRenderer, 0, 0, 0, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false; // renderer init fail
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false; // window init fail
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false; // SDL init fail
    }

    std::cout << "init success\n";
    m_bRunning = true; // everything inited successfully, start the main loop

    if(!TheTextureManager::Instance()->load("../assets/bck.jpeg", "background", m_pRenderer))
    {
        return false;
    }

    if(!TheTextureManager::Instance()->load("../assets/falcon.png", "falcon", m_pRenderer))
    {
        return false;
    }
    if(!TheTextureManager::Instance()->load("../assets/tie.png", "tie", m_pRenderer))
    {
        return false;
    }

    m_gameObjects.push_back(new BackGround(new LoadParams(0, 0, 0, 0, "background")));
    m_gameObjects.push_back(new Player(new LoadParams(400, 500, 100, 100, "falcon")));
    m_gameObjects.push_back(new Enemy(new LoadParams(200, -50, 100, 100, "tie")));
    m_gameObjects.push_back(new Enemy(new LoadParams(300, -100, 100, 100, "tie")));
    m_gameObjects.push_back(new Enemy(new LoadParams(400, -150, 100, 100, "tie")));
    m_gameObjects.push_back(new Enemy(new LoadParams(500, -200, 100, 100, "tie")));
    m_gameObjects.push_back(new Enemy(new LoadParams(600, -250, 100, 100, "tie")));
    m_gameObjects.push_back(new Enemy(new LoadParams(700, -300, 100, 100, "tie")));

    return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer);

    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw();
    }
    SDL_PumpEvents();
    SDL_RenderPresent(m_pRenderer);
}

void Game::clean()
{
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(m_pWindow);
    SDL_DestroyRenderer(m_pRenderer);
    SDL_Quit();
}

void Game::handleEvents()
{
    InputHandler::Instance()->update();
}

void Game::update()
{
    for(std::vector<GameObject*>::size_type i = 0; i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}