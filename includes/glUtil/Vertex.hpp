#ifndef _INKSMALLFROG_VERTEX_
#define _INKSMALLFROG_VERTEX_

#include "../math/Vector.hpp"

class Vertex{
 public:
  Vertex(const Vector3f &position);
  Vertex(const Vector3f &position, const Vector2f &coord);
  Vertex(const Vector3f &position, const Vector2f &coord, const Vector3f &m_normal);
  Vertex(const Vector3f &position, const Vector2f &coord, const Vector3f &m_normal, float reflectPower);
  Vertex(const Vertex &vertex);

  void SetPosition(float x, float y, float z);
  void SetPosition(const Vector3f &position);
  void SetTextureCoord(float s, float v);
  void SetTextureCoord(const Vector2f &coord);
  void SetNormal(float x, float y, float z);
  void SetNormal(const Vector3f &normal);
  void NormalizeNormal();
  void SetReflectPower(float reflectPower);

  const Vector3f& GetPosition()const;
  const Vector2f& GetTextureCoord()const;
  const Vector3f& GetNormal()const;
  const float GetReflectPower()const;
  
 private:
  Vector3f m_position;
  Vector2f m_textureCoord;
  Vector3f m_normal;
  float m_reflectPower;
};

#endif
