#pragma once
#include "Sprite.h"
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <string>
#include <iostream>
#include "GLSLProgram.h"

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

    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();

    Sprite sprite;

    GLSLProgram colorProgram;

};
