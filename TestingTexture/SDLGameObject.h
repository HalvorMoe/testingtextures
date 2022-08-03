//
// Created by Halvor Moe on 21/04/2022.
//

#ifndef TESTINGTEXTURE_SDLGAMEOBJECT_H
#define TESTINGTEXTURE_SDLGAMEOBJECT_H

#include <string>

#include "GameObject.h"
#include "LoadParams.h"
#include "Vector2D.h"

class SDLGameObject : public GameObject
{
public:

    SDLGameObject(const LoadParams* pParams);

    virtual void draw();
    virtual void drawBack();
    virtual void update();
    virtual void clean() {};

protected:

    Vector2D m_position;
    Vector2D m_velocity;
    Vector2D m_acceleration;

    int m_width;
    int m_height;

    int m_currentRow;
    int m_currentFrame;

    std::string m_textureID;
};


#endif //TESTINGTEXTURE_SDLGAMEOBJECT_H
