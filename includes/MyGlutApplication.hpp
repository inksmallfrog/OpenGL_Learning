#ifndef _INKSMALLFROG_MYGLUTAPPLICATION_
#define _INKSMALLFROG_MYGLUTAPPLICATION_


class Shader;
class Pipeline;
class Camera;
class Texture;

#include "./glut/IGlutApplication.hpp"
#include <GL/glut.h>

class MyGlutApplication : public IGlutApplication{
 public:
  MyGlutApplication();
  virtual ~MyGlutApplication();

  virtual void Run();

 protected:
  virtual bool Init();
  virtual void Display();
  virtual void IdleDisplay();
  virtual void GetMouseMove(int x, int y);
  virtual void GetMouseButtonState(int button, int state, int x, int y);
  virtual void GetSpecialKeyState(int key, int x, int y);
  virtual void GetKeyState(unsigned char key, int x, int y);

 private:
  void CreateWindow();
  bool CreateShader();
  void CreatePipeline();
  bool CreateTexture();
  void CreateVertexBuffer();
  void CreateIndexBuffer();
  
  GLuint VBO;
  GLuint IBO;
  GLuint PCWModel;
  GLuint textureSampler;
  Texture *texture;
  Shader *shader;
  Pipeline *pipeline;
  Camera *camera;
};

#endif
