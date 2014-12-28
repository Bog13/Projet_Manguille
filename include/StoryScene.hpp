#ifndef STORYSCENE_HPP
#define STORYSCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <Scene.hpp>
using namespace sf;

class StoryScene: public Scene
{
public:
  StoryScene(Game *o,std::string speech,int img,int theme);
  virtual ~StoryScene();
  void addLn();
  virtual void update();
  virtual void display(RenderWindow* rw);

private:
  std::string m_speech;
  int m_timeMin;
  bool m_readyToQuit;
  Clock m_clock;
  Clock m_timePlaying;
  RectangleShape m_bg;
  RectangleShape m_bar;
  Font m_font;
  Text m_text;

  int m_begin;
  int m_end;
  int m_sizeMax;
  int m_lineMax;

};

#endif
