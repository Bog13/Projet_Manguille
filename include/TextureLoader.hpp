#ifndef TEXTURE_LOADER_HPP
#define TEXTURE_LOADER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include <global.hpp>
using namespace sf;


class TextureLoader
{
public:

  Texture* get(int index);
  void add(std::string path);


  static TextureLoader* instance()
  {
    if( m_instance == nullptr )
      {
	m_instance = new TextureLoader;
      }

    return m_instance;
  }

  static void init()
  {
    TextureLoader* t = TextureLoader::instance();
    t->add(DATA_PATH + "/img/menu_fond.png");
    t->add(DATA_PATH + "/img/menu_jouer.png");
    
  }

  static void kill()
  {
    delete m_instance;
  }

private:

  std::vector<Texture*> m_vec;

  static TextureLoader* m_instance;
  TextureLoader();
  ~TextureLoader();
};



#endif
