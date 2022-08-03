//
// Created by Halvor Moe on 20/04/2022.
//

#include <string>
#include "SDL.h"

#include "Enemy.h"

Enemy::Enemy(const LoadParams* pParams) : SDLGameObject(pParams) {
    m_velocity.setX(-2);
    m_velocity.setY(1);
}

void Enemy::draw(){
    SDLGameObject::draw();
}

void Enemy::update() {

    if (m_position.getX() <= 0){
        m_velocity.setX(2);
    }

    if (m_position.getX() >= 800 -64){
        m_velocity.setX(-2);
    }

    if (m_position.getY() >= 400){
        m_velocity.setY(-1);
    }

    if (m_position.getY() <= 0){
        m_velocity.setY(1);
    }

    SDLGameObject::update();
}

void Enemy::clean() {}