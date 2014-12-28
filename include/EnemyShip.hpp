#ifndef ENEMYSHIP_HPP
#define ENEMYSHIP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Ship.hpp>
using namespace sf;



class EnemyShip: public Ship
{
public:
  EnemyShip(int vx, int freq, int acc);
  ~EnemyShip();

  void update();
  void updateShoot();

  void display(RenderWindow *w);
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



