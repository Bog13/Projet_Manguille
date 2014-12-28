#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
using namespace sf;

class Menu: public Scene
{
public:
  Menu(Game *o);
  virtual ~Menu();

  virtual void update();
  void updateButtons();
  virtual void display(RenderWindow* rw);

private:
  int m_button;
  int m_nbButton;
  int m_timeMin;
  Clock m_clock;
  RectangleShape m_bg;
  RectangleShape m_jouer;
  RectangleShape m_quitter;
};

#endif
