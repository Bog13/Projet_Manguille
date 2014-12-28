#include <Missile.hpp>
#include <TextureLoader.hpp>
#include <cmath>
Missile::Missile(int a,int x,int y): m_angle(a),m_xvel(3),m_yvel(3)
{
  m_rs = RectangleShape(Vector2f(8,8));
  m_rs.setFillColor(Color::Red);
  m_rs.setPosition(Vector2f(x+16,y));
  
}


void Missile::update()
{
  m_rs.move(m_xvel * cos((m_angle*M_PI)/180),-m_yvel * sin((m_angle*M_PI)/180) );
}

void Missile::display(RenderWindow *w)
{
  w->draw(m_rs);
}


Missile::~Missile()
{
}
