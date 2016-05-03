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

enum class GameState {PLAY, EXIT};
class MainGame{
public:
    MainGame();
    ~MainGame();

    void run();



private:
    SDL_Window* window;
    int screenWidth = 1024;
    int screenHeight = 768;
    float time = 0;
    GameState gameState;

    Camera camera;
    float fps;
    float frameTime;
    float maxfps = 60.0f;
    //GLTexture playerTexture;

    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();
    void calculateFPS();

    std::vector<Sprite*> sprites;

    GLSLProgram colorProgram;

};
