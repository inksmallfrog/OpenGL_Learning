#include <string>
#include "../../../includes/glUtil/Shader.hpp"
#include "../../../includes/glUtil/light/AmbientLight.hpp"

AmbientLight::AmbientLight() :
    Light::Light(){
}

AmbientLight::AmbientLight(float r, float g, float b) :
    Light::Light(r, g, b){
}

AmbientLight::AmbientLight(const Vector3f &ambientColor) :
    Light::Light(ambientColor){
}

AmbientLight::AmbientLight(const AmbientLight &light) :
    Light::Light(light.GetAmbientColor()){
}

void AmbientLight::UseLight(const char *lightName){
  std::string lightString = lightName;
  shader->SetUniform3f(lightString + ".ambientColor", m_ambientColor.x, m_ambientColor.y, m_ambientColor.z);
}
