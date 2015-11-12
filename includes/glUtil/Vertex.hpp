#ifndef _INKSMALLFROG_VERTEX_
#define _INKSMALLFROG_VERTEX_

#include "../math/Vector.hpp"

class Vertex{
 public:
  Vertex(float x, float y, float z, float s, float v);
  Vertex(const Vector3f &position, const Vector2f &coord);
  Vertex(const Vertex &vertex);

  void SetPosition(float x, float y, float z);
  void SetPosition(const Vector3f &position);
  void SetTextureCoord(float s, float v);
  void SetTextureCoord(const Vector2f &coord);

  const Vector3f& GetPosition()const;
  const Vector2f& GetTextureCoord()const;
  
 private:
  Vector3f m_position;
  Vector2f m_textureCoord;
};

#endif
