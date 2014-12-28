#include <iostream>
#include <Game.hpp>
#include <global.hpp>
#include <TextureLoader.hpp>
#include <MusicLoader.hpp>

using namespace std;

int main()
{

  sf::RenderWindow window;

  if( FULLSCREEN )
    {
      window.create(sf::VideoMode(WIDTH,HEIGHT),PROJECT_NAME,sf::Style::Fullscreen);
    }
  else
    {
      window.create(sf::VideoMode(WIDTH,HEIGHT),PROJECT_NAME,sf::Style::Close);
    }



  TextureLoader::init();
  MusicLoader::init();

  Game game(&window);
  game.render();

  
  TextureLoader::kill();
  MusicLoader::kill();
  return 0;
}
