#pragma once
#include"ColliderComponent.h"
#include"GameObject.h"
#include"TransformComponent.h"
#include"RigidbodyComponent.h"


class RectColliderComponent : public ColliderComponent///check this inheritance
{
private:
	shared_ptr<GameObject> gameObject;
	shared_ptr<TransformComponent> transform;

	FloatRect thisGameObjectBound;
	RectangleShape rect;
	//RectangleShape rectInvisiable;
	string componentName = "Rect"+tag;
	bool makeColliderVisiable = true;
	
public:
	RectColliderComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void SettingColliderVisual();
	void update(float dtAsSecond);
	void draw(RenderWindow& window); 
	FloatRect getColliderBound();
	shared_ptr<GameObject> getThisComponentGameObject();

};

