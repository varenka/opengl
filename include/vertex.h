#ifndef VERTEX_H
#define VERTEX_H

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <sstream>

using namespace std;

class Vertex
{
public:
    Vertex(const glm::vec3& pos, const glm::vec3& color);

    inline glm::vec3* GetPos()
    {
        return &m_pos;
    }
    inline glm::vec3* GetColor()
    {
        return &m_color;
    }
    const string GetString();

    virtual ~Vertex();
private:
    glm::vec3 m_pos;
    glm::vec3 m_color;
};

#endif // VERTEX_H
