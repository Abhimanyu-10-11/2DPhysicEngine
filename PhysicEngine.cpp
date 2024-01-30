#include "PhysicEngine.h"
#include<iostream>
using namespace sf;
using namespace pe;

PhysicEngine::PhysicEngine()
{

	window.create(VideoMode(windowWidth, windowHeight), "2DPhysic");
	gOAndC = new GameObjectAndComponentCreator();

	
}

void PhysicEngine::run()
{
	

	Time dt;
	Event event;
	while (window.isOpen())
	{
		dt = clock.restart();
		totalGameRunningTime += dt.asSeconds();
		while (window.pollEvent(event))
		{
			
			if (event.key.code == Keyboard::Escape)
			{
				window.close();
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}

		}
		update(dt.asSeconds());
		draw();
		
		

	}
}


void PhysicEngine::update(float dtAsSecond)
{
	for (shared_ptr<GameObject> gameObject : 
					gOAndC->getAllGameObjectList())
	{
		gameObject->update(dtAsSecond);
	}
}

void PhysicEngine::draw()
{
	window.clear(Color::Blue);

	for (shared_ptr<GameObject> gameObject :
		gOAndC->getAllGameObjectList())
	{
		gameObject->draw(window);
	}
	window.display();
}
