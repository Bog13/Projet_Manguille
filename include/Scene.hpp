#ifndef SCENE_HPP
#define SCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Game;
class Controller;

class Scene
{
public:
  Scene(Game *o);
  virtual ~Scene();

  virtual void update() = 0;
  virtual void display(RenderWindow* rw) = 0;

protected:
  Controller *m_controller;
  Game *m_owner;
};

#endif
