#include <Menu.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <global.hpp>
#include <Game.hpp>
#include <Controller.hpp>

Menu::Menu(Game *o):Scene(o,MENU,MENU), m_button(0), m_timeMin(250), m_nbButton(2)
{
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(MENU) );


  m_jouer = RectangleShape(Vector2f(100,25));
  m_jouer.setTexture( TextureLoader::instance()->get(MENU_JOUER) );
  m_jouer.setPosition(Vector2f(WIDTH/6, HEIGHT/2  ));

  m_quitter = RectangleShape(Vector2f(100,25));
  m_quitter.setTexture( TextureLoader::instance()->get(MENU_QUITTER) );
  m_quitter.setPosition(Vector2f(WIDTH/6, HEIGHT/2 + 100  ));

  
  m_clock.restart();
  
}

void Menu::updateButtons()
{
  switch(m_button)
    {
    case 0:
        m_jouer.setTexture( TextureLoader::instance()->get(MENU_JOUER2) );
	m_quitter.setTexture( TextureLoader::instance()->get(MENU_QUITTER) );
      break;

    case 1:
        m_jouer.setTexture( TextureLoader::instance()->get(MENU_JOUER) );
	m_quitter.setTexture( TextureLoader::instance()->get(MENU_QUITTER2) );
      break;


    }
}

void Menu::update()
{

  updateButtons();

  if(m_controller->down() && m_clock.getElapsedTime().asMilliseconds() > m_timeMin)
    {
      ++m_button;
      if(m_button >= m_nbButton) m_button = 0;
      m_clock.restart();
    }

  if(m_controller->up() && m_clock.getElapsedTime().asMilliseconds() > m_timeMin)
    {
      --m_button;
      if(m_button < 0) m_button = m_nbButton -1 ;
      m_clock.restart();
    }

  if(m_controller->shoot())
    {
      
      switch(m_button)
	{
	case 0: 
	  m_owner->nextScene();
	  break;

	case 1:
	  m_owner->quit();
	  break;
	}
    }
}

void Menu::display(RenderWindow *w)
{
  w->draw(m_bg);
  w->draw(m_jouer);
  w->draw(m_quitter);
}

Menu::~Menu()
{
  
}
