#ifndef MUSIC_LOADER_HPP
#define MUSIC_LOADER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <global.hpp>
using namespace sf;

class MusicLoader
{
public:

  Music* get(int index);
  void add(std::string path);


  static MusicLoader* instance()
  {
    if( m_instance == nullptr )
      {
	m_instance = new MusicLoader;
      }

    return m_instance;
  }

  static void init()
  {
    MusicLoader::instance()->add(DATA_PATH + "/music/menu.ogg");
  }

  static void kill()
  {
    delete m_instance;
  }

private:

  std::vector<Music*> m_vec;

  static MusicLoader* m_instance;
  MusicLoader();
  ~MusicLoader();
};



#endif