#include "../../includes/glUtil/Vertex.hpp"

Vertex::Vertex(const Vector3f &position) :
    m_position(position),
    m_textureCoord(),
    m_normal(),
    m_reflectPower(){
}

Vertex::Vertex(const Vector3f &position, const Vector2f &coord) :
    m_position(position),
    m_textureCoord(coord){
}

Vertex::Vertex(const Vector3f &position, const Vector2f &coord, const Vector3f &normal) :
    m_position(position),
    m_textureCoord(coord),
    m_normal(normal){
}

Vertex::Vertex(const Vector3f &position, const Vector2f &coord, const Vector3f &normal, float reflectPower) :
    m_position(position),
    m_textureCoord(coord),
    m_normal(normal),
    m_reflectPower(reflectPower){
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

void Vertex::SetNormal(float x, float y, float z){
  m_normal.x = x;
  m_normal.y = y;
  m_normal.z = z;
}

void Vertex::SetNormal(const Vector3f &normal){
  m_normal = normal;
}

void Vertex::NormalizeNormal(){
  m_normal.Normalize();
}

void Vertex::SetReflectPower(float reflectPower){
  m_reflectPower = reflectPower;
}

const Vector3f& Vertex::GetPosition()const{
  return m_position;
}

const Vector2f& Vertex::GetTextureCoord()const{
  return m_textureCoord;
}

const Vector3f& Vertex::GetNormal()const{
  return m_normal;
}

const float Vertex::GetReflectPower()const{
  return m_reflectPower;
}
