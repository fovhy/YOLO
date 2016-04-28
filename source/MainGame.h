#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

enum class GameState {PLAY, EXIT};
class MainGame{
public:
    MainGame();
    ~MainGame();

    void run();
    void initSystems();
    void gameLoop();

    void processInput();


private:
    SDL_Window* window;
    int screenWidth = 1024;
    int screenHeight = 768;
    GameState gameState;

};
