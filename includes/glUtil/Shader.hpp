#ifndef _INKSMALLFROG_SHADER_
#define _INKSMALLFROG_SHADER_

#include <vector>
#include <string>
#include <GL/glut.h>

class Shader{
 public:
  Shader();
  ~Shader();

  bool MakeShader(std::vector<std::string> &shaders);
  void UseShader();
  const GLuint GetUniformLocation(const char *variableName)const;
  const bool SetUniform1f(const std::string variableName, float x)const;
  const bool SetUniform3f(const std::string variableName, float x, float y, float z)const;
  const bool SetUniformBlockIndex(const char *blockName, GLuint buffer)const;
  const bool IsShaderLoaded(const std::string &shaderName)const;
  
 private:
  const bool CompileShader(const std::string &fileName);
  int LoadShader(const std::string &fileName, std::string &content);
  GLenum CheckShaderType(const std::string &fileName);
  
  GLuint m_shaderProgram;
  std::vector<std::string> m_loadedShaders;
  std::vector<GLuint> m_bufferShaders;
};

#endif
