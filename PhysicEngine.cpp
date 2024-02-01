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
	//GameObject Awake Calling
	// //GameObject Start calling
	for (shared_ptr<GameObject> gameObject :
		gOAndC->getAllGameObjectList())
	{
		gameObject->awake();
	}
	//GameObject Start calling
	for (shared_ptr<GameObject> gameObject :
		gOAndC->getAllGameObjectList())
	{
		gameObject->start();
	}

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
		//check frame per second
		//cout << dt.asSeconds()<<endl;
		
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
