#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <string>
#include <iostream>

using namespace std;

class Window
{
public:
    Window();

    unsigned int* GetWidth() { return &m_width; }
    unsigned int* GetHeight() { return &m_height; }

    void Init(unsigned int width, unsigned int height, const string& title, bool fullScreen);
    void Update();
    void Quit();
    virtual ~Window();
private:
    unsigned int m_width;
    unsigned int m_height;
    SDL_GLContext m_glContext;
    SDL_Window* m_windowPtr;
};

#endif // WINDOW_H
