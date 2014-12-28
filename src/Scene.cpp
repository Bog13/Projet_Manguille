#include <Scene.hpp>
#include <Game.hpp>

Scene::Scene(Game *o,int i,int m): m_owner(o), m_controller(o->getController()),
				   m_music(m),m_img(i)
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
