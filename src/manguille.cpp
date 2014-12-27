#include <iostream>
#include <Game.hpp>
#include <global.hpp>
#include <TextureLoader.hpp>
using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),PROJECT_NAME);

  TextureLoader::init();

  Game game(&window);
  game.render();

  
  TextureLoader::kill();

  return 0;
}
