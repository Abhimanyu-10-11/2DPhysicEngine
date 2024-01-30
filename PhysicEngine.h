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
		Time dt;
		float totalGameRunningTime = 0;
		int windowWidth = 1920 / 2, windowHeight = 1080 / 2;
		GameObjectAndComponentCreator* gOAndC;
		void update(float dtAsSecond);
		void draw();
	public:
		PhysicEngine();
		void run();
	};

}


