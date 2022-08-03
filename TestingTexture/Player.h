//
// Created by Halvor Moe on 18/04/2022.
//

#ifndef TESTINGTEXTURE_PLAYER_H
#define TESTINGTEXTURE_PLAYER_H


#include <string>
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject {
public:
    Player(const LoadParams* pParams);

    void draw();
    void update();
    void clean();

};


#endif //TESTINGTEXTURE_PLAYER_H
