#ifndef KEYBOARD_CONTROLLER_HPP
#define KEYBOARD_CONTROLLER_HPP
#include <iostream>
#include <SFML/Graphics.hpp>

#include <Controller.hpp>
using namespace sf;

class KeyboardController: public Controller
{
public:
  KeyboardController();
  ~KeyboardController();
  
  virtual bool up();
  virtual bool down();
  virtual bool left();
  virtual bool right();

  virtual bool shoot();
  virtual bool quit();

};

#endif
