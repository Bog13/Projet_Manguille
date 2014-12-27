#include <Menu.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <global.hpp>

Menu::Menu():Scene()
{
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(MENU) );


  m_jouer = RectangleShape(Vector2f(100,25));
  m_jouer.setTexture( TextureLoader::instance()->get(MENU_JOUER) );
  m_jouer.setPosition(Vector2f(WIDTH/6, HEIGHT/2  ));

  

  
  MusicLoader::instance()->get(MENU)->setLoop(true);
  MusicLoader::instance()->get(MENU)->play();
  
}

void Menu::update()
{

}

void Menu::display(RenderWindow *w)
{
  w->draw(m_bg);
  w->draw(m_jouer);
}

Menu::~Menu()
{
}
