#include <string>
#include "../../../includes/glUtil/Shader.hpp"
#include "../../../includes/glUtil/light/SpotLight.hpp"
#include "../../../includes/math/Math3dUtil.hpp"
SpotLight::SpotLight() :
    DirectionLightBase(),
    PointLightBase(),
    DiffuseLightBase(),
    m_attenuations(),
    m_borderAngle(){
}

SpotLight::SpotLight(const SpotLightInfo &lightInfo) :
    DirectionLightBase(lightInfo.direction),
    PointLightBase(lightInfo.position),
    DiffuseLightBase(lightInfo.ambientColor, lightInfo.diffuseIntensity),
    m_borderAngle(lightInfo.borderAngle){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = lightInfo.attenuations[i];
  }
}

SpotLight::SpotLight(const SpotLight &light) :
    DirectionLightBase(light),
    PointLightBase(light),
    DiffuseLightBase(light),
    m_borderAngle(light.GetBorderAngle()){
  const float *attenuations = light.GetAttenuations();
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = attenuations[i];
  }
}

void SpotLight::SetAttenuations(float attenuations[3]){
  for(int i = 0; i < 3; ++i){
    m_attenuations[i] = attenuations[i];
  }
}

void SpotLight::SetBorderAngle(float borderAngle){
  m_borderAngle = borderAngle;
}

const float* SpotLight::GetAttenuations()const{
  return m_attenuations;
}

const float SpotLight::GetBorderAngle()const{
  return m_borderAngle;
}

void SpotLight::UseLight(const char *lightName){
  m_direction.Normalize();
  float borderCos = cosf(DEGREE_TO_RADIO(m_borderAngle));

  std::string lightString = lightName;
  shader->SetUniform3f(lightString + ".ambientColor", m_ambientColor.x, m_ambientColor.y, m_ambientColor.z);
  shader->SetUniform3f(lightString + ".direction", m_direction.x, m_direction.y, m_direction.z);
  shader->SetUniform3f(lightString + ".position", m_position.x, m_position.y, m_position.z);
  shader->SetUniform1f(lightString + ".diffuseIntensity", m_diffuseIntensity);
  shader->SetUniform1f(lightString + ".attenuations[0]", m_attenuations[0]);
  shader->SetUniform1f(lightString + ".attenuations[1]", m_attenuations[1]);
  shader->SetUniform1f(lightString + ".attenuations[2]", m_attenuations[2]);
  shader->SetUniform1f(lightString + ".borderCos", borderCos);
}

