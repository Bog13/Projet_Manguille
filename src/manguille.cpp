#include <iostream>
#include <Game.hpp>
#include <global.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>

using namespace std;

int main()
{
  sf::RenderWindow window(sf::VideoMode(WIDTH,HEIGHT),PROJECT_NAME);

  TextureLoader::init();
  MusicLoader::init();

  Game game(&window);
  game.render();

  
  TextureLoader::kill();
  MusicLoader::kill();
  return 0;
}
