#ifndef SHIP_HPP
#define SHIP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace sf;

class BattleScene;

class Ship
{
public:
  Ship(BattleScene* o,int vx, int freq, int acc);
  ~Ship();

  virtual void update()=0;
  virtual void updateLife();
  virtual void updateShoot()=0;
  virtual void shoot();
  virtual void display(RenderWindow *w);

  virtual RectangleShape getRectangleShape(){return m_rs;}
  virtual void hit(int value){m_life -= value;}
protected:
  Clock m_clock;
  int m_w;
  int m_h;
  RectangleShape m_rs;

  RectangleShape m_rlife;
 
  int m_xvel;
  int m_shootFreq;
  int m_accuracy;
  int m_life;
  int m_maxLife;
  BattleScene* m_owner;
};

#endif



