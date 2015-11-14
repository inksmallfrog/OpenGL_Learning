#include "../../../includes/glUtil/light/DirectionLightBase.hpp"

DirectionLightBase::DirectionLightBase() :
    m_direction(){
}

DirectionLightBase::DirectionLightBase(const Vector3f &direction) :
    m_direction(direction){
}

DirectionLightBase::DirectionLightBase(const DirectionLightBase &light) :
    m_direction(light.GetDirection()){
}

DirectionLightBase::~DirectionLightBase(){
}

void DirectionLightBase::SetDirection(float x, float y, float z){
  m_direction.x = x;
  m_direction.y = y;
  m_direction.z = z;
}

void DirectionLightBase::SetDirection(const Vector3f &direction){
  m_direction = direction;
}

const Vector3f& DirectionLightBase::GetDirection()const{
  return m_direction;
}
