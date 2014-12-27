#include <Game.hpp>
#include <global.hpp>
#include <Scene.hpp>
#include <Menu.hpp>
#include <TextureLoader.hpp>

Game::Game(RenderWindow *w): m_window(w)
{
  m_scene = new Menu;
}

void Game::update()
{
  m_scene->update();
}


void Game::display()
{
  m_scene->display(m_window);
}

void Game::render()
{
  Event event;

  while( m_window->isOpen() )
    {
      while( m_window->pollEvent(event) )
	{
	  switch(event.type)
	    {
	    case Event::Closed:
	      m_window->close();
	      break;

	    case Event::KeyPressed:

	      switch(event.key.code)
		{
		case Keyboard::Escape:
		  m_window->close();
		  break;

		default:break;
		}
	      
	      break;

	    default:break;
	    }
	}

      m_window->clear(Color(4,139,154));
      update();
      display();
      m_window->display();
    }
}

Game::~Game()
{
  delete m_scene;
}
