//
// Created by Halvor Moe on 21/04/2022.
//

#ifndef TESTINGTEXTURE_INPUTHANDLER_H
#define TESTINGTEXTURE_INPUTHANDLER_H

#include <vector>
#include "SDL.h"
#include "Vector2D.h"

class InputHandler {
public:
    /*
    InputHandler(const InputHandler &) = delete;

    InputHandler &operator=(const InputHandler &) = delete;

    InputHandler(InputHandler &&) = delete;

    InputHandler &operator=(InputHandler &&) = delete;
    */

    static InputHandler* Instance(){
        if (s_pInstance == 0){
            s_pInstance = new InputHandler();
        }
        return s_pInstance;
    }

    void update();
    void clean();

    bool isKeyDown(SDL_Scancode key);


private:
    InputHandler() {};

    static InputHandler* s_pInstance;
    const Uint8* m_keystates;

    void onKeyDown();
    void onKeyUp();

};


#endif //TESTINGTEXTURE_INPUTHANDLER_H
