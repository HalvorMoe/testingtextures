//
// Created by Halvor Moe on 20/04/2022.
//

#ifndef TESTINGTEXTURE_ENEMY_H
#define TESTINGTEXTURE_ENEMY_H

#include <string>

#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:

    Enemy(const LoadParams* pParams);

    void draw();
    void update();
    void clean();

};

#endif //TESTINGTEXTURE_ENEMY_H
