#include "Stage.h"

/*GLTexture Stage::grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
GLTexture Stage:: iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
GLTexture Stage:: dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
GLTexture Stage::poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");*/
void Stage::init(){
    //load all the textures
    grassTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkGreen.png");
    iceTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkBlue.png");
    dirtTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_LightBeige.png");
    poisonTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/LandPiece_DarkPing.png");
    backGroundTexture = stageManager.getTexture("../YOLO/texture/JJU/PNG/Backgrounds/background.png");
}

// for now it is just gonna be hard coded
void Stage::setStage(SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;
    spriteBatch.begin();
    glm::vec4 wholeScreen(0, -384, 1030, 770);
    glm::vec4 uv(0, 0, 1, 1);
    spriteBatch.draw(wholeScreen,uv, backGroundTexture.id, 0.0f, solidColor);
    spriteBatch.end();
    spriteBatch.renderBatches();

}
