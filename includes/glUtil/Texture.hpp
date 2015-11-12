#ifndef _INKSMALLFROG_TEXTURE_
#define _INKSMALLFROG_TEXTURE_

#include <string>
#include <GL/glut.h>

#include <ImageMagick-6/Magick++.h>

class Texture{
 public:
  Texture(GLenum type, const std::string &fileName);
  ~Texture();

  bool LoadTexture();
  void UseTexture(GLenum textureUnit);

 private:
  const std::string m_textureFileName;

  GLuint m_textureObject;
  GLenum m_textureType;

  Magick::Image *m_image;
  Magick::Blob m_blob;
};

#endif
