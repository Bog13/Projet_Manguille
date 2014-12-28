#include <Missile.hpp>
#include <TextureLoader.hpp>
#include <cmath>
Missile::Missile(int a,int x,int y): m_angle(a),m_xvel(5),m_yvel(3), m_actif(true)
{
  m_rs = RectangleShape(Vector2f(8,8));
  m_rs.setFillColor(Color::Red);
  m_rs.setPosition(Vector2f(x+16,y));
  
}


void Missile::update()
{
  if(m_actif)
    {
      m_rs.move(m_xvel * cos((m_angle*M_PI)/180),-m_yvel * sin((m_angle*M_PI)/180) );
    }

  if(isOut()) m_actif = false;
}

void Missile::display(RenderWindow *w)
{
  if(m_actif)
    {
      w->draw(m_rs);
    }
}


Missile::~Missile()
{
}
