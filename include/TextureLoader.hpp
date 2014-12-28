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
    t->add(DATA_PATH + "/img/menu_jouer2.png");
    t->add(DATA_PATH + "/img/menu_quitter.png");
    t->add(DATA_PATH + "/img/menu_quitter2.png");
    t->add(DATA_PATH + "/img/fond_1.png");
    t->add(DATA_PATH + "/img/fond_2.png");
    t->add(DATA_PATH + "/img/fond_3.png");
    t->add(DATA_PATH + "/img/fond_4.png");
    t->add(DATA_PATH + "/img/ship.png");
    t->add(DATA_PATH + "/img/empereur.png");


    
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
