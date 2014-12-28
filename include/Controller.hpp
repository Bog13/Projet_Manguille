#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;

class Controller
{
public:
  Controller();
  ~Controller();
  
  Event* getEvent(){return &m_event;}

  virtual bool up() = 0;
  virtual bool down() = 0;
  virtual bool left() = 0;
  virtual bool right() = 0;

  virtual bool shoot() = 0;
  virtual bool quit() = 0;


protected:
  Event m_event;
};

#endif
