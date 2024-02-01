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
		View gameView;
		Clock clock;
		Time dt;
		float totalGameRunningTime = 0;
		int windowWidth = 1920 / 2, windowHeight = 1080 / 2;
		void update(float dtAsSecond);
		void draw();
	public:
		static GameObjectAndComponentCreator* gOAndC;
		PhysicEngine();
		void run();
	};

}


