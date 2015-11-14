#ifndef _INKSMALLFROG_LIGHT_AMBIENTLIGHT_
#define _INKSMALLFROG_LIGHT_AMBIENTLIGHT_

#include "./LightBase.hpp"

class AmbientLight : public Light{
 public:
  AmbientLight();
  AmbientLight(float r, float g, float b);
  AmbientLight(const Vector3f &ambientColor);
  AmbientLight(const AmbientLight &light);
  
  virtual void UseLight(const char *lightName);
};

#endif
