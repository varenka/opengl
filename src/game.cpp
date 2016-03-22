#include "game.h"

Game::Game(unsigned int width, unsigned int height, const string& title, bool fullScreen)
{
    SDL_Init(SDL_INIT_EVERYTHING);

    m_window.Init(width, height, title, fullScreen);
    isClosed = false;
}

Game::~Game()
{

}

levelSymbol Game::stringToLevelSymbol(const string& str)
{
    if(str == "GameObject") return GameObject;
    if(str == "Light") return Light;
    if(str == "MeshRenderer") return MeshRenderer;
    //else
    return Invalid;
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

void Game::LoadLevel(const string& fileName)
{
    ifstream if_stream(fileName.c_str());

    string line;

    if(io::exists(fileName.c_str()))
    {
        while(if_stream.good())
        {
            getline(if_stream, line);
            if(line[0] == '#')
            {
                //# is commented out, do nothing
            }
            else
            {
                switch(stringToLevelSymbol(io::upToFirstSpace(line)))
                {
                case GameObject:
                    cout << "Found GameObject" << endl;
                    break;
                default:
                    cout << "Error while loading " << m_currentLevel << ": Unrecognized symbol: " << line << endl;
                }
            }
        }
    }
    else
    {
        cout << "Could not open level: " << fileName << endl;
    }

}
