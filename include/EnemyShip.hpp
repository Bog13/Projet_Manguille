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
  EnemyShip(BattleScene* o,int px, int vx, int freq, int acc);
  ~EnemyShip();

  virtual void update();
  virtual void updateShoot();

  virtual void display(RenderWindow *w);
protected:
  
 
    
};

#endif



