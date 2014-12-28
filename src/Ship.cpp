#include <Ship.hpp>
#include <TextureLoader.hpp>
#include <Missile.hpp>
#include <Game.hpp>

Ship::Ship(int vx, int freq, int acc)
{

  m_xvel = vx ;m_shootFreq = freq ; m_w = 64 ; m_h = 32 ; m_accuracy = acc ; m_life = 100 ; m_maxLife = 100 ;

  m_rs = RectangleShape(Vector2f(m_w,m_h));
  m_rs.setTexture( TextureLoader::instance()->get(I_SHIP_1) );
  m_rs.setPosition(Vector2f(WIDTH+m_rs.getLocalBounds().width,Game::random(0,HEIGHT - m_rs.getLocalBounds().height)));


  m_rlife = RectangleShape(Vector2f(m_w,m_h/4));
  m_rlife.setFillColor(Color::Red);


  m_clock.restart();
}


void Ship::updateLife()
{
  m_rlife = RectangleShape(Vector2f((m_life*m_w)/m_maxLife,m_h/4));
  m_rlife.setPosition(Vector2f(m_rs.getPosition().x,m_rs.getPosition().y + m_h));
  m_rlife.setFillColor(Color(255-m_life,0,0));
}


void Ship::shoot()
{
  m_missiles.push_back(new Missile(180+Game::random(-m_accuracy,m_accuracy),m_rs.getPosition().x,m_rs.getPosition().y));
}


void Ship::updateMissiles()
{
  for(int i = 0 ; i<m_missiles.size(); i++)
    {

      if(!m_missiles[i]->isOut()) 
	{
	  m_missiles[i]->update();
	}
    }
}



void Ship::display(RenderWindow *w)
{
  w->draw(m_rs);

  for(Missile* m: m_missiles)
    {
      m->display(w);
    }

  w->draw(m_rlife);
}


Ship::~Ship()
{
  for(Missile* m: m_missiles)
    {
      delete m;
    }
}
