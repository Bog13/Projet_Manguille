#include <PlayerShip.hpp>
#include <TextureLoader.hpp>
#include <Missile.hpp>
#include <Game.hpp>
#include <Ship.hpp>
#include <Controller.hpp>
#include <BattleScene.hpp>

PlayerShip::PlayerShip(BattleScene* o,Controller *c): Ship(o,0,100,2), m_controller(c), m_yvel(5)
{
  m_name = "playership";
  m_maxLife = 500;
  m_life = m_maxLife;
  m_rs.setPosition(Vector2f(0,Game::random(0,HEIGHT - m_h)));
}


void PlayerShip::shoot()
{
  m_owner->addMissile(new Missile(Game::random(-m_accuracy,m_accuracy),m_rs.getPosition().x + m_w,m_rs.getPosition().y));
}

void PlayerShip::updateShoot()
{
  if(m_clock.getElapsedTime().asMilliseconds() > m_shootFreq)
    {
      if( m_controller->shoot() )
	{
	  shoot();
	}

      m_clock.restart();
    }

  
}


void PlayerShip::update()
{
 
  if(m_life > 0)
    {
      updateShoot();
      
      if(m_controller->up() )
	{
	  m_rs.move(m_xvel,-m_yvel);
	}

      if(m_controller->down() )
	{
	  m_rs.move(m_xvel,m_yvel);
	}
     } 




  updateLife();

  
}

void PlayerShip::display(RenderWindow *w)
{
  Ship::display(w);
}


PlayerShip::~PlayerShip()
{
  
}
