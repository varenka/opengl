#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "shader.h"

using namespace std;

class Window
{
public:
    Window() { r = 0.15f; g = 0.15f; b = 0.3f; a = 1.0f; }

    ///background clear colors
    float r, g, b, a;

    unsigned int* GetWidth() { return &m_width; }
    unsigned int* GetHeight() { return &m_height; }

    void Init(unsigned int width, unsigned int height, const string& title, bool fullScreen);
    void Update();
    void Quit();
    virtual ~Window() {}
private:
    unsigned int m_width;
    unsigned int m_height;
    SDL_GLContext m_glContext;
    SDL_Window* m_windowPtr;

    vector<GLuint> m_elements;
};

#endif // WINDOW_H
