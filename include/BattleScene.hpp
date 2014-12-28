#ifndef BATTLESCENE_HPP
#define BATTLESCENE_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <Scene.hpp>
using namespace sf;

class Ship;
class Missile;

class BattleScene: public Scene
{
public:
  BattleScene(Game *o,int nw,int wf,int img,int theme);
  virtual ~BattleScene();
  void newWave(int nb);
  virtual void update();
  virtual void display(RenderWindow* rw);
  void addMissile(Missile *m);
  bool collide(Ship* s, Missile *m);
private:
  RectangleShape m_bg;
  std::vector<Ship*> m_enemies;
  std::vector<Missile*> m_missiles;
  Clock m_clock;
  int m_waveFreq;
  int m_nb_wave;
  bool m_first;
};

#endif
