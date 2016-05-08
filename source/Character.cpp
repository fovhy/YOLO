#include "Character.h"

void Character::init(std::string filePath, float width, float height){
    characterTexuture_ = characterManager_.getTexture(filePath.c_str());
    characterWidth_ = width;
    characterHeight_= height;

}

void Character::drawAnimation(const glm::vec2 &pos, int direction,
                              Action aAction, SpriteBatch& spriteBatch){
    spriteBatch.begin();
    glm::vec4 temp(pos.x, pos.y, characterWidth_, characterHeight_);
    glm::vec4 uv(0, 0, 1, 1);
    Color color;
    color.r = 255;
    color.b = 255;
    color.g = 255;
    color.a = 255;
    spriteBatch.draw(temp, uv, characterTexuture_.id, 0.0f, color);
}

