#include "MainGame.h"
MainGame::MainGame::MainGame(){
    window = nullptr;
    gameState = GameState::PLAY;

}

MainGame::~MainGame(){

}

void MainGame::run(){
    initSystems();

    gameLoop();
}
void MainGame::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Yolo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,SDL_WINDOW_OPENGL);
}

void MainGame::gameLoop(){
    while(gameState != GameState::EXIT){
        processInput();
    }
}

void MainGame::processInput(){
    SDL_Event evnt;

    while(SDL_PollEvent(&evnt)){
        switch(evnt.type){
        case SDL_QUIT:
            gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            std::cout<<evnt.motion.x << " " << evnt.motion.y << std::endl;
            break;
        }
    }
}
