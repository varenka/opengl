#include "shader.h"

void checkGlError(string recent)
{
    GLenum glError = glGetError();
    if(glError == GL_NO_ERROR)
    {
        cout << "No errors after " << recent << endl;
    }
    else
    {
        cout << "Error " << glError << " after " << endl;
    }
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

    ///load shader source files
    m_vertexSource = io::loadTextFile(m_vertexFileName);
    m_fragmentSource = io::loadTextFile(m_fragmentFileName);

    ///get shader ids
    m_vertexID = glCreateShader(GL_VERTEX_SHADER);
    m_fragmentID = glCreateShader(GL_FRAGMENT_SHADER);
    cout << "Shader IDs are: " << m_vertexID << " for vertex shader and " << m_fragmentID << " for fragment shader." << endl;

    ///upload shader sources to GPU
    const GLchar* fragmentShaderChar = m_fragmentSource.c_str();
    const GLchar* vertexShaderChar = m_vertexSource.c_str();

    glShaderSource(m_vertexID, 1, &vertexShaderChar, NULL);
    glShaderSource(m_fragmentID, 1, &fragmentShaderChar, NULL);

    ///compile vertex shader
    glCompileShader(m_vertexID);
    CheckShaderError(m_vertexID, GL_COMPILE_STATUS);

    ///compile fragment shader
    glCompileShader(m_fragmentID);
    CheckShaderError(m_fragmentID, GL_COMPILE_STATUS);
    checkGlError("compiling fragment and vertex shaders.");

    ///create final program
    m_programID = glCreateProgram();
    checkGlError("creating shader program.");
    cout << "Created program with id: " << m_programID << endl;
    glAttachShader(m_programID, m_vertexID);
    glAttachShader(m_programID, m_fragmentID);

    ///this defines which buffers the
    ///fragment shader writes to, 0 by default
    ///causes a segfault if enabled, because this isn't enabled in the shaders
    //glBindFragDataLocation(m_programID, 0, "outColor");

    ///linking shaders
    glLinkProgram(m_programID);
    CheckShaderError(m_programID, GL_LINK_STATUS);
    ///start using shaderProgram
    glUseProgram(m_programID);

}

void Shader::CheckShaderError(GLuint id, int type)
{
    char compileLog[512];
    bzero(&compileLog, sizeof(compileLog));
    GLint status;
    glGetShaderiv(id, type, &status);
    if(status == 0 || status == 1) {
        printf("Shader compiled successfully.\n");
    }else {
        printf("Shader failed to compile. Status: %i\n", status);
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

string io::upToFirstSpace(string str)
{
    string ret = "";
    vector<char> compare;
    unsigned int spaceIndex;
    for(int i = 0; i < str.length() - 1; i++)
    {
        if(str[i] == ' ') {
            //push compare into ret
            spaceIndex = i;
            for(int f = 0; f < compare.size(); f++)
            {
                ret.append((const char*)compare[i]);
            }
            return ret;
        }
        else
        {
            /*cout << "Trying to append ret...." << endl;
            ret.append((const char*)str[i]);
            cout << "Appended ret." << endl;*/
            compare.push_back(str[i]);
        }
    }
}
