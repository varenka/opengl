#include "shader.h"

Shader::Shader()
{
    //ctor
}

Shader::~Shader()
{
    //dtor
}

const string Shader::GetFileName()
{
    return m_fileName;
}

void Shader::Load(const string& fileName)
{
    m_programID = glCreateProgram();
    if(m_programID == 0)
        cout << "Could not create shader program: " << fileName << " with ID " << m_programID << endl;

    m_fileName = fileName;
    m_vertexFileName = m_fileName + ".vs";
    m_fragmentFileName = m_fileName + ".fs";

    ///load source files
    m_vertexSource = io::loadTextFile(m_vertexFileName);
    m_fragmentSource = io::loadTextFile(m_fragmentFileName);

    ///get shader ids
    m_vertexID = glCreateShader(GL_VERTEX_SHADER);
    m_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);

    ///upload shader sources
    const GLchar* fragmentShaderChar = m_fragmentSource.c_str();
    const GLchar* vertexShaderChar = m_vertexSource.c_str();

    glShaderSource(m_vertexID, 1, &vertexShaderChar, NULL);
    glShaderSource(m_fragmentID, 1, &fragmentShaderChar, NULL);

    ///compile vertex shader
    glCompileShader(m_vertexID);
    CheckShaderError(m_vertexID);

    ///compile fragment shader
    glCompileShader(m_fragmentID);
    CheckShaderError(m_fragmentID);

    ///create final program
    m_programID = glCreateProgram();
    glAttachShader(m_programID, m_vertexID);
    glAttachShader(m_programID, m_vertexID);

    ///this defines which buffers the
    ///fragment shader writes to, 0 by default
    glBindFragDataLocation(m_programID, 0, "outColor");

    ///linking shaders
    glLinkProgram(m_programID);
    ///start using shaderProgram
    glUseProgram(m_programID);

}

void Shader::CheckShaderError(GLuint id)
{
    char compileLog[512];
    GLint status;
    glGetShaderiv(id, GL_COMPILE_STATUS, &status);
    if(status) {
        printf("Shader compiled successfully.\n");
    }else {
        printf("Shader failed to compile.\n");
        glGetShaderInfoLog(id, 512, NULL, compileLog);
        printf(compileLog);
    }
}

string io::loadTextFile(const string& fileName)
{
    ifstream if_stream(fileName.c_str());

    string output;
    string line;

    if(io::exists(fileName.c_str()))
    {
        while(if_stream.good())
        {
            getline(if_stream, line);
            output.append(line + "\n");
        }
    }

    return output;
}

bool io::exists(const string& fileName)
{
    ifstream fs(fileName.c_str());

    if(fs.good())
    {
        return true;
    }
    cout << "Could not open file: " << fileName << endl;
    return false;
}

string io::getVectorString(glm::vec3* vec)
{
    stringstream ss;
    ss << "(" << vec->x << ", " << vec->y << ", " << vec->z << ")";
    return ss.str();
}
