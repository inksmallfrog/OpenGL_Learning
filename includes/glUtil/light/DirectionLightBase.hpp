#ifndef _INKSMALLFROG_LIGHT_DIRECTIONLIGHTBASE_
#define _INKSMALLFROG_LIGHT_DIRECTIONLIGHTBASE_

#include "LightBase.hpp"

class DirectionLightBase{
 public:
  DirectionLightBase();
  DirectionLightBase(const Vector3f &direction);
  DirectionLightBase(const DirectionLightBase &light);
  virtual ~DirectionLightBase();

  void SetDirection(float x, float y, float z);
  void SetDirection(const Vector3f &direction);

  const Vector3f& GetDirection()const;

 protected:
  Vector3f m_direction;
};

#endif
