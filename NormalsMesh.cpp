/// \file NormalsMesh.cpp
/// \brief Definition of NormalsMesh class and any associated global functions.
/// \author Ryan Ganzke
/// \version A08

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Mesh.hpp"
#include "NormalsMesh.hpp"

NormalsMesh::NormalsMesh (OpenGLContext* context, ShaderProgram* shader)
  : Mesh (context, shader)
{

}

NormalsMesh::NormalsMesh (OpenGLContext* context, ShaderProgram* shader, std::string filename, unsigned int meshNum)
  : Mesh (context, shader)
{
  Assimp::Importer importer;
  unsigned int flags =
    aiProcess_Triangulate              // convert all shapes to triangles
    | aiProcess_GenSmoothNormals       // create vertex normals if not there
    | aiProcess_JoinIdenticalVertices; // combine vertices for indexing
  const aiScene* scene = importer.ReadFile (filename,
					    flags);
  if (scene == nullptr)
  {
    auto error = importer.GetErrorString ();
    std::cerr << "Failed to load model " << filename << " with error " << error << std::endl;
  }
  else
  {
    if(meshNum >= scene->mNumMeshes)
    {
      std::cerr << "Could not read mesh " << meshNum << " from " << filename << " because it only has " << scene->mNumMeshes << " meshes." << std::endl;
    }
    else
    {
      const aiMesh* mesh = scene->mMeshes[meshNum];
      std::vector<float> vertexData;
      std::vector<unsigned int> indexes;
      for (unsigned vertexNum = 0; vertexNum < mesh->mNumVertices; ++vertexNum)
      {
	vertexData.push_back (mesh->mVertices[vertexNum].x);
	vertexData.push_back (mesh->mVertices[vertexNum].y);
	vertexData.push_back (mesh->mVertices[vertexNum].z);
	vertexData.push_back (mesh->mNormals[vertexNum].x);
	vertexData.push_back (mesh->mNormals[vertexNum].y);
	vertexData.push_back (mesh->mNormals[vertexNum].z);
      }
      for (unsigned int faceNum = 0; faceNum < mesh->mNumFaces; ++faceNum)
      {
	const aiFace& face = mesh->mFaces[faceNum];
	for (unsigned int indexNum = 0; indexNum < 3; ++indexNum)
	{
	  unsigned int vertexNum = face.mIndices[indexNum];
	  indexes.push_back (vertexNum);
	}
      }
      addGeometry (vertexData);
      addIndices (indexes);
    }
  }
}

unsigned int
NormalsMesh::getFloatsPerVertex () const
{
    return 2 * Mesh::getFloatsPerVertex ();
}

void
NormalsMesh::enableAttributes ()
{

    const GLint NORM_ATTRIB_INDEX = 2;
    
    m_context->enableVertexAttribArray (NORM_ATTRIB_INDEX);
    m_context->vertexAttribPointer (NORM_ATTRIB_INDEX, 3, GL_FLOAT, GL_FALSE,
            (6 * sizeof(float)), reinterpret_cast<void*> (3 * sizeof(float)));
    
    Mesh::enableAttributes ();
}