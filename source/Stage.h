#pragma once
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>
#include <vector>
#include "GLSLProgram.h"
#include "GLTexture.h"
#include "ImageLoader.h"
#include "Camera.h"
#include "spriteBatch.h"
#include "fileManager.h"
#include "ResourceManager.h"
#include "tile.h"
#include "Player.h"
#include "Physic.h"

class Stage{
public:
    Stage(){}
    ~Stage(){}
    void init();
    void setStage(SpriteBatch &);
    static const int PLAYER_NUMBERS= 1;
    std::vector<Player> players;
    Physic myPhysic;
    void tileCollisionChecking();
    void update();
    void processInput();
    void draw(SpriteBatch& spriteBattch);

    void applyGravity();
private:
    GLTexture grassTexture;
    GLTexture iceTexture;
    GLTexture dirtTexture;
    GLTexture poisonTexture;
    GLTexture backGroundTexture;

    // store each level of tiles
    std::vector<tile> firstLevel;
    std::vector<tile> secondLevel;
    std::vector<tile> thirdLevel;
    std::vector<tile> fourthLevel;

    // two players

    int tileWidth = 100;
    int tileHeight = 30;

    glm::vec4 getTilesLeftRight(const glm::vec4& pos, int);
    glm::vec4 getTilesUpDown(const glm::vec4& pos, int);
    void drawTiles(const std::vector<tile>& level, SpriteBatch& spriteBatch);
    ResourceManager stageManager;


};
