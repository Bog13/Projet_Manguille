#include <MusicLoader.hpp>

MusicLoader* MusicLoader::m_instance = nullptr;


MusicLoader::MusicLoader()
{
  
}

Music* MusicLoader::get(int index)
{
  if(index < 0 || index >= m_vec.size()) return nullptr;
  return m_vec[index];
}

void MusicLoader::add(std::string path)
{
  Music *tmp = new Music;
 
  bool ok = tmp->openFromFile(path);
  
  if( ok )
    {
      m_vec.push_back(tmp);
      std::cout<<path<<" loaded."<<std::endl;
    }
  else
    {
      std::cerr<<"Can't load "<<path<<" !"<<std::endl;
    }
  
}

void MusicLoader::stop()
{
   for(Music *m: m_vec)
    {
      m->stop();
    }

}

void MusicLoader::play(int i)
{
  stop();

   m_vec[i]->play();
}

MusicLoader::~MusicLoader()
{
  for(Music *m: m_vec)
    {
      delete m;
    }
}
