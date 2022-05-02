// \file Material.hpp
/// \brief Declaration of Material class and any associated global functions.
/// \author Ryan Ganzke & Christian Shepperson
/// \version A09

#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include "Vector3.hpp"

class Material
{
public:
    Material (Vector3 ambientReflection, Vector3 diffuseReflection,
        Vector3 specularReflection, float shininess);

    ~Material ();

    void
    setUniforms ();

    void
    setAmbientReflection (Vector3 ambientReflection);

    void
    setDiffuseReflection (Vector3 diffuseReflection);

    void
    setSpecularReflection (Vector3 specularReflection);

    void
    setShininess (float shininess);

    Vector3
    getAmbient();

    Vector3
    getDiffuse();
    
    Vector3
    getSpecular();

    float
    getShiny();

private:
    Vector3 m_ambient;
    Vector3 m_diffuse;
    Vector3 m_specular;
    float m_shininess;
}
#endif //MATERIAL_HPP