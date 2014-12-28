#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
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
  void playMenu();
  void playGame();
private:
  bool m_running;
  RenderWindow *m_window;
  Scene *m_scene;
  Controller *m_controller;

};

#endif
