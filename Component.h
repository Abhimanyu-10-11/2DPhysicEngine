#pragma once
#include<SFML/Graphics.hpp>
using namespace sf;

class Component
{
public:
	String tag = "component";
	virtual void start() = 0;
	virtual void update(float) = 0;
	virtual void draw(RenderWindow&) = 0;
	virtual String& getSpecific_Tag() = 0;
};

