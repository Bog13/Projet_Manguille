#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class Missile;

class Ship
{
public:
  Ship(int vx, int freq, int acc);
  ~Ship();

  virtual void update()=0;
  virtual void updateLife();
  virtual void updateShoot()=0;
  virtual void updateMissiles();
  virtual void shoot();
  virtual void display(RenderWindow *w);

protected:
  Clock m_clock;
  int m_w;
  int m_h;
  RectangleShape m_rs;

  RectangleShape m_rlife;
 
  std::vector<Missile*> m_missiles;
  int m_xvel;
  int m_shootFreq;
  int m_accuracy;
  int m_life;
  int m_maxLife;
};

#endif



