#ifndef _INKSMALLFROG_LIGHT_
#define _INKSMALLFROG_LIGHT_

#include "../math/Vector3.hpp"
#include <GL/glut.h>

class Shader;

class Light{
 public:
  Light();
  virtual void UseLight(const char *lightName) = 0;
  
  virtual void SetAmbient(float r, float g, float b);
  virtual void SetAmbient(const Vector3f &ambient);

 public:
  static Shader *shader;
  
 protected:
  Vector3f m_ambient;
  GLuint m_ambientLocation;
};

class AmbientLight : public Light{
 public:
  AmbientLight();
  AmbientLight(float r, float g, float b);
  AmbientLight(const Vector3f &ambient);
  virtual void UseLihgt(const char *lightName);
};

class DirectionLight : public Light{
 public:
  DirectionLight();
  DirectionLight(const Vector3f &direction, const Vector3f &ambient);
  void SetDirection(float x, float y, float z);
  void SetDirection(const Vector3f &direction);
  virtual void UseLight(const char *lightName);

 private:
  Vector3f m_direction;
};

class PointLight : public Light{
 public:
  PointLight();
  PointLight(const Vector3f &position, const Vector3f &ambient);
  void SetPosition(float x, float y, float z);
  void SetPosition(const Vector3f &position);
  virtual void UseLight();
  
 private:
  Vector3f m_position;
  float attenuation[3];
};

#endif
