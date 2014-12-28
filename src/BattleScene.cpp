#include <BattleScene.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <global.hpp>
#include <Game.hpp>
#include <Controller.hpp>
#include <Ship.hpp>
#include <EnemyShip.hpp>

BattleScene::BattleScene(Game *o,int img,int theme):Scene(o,img,theme)
{
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(img) );

  m_enemies.push_back(new EnemyShip(1,250,5));

}



void BattleScene::update()
{
 
  for(Ship *s: m_enemies)
    {
      s->update();
    }

  if( m_controller->shoot() ) m_owner->nextScene();
 
}

void BattleScene::display(RenderWindow *w)
{
  w->draw(m_bg);

  for(Ship *s: m_enemies)
    {
      s->display(w);
    }
}

BattleScene::~BattleScene()
{
  for(Ship *s: m_enemies)
    {
      delete s;
    }
}
