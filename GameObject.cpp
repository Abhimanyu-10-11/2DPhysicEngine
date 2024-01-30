#include "GameObject.h"
#include<iostream>

int GameObject::totalNumberOfGameObjectEverCreated;
GameObject::GameObject(string name)
{
	totalNumberOfGameObjectEverCreated++;
	objectId = GameObject::totalNumberOfGameObjectEverCreated;
	this->name = name +"::"+std::to_string(objectId);
}

void GameObject::start()
{
	auto start = components.begin();
	auto end = components.end();
	for (start; start != end; start++)
	{
		(*start)->start();
	}
}

void GameObject::update(float dtAsSecond)
{
	auto start = components.begin();
	auto end = components.end();
	for (start; start != end; start++)
	{
		(*start)->update(dtAsSecond);
	}

}

void GameObject::draw(RenderWindow& window)
{
	auto start = components.begin();
	auto end = components.end();
	for (start; start != end; start++)
	{
		(*start)->draw(window);
	}
}

void GameObject::addComponent(shared_ptr<Component> component)
{
	components.push_back(component);
}

shared_ptr<Component> GameObject::findComponentWithSpecificTag(string component)
{
	auto start = components.begin();
	auto end = components.end();
	int index = 0;
	for (start; start != end; start++)
	{
		if (component == (*start)->getSpecific_Tag())
		{
			return components[index];
		}
		index++;
	}
	return NULL;
}

String GameObject::getName()
{
	return name;
}
