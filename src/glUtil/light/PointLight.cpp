#include <string>
#include "../../../includes/glUtil/Shader.hpp"
#include "../../../includes/glUtil/light/PointLight.hpp"

PointLight::PointLight() :
    PointLightBase(),
    DiffuseLightBase(){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = 0.0f;
  }
}

PointLight::PointLight(const Vector3f &ambientColor, const Vector3f &position, float diffuseIntensity, const float attenuations[3]) :
    PointLightBase(position),
    DiffuseLightBase(ambientColor, diffuseIntensity){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = attenuations[i];
  }  
}

PointLight::PointLight(const PointLightInfo &lightInfo) :
    PointLightBase(lightInfo.position),
    DiffuseLightBase(lightInfo.ambientColor, lightInfo.diffuseIntensity){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = lightInfo.attenuations[i];
  }
}

PointLight::PointLight(const PointLight &light) :
    PointLightBase(light),
    DiffuseLightBase(light){
  const float *attenuations;
  attenuations = light.GetAttenuations();
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = attenuations[i];
  }
}

void PointLight::SetAttenuation(const float attenuations[3]){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = attenuations[i];
  }
}

const float* PointLight::GetAttenuations()const{
  return m_attenuations;
}

void PointLight::UseLight(const char *lightName){
  std::string lightString = lightName;
  shader->SetUniform3f(lightString + ".ambientColor", m_ambientColor.x, m_ambientColor.y, m_ambientColor.z);
  shader->SetUniform3f(lightString + ".position", m_position.x, m_position.y, m_position.z);
  shader->SetUniform1f(lightString + ".diffuseIntensity", m_diffuseIntensity);
  shader->SetUniform1f(lightString + ".attenuations[0]", m_attenuations[0]);
  shader->SetUniform1f(lightString + ".attenuations[1]", m_attenuations[1]);
  shader->SetUniform1f(lightString + ".attenuations[2]", m_attenuations[2]);
}

