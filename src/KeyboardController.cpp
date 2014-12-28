#include <KeyboardController.hpp>


KeyboardController::KeyboardController()
{
}

bool KeyboardController::up()
{
  return Keyboard::isKeyPressed(Keyboard::Up);
}

bool KeyboardController::down()
{
  return Keyboard::isKeyPressed(Keyboard::Down);
}

bool KeyboardController::left()
{
  return Keyboard::isKeyPressed(Keyboard::Left);
}

bool KeyboardController::right()
{
  return Keyboard::isKeyPressed(Keyboard::Right);
}

bool KeyboardController::shoot()
{
  return Keyboard::isKeyPressed(Keyboard::Space);
}

bool KeyboardController::quit()
{
  return Keyboard::isKeyPressed(Keyboard::Escape);
}

KeyboardController::~KeyboardController()
{
}
