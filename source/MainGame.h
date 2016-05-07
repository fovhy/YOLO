#pragma once
#include "Stage.h"
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
    ResourceManager mainManager;

    Camera camera;
    float fps;
    float frameTime;
    float maxfps = 60.0f;
    //GLTexture playerTexture;

    Stage myStage;

    void initSystems();
    void gameLoop();
    void processInput();
    void drawGame();
    void initShaders();
    void calculateFPS();

    SpriteBatch spriteBatch_;
    GLSLProgram colorProgram;


};
