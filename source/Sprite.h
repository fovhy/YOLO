#pragma once
#include <GL/glew.h>
#include <cstddef>
#include "Vertex.h"

class Sprite{
public:
    Sprite();
    ~Sprite();
    void init(float x, float y, float width, float height);
    void draw();

private:
    float x;
    float y;
    float width;
    float height;
    GLuint vboID = 0;
};
