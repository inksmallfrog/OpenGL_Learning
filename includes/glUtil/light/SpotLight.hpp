#ifndef _INKSMALLFROG_LIGHT_SPOTLIGHT_
#define _INKSMALLFROG_LIGHT_SPOTLIGHT_

#include "./DirectionLightBase.hpp"
#include "./PointLightBase.hpp"
#include "./DiffuseLightBase.hpp"

struct SpotLightInfo{
  Vector3f ambientColor;
  Vector3f direction;
  Vector3f position;
  float diffuseIntensity;
  float attenuations[3];
  float borderAngle;
};

class SpotLight : public DirectionLightBase, public PointLightBase, public DiffuseLightBase{
 public:
  SpotLight();
  SpotLight(const SpotLightInfo &lightInfo);
  SpotLight(const SpotLight &light);

  void SetAttenuations(float attenuations[3]);
  void SetBorderAngle(float borderAngle);

  const float* GetAttenuations()const;
  const float GetBorderAngle()const;
  
  virtual void UseLight(const char* lightName);
  
 private:
  float m_attenuations[3];
  float m_borderAngle;
};

#endif
