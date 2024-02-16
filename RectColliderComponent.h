#pragma once
#include"ColliderComponent.h"
#include"GameObject.h"
#include"TransformComponent.h"
#include"SimpleGraphicComponent.h"


class RectColliderComponent : public ColliderComponent///check this inheritance
{
private:
	shared_ptr<GameObject> gameObject;
	shared_ptr<TransformComponent> transform;
	shared_ptr<SimpleGraphicComponent> gameObjectSimpleGraphicComponent;

	FloatRect thisGameObjectBound;
	RectangleShape rect;
	string componentName = "Rect"+ Tag;
	bool makeColliderVisualVisable = true;
public:
	//CollisionType collisionType = CollisionType::Box;
	RectColliderComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void SettingColliderVisual();
	void update(float dtAsSecond);
	void draw(RenderWindow& window); 
	FloatRect getColliderBound();
	void setIsColliderActive(bool active);
	bool getIsColliderActive();
	void setMakeColliderVisualVisable(bool);
	int getCollisionType();
	shared_ptr<GameObject>
		getThisComponentGameObject();
	

};

