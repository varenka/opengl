#ifndef GAME_H
#define GAME_H

#include "window.h"

enum levelSymbol
{
    Entity,
    Light,
    MeshRenderer,
    Invalid,
};

class Game
{
public:
    Game(unsigned int width, unsigned int height, const string& title, bool fullScreen);

    bool isClosed;

    void PollInput();
    void Update();
    void LoadLevel(const string& fileName);
    void ExecuteLine(const string& l);
    void Quit();

    Window* GetWindow() { return &m_window; }
    const string GetCurrentLevel() { return m_currentLevel; }

    levelSymbol stringToLevelSymbol(const string& str);

    virtual ~Game();
private:
    Window m_window;
    string m_currentLevel;
};

#endif // GAME_H
