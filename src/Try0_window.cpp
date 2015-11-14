#include <GL/glew.h>
#include <ImageMagick-6/Magick++.h>
#include <string>
#include <vector>
#include <iostream>
#include "../includes/MyGlutApplication.hpp"
#include "../includes/glUtil/Shader.hpp"
#include "../includes/glUtil/Pipeline.hpp"
#include "../includes/glUtil/Camera.hpp"
#include "../includes/glUtil/Texture.hpp"
#include "../includes/glUtil/Light.hpp"
#include "../includes/glUtil/Vertex.hpp"
#include "../includes/util/Release.hpp"


MyGlutApplication::MyGlutApplication(){
}

MyGlutApplication::~MyGlutApplication(){
  SAFE_DELETE(camera);
  SAFE_DELETE(pipeline);
  SAFE_DELETE(shader);
  SAFE_DELETE(texture);
  SAFE_DELETE(light);
  SAFE_DELETE(ambientLight);

  glDeleteBuffers(1, &IBO);
  glDeleteBuffers(1, &VBO);
}

void MyGlutApplication::Run(){
  IGlutApplication::Run();
}

bool MyGlutApplication::Init(){
  CreateWindow();

  GLenum res = glewInit();
  if(res != GLEW_OK){
    std::cout << "Can't init glew! error: " << glewGetErrorString(res) << std::endl;
    exit(0);
  }
  
  if(!CreateShader()){
    return false;
  }
  CreatePipeline();
  CreateLight();
  CreateTexture();
  CreateVertexIndexBuffer();

  glutWarpPointer(400, 300);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);

  return true;
}

void MyGlutApplication::Display(){
  glClear(GL_COLOR_BUFFER_BIT);

  pipeline->UsePCW();
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glEnableVertexAttribArray(2);
  glEnableVertexAttribArray(3);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)0);
  texture->UseTexture(GL_TEXTURE0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)12);
  glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)20);
  glVertexAttribPointer(3, 1, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid*)32);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
  glDisableVertexAttribArray(2);
  glDisableVertexAttribArray(3);
    
  glutSwapBuffers();
}

void MyGlutApplication::IdleDisplay(){
  Display();
}

void MyGlutApplication::GetMouseMove(int x, int y){
  camera->RotateCamera(x, y);
}

void MyGlutApplication::GetMouseButtonState(int button, int state, int x, int y){
  
}

void MyGlutApplication::GetSpecialKeyState(int key, int x, int y){
  switch(key){
    case GLUT_KEY_UP:
      camera->MoveCamera(DIRECTION_UP);
      break;

    case GLUT_KEY_DOWN:
      camera->MoveCamera(DIRECTION_DOWN);
      break;

    case GLUT_KEY_LEFT:
      camera->MoveCamera(DIRECTION_LEFT);
      break;

    case GLUT_KEY_RIGHT:
      camera->MoveCamera(DIRECTION_RIGHT);
      break;

    default:
      break;
  }
}

void MyGlutApplication::GetKeyState(unsigned char key, int x, int y){
  
}

void MyGlutApplication::CreateWindow(){
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(800, 600);
  glutCreateWindow("GLUT_FRAME");
}

bool MyGlutApplication::CreateShader(){
  shader = new Shader;
  std::vector<std::string> shaders;
  shaders.push_back("../shader/shader.vert");
  shaders.push_back("../shader/shader.frag");
  return shader->MakeShader(shaders);
}

void MyGlutApplication::CreatePipeline(){
  camera = new Camera;
  pipeline = new Pipeline;
  pipeline->DefaultPipeline(camera);
  pipeline->SetShader(shader);
}

void MyGlutApplication::CreateLight(){
  Light::SetCurrentShader(shader);

  float attenuation[] = {
    1.0f,
    0.001f,
    0.0002f
  };

  SpotLightInfo lightInfo = {
    Vector3f(0.8f, 0.8f, 0.8f),
    Vector3f(0.0f, 0.0f, 1.0f),
    Vector3f(0.0f, 0.0f, 0.0f),
    1.0f,
    {1.0f, 0.0f, 0.0f},
    20.0f
  };
  
  light = new SpotLight(lightInfo);
  light->UseLight("spotLight");

  ambientLight = new AmbientLight(Vector3f(0.4f, 0.4f, 0.4f));
  ambientLight->UseLight("ambientLight");
}

bool MyGlutApplication::CreateTexture(){
  std::string textureFile = "../res/texture/test.jpg";
  texture = new Texture(GL_TEXTURE_2D, textureFile);
  texture->UseTexture(GL_TEXTURE0);
  textureSampler = shader->GetUniformLocation("textureSampler");
  glUniform1i(textureSampler, 0);
  return true;
}

void MyGlutApplication::CreateVertexIndexBuffer(){
  Vertex vertices[4] = {
    Vertex(Vector3f(-90.0f, -50.0f, 50.0f),
           Vector2f(0.0f, 1.0f),
           Vector3f(),
           0.0f),
    Vertex(Vector3f(90.0f, -50.0f, 50.0f),
           Vector2f(1.0f, 1.0f),
           Vector3f(),
           0.0f),
    Vertex(Vector3f(90.0f, 50.0f, 50.0f),
           Vector2f(1.0f, 0.0f),
           Vector3f(),
           0.0f),
    Vertex(Vector3f(-90.0f, 50.0f, 50.0f),
           Vector2f(0.0f, 0.0f),
           Vector3f(),
           0.0f),
  };
  GLuint indices[] = {
    0, 1, 3,
    3, 1, 2
  };
  CalculateNormal(vertices, sizeof(vertices) / sizeof(vertices[0]), indices, sizeof(indices) / sizeof(indices[0]));
  
  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glGenBuffers(1, &IBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

void MyGlutApplication::CalculateNormal(Vertex *vertexs, int vNumber, uint *indices, int iNumber){
  for(int i = 0; i < iNumber; i += 3){
    Vector3f p[3] = {
      vertexs[indices[i]].GetPosition(),
      vertexs[indices[i + 1]].GetPosition(),
      vertexs[indices[i + 2]].GetPosition()
    };
    Vector3f n[3] = {
      vertexs[indices[i]].GetNormal(),
      vertexs[indices[i + 1]].GetNormal(),
      vertexs[indices[i + 2]].GetNormal()
    };

    Vector3f normal = (p[1] - p[2]).Cross(p[0] - p[1]);

    for(int j = 0; j < 3; ++j){
      vertexs[indices[i + j]].SetNormal(n[j] + normal);
    }
  }

  for(int i = 0; i < vNumber; ++i){
    vertexs[i].NormalizeNormal();
  }
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  
  MyGlutApplication app;
  app.Run();

  return 0;
}
