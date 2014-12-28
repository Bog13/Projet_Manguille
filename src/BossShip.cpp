#include <BossShip.hpp>
#include <TextureLoader.hpp>
#include <Missile.hpp>
#include <Game.hpp>
#include <Ship.hpp>
#include <BattleScene.hpp>

BossShip::BossShip(BattleScene* o,Ship* op,int vx, int freq, int acc,int img): Ship(o,vx,freq,acc),
									       m_opponent(op)
{
  m_maxLife = 500;
  m_life = m_maxLife;
  m_name = "bossship";
  m_rs.setTexture(TextureLoader::instance()->get(img));
}



void BossShip::updateShoot()
{
  if(m_clock.getElapsedTime().asMilliseconds() > m_shootFreq)
    {
      shoot();
      m_clock.restart();
    }
}


void BossShip::update()
{
 
  if(m_life > 0)
    {
      updateShoot();
      
      if(m_rs.getPosition().x > WIDTH/2 )
	{
	  m_rs.move(-m_xvel,0);
	}
     
	
      if(m_opponent->getRectangleShape().getPosition().y > m_rs.getPosition().y)
	{
	  m_rs.move(0,m_xvel);
	}
      else 
	{
	  m_rs.move(0,-m_xvel);
	}
	
    }
  else
    {
      m_rs.move(-m_xvel/2,m_xvel);
      m_rs.rotate(0.2);
    }

  updateLife();

  
}

void BossShip::display(RenderWindow *w)
{
  Ship::display(w);
}


BossShip::~BossShip()
{
}
