#ifndef _INKSMALLFROG_LIGHT_DIRECTIONLIGHT_
#define _INKSMALLFROG_LIGHT_DIRECTIONLIGHT_

#include "./DirectionLightBase.hpp"
#include "./DiffuseLightBase.hpp"

struct DirectionLightInfo{
  Vector3f ambientColor;
  Vector3f direction;
  float diffuseIntensity;
};

class DirectionLight : public DirectionLightBase, public DiffuseLightBase{
 public:
  DirectionLight();
  DirectionLight(const Vector3f &ambientColor, const Vector3f &direction, float diffuseIntensity);
  DirectionLight(const DirectionLightInfo &lightInfo);
  DirectionLight(const DirectionLight &light);
  virtual ~DirectionLight();
  virtual void UseLight(const char *lightName);
};

#endif
