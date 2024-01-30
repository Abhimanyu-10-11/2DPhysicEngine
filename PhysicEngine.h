#pragma once
#include<SFML/Graphics.hpp>
#include"GameObjectAndComponentCreator.h"

using namespace sf;

namespace pe
{
	class PhysicEngine
	{
	private:

		RenderWindow window;
		Clock clock;
		float totalGameRunningTime = 0;
		int windowWidth = 1920 / 2, windowHeight = 1080 / 2;
		GameObjectAndComponentCreator* gOAndC;
	public:
		PhysicEngine();
		void run();
		void update(float dtAsSecond);
		void draw();
	};

}


