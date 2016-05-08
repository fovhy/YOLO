#pragma once
#include "glm/glm.hpp"
#include "inputManager.h"
#include "GLTexture.h"
#include "GL/glew.h"
#include <string>
#include "spriteBatch.h"
#include <vector>
#include "Physic.h"
#include "fileManager.h"
#include <iostream>
#include "ResourceManager.h"
#include <cmath>
enum class Action{
    STAND_STILL,
    ATTACK,
    JUMP,
    JUMP_ATTACK,
    SLAM_ATTACK,
    SPECIAL_ATTACK,
    RUN
};

class Character{
public:
    Character(){}
    ~Character(){}
    void init(std::string filePath, float width, float height);
    void drawAnimation(const glm::vec2& pos, int direction, Action aAction, SpriteBatch& spriteBatch);
    float getWidth(){ return characterWidth_ ;}
    float getHeight(){ return characterHeight_;}
private:
    ResourceManager characterManager_;
    GLTexture characterTexuture_;
    float characterWidth_ = 0;
    float characterHeight_ = 0;
};

