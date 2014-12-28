#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace sf;

class Scene;
class Controller;

class Game
{
public:
  Game(RenderWindow *w);
  ~Game();

  void render();
  void update();
  void display();

  Controller *getController();

  void quit();

  void nextScene();
  void change(Scene *s);
  void make();


  static int random(int a,int b)
  {
    return rand()%(b-a)+a;
  }

private:
  void next();

  bool m_running;
  RenderWindow *m_window;
  Scene *m_scene;
  Controller *m_controller;
  int m_numScene;
  std::vector<Scene*> m_scenes;
  Clock m_timeBeetwenScene;
};

#endif
