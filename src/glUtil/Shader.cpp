#include <GL/glew.h>
#include <assert.h>
#include <iostream>
#include <fstream>
#include "../../includes/glUtil/Shader.hpp"

Shader::Shader(){
  m_shaderProgram = glCreateProgram();
}

Shader::~Shader(){
  std::vector<GLuint>::iterator it = m_bufferShaders.begin();
  for(;it != m_bufferShaders.end(); ++it){
    glDeleteShader(*it);
  }
  glDeleteProgram(m_shaderProgram);
}

bool Shader::MakeShader(std::vector<std::string> &shaders){
  assert(m_shaderProgram != 0);

  std::vector<std::string>::iterator it = shaders.begin();
  for(;it != shaders.end(); ++it){
    if(!CompileShader(*it)){
      return false;
    }
    m_loadedShaders.push_back(*it);
  }

  int res;
  char error[1024];
  
  glLinkProgram(m_shaderProgram);
  glGetProgramiv(m_shaderProgram, GL_LINK_STATUS, &res);
  if(res == 0){
    glGetProgramInfoLog(m_shaderProgram, 1024, 0, error);
    std::cout << "Link shader program failed! error: " << error << std::endl;
    return false;
  }

  glValidateProgram(m_shaderProgram);
  glGetProgramiv(m_shaderProgram, GL_VALIDATE_STATUS, &res);
  if(res == 0){
    glGetProgramInfoLog(m_shaderProgram, 1024, 0, error);
    std::cout << "Validate shader program failed! error: " << error << std::endl;
    return false;
  }

  glUseProgram(m_shaderProgram);
  return true;
}

void Shader::UseShader(){
  assert(m_shaderProgram != 0);
  glUseProgram(m_shaderProgram);
}

GLuint Shader::GetUniformLocation(const char* variableName){
  return glGetUniformLocation(m_shaderProgram, variableName);
}

/*GLuint Shader::GetUniformBlockLocation(const char* blockName){
  return glGetUniformBlockIndex(m_shaderProgram, blockName);
  }*/

bool Shader::IsShaderLoaded(const std::string &shaderName){
  //  return m_loadedShaders.
  return true;
}

bool Shader::CompileShader(const std::string &fileName){
  GLenum type = CheckShaderType(fileName);
  assert(type != GL_ZERO);
  GLuint shader = glCreateShader(type);

  std::string content;
  int length;
  length = LoadShader(fileName, content);
  if(0 == length){
    std::cout << "Load shader " << fileName << " failed! " << std::endl;
    return false;
  }

  const char *contents[1] = {
    content.c_str()
  };
  int lengths[1] = {
    length
  };
    
  glShaderSource(shader, 1, contents, lengths);
  glCompileShader(shader);  
  int res;
  char error[1024];
  glGetShaderiv(shader, GL_COMPILE_STATUS, &res);
  if(res == 0){
    glGetShaderInfoLog(shader, 1024, 0, error);
    std::cout << "Compile shader " << fileName << " failed! error: " << error << std::endl;
    return false;
  }

  glAttachShader(m_shaderProgram, shader);
  m_bufferShaders.push_back(shader);
  return true;
}

int Shader::LoadShader(const std::string &fileName, std::string &content){
  std::ifstream reader(fileName.c_str());
  if(!reader.is_open()){
    std::cout << "Can't open file " << fileName << "!" << std::endl;
    return 0;
  }

  char buffer[1024];
  while(!reader.eof()){
    reader.getline(buffer, 1024);
    content.append(buffer);
    content.append("\n");
  }

  return content.length();
}

GLenum Shader::CheckShaderType(const std::string &fileName){
  if(fileName.find(".vs") != -1){
    return GL_VERTEX_SHADER;
  }

  if(fileName.find(".fs") != -1){
    return GL_FRAGMENT_SHADER;
  }

  return GL_ZERO;
}
