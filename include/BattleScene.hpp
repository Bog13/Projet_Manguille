#ifndef BATTLESCENE_HPP
#define BATTLESCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <Scene.hpp>
using namespace sf;

class Ship;

class BattleScene: public Scene
{
public:
  BattleScene(Game *o,int img,int theme);
  virtual ~BattleScene();

  virtual void update();
  virtual void display(RenderWindow* rw);

private:
  RectangleShape m_bg;
  std::vector<Ship*> m_enemies;

};

#endif
