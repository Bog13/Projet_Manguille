#ifndef PLAYERSHIP_HPP
#define PLAYERSHIP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Ship.hpp>
using namespace sf;

class Controller;

class PlayerShip: public Ship
{
public:
  PlayerShip(BattleScene* o,Controller *c);
  ~PlayerShip();

  virtual void update();
  virtual void updateShoot();
  virtual void shoot();
  virtual void display(RenderWindow *w);

protected:
  Controller *m_controller;
  int m_yvel;
    
};

#endif


