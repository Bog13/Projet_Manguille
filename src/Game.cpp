#include <Game.hpp>
#include <global.hpp>
#include <Scene.hpp>
#include <Menu.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <Controller.hpp>
#include <KeyboardController.hpp>

Game::Game(RenderWindow *w): m_window(w), m_running(true)
{
  m_controller = new KeyboardController;
  m_scene = new Menu(this);
}

Controller* Game::getController()
{
  return m_controller;
}

void Game::playMenu()
{
  if(m_scene != nullptr) delete m_scene;
  m_scene = new Menu(this);
}

void Game::playGame()
{
  if(m_scene != nullptr)
    {
      delete m_scene;
    }

  m_scene = nullptr;
}

void Game::quit()
{
  m_running = false;
}

void Game::update()
{
  if(m_scene != nullptr)
    {
      m_scene->update();
    }
}


void Game::display()
{
  if(m_scene != nullptr)
    {
      m_scene->display(m_window);
    }

  if(m_controller->quit()) quit();
}

void Game::render()
{
  Event* event = m_controller->getEvent();;

  while( m_running )
    {
      while( m_window->pollEvent(*event) )
	{
	  switch(event->type)
	    {
	    case Event::Closed:
	      m_running = false;
	      break;

	    case Event::KeyPressed:

	      switch(event->key.code)
		{
	       
		
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
  delete m_controller;
  delete m_scene;
}
