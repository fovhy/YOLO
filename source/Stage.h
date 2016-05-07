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
enum tiles{
    GRASS,
    ICE,
    DIRT,
    POISON
};

class Stage{
public:
    Stage(){}
    ~Stage(){}
    void init();
    void setStage(SpriteBatch &);
private:
    tiles grass = GRASS;
    tiles ice = ICE;
    tiles dirt = DIRT;
    tiles poison = POISON;
    GLTexture grassTexture;
    GLTexture iceTexture;
    GLTexture dirtTexture;
    GLTexture poisonTexture;
    GLTexture backGroundTexture;

    glm::vec4 getTilesLeftRight(const glm::vec4& pos, int);
    glm::vec4 getTilesUpDown(const glm::vec4& pos, int);
    ResourceManager stageManager;


};
