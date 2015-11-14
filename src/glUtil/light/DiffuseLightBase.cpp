#include "../../../includes/glUtil/light/DiffuseLightBase.hpp"

DiffuseLightBase::DiffuseLightBase() :
    m_diffuseIntensity(0.0f),
    Light(){
}

DiffuseLightBase::DiffuseLightBase(const Vector3f &ambientColor, float diffuseIntensity) :
    m_diffuseIntensity(diffuseIntensity),
    Light(ambientColor){
}

DiffuseLightBase::DiffuseLightBase(const DiffuseLightBase &light) :
    m_diffuseIntensity(light.GetDiffuseIntensity()),
    Light(light){  
}

void DiffuseLightBase::SetDiffuseIntensity(float diffuseIntensity){
  m_diffuseIntensity = diffuseIntensity;
}

const float DiffuseLightBase::GetDiffuseIntensity()const{
  return m_diffuseIntensity;
}
