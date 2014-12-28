#include <EnemyShip.hpp>
#include <TextureLoader.hpp>
#include <Missile.hpp>
#include <Game.hpp>
#include <Ship.hpp>
EnemyShip::EnemyShip(int vx, int freq, int acc): Ship(vx,freq,acc)
{


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
      updateMissiles();
      
      m_rs.move(-m_xvel,0);
    }

  updateLife();

  
}

void EnemyShip::display(RenderWindow *w)
{
  Ship::display(w);
}


EnemyShip::~EnemyShip()
{
  for(Missile* m: m_missiles)
    {
      delete m;
    }
}
