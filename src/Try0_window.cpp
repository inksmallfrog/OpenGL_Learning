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
#include "../includes/glUtil/Vertex.hpp"
#include "../includes/util/Release.hpp"


MyGlutApplication::MyGlutApplication(){
}

MyGlutApplication::~MyGlutApplication(){
  SAFE_DELETE(camera);
  SAFE_DELETE(pipeline);
  SAFE_DELETE(shader);
  SAFE_DELETE(texture);

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
  
  CreateShader();
  CreatePipeline();
  CreateTexture();
  CreateVertexBuffer();
  CreateIndexBuffer();

  PCWModel = shader->GetUniformLocation("PCWModel");
  
  glutWarpPointer(400, 300);

  glEnable(GL_CULL_FACE);
  glCullFace(GL_BACK);
  glFrontFace(GL_CCW);

  return true;
}

void MyGlutApplication::Display(){
  glClear(GL_COLOR_BUFFER_BIT);

  glUniformMatrix4fv(PCWModel, 1, GL_TRUE, pipeline->GeneratePCW().m_data[0]);
  
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glEnableVertexAttribArray(0);
  glEnableVertexAttribArray(1);
  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)0);
  texture->UseTexture(GL_TEXTURE0);
  glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (const GLvoid *)12);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
  glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
  glDisableVertexAttribArray(0);
  glDisableVertexAttribArray(1);
    
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
  shaders.push_back("../shader/shader.vs");
  shaders.push_back("../shader/shader.fs");
  return shader->MakeShader(shaders);
}

void MyGlutApplication::CreatePipeline(){
  camera = new Camera;
  pipeline = new Pipeline;
  pipeline->DefaultPipeline(camera);
}

bool MyGlutApplication::CreateTexture(){
  std::string textureFile = "../res/texture/test.jpg";
  texture = new Texture(GL_TEXTURE_2D, textureFile);
  texture->UseTexture(GL_TEXTURE0);
  textureSampler = shader->GetUniformLocation("textureSampler");
  glUniform1i(textureSampler, 0);
  return true;
}

void MyGlutApplication::CreateVertexBuffer(){
  Vertex vertices[4] = {
    Vertex(-10.0f, 0.0f, 50.0f, 0.0f, 0.5f),
    Vertex(0.0f, 0.0f, 70.0f, 0.5f, 1.0f),
    Vertex(10.0f, 0.0f, 50.0f, 1.0f, 0.0f),
    Vertex(0.0f, 10.0f, 60.0f, 0.0f, 0.0f)
  };

  glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

void MyGlutApplication::CreateIndexBuffer(){
  GLuint indices[12] = {
    0, 1, 2,
    1, 0, 3,
    2, 1, 3,
    3, 0, 2
  };

  glGenBuffers(1, &IBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
}

int main(int argc, char **argv){
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
  
  MyGlutApplication app;
  app.Run();

  return 0;
}
