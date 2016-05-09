

#include "ninja.h"

void Ninja::init(){
    characterWidth_ = 70;
    characterHeight_ = 70;
    idle.resize(4);
    idle[0] = characterManager_.getTexture("../YOLO/texture/ninja/idle_0.png");
    idle[1] = characterManager_.getTexture("../YOLO/texture/ninja/idle_1.png");
    idle[2] = characterManager_.getTexture("../YOLO/texture/ninja/idle_2.png");
    idle[3] = characterManager_.getTexture("../YOLO/texture/ninja/idle_3.png");
    idleC = 0.1;
    run.resize(6);
    run[0] = characterManager_.getTexture("../YOLO/texture/ninja/run_0.png");
    run[1] = characterManager_.getTexture("../YOLO/texture/ninja/run_1.png");
    run[2] = characterManager_.getTexture("../YOLO/texture/ninja/run_2.png");
    run[3] = characterManager_.getTexture("../YOLO/texture/ninja/run_3.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/ninja/run_4.png");
    run[4] = characterManager_.getTexture("../YOLO/texture/ninja/run_5.png");
    runC = 0.2;

    jump.resize(1);
    jump[0] = characterManager_.getTexture("../YOLO/texture/ninja/jump_0.png");
    jumpC = 0.0;

    fall.resize(1);
    fall[0] = characterManager_.getTexture("../YOLO/texture/ninja/jump_2.png");
    fallC = 0.1;

    attack.resize(3);
    attack[0] = characterManager_.getTexture("../YOLO/texture/ninja/attack_0.png");
    attack[1] = characterManager_.getTexture("../YOLO/texture/ninja/attack_1.png");
    attack[2] = characterManager_.getTexture("../YOLO/texture/ninja/attack_2.png");
    attackC = 0.1;

    jumpAttack.resize(2);

    jumpAttack[0] = characterManager_.getTexture("../YOLO/texture/ninja/jump_3.png");
    jumpAttack[1] = characterManager_.getTexture("../YOLO/texture/ninja/jump_3.png");
    jumpAttackC = 0.1;

    stunned.resize(1);
    stunned[0] = characterManager_.getTexture("../YOLO/texture/ninja/x_1.png");
    stunnedC = 0.01;

    attackWidth = 40;
    attackHeight = 100;


}

void Ninja::spawnSpecialAttackBox(const glm::vec2 &pos, int direction)
{

}


void Ninja::drawSpecialAttack(const glm::vec2& pos, int direction,SpriteBatch& spriteBatch){

    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;

    if(specialAttackS > specialAttack.size() -1){
        specialAttackS = 0;
    }
    glm::vec4 uv;
    if(direction == 1){
        uv = glm::vec4(0, 0, 1, 1);
    }else{
        uv = glm::vec4 (0, 0, -1, 1);
    }
    spriteBatch.draw(glm::vec4(pos.x, pos.y, characterWidth_, characterHeight_),
                     uv, specialAttack[(int)specialAttackS].id, 1.0, solidColor);
    specialAttackS += specialAttackC;
}
