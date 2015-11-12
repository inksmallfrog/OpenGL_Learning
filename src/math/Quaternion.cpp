#include "../../includes/math/Vector3.hpp"
#include "../../includes/math/Quaternion.hpp"
#include "../../includes/math/Math3dUtil.hpp"

Quaternion::Quaternion() :
    x(0.0f),
    y(0.0f),
    z(0.0f),
    a(0.0f){
}

Quaternion::Quaternion(const Vector3f &vector3f) :
    x(vector3f.x),
    y(vector3f.y),
    z(vector3f.z),
    a(0.0f){
}

void Quaternion::Normalize(){
  float length = x * x + y * y + z * z + a * a;
  x /= length;
  y /= length;
  z /= length;
  a /= length;
}

Quaternion Quaternion::Inverse(){
  Normalize();
  Quaternion res;
  res.x = -1 * x;
  res.y = -1 * y;
  res.z = -1 * z;
  res.a = a;

  return res;
}

void Quaternion::MakeRotationQuaternion(const Vector3f &axis, float angle, bool isDegree){
  if(isDegree){
    angle = DEGREE_TO_RADIO(angle);
  }
  float halfAngle = angle / 2;
  
  x = axis.x * sinf(halfAngle);
  y = axis.y * sinf(halfAngle);
  z = axis.z * sinf(halfAngle);
  a = cosf(halfAngle);
}

Quaternion Quaternion::operator*(const Quaternion &right)const{
  Quaternion res;
  res.x = x * right.a + a * right.x + y * right.z - z * right.y;
  res.y = y * right.a + a * right.y + z * right.x - x * right.z;
  res.z = z * right.a + a * right.z + x * right.y - y * right.x;
  res.a = a * right.a - x * right.x - y * right.y - z * right.z;

  return res;
}

void Quaternion::GetVector3(Vector3f &outVector)const{
  outVector.x = x;
  outVector.y = y;
  outVector.z = z;
}
