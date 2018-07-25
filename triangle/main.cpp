#include "GLApp.h"
#include "emscripten.h"
#include "emscripten/bind.h"

GLApp app;

void init(std::string json)
{
    app.init(json);
}

void translateX(float x) {
    app.updateTranslationX(x);
}

void render()
{
    app.draw(nullptr);
}

EMSCRIPTEN_BINDINGS(my_module) {
    emscripten::function("init", &init);
    emscripten::function("render", &render);
    emscripten::function("translateX", &translateX);
}
