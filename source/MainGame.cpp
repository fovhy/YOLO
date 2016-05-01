#include "MainGame.h"
#include "Error.h"
MainGame::MainGame::MainGame(){
    window = nullptr;
    gameState = GameState::PLAY;

}



MainGame::~MainGame(){

}

void MainGame::run(){
    initSystems();

    sprite.init(-1.0f, -1.0f, 2.0f, 2.0f);

    gameLoop();
}
void MainGame::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);

    window = SDL_CreateWindow("Yolo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight,SDL_WINDOW_OPENGL);
    if(window == nullptr){
        printError("Windows failed to open");
    }
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if(glContext == nullptr){
        printError("SDL_GL context could not be created!");
    }
    GLenum glewSignal = glewInit();
    if (glewSignal != GLEW_OK){
        printError("Failed to initialize glew");
    }
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    initShaders();
}

void MainGame::gameLoop(){
    while(gameState != GameState::EXIT){
        time += 0.01;
        processInput();
        drawGame();
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

void MainGame::drawGame(){

    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    colorProgram.use();

    GLuint timeLocation = colorProgram.getUniformLocation("time");

    glUniform1f(timeLocation, time);


    sprite.draw();


    colorProgram.unuse();

    SDL_GL_SwapWindow(window);
}

void MainGame::initShaders(){
    colorProgram.compileShaders("../YOLO/shader/colorShadingVert.glsl",
                                "../YOLO/shader/colorShadingFrag.glsl" );
    colorProgram.addAttribute("vertexPosition");
    colorProgram.addAttribute("vertexColor");
    colorProgram.linkShaders();
}
