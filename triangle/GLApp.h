#pragma once
#include "esUtil.h"

#include <string>
#include <vector>
#include <deque>
#include <iostream>
#include <time.h>
#include <fstream>

class GLApp : public EGLWindow
{
  public:
    GLApp();
    ~GLApp();
    void init(std::string json);
    void update(float deltaTime);
    void draw(unsigned char *data);

    void updateTranslationX(float x);
    
  private:
    
    GLuint programObject;
    GLuint vbuffer;

    GLint uniformOriginX;

    int _screenWidth;
    int _screenHeight;
    int _cameraWidth;
    int _cameraHeight;
    bool _initialised;
};