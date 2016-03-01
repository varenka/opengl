#include "game.h"

Game::Game(unsigned int width, unsigned int height, const string& title, bool fullScreen)
{
    m_window.Init(width, height, title, fullScreen);
    isClosed = false;
}

Game::~Game()
{

}

void Game::PollInput()
{
    SDL_Event e;
    while(SDL_PollEvent(&e))
    {
        switch(e.type)
        {
            case SDL_QUIT:
                isClosed = true;
                break;
            default:
                break;
        }
    }
}

void Game::Quit()
{
    m_window.Quit();
}

void Game::Update()
{
    m_window.Update();
}
