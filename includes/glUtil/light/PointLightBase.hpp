#ifndef _INKSMALLFROG_LIGHT_POINTLIGHTBASE_
#define _INKSMALLFROG_LIGHT_POINTLIGHTBASE_

#include "./LightBase.hpp"

class PointLightBase{
 public:
  PointLightBase();
  PointLightBase(const Vector3f &position);
  PointLightBase(const PointLightBase &light);
  virtual ~PointLightBase();

  void SetPosition(float x, float y, float z);
  void SetPosition(const Vector3f &position);

  const Vector3f& GetPosition()const;
  
 protected:
  Vector3f m_position;
};

#endif
