#include "vertex.h"

Vertex::Vertex(const glm::vec3& pos, const glm::vec3& color)
{
    m_pos = pos;
    m_color = color;
}

Vertex::~Vertex()
{
    //dtor
}

const string Vertex::GetString()
{
    stringstream ss;
    ss << "position: (" << m_pos.x << ", " << m_pos.y << ", " << m_pos.z << ")" << " color: (" << m_color.x << ", " << m_color.y << ", " << m_color.z << ")";
    return ss.str();
}
