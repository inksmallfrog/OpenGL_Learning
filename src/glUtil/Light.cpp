#include "../../includes/glUtil/Light.hpp"
#include "../../includes/glUtil/Shader.hpp"

Shader* Light::shader = NULL;

Light::Light() :
    m_ambient(),
    m_light(GL_INVALID_VALUE){
}

void Light::SetAmbient(float r, float g, float b){
  m_ambient.x = r;
  m_ambient.y = g;
  m_ambient.z = b;
}

void Light::SetAmbient(const Vector3f &ambient){
  m_ambient = ambient;
}

AmbientLight::AmbientLight() :
    Light(){
}

AmbientLight::AmbientLight(float r, float g, float b){
  m_ambient.x = r;
  m_ambient.y = g;
  m_ambient.z = b;
}

AmbientLight::AmbientLight(const Vector3f &ambient){
  m_ambient = ambient;
}

void AmbientLight::UseLihgt(const char *lightName){
  std::string lightAmbient = lightName
}
