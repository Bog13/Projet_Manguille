#ifndef SCENE_HPP
#define SCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Scene
{
public:
  Scene();
  ~Scene();

  virtual void update() = 0;
  virtual void display(RenderWindow* rw) = 0;

private:
};

#endif
