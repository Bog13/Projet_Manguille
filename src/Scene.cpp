#include <Scene.hpp>
#include <Game.hpp>

Scene::Scene(Game *o): m_owner(o), m_controller(o->getController())
{
}

void Scene::update()
{
}

void Scene::display(RenderWindow *w)
{
}

Scene::~Scene()
{
    std::cout<"QUIT !\n";
}
