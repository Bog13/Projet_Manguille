#ifndef BOSSSHIP_HPP
#define BOSSSHIP_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <Ship.hpp>
using namespace sf;



class BossShip: public Ship
{
public:
  BossShip(BattleScene* o, Ship* op,int vx, int freq, int acc,int img);
  ~BossShip();

  virtual void update();
  virtual void updateShoot();

  virtual void display(RenderWindow *w);
protected:
  Ship* m_opponent;
 
    
};

#endif
