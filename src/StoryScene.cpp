#include <StoryScene.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>
#include <global.hpp>
#include <Game.hpp>
#include <Controller.hpp>

StoryScene::StoryScene(Game *o,std::string speech,int img,int theme):Scene(o,img,theme),m_speech(speech), m_timeMin(250)
							    , m_begin(0)
{
  m_readyToQuit = false;

  m_music = theme;
  m_bg = RectangleShape(Vector2f(WIDTH,HEIGHT));
  m_bg.setTexture( TextureLoader::instance()->get(img) );

  m_bar = RectangleShape(Vector2f(WIDTH,HEIGHT/5));
  m_bar.setFillColor(Color(255,255,255));
  m_bar.setOutlineThickness(10);
  m_bar.setOutlineColor(Color::Black);
  m_bar.setPosition(Vector2f(0, HEIGHT - m_bar.getLocalBounds().height));

 
  m_font.loadFromFile(DATA_PATH + "/font/elvifrance.ttf");
  m_text.setFont(m_font);
  m_text.setCharacterSize(20);
  m_text.setString(m_speech);
  m_text.setColor(Color::Black);
  m_text.setPosition(Vector2f(0,HEIGHT - m_bar.getLocalBounds().height - 20));


  m_clock.restart();
  m_timePlaying.restart();

  m_sizeMax = 50;
  m_lineMax = 3;
  m_begin = 0;
  m_end = m_sizeMax * m_lineMax;
  addLn();

}

void StoryScene::addLn()
{
  int b = 0;

  for(int i=0; i<m_speech.size();i++)
    {
      if(i%m_sizeMax == 0)
	{
	  m_speech = m_speech.substr(0,i) + '\n' + m_speech.substr(i,m_speech.size());
	}
    }
}



void StoryScene::update()
{
 
  
  if(  m_controller->down() && m_clock.getElapsedTime().asMilliseconds() > m_timeMin)
    {


      if(m_begin + m_sizeMax < m_speech.size())
	{
	  m_begin += m_sizeMax;
	}

      m_clock.restart();
    }

if(  m_controller->up() && m_clock.getElapsedTime().asMilliseconds() > m_timeMin)
    {


      if(m_begin - m_sizeMax >= 0)
	{
	  m_begin -= m_sizeMax;
	}

      m_clock.restart();
    }

 if(  m_controller->shoot())
   {
     
     m_owner->nextScene();
   }


  std::string txt =  m_speech.substr(m_begin,m_end);

  if(m_begin > m_sizeMax * (m_lineMax-2) )
    {
      m_text.setString(txt);
    }
  else
    {
      if(m_speech.size() > m_sizeMax) 
	{
	  m_text.setString(txt + " ...");
	}else m_text.setString(txt);
    }

  
 
}

void StoryScene::display(RenderWindow *w)
{
  w->draw(m_bg);
  w->draw(m_bar);
  w->draw(m_text);
}

StoryScene::~StoryScene()
{
  
}
