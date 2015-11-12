#ifndef _INKSMALLFROG_MATH3D_VECTOR2_
#define _INKSMALLFROG_MATH3D_VECTOR2_

class Vector2f{
 public:
  Vector2f();
  Vector2f(float _x, float _y);
  Vector2f(const Vector2f &vector2f);
  
 public:
  float x;
  float y;
};

#endif
