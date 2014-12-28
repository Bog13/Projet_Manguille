#ifndef MISSILE_HPP
#define MISSILE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <global.hpp>
using namespace sf;

class Missile
{
public:
  Missile(int a,int x,int y);
  ~Missile();

  void update();
  void display(RenderWindow *w);

  bool isOut()
  {
    int x = m_rs.getPosition().x;
    int y = m_rs.getPosition().y;
    int w = m_rs.getGlobalBounds().width;
    int h = m_rs.getGlobalBounds().height;

    return (x + w < 0 || x  > WIDTH || y + h < 0 || y  > HEIGHT);
  }
							      
							      
protected:
  RectangleShape m_rs;
  int m_angle;
  int m_xvel;
  int m_yvel;
};

#endif
