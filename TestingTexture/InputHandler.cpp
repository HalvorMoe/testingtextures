//
// Created by Halvor Moe on 21/04/2022.
//

#include "InputHandler.h"

InputHandler* InputHandler::s_pInstance = 0;


void InputHandler::onKeyDown() {
    m_keystates = SDL_GetKeyboardState(0);
}

void InputHandler::onKeyUp() {
    m_keystates = SDL_GetKeyboardState(0);
}

bool InputHandler::isKeyDown(SDL_Scancode key) {
    if (m_keystates != 0){
        if (m_keystates[key] == 1){
            return true;
        } else {
            return false;
        }
    }
    return false;
}

void InputHandler::clean() {

}

void InputHandler::update() {
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_KEYDOWN:
                onKeyDown();
                break;

            case SDL_KEYUP:
                onKeyUp();
                break;

            default:
                break;
        }
    }
}