#ifndef MESH_H
#define MESH_H
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "vertex.h"
#include "shader.h"

using namespace std;

class Mesh
{
public:
    Mesh();

    void Init(Vertex* verts, unsigned int numVerts, GLuint programID);
    void Draw();

    virtual ~Mesh();
private:
    vector<Vertex> m_vertices;
    GLuint m_vbo;
};

#endif // MESH_H
