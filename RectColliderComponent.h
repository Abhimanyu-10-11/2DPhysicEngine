#pragma once
#include"ColliderComponent.h"
#include"GameObject.h"
#include"TransformComponent.h"
#include"GraphicComponent.h"


class RectColliderComponent : public ColliderComponent///check this inheritance
{
private:
	shared_ptr<GameObject> gameObject;
	shared_ptr<TransformComponent> gameObjecctTransform;
	shared_ptr<GraphicComponent> gameObjectGraphicComponent;

	FloatRect thisGameObjectBound;
	RectangleShape rect;
	string componentName = "Rect"+ Specific_Tag;
	bool makeColliderVisualVisable = true;
public:
	RectColliderComponent(shared_ptr<GameObject> gameObject);
	void awake();
	void start();
	void SettingColliderVisual();
	void update(float dtAsSecond);
	void draw(RenderWindow& window); 
	FloatRect getColliderBound();
	bool getIsColliderActive();
	void setMakeColliderVisualVisable(bool);
	shared_ptr<GameObject>
		getThisComponentGameObject();
	

};

