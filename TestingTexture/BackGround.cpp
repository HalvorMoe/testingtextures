//
// Created by Halvor Moe on 22/04/2022.
//

#include "BackGround.h"
BackGround::BackGround(const LoadParams* pParams) : SDLGameObject(pParams) {}

void BackGround::draw(){
    SDLGameObject::drawBack();
}

void BackGround::update() {
    SDLGameObject::update();
}

void BackGround::clean() {}