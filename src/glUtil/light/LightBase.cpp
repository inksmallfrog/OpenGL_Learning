#include "../../../includes/glUtil/light/LightBase.hpp"

Shader* Light::shader = NULL;

void Light::SetCurrentShader(Shader *shader){
  Light::shader = shader;
}

Light::Light() :
    m_ambientColor(){
}

Light::Light(float r, float g, float b) :
    m_ambientColor(r, g, b){
}

Light::Light(const Vector3f &ambient) :
    m_ambientColor(ambient){
}

Light::Light(const Light &light) :
    m_ambientColor(light.GetAmbientColor()){
}

Light::~Light(){
}

void Light::SetAmbientColor(float r, float g, float b){
  m_ambientColor.x = r;
  m_ambientColor.y = g;
  m_ambientColor.z = b;
}

void Light::SetAmbientColor(const Vector3f &ambient){
  m_ambientColor = ambient;
}

const Vector3f& Light::GetAmbientColor()const{
  return m_ambientColor;
}

