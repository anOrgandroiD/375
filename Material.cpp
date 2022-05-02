/// \file Matrix3.hpp
/// \brief Definition of Material class and any associated global functions.
/// \author Ryan Ganzke & Christian Shepperson
/// \version A09

#include "Material.hpp"

Material::Material (Vector3 ambientReflection, Vector3 diffuseReflection,
    Vector3 specularReflection, float shininess)
  : m_ambient (ambientReflection), m_diffuse (diffuseReflection),
    m_specular (specularReflection), m_shininess (shininess)
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
Material::setShininess (float shininess)
{
    m_shininess = shininess;
}

Vector3
Material::getAmbient(){
    return m_ambient;
 }
 
Vector3
Material::getDiffuse(){
    return m_diffuse;
}
    
Vector3
Material::getSpecular(){
    return m_specular;
}

float
Material::getShiny(){
    return m_shininess;
 }