#include <string>
#include "../../../includes/glUtil/Shader.hpp"
#include "../../../includes/glUtil/light/DirectionLight.hpp"

DirectionLight::DirectionLight() :
    DirectionLightBase(),
    DiffuseLightBase(){  
}

DirectionLight::DirectionLight(const Vector3f &ambientColor, const Vector3f &direction, float diffuseIntensity) :
    DirectionLightBase(direction),
    DiffuseLightBase(ambientColor, diffuseIntensity){
}

DirectionLight::DirectionLight(const DirectionLightInfo &lightInfo) :
    DirectionLightBase(lightInfo.direction),
    DiffuseLightBase(lightInfo.ambientColor, lightInfo.diffuseIntensity){
}

DirectionLight::DirectionLight(const DirectionLight &light) :
    DirectionLightBase(light),
    DiffuseLightBase(light){
}

DirectionLight::~DirectionLight(){
}

void DirectionLight::UseLight(const char *lightName){
  m_direction.Normalize();
  std::string lightString = lightName;
  shader->SetUniform3f(lightString + ".ambientColor", m_ambientColor.x, m_ambientColor.y, m_ambientColor.z);
  shader->SetUniform3f(lightString + ".direction", m_direction.x, m_direction.y, m_direction.z);
  shader->SetUniform1f(lightString + ".diffuseIntensity", m_diffuseIntensity);
}

