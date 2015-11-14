#include <GL/glew.h>
#include "../../includes/glUtil/Pipeline.hpp"
#include "../../includes/glUtil/Camera.hpp"
#include "../../includes/glUtil/Shader.hpp"

Pipeline::Pipeline(){  
  m_world.dirty = true;
  m_perspective.dirty = true;
  m_PCWdirty = true;
}

void Pipeline::DefaultPipeline(Camera *camera){
  m_camera = camera;
  m_world.scale.x = 1.0f;
  m_world.scale.y = 1.0f;
  m_world.scale.z = 1.0f;
  m_perspective.angle = 90.0f;
  m_perspective.width = 800;
  m_perspective.height = 600;
  m_perspective.zNear = 1;
  m_perspective.zFar = 1000;
}

void Pipeline::SetWorld(const World &world){
  m_world.transfer = world.transfer;
  m_world.rotate = world.rotate;
  m_world.scale = world.scale;
  m_world.dirty = true;
}

void Pipeline::SetWorldTransformation(const Vector3f &transformation){
  m_world.transfer = transformation;
  m_world.dirty = true;
}

void Pipeline::SetWorldRotation(const Vector3f &rotation){
  m_world.rotate = rotation;
  m_world.dirty = true;
}

void Pipeline::SetWorldScalation(const Vector3f &scalation){
  m_world.scale = scalation;
  m_world.dirty = true;
}

const Matrix4f& Pipeline::GenerateWorld(){
  if(m_world.dirty){
    Matrix4f transfer;
    Matrix4f rotate;
    Matrix4f scale;
    
    transfer.MakeTransformationMatrix4f(m_world.transfer);
    rotate.MakeRotationMatrix4f(m_world.rotate);
    scale.MakeScalationMatrix4f(m_world.scale);
    
    m_matrixWorld = transfer * rotate * scale;
    
    m_world.dirty = false;
    m_PCWdirty = true;
  }

  return m_matrixWorld;  
}

void Pipeline::SetCamera(Camera *camera){
  m_camera = camera;
}

const Matrix4f& Pipeline::GenerateCamera(){
  bool succeed;
  Matrix4f cameraMatrix = m_camera->GenerateMatrix(succeed);
  if(succeed){
    m_matrixCamera = cameraMatrix;
    m_PCWdirty = true;
  }

  return m_matrixCamera;
}

void Pipeline::SetPerspective(const Perspective &perspective){
  m_perspective.angle = perspective.angle;
  m_perspective.width = perspective.width;
  m_perspective.height = perspective.height;
  m_perspective.zNear = perspective.zNear;
  m_perspective.zFar = perspective.zFar;
  m_perspective.dirty = true;
}

void Pipeline::SetPerspectiveAngle(float angle){
  m_perspective.angle = angle;
  m_perspective.dirty = true;
}

void Pipeline::SetPerspectiveWidth(float width){
  m_perspective.width = width;
  m_perspective.dirty = true;
}

void Pipeline::SetPerspectiveHeight(float height){
  m_perspective.height = height;
  m_perspective.dirty = true;
}

void Pipeline::SetPerspectiveZnear(float zNear){
  m_perspective.zNear = zNear;
  m_perspective.dirty = true;
}

void Pipeline::SetPerspectiveZfar(float zFar){
  m_perspective.zFar = zFar;
  m_perspective.dirty = true;
}

const Matrix4f& Pipeline::GeneratePerspective(){
  if(m_perspective.dirty){
    m_matrixPerspective.MakePerspectiveMatrix4f(m_perspective.angle, m_perspective.width, m_perspective.height, m_perspective.zNear, m_perspective.zFar);
    
    m_perspective.dirty = false;
    m_PCWdirty = true;
  }

  return m_matrixPerspective;
}

const Matrix4f Pipeline::UsePCW(){
  GeneratePerspective();
  GenerateCamera();
  GenerateWorld();
  if(m_PCWdirty){
    m_PCWModel = m_matrixPerspective * m_matrixCamera * m_matrixWorld;
    glUniformMatrix4fv(m_PipelineModelLocation, 1, GL_TRUE, m_PCWModel.m_data[0]);
    SetUniformWorld();
    SetUniformCameraPosition();
  }
  return m_PCWModel;
}

const Matrix4f Pipeline::UsePW(){
  GeneratePerspective();
  GenerateWorld();
  return m_matrixPerspective * m_matrixWorld;
}

const Matrix4f Pipeline::UseCW(){
  GenerateCamera();
  GenerateWorld();
  return m_matrixCamera * m_matrixWorld;
}

const Matrix4f Pipeline::UsePC(){
  GeneratePerspective();
  GenerateCamera();
  return m_matrixPerspective * m_matrixCamera;
}

void Pipeline::SetUniformWorld(){
  glUniformMatrix4fv(m_WorldLocation, 1, GL_TRUE, m_matrixWorld.m_data[0]);
}

void Pipeline::SetUniformCameraPosition(){
  Vector3f position = m_camera->GetPosition();
  glUniform3f(m_CameraPositionLocation, position.x, position.y, position.z);
}

void Pipeline::SetShader(const Shader *shader){
  m_shader = shader;
  m_PipelineModelLocation = m_shader->GetUniformLocation("pipelineModel");
  m_WorldLocation = m_shader->GetUniformLocation("worldModel");
  m_CameraPositionLocation = m_shader->GetUniformLocation("cameraPosition");
}
