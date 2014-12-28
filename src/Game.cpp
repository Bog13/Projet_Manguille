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
  
  //make();


  next();

}

void Game::make()
{
  std::string d1 = "Suite a un conflit nee entre deux grandes nations, celle du comte Xelor et du comte Yaarvin, l'empereur charge le capitaine Manguille, son dernier general, de retablir la paix dans un systeme voisin. Alors s'engage, entre le capitaine et les grandes armees, un terrible combat.";

  std::string d2 = "Le capitaine Manguille ressort victorieux de cet assault... Mais ce n'est qu'un debut, maintenant que les armees sont faible ,il va s'occuper en personne des generaux.";

  std::string d3 = "Les deux generaux sont morts, les armees se replient vers leurs bases respective et le capitaine Manguille se prepare a prendre la forteresse spatiale du comte Yaarvin.";

  std::string d4 = "Ca y est, le conflit prend fin... Le capitaine Manguille rentre victorieux sur la planete de l'empereur, mais ... une surprise l'attend...";

  std::string d5 = "Alors que le conflit venait de prendre fin, Manguille comprend soudain que l'emprereur, en cachette, a donne des troupes au comte Xelor afin de s'assure que le capitaine ne reviendrait pas vivant de la  guerre... Ce stratageme avait pour but d'ecarte Manguille, son dernier general qui est la seul barriere entre l'empereur et le pouvoir absolu.";


  m_scenes.push_back( new Menu(this));
  m_scenes.push_back( new StoryScene(this,d1,I_EMPEROR,M_PEACE_3));
  m_scenes.push_back( new StoryScene(this,d2,I_MANGUILLE,M_WAR_2));
  m_scenes.push_back( new StoryScene(this,d3,I_MANGUILLE,M_WAR_4));
  m_scenes.push_back( new StoryScene(this,d4,I_BATTLE_3,M_WAR_7));
  m_scenes.push_back( new StoryScene(this,d5,I_EMPEROR,M_WAR_6));

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
