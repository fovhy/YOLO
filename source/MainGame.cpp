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

    //playerTexture = ImageLoader::loadPNG("../YOLO/texture/JJU/PNG/CharacterRight_Standing.png");

    gameLoop();
}
void MainGame::initSystems() {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

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

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);

    initShaders();
    camera.init(screenWidth, screenHeight);
    spriteBatch_.init();
    myStage.init();

}

void MainGame::gameLoop(){
    while(gameState != GameState::EXIT){
        float startTicks = SDL_GetTicks();
        time += 0.1;
        processInput();
        calculateFPS();
        static int frameCounter = 0;
        frameCounter ++;
        if(frameCounter == 10){
            //std::cout << fps << std::endl;
            frameCounter = 0;
        }
        drawGame();
// limit fps to be 60
        float frameTicks = SDL_GetTicks() - startTicks;
        if(1000.0/ maxfps > frameTicks){
            SDL_Delay(1000.0F/ maxfps - frameTicks);
        }
    }
}

void MainGame::processInput(){
    SDL_Event evnt;

    const float CAMERA_SPEED = 2.0f;

    while(SDL_PollEvent(&evnt)){
        switch(evnt.type){
        case SDL_QUIT:
            gameState = GameState::EXIT;
            break;
        case SDL_MOUSEMOTION:
            //std::cout<<evnt.motion.x << " " << evnt.motion.y << std::endl;
            break;
        case SDL_KEYDOWN:
            inputManager_.pressKey(evnt.key.keysym.sym);
            break;
        case SDL_KEYUP:
            inputManager_.releaseKey(evnt.key.keysym.sym);
            break;
        }
    }

    if(inputManager_.isKeyPressed(SDLK_s)){
        camera.setPosition(camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
    }
    camera.update();
}

void MainGame::drawGame(){

    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    colorProgram.use();

    glActiveTexture(GL_TEXTURE0);

    //glBindTexture(GL_TEXTURE_2D, playerTexture.id);

    GLint textureLocation = colorProgram.getUniformLocation("mySampler");

    glUniform1i(textureLocation, 0);

    // GLuint timeLocation = colorProgram.getUniformLocation("time");
    //glUniform1f(timeLocation, time);

    GLuint pLocation = colorProgram.getUniformLocation("ortho");
    glm::mat4 cameraMatrix = camera.getCameraMatrix();

    glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));




    myStage.setStage(spriteBatch_);

    spriteBatch_.begin();
    glm::vec4 pos(1000, 0, 50, 50);
    glm::vec4 uv(0, 0, 1, 1);
    glm::vec4 pos2(100, 220, 500, 500);
    glm::vec4 uv2(0, 0, 1, 1);
    static GLTexture texture2 = mainManager.getTexture("../YOLO/texture/JJU/PNG/HappyCloud.png");
    static GLTexture texture = mainManager.getTexture("../YOLO/texture/JJU/PNG/CharacterRight_Standing.png");
    Color color;
    color.r = 255;
    color.b = 255;
    color.g = 255;
    color.a = 255;
    spriteBatch_.draw(pos, uv, texture.id, 0.0f, color);
    //spriteBatch_.draw(pos2, uv2, texture2.id, 0.0f, color);

    spriteBatch_.end();

    spriteBatch_.renderBatches();


    glBindTexture(GL_TEXTURE_2D, 0);
    colorProgram.unuse();
    SDL_GL_SwapWindow(window);
}

void MainGame::initShaders(){
    colorProgram.compileShaders("../YOLO/shader/colorShadingVert.glsl",
                                "../YOLO/shader/colorShadingFrag.glsl" );
    colorProgram.addAttribute("vertexPosition");
    colorProgram.addAttribute("vertexColor");
    colorProgram.addAttribute("vertexUV");
    colorProgram.linkShaders();
}

void MainGame::calculateFPS(){
    static const int NUM_SAMPLES = 10;
    static float frameTimes[NUM_SAMPLES];

    static float prevTicks = SDL_GetTicks();

    static int currentFrame = 0;
    float currentTicks = SDL_GetTicks();
    frameTime = currentTicks - prevTicks;

    frameTimes[currentFrame % NUM_SAMPLES] = frameTime;

    int count;
    currentFrame++;

    if(currentFrame < NUM_SAMPLES){
        count = currentFrame;
    }else{
        count = NUM_SAMPLES;
    }
    prevTicks =  currentTicks;

    float frameTimeAverage = 0;;

    for(int i = 0; i < count; ++i){
        frameTimeAverage += frameTimes[i];
    }
    frameTimeAverage /= count;
    if(frameTimeAverage > 0){
        fps = 1000.0f / frameTimeAverage;
    }else{
        fps = 60.0f;
    }
}
