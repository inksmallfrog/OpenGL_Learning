#ifndef _INKSMALLFROG_LIGHT_LIGHTBASE_
#define _INKSMALLFROG_LIGHT_LIGHTBASE_

#include "../../math/Vector3.hpp"
#include <GL/glut.h>

class Shader;

class Light{
 public:
  static Shader *shader;
  static void SetCurrentShader(Shader *shader);

 public:
  Light();
  Light(float r, float g, float b);
  Light(const Vector3f &ambientColor);
  Light(const Light &light);
  virtual ~Light();
  virtual void UseLight(const char *lightName) = 0;
  
  void SetAmbientColor(float r, float g, float b);
  void SetAmbientColor(const Vector3f &ambientColor);

  const Vector3f& GetAmbientColor()const;
  
 protected:
  Vector3f m_ambientColor;
};

#endif
