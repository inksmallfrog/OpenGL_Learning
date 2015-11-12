#include <ImageMagick-6/Magick++.h>
#include <iostream>
#include "../../includes/glUtil/Texture.hpp"


Texture::Texture(GLenum type, const std::string &fileName) :
    m_textureFileName(fileName),
    m_textureType(type){
  LoadTexture();
}

Texture::~Texture(){
}

bool Texture::LoadTexture(){
    m_image = new Magick::Image(m_textureFileName);
    if(NULL == m_image){
      std::cout << "Can't load image " << m_textureFileName << std::endl;
      return false;
    }
    m_image->write(&m_blob, "RGBA");
    
    glGenTextures(1, &m_textureObject);
    glBindTexture(m_textureType, m_textureObject);
    glTexImage2D(m_textureType, 0, GL_RGBA, m_image->columns(), m_image->rows(), 0, GL_RGBA, GL_UNSIGNED_BYTE, m_blob.data());

    glTexParameterf(m_textureType, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(m_textureType, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    return true;
}

void Texture::UseTexture(GLenum textureUnit){
  glActiveTexture(textureUnit);
  glBindTexture(m_textureType, m_textureObject);
}
