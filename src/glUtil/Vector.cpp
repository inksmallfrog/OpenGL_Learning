#include "../../includes/glUtil/Vertex.hpp"

Vertex::Vertex(float x, float y, float z, float s, float v) :
    m_position(x, y, z),
    m_textureCoord(s, v){
}

Vertex::Vertex(const Vector3f &position, const Vector2f &coord) :
    m_position(position),
    m_textureCoord(coord){
}

Vertex::Vertex(const Vertex &vertex) :
    m_position(vertex.GetPosition()),
    m_textureCoord(vertex.GetTextureCoord()){
}

void Vertex::SetPosition(float x, float y, float z){
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
}

void Vertex::SetPosition(const Vector3f &position){
  m_position = position;
}

void Vertex::SetTextureCoord(float s, float v){
  m_textureCoord.x = s;
  m_textureCoord.y = v;
}

void Vertex::SetTextureCoord(const Vector2f &coord){
  m_textureCoord = coord;
}

const Vector3f& Vertex::GetPosition()const{
  return m_position;
}

const Vector2f& Vertex::GetTextureCoord()const{
  return m_textureCoord;
}
