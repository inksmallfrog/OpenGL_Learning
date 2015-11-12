#include <cmath>
#include <iostream>
#include "../../includes/math/Vector3.hpp"
#include "../../includes/math/Matrix4.hpp"
#include "../../includes/math/Quaternion.hpp"
#include "../../includes/math/Math3dUtil.hpp"
#include "../../includes/glUtil/Camera.hpp"

Matrix4f::Matrix4f(){
  Initialize();
}

Matrix4f::Matrix4f(float data[4][4]){
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      m_data[y][x] = data[y][x];
    }
  }
}

Matrix4f::Matrix4f(const Matrix4f &matrix4f){
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      m_data[y][x] = matrix4f.m_data[y][x];
    }
  }
}

void Matrix4f::Initialize(){
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      if(x == y){
        m_data[y][x] = 1.0f;
      }
      else{
        m_data[y][x] = 0.0f;
      }
    }
  }
}

const Matrix4f& Matrix4f::MakeTransformationMatrix4f(float tX, float tY, float tZ){
  Initialize();
  m_data[0][3] = tX;
  m_data[1][3] = tY;
  m_data[2][3] = tZ;

  return *this;
}

const Matrix4f& Matrix4f::MakeTransformationMatrix4f(const Vector3f &transformation){
  Initialize();
  m_data[0][3] = transformation.x;
  m_data[1][3] = transformation.y;
  m_data[2][3] = transformation.z;

  return *this;
}

const Matrix4f& Matrix4f::MakeRotationMatrix4f(float rX, float rY, float rZ, bool isDegree){
  if(isDegree){
    rX = DEGREE_TO_RADIO(rX);
    rY = DEGREE_TO_RADIO(rY);
    rZ = DEGREE_TO_RADIO(rZ);
  }
  
  Matrix4f rotateX;
  rotateX.m_data[1][1] = cosf(rX);
  rotateX.m_data[1][2] = -sinf(rX);
  rotateX.m_data[2][1] = sinf(rX);
  rotateX.m_data[2][2] = cosf(rX);

  Matrix4f rotateY;
  rotateY.m_data[0][0] = cosf(rY);
  rotateY.m_data[0][2] = -sinf(rY);
  rotateY.m_data[2][0] = sinf(rY);
  rotateY.m_data[2][2] = cosf(rY);

  Matrix4f rotateZ;
  rotateZ.m_data[0][0] = cosf(rZ);
  rotateZ.m_data[0][1] = -sinf(rZ);
  rotateZ.m_data[1][0] = sinf(rZ);
  rotateZ.m_data[1][1] = cosf(rZ);

  *this = rotateX * rotateY * rotateZ;
  return *this;
}

const Matrix4f& Matrix4f::MakeRotationMatrix4f(const Vector3f &rotation, bool isDegree){
  int rX = rotation.x;
  int rY = rotation.y;
  int rZ = rotation.z;

  return MakeRotationMatrix4f(rX, rY, rZ, isDegree);
}

const Matrix4f& Matrix4f::MakeScalationMatrix4f(float sX, float sY, float sZ){
  Initialize();
  m_data[0][0] = sX;
  m_data[1][1] = sY;
  m_data[2][2] = sZ;

  return *this;
}

const Matrix4f& Matrix4f::MakeScalationMatrix4f(const Vector3f &scalation){
  Initialize();
  m_data[0][0] = scalation.x;
  m_data[1][1] = scalation.y;
  m_data[2][2] = scalation.z;

  return *this;
}

const Matrix4f& Matrix4f::MakePerspectiveMatrix4f(float angle, float width, float height, float zNear, float zFar, bool isDegree){
  if(isDegree){
    angle = DEGREE_TO_RADIO(angle);
  }
  float tanHalfAngle = tanf(angle / 2);
  float ratioWidthHeight = width / height;
  float zDistance = zFar - zNear;
  
  Initialize();
  m_data[0][0] = 1 / tanHalfAngle;
  m_data[1][1] = 1 / tanHalfAngle * ratioWidthHeight;
  m_data[2][2] = (zFar + zNear) / zDistance;
  m_data[2][3] = -2 * zFar * zNear / zDistance;
  m_data[3][2] = 1.0f;
  m_data[3][3] = 0.0f;
  
  return *this;
}

const Matrix4f& Matrix4f::MakeCameraRotation(const Vector3f &right, const Vector3f &up, const Vector3f &target){
  m_data[0][0] = right.x; m_data[0][1] = right.y; m_data[0][2] = right.z; m_data[0][3] = 0.0f;
  m_data[1][0] = up.x; m_data[1][1] = up.y; m_data[1][2] = up.z; m_data[1][3] = 0.0f;
  m_data[2][0] = target.x; m_data[2][1] = target.y; m_data[2][2] = target.z; m_data[2][3] = 0.0f;
  
  return *this;
}

Matrix4f Matrix4f::operator=(const Matrix4f &right){
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      m_data[y][x] = right.m_data[y][x];
    }
  }
  return *this;
}

Matrix4f Matrix4f::operator*(const Matrix4f &right){
  Matrix4f res;
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      res.m_data[y][x] = m_data[y][0] * right.m_data[0][x]
          + m_data[y][1] * right.m_data[1][x]
          + m_data[y][2] * right.m_data[2][x]
          + m_data[y][3] * right.m_data[3][x];
    }
  }
  return res;
}

Matrix4f Matrix4f::operator*=(const Matrix4f &right){
  *this = (*this) * right;
  return *this;  
}

void Matrix4f::Print()const{
  for(int y = 0; y < 4; ++y){
    for(int x = 0; x < 4; ++x){
      std::cout << m_data[y][x] << " ";
    }
    std::cout << "\n";
  }
}
