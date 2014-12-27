#include <iostream>
#include <Game.hpp>
#include <global.hpp>
using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),PROJECT_NAME);

  Game game(&window);
  game.render();

  return 0;
}
