#include "window.h"

Window::Window()
{

}

void Window::Init(unsigned int width, unsigned int height, const string& title, bool fullScreen)
{

    ///set color mode to 32bps
    int colorSize = 8;
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, colorSize);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, colorSize);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, colorSize);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, colorSize);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, (colorSize * 4));
    //SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    ///set double buffered to true
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_windowPtr = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
    m_glContext = SDL_GL_CreateContext(m_windowPtr);

    GLenum status = glewInit();

    if(status != GLEW_OK)
    {
        cout << "Glew failed to initialize." << endl;
    }
}

void Window::Update()
{
    glClearColor(0.15f, 0.15f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    //glDrawArrays(GL_TRIANGLES, 0, 3);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    SDL_GL_SwapWindow(m_windowPtr);
}

Window::~Window()
{

}

void Window::Quit()
{
    SDL_GL_DeleteContext(m_glContext);
    SDL_DestroyWindow(m_windowPtr);
    SDL_Quit();
}
