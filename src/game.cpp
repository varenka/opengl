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
    if(str == "Entity") return Entity;
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

void Game::ExecuteLine(const string& l)
{
    levelSymbol symbol = stringToLevelSymbol(l.substr(0, l.find_first_of(" ")));
    switch(symbol)
    {
    case Entity:
        cout << "Found entity." << endl;
        break;
    case Light:
        cout << "Found light." << endl;
        break;
    case MeshRenderer:
        cout << "Found MeshRenderer." << endl;
        break;
    case Invalid:
        cout << "Error while executing line: " << l << endl;
    default:
        break;
    }
}

//this is broken
void Game::LoadLevel(const string& fileName)
{
    ifstream if_stream(fileName.c_str());

    string line;

    string levelSource;
    if_stream >> levelSource;

    if(io::exists(fileName.c_str()))
    {
        while(if_stream.good())
        {
            getline(if_stream, line);
            levelSource.append(line + "\n");
            ExecuteLine(line);
        }
    }
    cout << "Loaded " << fileName << ":" << endl;
    cout << levelSource << endl;

}
