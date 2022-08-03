//
// Created by Halvor Moe on 18/04/2022.
//

#include "Player.h"

Player::Player(const LoadParams* pParams) : SDLGameObject(pParams) {}

void Player::draw(){
    SDLGameObject::draw();
}

void Player::update() {
    m_velocity.setX(0);
    m_velocity.setY(0);
    m_position += m_velocity;

    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
    {
        if (m_position.getX() <= 800 - 64){
            m_velocity.setX(5);
        }
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
    {
        if (m_position.getX() >= 0){
            m_velocity.setX(-5);
        }
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_UP))
    {
        if (m_position.getY() >= 0){
            m_velocity.setY(-5);
        }
    }
    if(InputHandler::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
    {
        if (m_position.getY() <= 640 - 64){
            m_velocity.setY(5);
        }
    }
    SDLGameObject::update();
}

void Player::clean() {}
