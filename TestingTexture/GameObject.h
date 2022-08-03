//
// Created by Halvor Moe on 18/04/2022.
//

#ifndef TESTINGTEXTURE_GAMEOBJECT_H
#define TESTINGTEXTURE_GAMEOBJECT_H

#include <string>
#include "LoadParams.h"

class GameObject
{
public:

    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;


protected:

    GameObject(const LoadParams* pParams) {}
    virtual ~GameObject() {}
};



#endif //TESTINGTEXTURE_GAMEOBJECT_H
