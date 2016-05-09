
#pragma once
#include "Character.h"

class Ninja : public Character{
public:
    void init();
    void spawnAttackBox();
    void spawnSpecialAttackBox();
private:
    void drawSpecialAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch);
};
