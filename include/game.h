#ifndef GAME_H
#define GAME_H

#include "window.h"

class Game
{
public:
    Game(unsigned int width, unsigned int height, const string& title, bool fullScreen);

    void PollInput();
    void Update();
    bool isClosed;

    void Quit();

    virtual ~Game();
private:
    Window m_window;
};

#endif // GAME_H
