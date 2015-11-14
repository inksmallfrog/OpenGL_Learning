#ifndef _INKSMALLFROG_MATH3D_VECTOR3_
#define _INKSMALLFROG_MATH3D_VECTOR3_

class Vector3f{
 public:
  Vector3f();
  Vector3f(float x, float y, float z);
  Vector3f(const Vector3f &vector3f);
  void Normalize();
  Vector3f operator=(const Vector3f &right);
  Vector3f operator+(const Vector3f &right);
  Vector3f operator+=(const Vector3f &right);
  Vector3f operator-(const Vector3f &right);
  Vector3f operator-=(const Vector3f &right);
  Vector3f operator*(float right)const;
  Vector3f operator*=(float right);
  float Dot(const Vector3f &right);
  Vector3f Cross(const Vector3f &right);
  void Print()const;
  
 public:
  float x;
  float y;
  float z;
};

#endif
