#include "Player.h"
#include <SDL2/SDL.h>

void Player::init(const glm::vec2& pos){
    setPosition(pos);
    characters.resize(CHARACTER_NUMBERS);
    characters[0].init("../YOLO/texture/JJU/PNG/CharacterRight_Standing.png", 50, 50);
//    characters[1].init();
 //   characters[2].init();
 //   characters[3].init();
}


void Player::limitSpeed(float& speed){
    if(speed < -MAX_VELOCITY)
        speed = -MAX_VELOCITY;
    if(speed > MAX_VELOCITY)
        speed = MAX_VELOCITY;
}

void Player::processInput(){
    switch(currentState_){
    case STANDING:
        if(playerType_ == PLAYER_ONE){
            if(playerInputManager.isKeyPressed(SDLK_w) && onTile){
                velocityY_ += 10;
            }
            if(playerInputManager.isKeyPressed(SDLK_s) && !onTile){
                velocityY_ -= 0.1;
            }
            if(playerInputManager.isKeyPressed(SDLK_a)){
                if(velocityX_ > 0)
                    velocityX_ = 0;
                else
                    velocityX_ -= 0.1;
            }
            if(playerInputManager.isKeyPressed(SDLK_d)){
                if(velocityX_ < 0)
                    velocityX_ = 0;
                else
                    velocityX_ += 0.1;
            }
        }
        break;
    case TAKE_DAMAGE:
        break;
    case JUMPING:
        break;
    case FALLING:
        break;
    }

}

void Player::update(){
    velocityX_ += accelerationX_;
    velocityY_ += accelerationY_;

    limitSpeed(velocityX_);
    limitSpeed(velocityY_);

    playerPosition_.x += velocityX_;
    playerPosition_.y += velocityY_;

}

void Player::drawPlayer(SpriteBatch &spriteBatch){
    if(currentCharacter_ == nullptr)
        exit(-1);
    currentCharacter_->drawAnimation(playerPosition_, 1, Action::STAND_STILL, spriteBatch);
}

