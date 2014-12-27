#include <Menu.hpp>
#include <TextureLoader.hpp>
#include <global.hpp>

Menu::Menu():Scene()
{
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(0) );
}

void Menu::update()
{

}

void Menu::display(RenderWindow *w)
{
  w->draw(m_bg);
}

Menu::~Menu()
{
}
