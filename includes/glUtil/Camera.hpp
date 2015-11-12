#ifndef _INKSMALLFROG_CAMERA_
#define _INKSMALLFROG_CAMERA_

#include "../math/Vector3.hpp"
#include "../math/Matrix4.hpp"

enum Direction{
  DIRECTION_UP,
  DIRECTION_DOWN,
  DIRECTION_LEFT,
  DIRECTION_RIGHT
};

class Camera{
 public:
  Camera();
  Camera(Vector3f position, Vector3f up, Vector3f target);

  void MoveCamera(Direction direction);
  void RotateCamera(int mouseX, int mouseY);

  const Vector3f& getPosition()const;
  const Vector3f& getUp()const;
  const Vector3f& getTarget()const;
  const float getVerticalAngle()const;
  const float getHorizentalAngle()const;
  void setRightVector3(const Vector3f& right);
  
  Matrix4f GenerateMatrix(bool &outSucceed);
  
 private:
  Vector3f m_position;
  Vector3f m_up;
  Vector3f m_target;
  Vector3f m_right;

  Vector3f m_initUp;
  Vector3f m_initTarget;
  
  int m_lastMouseX;
  int m_lastMouseY;

  float m_verticalAngle;
  float m_horizonAngle;
  
  int m_moveStep;
  float m_rotateScale;
  int m_borderDistance;

  bool m_onBorder;
  bool m_dirty;
};

#endif
