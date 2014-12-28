#include <Game.hpp>
#include <global.hpp>
#include <Scene.hpp>
#include <Menu.hpp>
#include <StoryScene.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <Controller.hpp>
#include <KeyboardController.hpp>

Game::Game(RenderWindow *w): m_window(w), m_running(true)
{
  m_controller = new KeyboardController;
  m_numScene = -1;

  m_scene = nullptr;

  m_scenes.push_back(new Menu(this));
  m_scenes.push_back(new StoryScene(this,"rien a ajouter !",1,0));
  m_scenes.push_back(new StoryScene(this,"Ceci est un dialogue, c'est fou non ? Je me demande ou est passe ce poisson ! Vous l'aimiez temps, vous le xxx comme si cetait votre fils ! Avez vous regardez dans le tiroir ? Avez vous regardez sous sa trompe ?",0,1));
  m_scenes.push_back(new StoryScene(this,"Troisieme scene",2,0));



   next();

}

Controller* Game::getController()
{
  return m_controller;
}



void Game::change(Scene *s)
{
  m_scene = s;

  if(m_scene != nullptr)
    {
      MusicLoader::instance()->play(m_scene->getMusic());
    }
}

void Game::nextScene()
{
  if(m_timeBeetwenScene.getElapsedTime().asMilliseconds() > 500 )
    {
      next();
      m_timeBeetwenScene.restart();
    }
}

void Game::next()
{

  if(m_numScene + 1 < m_scenes.size())
    {
      ++m_numScene;
      change( m_scenes[m_numScene] );
    }
  else
    {
      m_scene = nullptr;
    }
}

void Game::quit()
{
  MusicLoader::instance()->stop();
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

  for(Scene *s:m_scenes)
    {
      delete s;
    }

}
