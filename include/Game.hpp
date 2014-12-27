#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Scene;

class Game
{
public:
  Game(RenderWindow *w);
  ~Game();

  void render();
  void update();
  void display();
private:
  RenderWindow *m_window;
  Scene *m_scene;

};

#endif
