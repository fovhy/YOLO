#pragma once
#include "Character.h"
#include "inputManager.h"
enum PlayerStates{
    STANDING,
    TAKE_DAMAGE,
    JUMPING,
    FALLING
};

enum PlayerType{
    PLAYER_ONE,
    PLAYER_TWO
};

class Player{
public:
    Player(){}
    ~Player(){}


    void init(const glm::vec2& pos);
    void processInput();
    void update();
    void drawPlayer(SpriteBatch& spriteBatch);
    void setCurrentCharacters(Character* character){
        currentCharacter_ = character;
    }
    void setPosition(const glm::vec2& pos){
        playerPosition_ = pos;
    }

    void setPlayerType(PlayerType aType){
        playerType_ = aType;
    }

    void setFacing(int facing){
        this->facing = facing;
    }

    void setPayerState(PlayerStates aState){
        currentState_ = aState;
    }
    void setVX(float vx){velocityX_ = vx;}
    void setVY(float vy){velocityY_ = vy;}

    void setX(float x){playerPosition_.x = x;}
    void setY(float y){playerPosition_.y = y;}

    float getX(){return playerPosition_.x;}
    float getY(){return playerPosition_.y;}

    float getVX(){return velocityX_;}
    float getVY(){return velocityY_;}
    Character* getCurr(){ return currentCharacter_;}

    inputManager playerInputManager;
    std::vector<Character> characters;
    bool onTile = false;
    bool inAir = true;
    bool isDead = false;
private:
    void limitSpeed(float& speed);
    const float MAX_VELOCITY = 10;

    PlayerType playerType_;
    PlayerStates currentState_;

    const int CHARACTER_NUMBERS = 4;
    int facing = 0;

    float accelerationX_ = 0;
    float accelerationY_ = 0;
    float velocityX_ = 0;
    float velocityY_ = 0;



    Character* currentCharacter_ = nullptr;
    glm::vec2 playerPosition_ = glm::vec2(0.0f);
};
