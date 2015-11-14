#ifndef _INKSMALLFROG_PIPELINE_
#define _INKSMALLFROG_PIPELINE_

#include "../math/Vector3.hpp"
#include "../math/Matrix4.hpp"
#include <GL/glut.h>
class Camera;
class Shader;

struct World{
  Vector3f transfer;
  Vector3f rotate;
  Vector3f scale;
  bool dirty;
};

struct Perspective{
  float angle;
  float width;
  float height;
  float zNear;
  float zFar;
  bool dirty;
};

class Pipeline{
 public:
  Pipeline();

  void DefaultPipeline(Camera *camera);

  void SetWorld(const World& world);
  void SetWorldTransformation(const Vector3f& transformation);
  void SetWorldRotation(const Vector3f& rotation);
  void SetWorldScalation(const Vector3f& scalation);
  const Matrix4f& GenerateWorld();

  void SetCamera(Camera *camera);
  const Matrix4f& GenerateCamera();
  
  void SetPerspective(const Perspective& perspective);
  void SetPerspectiveAngle(float angle);
  void SetPerspectiveWidth(float width);
  void SetPerspectiveHeight(float height);
  void SetPerspectiveZnear(float zNear);
  void SetPerspectiveZfar(float zFar);
  const Matrix4f& GeneratePerspective();

  const Matrix4f UsePCW();
  const Matrix4f UsePW();
  const Matrix4f UseCW();
  const Matrix4f UsePC();

  void SetUniformWorld();
  void SetUniformCameraPosition();

  void SetShader(const Shader *shader);
  
 private:
  Matrix4f m_PCWModel;
  bool m_PCWdirty;
  GLuint m_PipelineModelLocation;
  
  World m_world;
  Matrix4f m_matrixWorld;
  GLuint m_WorldLocation;
  
  Camera *m_camera;
  Matrix4f m_matrixCamera;
  GLuint m_CameraPositionLocation;
  
  Perspective m_perspective;
  Matrix4f m_matrixPerspective;

  const Shader* m_shader;
};

#endif
