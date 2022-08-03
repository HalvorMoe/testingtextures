//
// Created by Halvor Moe on 22/04/2022.
//

#ifndef TESTINGTEXTURE_BACKGROUND_H
#define TESTINGTEXTURE_BACKGROUND_H

#include <string>
#include "SDLGameObject.h"

class BackGround : public SDLGameObject {
public:
    BackGround(const LoadParams* pParams);

    void draw();
    void update();
    void clean();
};


#endif //TESTINGTEXTURE_BACKGROUND_H
