#include <iostream>
#include "game.h"
#include "mesh.h"
#include "shader.h"

using namespace std;

int main()
{
    Game game(800, 600, "test", false);
    Shader shader;
    shader.Load("./res/shader");
    Mesh mesh;
    /*const GLfloat vertices[] = {
        -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, // Top-left
        0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
        0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f  // Bottom-left
    };*/
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, 0.5, 1.0), glm::vec3(0.0, 0.0, 0.0)),
                            Vertex(glm::vec3(0.5, 0.5, 1.0), glm::vec3(0.0, 0.0, 0.0)),
                            Vertex(glm::vec3(0.5, -0.5, 1.0), glm::vec3(0.0, 0.0, 0.0)), };
    mesh.Init(&vertices[0], 3, shader.GetProgramID());
    while(!game.isClosed)
    {
        game.PollInput();
        game.Update();
    }
    game.Quit();
    return 0;
}
