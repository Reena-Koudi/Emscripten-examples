#include "GLApp.h"

float translationx = 0;

const GLfloat vVertices[] = {
    0.0f, 0.5f, 0.0f, 1.0, 0.0, 0.0,
    -0.5f, -0.5f, 0.0f, 0.0, 1.0, 0.0,
    0.5f, -0.5f, 0.0f, 0.0, 0.0, 1.0 };

const char vertexShaderSource[] =
    "attribute vec4 vPosition;		                     \n"
    "attribute vec3 vColour;		                     \n"
    "uniform float transX;  		                     \n"
    "varying vec3 colour;                                \n"
    "void main() {                                       \n"
    "   gl_Position = vPosition;                         \n"
    "   gl_Position.x = transX + vPosition.x;            \n"
    "   colour = vColour;                                \n"
    "}                                                   \n";

const char fragmentShaderSource[] =
    "precision mediump float;                            \n"
    "varying vec3 colour;                                \n"
    "void main() {                                       \n"
    "   gl_FragColor = vec4(vec3(1.0,0.0,0.0), 1.0);                \n"
    "}                                                   \n";

GLApp::GLApp()
{
    printf("GLApp created\n");
}

GLApp::~GLApp()
{
}

void GLApp::init(std::string json)
{
    _screenWidth = 512;
    _screenHeight = 512;
    _cameraWidth = 512;
    _cameraHeight = 512;

    std::string windowName = "GLApp window";
    esCreateWindow(windowName.c_str(), _screenWidth, _screenHeight, ES_WINDOW_RGB);

    glGenBuffers(1, &vbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vbuffer);
   
    glBufferData(GL_ARRAY_BUFFER,sizeof(vVertices), &vVertices[0], GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    GLuint vertexShader = LoadShader(GL_VERTEX_SHADER, vertexShaderSource);
    GLuint fragmentShader = LoadShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    programObject = BuildProgram(vertexShader, fragmentShader, { "vPosition", "vColour" });

    uniformOriginX = glGetUniformLocation(programObject, "transX");

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    printf("GLApp init\n");
}

void GLApp::draw(unsigned char* data)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // enable shader program
    glUseProgram(programObject);

    glBindBuffer(GL_ARRAY_BUFFER, vbuffer);

    // set translation
    glUniform1f(uniformOriginX, translationx);

    // set up the positions attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // set up the colour attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // draw vertices
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    printf("GLApp draw\n");
}

void GLApp::updateTranslationX(float x) {
    
    translationx += x;
    printf("GLApp translate\n");
}

void GLApp::update(float deltaTime)
{
    printf("GLApp update\n");
}