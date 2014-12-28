#include <EnemyShip.hpp>
#include <TextureLoader.hpp>
#include <Missile.hpp>
#include <Game.hpp>
#include <Ship.hpp>
#include <BattleScene.hpp>
#include <SFML/Audio.hpp>

EnemyShip::EnemyShip(BattleScene* o,int px,int vx, int freq, int acc): Ship(o,vx,freq,acc)
{
  m_name = "enemyship";
  m_maxLife = 25;
  m_life = m_maxLife;

  int texture = 0;

  if( px <= Game::random(0,101))
    {
      texture = I_SHIP_Y;
    }
  else
    {
      texture = I_SHIP_X;
    }

  m_rs.setTexture(TextureLoader::instance()->get(texture));

}



void EnemyShip::updateShoot()
{
  if(m_clock.getElapsedTime().asMilliseconds() > m_shootFreq)
    {
      shoot();
      m_clock.restart();
    }
}


void EnemyShip::update()
{
 
  if(m_life > 0)
    {
      updateShoot();
      
      if(m_rs.getPosition().x > WIDTH/2 )
	{
	  m_rs.move(-m_xvel,0);
	}
    }
  else
    {

      m_rs.move(-m_xvel/2,m_xvel);
      m_rs.rotate(0.2);
    }

  updateLife();

  
}

void EnemyShip::display(RenderWindow *w)
{
  Ship::display(w);
}


EnemyShip::~EnemyShip()
{
}
