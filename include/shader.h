#ifndef SHADER_H
#define SHADER_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

class io
{
public:
    static string loadTextFile(const string& fileName);
    static bool exists(const string& fileName);
    static string getVectorString(glm::vec3* vec);
};

class Shader
{
public:
    Shader();

    void Load(const string& fileName);
    const string GetFileName();
    const GLuint GetProgramID()
    {
        return m_programID;
    }
    const GLint GetPosAttrib()
    {
        return m_posAttrib;
    }
    const GLint GetColAttrib()
    {
        return m_colAttrib;
    }

    static void CheckShaderError(GLuint id);
    virtual ~Shader();
private:
    GLuint m_programID;
    GLuint m_vertexID, m_fragmentID;
    GLint m_posAttrib;
    GLint m_colAttrib;

    string m_fileName;

    string m_vertexFileName;
    string m_fragmentFileName;

    string m_vertexSource;
    string m_fragmentSource;
};

#endif // SHADER_H
