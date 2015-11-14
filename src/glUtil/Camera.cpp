#include "../../includes/glUtil/Camera.hpp"
#include "../../includes/WindowConfig.hpp"
#include "../../includes/math/Quaternion.hpp"
#include <iostream>

Camera::Camera() :
    m_position(0.0f, 0.0f, 0.0f),
    m_initUp(0.0f, 1.0f, 0.0f),
    m_initTarget(0.0f, 0.0f, 1.0f),
    m_lastMouseX(WINDOW_WIDTH / 2),
    m_lastMouseY(WINDOW_HEIGHT / 2),
    m_moveStep(5),
    m_rotateScale(0.1),
    m_borderDistance(30),
    m_onBorder(false),
    m_dirty(true){
  m_right = m_up.Cross(m_target);
}

Camera::Camera(Vector3f position, Vector3f up, Vector3f target) :
    m_position(position),
    m_initUp(up),
    m_initTarget(target),
    m_lastMouseX(WINDOW_WIDTH / 2),
    m_lastMouseY(WINDOW_HEIGHT / 2),
    m_moveStep(5),
    m_rotateScale(0.05),
    m_borderDistance(60),
    m_onBorder(false),
    m_dirty(true){
  m_up.Normalize();
  m_target.Normalize();
  m_right = m_up.Cross(m_target);
}

void Camera::MoveCamera(Direction direction){
  switch(direction){
    case DIRECTION_UP:
      m_position += m_target * m_moveStep;
      break;

    case DIRECTION_DOWN:
      m_position -= m_target * m_moveStep;
      break;

    case DIRECTION_LEFT:
      m_position -= m_up.Cross(m_target) * m_moveStep;
      break;

    case DIRECTION_RIGHT:
      m_position += m_up.Cross(m_target) * m_moveStep;
      break;

    default:
      break;
  }

  m_dirty = true;
}

void Camera::RotateCamera(int mouseX, int mouseY){
  if(mouseX < m_borderDistance
     || mouseX > WINDOW_WIDTH - m_borderDistance
     || mouseY < m_borderDistance
     || mouseY > WINDOW_HEIGHT - m_borderDistance){
    m_onBorder = true;
  }
  else{
    m_onBorder = false;
  }
  
  m_verticalAngle += (mouseY - m_lastMouseY) * m_rotateScale;
  m_horizonAngle += (mouseX - m_lastMouseX) * m_rotateScale;

  m_lastMouseX = mouseX;
  m_lastMouseY = mouseY;
  
  m_dirty = true;
}

const Vector3f& Camera::GetPosition()const{
  return m_position;
}

const Vector3f& Camera::GetUp()const{
  return m_up;
}

const Vector3f& Camera::GetTarget()const{
  return m_target;
}

const float Camera::GetVerticalAngle()const{
  return m_verticalAngle;
}

const float Camera::GetHorizentalAngle()const{
  return m_horizonAngle;
}

Matrix4f Camera::GenerateMatrix(bool &outSucceed){
  if(m_onBorder == true){
    if(m_lastMouseX < m_borderDistance){
      m_horizonAngle -= 5 * m_rotateScale;
    }
    else if(m_lastMouseX > WINDOW_WIDTH - m_borderDistance){
      m_horizonAngle += 5 * m_rotateScale;
    }
    if(m_lastMouseY < m_borderDistance){
      m_verticalAngle -= 5 * m_rotateScale;
    }
    else if(m_lastMouseY > WINDOW_HEIGHT - m_borderDistance){
      m_verticalAngle += 5 * m_rotateScale;
    }
    m_dirty = true;
  }

  Matrix4f matrix;
  
  if(!m_dirty){
    outSucceed = false;
    return matrix;
  }

  Vector3f m_initRight = m_initUp.Cross(m_initTarget);
  
  Quaternion vAxis;
  vAxis.MakeRotationQuaternion(m_initUp, m_horizonAngle);
  (vAxis * Quaternion(m_initTarget) * vAxis.Inverse()).GetVector3(m_target);
  m_target.Normalize();
  m_initRight = m_initUp.Cross(m_target);
  Quaternion hAxis;
  hAxis.MakeRotationQuaternion(m_initRight, m_verticalAngle);
  (hAxis * Quaternion(m_target) * hAxis.Inverse()).GetVector3(m_target);
  m_target.Normalize();
  m_up = m_target.Cross(m_initRight);
  m_right = m_up.Cross(m_target);

  Matrix4f matrixCameraRotate;
  matrixCameraRotate.MakeCameraRotation(m_right, m_up, m_target);
  Matrix4f matrixCameraTranslation;
  matrixCameraTranslation.MakeTransformationMatrix4f(m_position * -1);

  matrix = matrixCameraRotate * matrixCameraTranslation;
  
  m_dirty = false;
  outSucceed = true;
  
  return matrix;
}
