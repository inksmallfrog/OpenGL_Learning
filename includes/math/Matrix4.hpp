#ifndef _INKSMALLFROG_MATH3D_MATRIX4_
#define _INKSMALLFROG_MATH3D_MATRIX4_

class Vector3f;
class Camera;

class Matrix4f{
 public:
  Matrix4f();
  Matrix4f(float data[4][4]);
  Matrix4f(const Matrix4f &matrix4f);

  void Initialize();
  //void Unitizate();

  const Matrix4f& MakeTransformationMatrix4f(float tX, float tY, float tZ);
  const Matrix4f& MakeTransformationMatrix4f(const Vector3f &transformation);
  const Matrix4f& MakeRotationMatrix4f(float rX, float rY, float rZ, bool isDegree = true);
  const Matrix4f& MakeRotationMatrix4f(const Vector3f &rotation, bool isDegree = true);
  const Matrix4f& MakeScalationMatrix4f(float sX, float sY, float sZ);
  const Matrix4f& MakeScalationMatrix4f(const Vector3f &scalation);
  const Matrix4f& MakePerspectiveMatrix4f(float angle, float width, float height, float zNear, float zFar, bool isDegree = true);
  const Matrix4f& MakeCameraRotation(const Vector3f &right, const Vector3f &up, const Vector3f &target);  
  Matrix4f operator=(const Matrix4f &right);
  Matrix4f operator*(const Matrix4f &right);
  Matrix4f operator*=(const Matrix4f &right);

  void Print()const;
  
 public:
  float m_data[4][4];
};

#endif
