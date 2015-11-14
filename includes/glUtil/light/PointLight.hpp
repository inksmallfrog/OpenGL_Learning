#ifndef _INKSMALLFROG_LIGHT_POINTLIGHT_
#define _INKSMALLFROG_LIGHT_POINTLIGHT_

#include "./PointLightBase.hpp"
#include "./DiffuseLightBase.hpp"

struct PointLightInfo{
  Vector3f ambientColor;
  Vector3f position;
  float diffuseIntensity;
  float attenuations[3];
};

class PointLight : public PointLightBase, public DiffuseLightBase{
 public:
  PointLight();
  PointLight(const Vector3f &ambientColor, const Vector3f &position, float diffuseIntensity, const float attenuations[3]);
  PointLight(const PointLightInfo &lightInfo);
  PointLight(const PointLight &light);
  
  void SetAttenuation(const float attenuations[3]);

  const float* GetAttenuations()const;
  
  virtual void UseLight(const char *lightName);
  
 private:
  float m_attenuations[3];
};

#endif
