#ifndef _INKSMALLFROG_LIGHT_DIFFUSELIGHTBASE_
#define _INKSMALLFROG_LIGHT_DIFFUSELIGHTBASE_
#include "LightBase.hpp"

class DiffuseLightBase : public Light{
 public:
  DiffuseLightBase();
  DiffuseLightBase(const Vector3f &ambientColor, float diffuseIntensity);
  DiffuseLightBase(const DiffuseLightBase &light);

  virtual void UseLight(const char *lightName) = 0;
  
  void SetDiffuseIntensity(float diffuseIntensity);
  const float GetDiffuseIntensity()const;

 protected:
  float m_diffuseIntensity;
};

#endif
