#ifndef _INKSMALLFROG_MESH_
#define _INKSMALLFROG_MESH_

#include <string>
#include <vector>
#include <GL/glut.h>
#include "../math/Vector.hpp"

class aiScene;
class aiMesh;
class Texture;

class Mesh{
 public:
  Mesh();
  Mesh(const std::string &fileName);
  Mesh(const Mesh &otherMesh);
  ~Mesh();
  
  bool LoadMesh(const std::string &fileName);
  void Render();

 private:
  bool InitFromScene(const aiScene *pScene, const std::string &fileName);
  void InitMesh(const aiMesh * pMesh,
                std::vector<Vector3f> &position,
                std::vector<Vector3f> &normals,
                std::vector<Vector2f> &texcoords,
                std::vector<unsigned int> &indices);
  bool InitMaterials(const aiScene *pScene, const std::string &fileName);
  void Clear();

  struct MeshEntry{
    unsigned int numIndices;
    unsigned int vertex;
    unsigned int index;
    unsigned int materialIndex;
    
    MeshEntry(){
      numIndices = 0;
      vertex = 0;
      index = 0;
      materialIndex = 0;
    }
  };

  GLuint m_VAO;
  GLuint m_Buffers[6];
  std::vector<MeshEntry> m_entries;
  std::vector<Texture*> m_textures;
};

#endif
