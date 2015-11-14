#include "../../../includes/glUtil/light/PointLightBase.hpp"

PointLightBase::PointLightBase() :
    m_position(){
}

PointLightBase::PointLightBase(const Vector3f &position) :
    m_position(position){
}

PointLightBase::PointLightBase(const PointLightBase &light) :
    m_position(light.GetPosition()){
}

PointLightBase::~PointLightBase(){
}

void PointLightBase::SetPosition(float x, float y, float z){
  m_position.x = x;
  m_position.y = y;
  m_position.z = z;
}

void PointLightBase::SetPosition(const Vector3f &position){
  m_position = position;
}

const Vector3f& PointLightBase::GetPosition()const{
  return m_position;
}
