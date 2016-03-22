#include <iostream>
#include "game.h"
#include "mesh.h"
#include "shader.h"
#include <GL/glu.h>

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
    Vertex vertices[] = { Vertex(glm::vec3(-0.5, 0.5, 1.0), glm::vec3(0.0, 1.0, 0.0)),
                            Vertex(glm::vec3(0.5, 0.5, 1.0), glm::vec3(1.0, 1.0, 0.0)),
                            Vertex(glm::vec3(0.5, -0.5, 1.0), glm::vec3(0.0, 0.0, 1.0)),
                            Vertex(glm::vec3(-0.5, -0.5, 1.0), glm::vec3(0.0, 0.0, 0.0)), };
    ///setup element array buffer
    GLuint elements[] = {
        0, 1, 2,
        2, 3, 0,
    };

    GLuint ebo;
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
        sizeof(elements), elements, GL_STATIC_DRAW);

    cout << "Shader programID is: " << shader.GetProgramID() << endl;
    mesh.Init(&vertices[0], 4, shader.GetProgramID());
    GLenum errCode;
    const GLubyte* errString;
    errCode = glGetError();
    if (errCode != GL_NO_ERROR)
    {
        cerr << errCode << endl;
        ofstream ofs;
        ofs.open("glerror.txt");
        ofs << errCode << endl;
        ofs.close();
    }
    if(glIsProgram(shader.GetProgramID()) == GL_FALSE)
    {
        cout << "The program with id " << shader.GetProgramID() << " does not exist." << endl;
    }
    else
    {
        cout << "Shader with program id " << shader.GetProgramID() << " has been created." << endl;
        cout << "Error code: " << glIsProgram(shader.GetProgramID()) << endl;
    }
    game.LoadLevel("./levels/test");
    while(!game.isClosed)
    {
        game.PollInput();
        game.Update();
    }
    glDeleteShader(shader.GetProgramID());
    game.Quit();
    return 0;
}
