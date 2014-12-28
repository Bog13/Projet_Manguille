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
#include <BossShip.hpp>


Game::Game(RenderWindow *w): m_window(w), m_running(true), m_gameover(false)
{
  srand(time(NULL));
  m_controller = new KeyboardController;
  m_numScene = -1;

  m_scene = nullptr;

  

  /* BattleScene *b = new BattleScene(this,100,2,3,10000,I_BATTLE_1,5);
  b->addBoss(new BossShip( b, b->getPlayer(),2,250,10,I_SHIP_X ) );
  m_scenes.push_back( b );*/
  
  make();


  next();

}

void Game::gameOver()
{

  
  m_scene = new StoryScene(this, "GAME OVER !", I_BATTLE_1, M_PEACE_3);
  MusicLoader::instance()->play(m_scene->getMusic());

  m_gameover = true;


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

  BattleScene *b = new BattleScene(this,50,4,2,10000,I_BATTLE_1,M_WAR_3);
  m_scenes.push_back( b );

  m_scenes.push_back( new StoryScene(this,d2,I_MANGUILLE,M_WAR_2));*/


  //attaque de yaarvin
  BattleScene *b3 = new BattleScene(this,0,2,4,10000,I_BATTLE_2,M_WAR_3);
  b3->addBoss(new BossShip( b3, b3->getPlayer(),2,100,10,I_SHIP_Y ) );
  m_scenes.push_back( b3 );

  //attaque de xelor
  BattleScene *b4 = new BattleScene(this,100,2,4,10000,I_BATTLE_3,M_WAR_4);
  b4->addBoss(new BossShip( b4, b4->getPlayer(),4,100,10,I_SHIP_X ) );
  m_scenes.push_back( b4 );

  m_scenes.push_back( new StoryScene(this,d3,I_MANGUILLE,M_WAR_4));

  //yaarvin
m_scenes.push_back( new StoryScene(this,"Toi ?! Traitre ! Tu vas perir !",I_YAARVIN,M_YAARVIN));
  BattleScene *b2 = new BattleScene(this,0,1,4,10000,I_BATTLE_2,M_YAARVIN);
  b2->addBoss(new BossShip( b2, b2->getPlayer(),4,700,10,I_SHIP_Y ) );
  m_scenes.push_back( b2 );

  
  //xelor
m_scenes.push_back( new StoryScene(this,"Arggg... Viens te battre !",I_XELOR,M_XELOR));
  BattleScene *b1 = new BattleScene(this,100,1,4,10000,I_BATTLE_1,M_XELOR);
  b1->addBoss(new BossShip( b1, b1->getPlayer(),1,100,10,I_SHIP_X ) );
  m_scenes.push_back( b1 );

  m_scenes.push_back( new StoryScene(this,d4,I_BATTLE_3,M_WAR_7));
  m_scenes.push_back( new StoryScene(this,d5,I_EMPEROR,M_WAR_6));


  m_scenes.push_back( new StoryScene(this,"La mort vous attends tous ! Venez l'accueillir !",I_EMPEROR,M_EMPEROR));
  BattleScene *b5 = new BattleScene(this,100,0,0,10000,I_BATTLE_1,M_EMPEROR);
  b5->addBoss(new BossShip( b5, b5->getPlayer(),1,1000,20,I_SHIP_X ) );
  m_scenes.push_back( b5 );

  m_scenes.push_back( new StoryScene(this,"Que ce passe t-il ? Vous ne saurez me vaincre aussi facilement ! Garde !!!",I_EMPEROR,M_EMPEROR));
  BattleScene *b6 = new BattleScene(this,0,10,2,1000,I_BATTLE_2,M_WAR_4);
  m_scenes.push_back( b6 );

  m_scenes.push_back( new StoryScene(this,"Je ne laisserai pas un sous homme comme vous me vaincre !",I_EMPEROR,M_EMPEROR));
  BattleScene *b7 = new BattleScene(this,100,0,0,10000,I_BATTLE_1,M_EMPEROR);
  b7->addBoss(new BossShip( b7, b7->getPlayer(),4,1000,10,I_SHIP_X ) );
  m_scenes.push_back( b7 );
  
  m_scenes.push_back( new StoryScene(this,"Non !!! J'ai echoue...",I_EMPEROR,M_PEACE_1));
  m_scenes.push_back( new StoryScene(this,"Rien ne saurais me vaincre !!! Muhahahahaha... ",I_MANGUILLE,M_PEACE_2));
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
  if(m_timeBeetwenScene.getElapsedTime().asMilliseconds() > 500)
    {
      if(m_gameover)
	{
	  quit();
	}
      else
	{
	  next();
	}

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
