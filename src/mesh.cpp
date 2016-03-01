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

    vector<glm::vec3> colors;
    vector<glm::vec3> positions;

    for(unsigned int i = 0; i < numVerts; i++)
    {
        colors.push_back(*verts[i].GetColor());
        cout << "pushed back colors using " << io::getVectorString(verts[i].GetColor()) << endl;
    }

    for(unsigned int i = 0; i < numVerts; i++)
    {
        positions.push_back(*verts[i].GetPos());
        cout << "pushed back positions using " << io::getVectorString(verts[i].GetPos()) << endl;
    }

    ///create vbo
    glGenBuffers(1, &m_vbo);

    ///make vbo the active object
    glBindBuffer(GL_ARRAY_BUFFER, m_vbo);


    ///copy the data from vertices into vertices[]
    vector<GLfloat> vertices;
    for(unsigned int i = 0; i < numVerts; i++)
    {
        vertices.push_back(positions[i].x);
        cout << "pushed back vertices using (" << positions[i].x;
        vertices.push_back(positions[i].y);
        cout << ", " << positions[i].y;
        vertices.push_back(positions[i].z);
        cout << ", " << positions[i].z << ")" << endl;

        vertices.push_back(colors[i].x);
        vertices.push_back(colors[i].y);
        vertices.push_back(colors[i].z);
    }

    ///upload vertices
    /*cout << "Uploading final buffer: " << endl;
    cout << vertices[0];
    for(unsigned int i = 1; i < vertices.size(); i++)
        cout << ", " << vertices[i];*/
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), &vertices[0], GL_STATIC_DRAW);
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
