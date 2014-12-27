#include <TextureLoader.hpp>

TextureLoader* TextureLoader::m_instance = nullptr;


TextureLoader::TextureLoader()
{
  
}

Texture* TextureLoader::get(int index)
{
  if(index < 0 || index >= m_vec.size()) return nullptr;
  return m_vec[index];
}

void TextureLoader::add(std::string path)
{
  Texture *tmp = new Texture;;
 
  bool ok = tmp->loadFromFile(path);
  
  if( ok )
    {
      m_vec.push_back(tmp);
      std::cout<<path<<" loaded."<<std::endl;
    }
  else
    {
      delete tmp;
      std::cerr<<"Can't load "<<path<<" !"<<std::endl;
    }
  
}


TextureLoader::~TextureLoader()
{

  for(Texture *t: m_vec)
    {
      delete t;
    }
}
