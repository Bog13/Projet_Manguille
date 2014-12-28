#include <Game.hpp>
#include <global.hpp>
#include <Scene.hpp>
#include <Menu.hpp>
#include <StoryScene.hpp>
#include <BattleScene.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <Controller.hpp>
#include <KeyboardController.hpp>

Game::Game(RenderWindow *w): m_window(w), m_running(true)
{
  srand(time(NULL));
  m_controller = new KeyboardController;
  m_numScene = -1;

  m_scene = nullptr;

    m_scenes.push_back( new BattleScene(this,I_BATTLE_1,5) );
  
  //  make();


  next();

}

void Game::make()
{
  std::string d1 = "test";


  m_scenes.push_back( new Menu(this));
  m_scenes.push_back( new StoryScene(this,d1,0,0));
}

Controller* Game::getController()
{
  return m_controller;
}



void Game::change(Scene *s)
{
  m_scene = s;
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
      MusicLoader::instance()->play(m_scene->getMusic());
    }
  else
    {
      m_scene = nullptr;
      MusicLoader::instance()->stop();
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
