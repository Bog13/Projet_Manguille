#include <BattleScene.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <global.hpp>
#include <Game.hpp>
#include <Controller.hpp>
#include <Ship.hpp>
#include <EnemyShip.hpp>
#include <PlayerShip.hpp>
#include <BossShip.hpp>
#include <Missile.hpp>

BattleScene::BattleScene(Game *o,int px,int nw,int ne, int wf,int img,int theme):Scene(o,img,theme), m_nb_wave(nw),
										 m_waveFreq(wf), m_first(true),m_nbEnemy(ne), m_victoryDelay(5000), m_px(px)
{
  m_boss = nullptr;
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(img) );

  m_enemies.push_back(new PlayerShip(this,m_controller));

  m_victoryClock.restart();
  m_clock.restart();
}

void BattleScene::newWave(int nb)
{
   for(int i=0; i< nb; i++)
    {
      m_enemies.push_back(new EnemyShip(this,m_px,1,500,5));
    }
}

void BattleScene::addBoss(Ship *s)
{
  m_boss = s;
}

void BattleScene::addMissile(Missile *m)
{
  m_missiles.push_back(m);
}


bool BattleScene::collide(Ship* s, Missile *m)
{
  int sx = s->getRectangleShape().getPosition().x;
  int sy = s->getRectangleShape().getPosition().y;
  int sw = s->getRectangleShape().getLocalBounds().width;
  int sh = s->getRectangleShape().getLocalBounds().height;

  int mx = m->getRectangleShape().getPosition().x;
  int my = m->getRectangleShape().getPosition().y;
  int mw = m->getRectangleShape().getLocalBounds().width;
  int mh = m->getRectangleShape().getLocalBounds().height;  

  return (mx + mw >= sx && mx <= sx + sw && my + mh >= sy && my <= sy + sh && m->isActif());
}


void BattleScene::update()
{
  int nbShipAlive = 0;

  for(Ship *s: m_enemies)
    {
      s->update();

      if(s->isAlive() && s->getName() != "playership")
	{
	  ++nbShipAlive;
	}
    }


  for(int i=0; i< m_missiles.size();i++)
    {
      m_missiles[i]->update();


      if( !m_missiles[i]->isActif() )
	{
	  //	  delete m_missiles[i]; TODO ?
	}
      else
	{

	  for(Ship *s: m_enemies)
	    {
	      if( collide(s,m_missiles[i]) )
		{
		  s->hit(5);
		  m_missiles[i]->setActif(false);
		}
	    }

	}

    }


  if(m_nb_wave == 0 && nbShipAlive == 0)
    {
      if(m_boss != nullptr)
	{
	  m_enemies.push_back(m_boss);
	}

      m_nb_wave = -2;
    }

  if( (m_clock.getElapsedTime().asMilliseconds() > m_waveFreq && m_nb_wave > 0) || m_first)
    {
      newWave(m_nbEnemy);
      --m_nb_wave;
      m_first = false;
      m_clock.restart();
    }

  

  if(nbShipAlive != 0)
    {
      m_victoryClock.restart();
    }


  if( m_victoryClock.getElapsedTime().asMilliseconds() > m_victoryDelay )
    {
      m_owner->nextScene();
    }

  if( !getPlayer()->isAlive() )
    {
      m_owner->gameOver();
    }
 
}

void BattleScene::display(RenderWindow *w)
{
  w->draw(m_bg);

  for(Ship *s: m_enemies)
    {
      s->display(w);
    }

  for(Missile *m: m_missiles)
    {
      m->display(w);
    }

}

BattleScene::~BattleScene()
{
  for(Ship *s: m_enemies)
    {
      delete s;
    }

  for(Missile *m: m_missiles)
    {
      delete m;
    }
}
