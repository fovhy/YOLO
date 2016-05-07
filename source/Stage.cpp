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

    firstLevel.resize(12);
    secondLevel.resize(12);
    thirdLevel.resize(12);
    fourthLevel.resize(12);
}

// for now it is just gonna be hard coded
void Stage::setStage(SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;
    spriteBatch.begin();
    glm::vec4 wholeScreen(0, -400, 1200, 800);
    glm::vec4 uv(0, 0, 1, 1);
    spriteBatch.draw(wholeScreen,uv, backGroundTexture.id, 0.0f, solidColor);
    glm::vec4 firstLevelPos(0, -200, tileWidth, tileHeight);
    firstLevel[0].setTile(firstLevelPos, POISON);
    firstLevel[1].setTile(getTilesLeftRight(firstLevelPos, 1), POISON);
    firstLevel[2].setTile(getTilesLeftRight(firstLevelPos, 2), POISON);
    firstLevel[3].setTile(getTilesLeftRight(firstLevelPos, 3), GRASS);
    firstLevel[4].setTile(getTilesLeftRight(firstLevelPos, 4), GRASS);
    firstLevel[5].setTile(getTilesLeftRight(firstLevelPos, 5), BLANK);

    firstLevel[6].setTile(getTilesLeftRight(firstLevelPos, 6), BLANK);
    firstLevel[7].setTile(getTilesLeftRight(firstLevelPos, 7), GRASS);
    firstLevel[8].setTile(getTilesLeftRight(firstLevelPos, 8), GRASS);
    firstLevel[9].setTile(getTilesLeftRight(firstLevelPos, 9), POISON);
    firstLevel[10].setTile(getTilesLeftRight(firstLevelPos, 10), POISON);
    firstLevel[11].setTile(getTilesLeftRight(firstLevelPos, 11), POISON);

    glm::vec4 secondLevelPos(0, -100, tileWidth, tileHeight);
    secondLevel[0].setTile(secondLevelPos, ICE);
    secondLevel[1].setTile(getTilesLeftRight(secondLevelPos, 1), ICE);
    secondLevel[2].setTile(getTilesLeftRight(secondLevelPos, 2), BLANK);
    secondLevel[3].setTile(getTilesLeftRight(secondLevelPos, 3), BLANK);
    secondLevel[4].setTile(getTilesLeftRight(secondLevelPos, 4), ICE);
    secondLevel[5].setTile(getTilesLeftRight(secondLevelPos, 5), ICE);

    secondLevel[6].setTile(getTilesLeftRight(secondLevelPos, 6), ICE);
    secondLevel[7].setTile(getTilesLeftRight(secondLevelPos, 7), ICE);
    secondLevel[8].setTile(getTilesLeftRight(secondLevelPos, 8), BLANK);
    secondLevel[9].setTile(getTilesLeftRight(secondLevelPos, 9), BLANK);
    secondLevel[10].setTile(getTilesLeftRight(secondLevelPos, 10), ICE);
    secondLevel[11].setTile(getTilesLeftRight(secondLevelPos, 11), ICE);

    glm::vec4 thirdLevelPos(0, 0, tileWidth, tileHeight);
    thirdLevel[0].setTile(thirdLevelPos, BLANK);
    thirdLevel[1].setTile(getTilesLeftRight(thirdLevelPos, 1), BLANK);
    thirdLevel[2].setTile(getTilesLeftRight(thirdLevelPos, 2), BLANK);
    thirdLevel[3].setTile(getTilesLeftRight(thirdLevelPos, 3), DIRT);
    thirdLevel[4].setTile(getTilesLeftRight(thirdLevelPos, 4), DIRT);
    thirdLevel[5].setTile(getTilesLeftRight(thirdLevelPos, 5), BLANK);

    thirdLevel[6].setTile(getTilesLeftRight(thirdLevelPos, 6), BLANK);
    thirdLevel[7].setTile(getTilesLeftRight(thirdLevelPos, 7), BLANK);
    thirdLevel[8].setTile(getTilesLeftRight(thirdLevelPos, 8), DIRT);
    thirdLevel[9].setTile(getTilesLeftRight(thirdLevelPos, 9), DIRT);
    thirdLevel[10].setTile(getTilesLeftRight(thirdLevelPos, 10), BLANK);
    thirdLevel[11].setTile(getTilesLeftRight(thirdLevelPos, 11), BLANK);

    glm::vec4 fourthLevelPos(0, 100, tileWidth, tileHeight);
    fourthLevel[0].setTile(fourthLevelPos, ICE);
    fourthLevel[1].setTile(getTilesLeftRight(fourthLevelPos, 1), ICE);
    fourthLevel[2].setTile(getTilesLeftRight(fourthLevelPos, 2), BLANK);
    fourthLevel[3].setTile(getTilesLeftRight(fourthLevelPos, 3), BLANK);
    fourthLevel[4].setTile(getTilesLeftRight(fourthLevelPos, 4), ICE);
    fourthLevel[5].setTile(getTilesLeftRight(fourthLevelPos, 5), ICE);

    fourthLevel[6].setTile(getTilesLeftRight(fourthLevelPos, 6), ICE);
    fourthLevel[7].setTile(getTilesLeftRight(fourthLevelPos, 7), ICE);
    fourthLevel[8].setTile(getTilesLeftRight(fourthLevelPos, 8), BLANK);
    fourthLevel[9].setTile(getTilesLeftRight(fourthLevelPos, 9), BLANK);
    fourthLevel[10].setTile(getTilesLeftRight(fourthLevelPos, 10), ICE);
    fourthLevel[11].setTile(getTilesLeftRight(fourthLevelPos, 11), ICE);

    drawTiles(firstLevel, spriteBatch);
    drawTiles(secondLevel, spriteBatch);
    drawTiles(thirdLevel, spriteBatch);
    drawTiles(fourthLevel, spriteBatch);

    spriteBatch.end();
    spriteBatch.renderBatches();
}
// draw a single level of tiles
void Stage::drawTiles(const std::vector<tile>& level, SpriteBatch& spriteBatch){
    Color solidColor;
    solidColor.r = 255;
    solidColor.g = 255;
    solidColor.b = 255;
    solidColor.a = 255;
    glm::vec4 uv(0, 0, 1, 1);
    for(auto aTile : level){
        switch(aTile.type){
        case GRASS:
            spriteBatch.draw(aTile.getPos(), uv, grassTexture.id, 0.0f, solidColor);
            break;
        case ICE:
            spriteBatch.draw(aTile.getPos(), uv, iceTexture.id, 0.0f, solidColor);
            break;
        case DIRT:
            spriteBatch.draw(aTile.getPos(), uv, dirtTexture.id, 0.0f, solidColor);
            break;
        case POISON:
            spriteBatch.draw(aTile.getPos(), uv, poisonTexture.id, 0.0f, solidColor);
            break;
        }
    }
}
// direction > 0 means right, < 0 means left
glm::vec4 Stage::getTilesLeftRight(const glm::vec4& pos, int direction){
    return pos + glm::vec4(tileWidth * direction, 0, 0, 0);
}

// direction > 0 means up, < 0 means down
glm::vec4 Stage::getTilesUpDown(const glm::vec4& pos, int direction){
    return pos + glm::vec4(0, tileHeight * direction, 0, 0);
}
