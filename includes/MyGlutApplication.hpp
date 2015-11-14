#ifndef _INKSMALLFROG_MYGLUTAPPLICATION_
#define _INKSMALLFROG_MYGLUTAPPLICATION_


class Shader;
class Pipeline;
class Camera;
class Texture;
class Light;
class Vertex;

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
  void CreateLight();
  bool CreateTexture();
  void CreateVertexIndexBuffer();
  void CalculateNormal(Vertex *vertexs, int vNumber, uint *indices, int iNumber);
  
  GLuint VBO;
  GLuint IBO;
  GLuint textureSampler;
  Light *light;
  Light *ambientLight;
  Texture *texture;
  Shader *shader;
  Pipeline *pipeline;
  Camera *camera;
};

#endif
