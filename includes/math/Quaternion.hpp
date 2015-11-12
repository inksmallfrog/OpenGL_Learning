#ifndef _INKSMALLFROG_MATH3D_QUATERNION_
#define _INKSMALLFROG_MATH3D_QUATERNION_

class Vector3f;

class Quaternion{
 public:
  Quaternion();
  Quaternion(const Vector3f &vector3);
  void Normalize();
  Quaternion Inverse();
  void MakeRotationQuaternion(const Vector3f& axis, float angle, bool isDegree = true);
  Quaternion operator*(const Quaternion &right)const;
  void GetVector3(Vector3f &outVector)const;

 public:
  float x;
  float y;
  float z;
  float a;
};

#endif
