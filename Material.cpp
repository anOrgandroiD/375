/// \file Matrix3.hpp
/// \brief Definition of Material class and any associated global functions.
/// \author Ryan Ganzke & Christian Shepperson
/// \version A09

#include <assimp/types.h>
#include <assimp/material.h>

#include "Material.hpp"

Material::Material (Vector3 ambientReflection, Vector3 diffuseReflection,
    Vector3 specularReflection, Vector3 emissiveIntensity, float shininess)
  : m_ambient (ambientReflection), m_diffuse (diffuseReflection),
    m_specular (specularReflection), m_emissive (emissiveIntensity), m_shininess (shininess)
{

}

Material::~Material ()
{

}

void
Material::setAmbientReflection (Vector3 ambientReflection)
{
    m_ambient = ambientReflection;
}

void
Material::setDiffuseReflection (Vector3 diffuseReflection)
{
    m_diffuse = diffuseReflection;
}

void
Material::setSpecularReflection (Vector3 specularReflection)
{
    m_specular = specularReflection;
}

void
Material::setEmissiveIntensity (Vector3 emissiveIntensity)
{
    m_emissive = emissiveIntensity;
}

void
Material::setShininess (float shininess)
{
    m_shininess = shininess;
}

Vector3
Material::getAmbient ()
{
    return m_ambient;
}
 
Vector3
Material::getDiffuse ()
{
    return m_diffuse;
}
    
Vector3
Material::getSpecular ()
{
    return m_specular;
}

Vector3
Material::getEmissive ()
{
    return m_emissive;
}

float
Material::getShiny()
{
    return m_shininess;
}

void
Material::setUniforms (ShaderProgram* shader)
{
  shader->setUniformVector ("uAmbientReflection", m_ambient);
  shader->setUniformVector ("uDiffuseReflection", m_diffuse);
  shader->setUniformVector ("uSpecularReflection", m_specular);
  shader->setUniformFloat ("uSpecularPower", m_shininess);
  shader->setUniformVector ("uEmmissiveIntensity", m_emissive);
}