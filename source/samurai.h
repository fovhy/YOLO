

#pragma once
#include "Character.h"

class Samurai : public Character{
public:
    void init();
    void spawnSpecialAttackBox(const glm::vec2& pos, int direction);
private:
    void drawSpecialAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
};
