#pragma once
#include"Component.h"
#include<vector>
using namespace std;
using namespace sf;

class GameObject
{


private:
	vector<shared_ptr<Component>> components;
	string name = "";
	int objectId = 0;
public:
	static int totalNumberOfGameObjectEverCreated;
	string tag = "GameObject";
	GameObject();
	void awake();///to set of object variables and reference and to push data to other places
	void start();//To pull data from other places
	void update(float dtAsSecond);
	void draw(RenderWindow& window);
	void addComponent(shared_ptr<Component>  component);
	shared_ptr<Component> findComponentWithSpecificTag(string component);
	template<class T>
	shared_ptr<T> getComponentOfType();
	String getName();
	void setName(string name);

};

template<class T>
inline shared_ptr<T> GameObject::getComponentOfType()
{
	T temp;
	string component_Name = temp.getSpecific_Tag();

	auto start = components.begin();
	auto end = components.end();
	int index = 0;
	for (start; start != end; start++)
	{
		if (component_Name == (*start)->getSpecific_Tag())
		{
			return static_pointer_cast<T>
				(components[index]);;
		}
		index++;
	}

	return NULL;
}
