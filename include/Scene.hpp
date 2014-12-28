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
  Scene(Game *o,int i,int m);
  virtual ~Scene();

  virtual void update() = 0;
  virtual void display(RenderWindow* rw) = 0;

  int getImg(){return m_img;}
  int getMusic(){return m_music;}
protected:
  Controller *m_controller;
  Game *m_owner;
  int m_music;
  int m_img;
};

#endif
