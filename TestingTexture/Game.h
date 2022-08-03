//
// Created by Halvor Moe on 13/04/2022.
//

#ifndef TESTINGTEXTURE_GAME_H
#define TESTINGTEXTURE_GAME_H

#include <vector>

#include "SDL.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "BackGround.h"

class Game
{
public:

    ~Game() {}

    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    void render();
    void update();
    void handleEvents();
    void clean();

    bool running() { return m_bRunning; }
    SDL_Renderer* getRenderer() const { return m_pRenderer; }

    static Game* Instance()
    {
        if(s_pInstance == 0)
        {
            s_pInstance = new Game();
            return s_pInstance;
        }
        return s_pInstance;
    }

private:

    Game() {};

    SDL_Window* m_pWindow;
    SDL_Renderer* m_pRenderer;
    SDL_Texture* m_pTexture;
    SDL_Rect m_sourceRectangle;
    SDL_Rect m_destinationRectangle;

    bool m_bRunning;
    int m_currentFrame;

    std::vector<GameObject*> m_gameObjects;

    static Game* s_pInstance;
};

#endif //TESTINGTEXTURE_GAME_H
