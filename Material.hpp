// \file Material.hpp
/// \brief Declaration of Material class and any associated global functions.
/// \author Ryan Ganzke & Christian Shepperson
/// \version A09

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Vector3.hpp"
#include "ShaderProgram.hpp"

class Material
{
public:
    Material (Vector3 ambientReflection, Vector3 diffuseReflection,
        Vector3 specularReflection, Vector3 emissiveIntensity, float shininess);

    ~Material ();

    void
    setAmbientReflection (Vector3 ambientReflection);

    void
    setDiffuseReflection (Vector3 diffuseReflection);

    void
    setSpecularReflection (Vector3 specularReflection);

    void
    setEmissiveIntensity (Vector3 emissiveIntensity);

    void
    setShininess (float shininess);

    Vector3
    getAmbient ();

    Vector3
    getDiffuse ();
    
    Vector3
    getSpecular ();

    Vector3
    getEmissive ();

    float
    getShiny ();

    void
    setUniforms (ShaderProgram* shader);

private:
    Vector3 m_ambient;
    Vector3 m_diffuse;
    Vector3 m_specular;
    Vector3 m_emissive;
    float m_shininess;
};
#endif //MATERIAL_HPP