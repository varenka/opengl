#include "mesh.h"

Mesh::Mesh()
{
    //ctor
}

void Mesh::Init(Vertex* verts, unsigned int numVerts, GLuint programID)
{
    for(unsigned int i = 0; i < numVerts; i++)
    {
        m_vertices.push_back(verts[i]);
        cout << "pushed back m_vertices using " << verts[i].GetString() << endl;
    }

    ///create vbo
    glGenBuffers(1, &m_vbo);

    ///make vbo the active object
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);


    ///copy the data from vertices into vertices[]
    vector<GLfloat> vertices;
    for(unsigned int i = 0; i < numVerts; i++)
    {
        vertices.push_back(verts[i].GetPos()->x);
        cout << "pushed back vertices using (" << verts[i].GetPos()->x;
        vertices.push_back(verts[i].GetPos()->y);
        cout << ", " << verts[i].GetPos()->y;
        vertices.push_back(verts[i].GetPos()->z);
        cout << ", " << verts[i].GetPos()->z << ")" << endl;

        vertices.push_back(verts[i].GetColor()->x);
        vertices.push_back(verts[i].GetColor()->y);
        vertices.push_back(verts[i].GetColor()->z);
    }
    GLfloat vertices2[vertices.size()];
    for(unsigned int i = 0; i < vertices.size(); i++)
        vertices2[i] = vertices[i];
    ///upload vertices
    /*cout << "Uploading final buffer: " << endl;
    cout << vertices[0];
    for(unsigned int i = 1; i < vertices.size(); i++)
        cout << ", " << vertices[i];*/
    /*const GLfloat vertices3[] = {
        -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, // Top-left
        0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, // Top-right
        //0.5f, -0.5f, 1.0f, 0.0f, 0.0f, 1.0f, // Bottom-right
        -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 1.0f  // Bottom-left
    };*/

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), &vertices2[0], GL_STATIC_DRAW);
    ///bind m_posAttrib to position
    GLint m_posAttrib = glGetAttribLocation(programID, "position");
    ///enable the position attribute array
    glEnableVertexAttribArray(m_posAttrib);
    ///arguments: input, number of values in that input,
    ///type of each component, should they be
    ///normalized, how many bytes between each
    ///attribute in the array (0 means no other data
    ///between elements), offset
    glVertexAttribPointer(m_posAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), 0);

    ///setup color vertex attrib
    GLint m_colAttrib = glGetAttribLocation(programID, "color");
    glEnableVertexAttribArray(m_colAttrib);
    glVertexAttribPointer(m_colAttrib, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float),
                          (void*)(3 * sizeof(float)));
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Mesh::~Mesh()
{
    //dtor
}

void Mesh::Draw()
{

}
