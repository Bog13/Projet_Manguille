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

  void update();
  void display(RenderWindow* rw);

private:
};

#endif
