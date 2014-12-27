#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
using namespace sf;

class Menu: public Scene
{
public:
  Menu();
  ~Menu();

  virtual void update();
  virtual void display(RenderWindow* rw);

private:
  RectangleShape m_bg;
  RectangleShape m_jouer;
};

#endif
