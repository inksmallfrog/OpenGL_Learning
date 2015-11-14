#include "../../includes/math/Math3dUtil.hpp"
#include "../../includes/math/Vector3.hpp"
#include <iostream>

Vector3f::Vector3f() :
    x(0.0f),
    y(0.0f),
    z(0.0f){
}

Vector3f::Vector3f(float x, float y, float z){
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3f::Vector3f(const Vector3f &vector3f){
  this->x = vector3f.x;
  this->y = vector3f.y;
  this->z = vector3f.z;
}

void Vector3f::Normalize(){
  float distance = sqrtf(x * x + y * y + z * z);
  x /= distance;
  y /= distance;
  z /= distance;
}

Vector3f Vector3f::operator=(const Vector3f &right){
  x = right.x;
  y = right.y;
  z = right.z;

  return (*this);
}

Vector3f Vector3f::operator+(const Vector3f &right){
  Vector3f res;
  res.x = this->x + right.x;
  res.y = this->y + right.y;
  res.z = this->z + right.z;

  return res;
}

Vector3f Vector3f::operator+=(const Vector3f &right){
  x += right.x;
  y += right.y;
  z += right.z;

  return (*this);
}

Vector3f Vector3f::operator-(const Vector3f &right){
  Vector3f res;
  res.x = this->x - right.x;
  res.y = this->y - right.y;
  res.z = this->z - right.z;

  return res;  
}

Vector3f Vector3f::operator-=(const Vector3f &right){
  x -= right.x;
  y -= right.y;
  z -= right.z;

  return (*this);  
}

Vector3f Vector3f::operator*(float right)const{
  Vector3f res;
  res.x = this->x * right;
  res.y = this->y * right;
  res.z = this->z * right;

  return res;
}

Vector3f Vector3f::operator*=(float right){
  x *= right;
  y *= right;
  z *= right;

  return (*this);
}

float Vector3f::Dot(const Vector3f &right){
  return (x * right.x + y * right.y + z * right.z);
}

Vector3f Vector3f::Cross(const Vector3f &right){
  Vector3f res;
  res.x = y * right.z - z * right.y;
  res.y = -x * right.z + z * right.x;
  res.z = x * right.y - y * right.x;
  res.Normalize();
  return res;
}

void Vector3f::Print()const{
  std::cout << x << " " << y << " " << z << std::endl;
}
