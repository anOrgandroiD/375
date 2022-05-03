/// \file SolarScene.cpp
/// \brief Definition of SolarScene class and any associated global functions.
/// \author Ryan Ganzke
/// \version A02

#include "SolarScene.hpp"
#include "ColorsMesh.hpp"
#include "NormalsMesh.hpp"

SolarScene::SolarScene (OpenGLContext* context, ShaderProgram* colorInfo, ShaderProgram* normInfo, ShaderProgram* genInfo, Camera* camera)
  : Scene::Scene (genInfo, camera)
{
  // LIGHT SOURCES
  //this->addPointLightSource (Vector3 (0.0f, 1.0f, 0.0f), Vector3 (0.2f, 0.2f, 0.2f), Vector3 (-1.0f, 0.0f, 0.0f), Vector3 (0.9f, 0.9f, 0.9f));

  this->addSpotLightSource (Vector3 (1.0f, 1.0f, 1.0f), Vector3 (0.9f, 0.9f, 0.9f), Vector3 (0.4f, 0.4f, 1.0f), Vector3 (0.3f, 0.6f, 0.235f), Vector3 (0.0f, 0.0f, -1.0f), 0.5f, 0.5f);
  this->addSpotLightSource (Vector3 (0.0f, 0.0f, 1.0f), Vector3 (0.4f, 0.9f, 0.2f), Vector3 (6.0f, 3.0f, -2.0f), Vector3 (0.7f, 0.8f, 0.2f), Vector3 (-0.1f, -0.7f, 0.1f), 0.5f, 0.5f);
  this->setUniforms ();

  // MATERIALS
  Material* emerald = new Material (Vector3 (0.0215f, 0.1745f, 0.00215f), Vector3 (0.07568f, 0.61424f, 0.07568f),
    Vector3 (0.633f, 0.727811f, 0.633f), Vector3 (0.5f, 0.5f, 0.5f), 0.6f);
  Material* gold = new Material (Vector3 (0.24725f, 0.1995f, 0.0745f), Vector3 (0.75164f, 0.60648f, 0.22648f),
    Vector3 (0.628281f, 0.555802f, 0.366065f), Vector3 (0.5f, 0.5f, 0.5f), 0.4f);
  Material* redRubber = new Material (Vector3 (0.05f, 0.05f, 0.05f), Vector3 (0.5f, 0.4f, 0.4f), Vector3 (0.7f, 0.04f, 0.04f), Vector3 (0.5f, 0.5f, 0.5f), 0.078125f);
  Material* cyanPlas = new Material (Vector3 (0.0f, 0.1f, 0.06f), Vector3 (0.0f, 0.50980392f, 0.50980392f), Vector3 (0.50196078f, 0.50196078f, 0.50196078f), Vector3 (0.5f, 0.5f, 0.5f), 0.25f);
  
  // SUN MESH
  NormalsMesh* sun = new NormalsMesh (context, genInfo, "models/sol.obj", 0, redRubber);

  this->add ("sun", sun);
  this->getMesh ("sun")->scaleWorld (0.04f);
  // this->getMesh ("sun")->moveUp (6.0f);
  this->getMesh ("sun")->scaleLocal (0.60f);
  this->getMesh ("sun")->prepareVao();

  // EARTH MESH
  NormalsMesh* earth = new NormalsMesh (context, genInfo, "models/sol.obj", 0, cyanPlas);

  this->add ("earth", earth);
  this->getMesh ("earth")->scaleWorld (0.04f);
  this->getMesh ("earth")->moveRight (6.0f);
  this->getMesh ("sun")->scaleLocal (0.60f);
  this->getMesh ("earth")->prepareVao();
}