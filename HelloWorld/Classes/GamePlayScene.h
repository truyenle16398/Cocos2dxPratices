#pragma once
#include "D:\Gameloft_Project\HelloWorld\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "OObject.h"
#include "Rock1.h"
#include "Bullet.h"
#include <vector>
USING_NS_CC;
using namespace std;
class GamePlayScene :
	public Scene
{
private:
	//Dinasour* d;
	vector<Rock1*> m_rocks;
public:
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);

	virtual void OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	virtual bool OnTouchBegan(Touch* touch, Event* event);
	virtual bool OnTouchEnded(Touch* touch, Event* event);
	virtual bool OnTouchMoved(Touch* touch, Event* event);
	CREATE_FUNC(GamePlayScene);

	GamePlayScene();
	~GamePlayScene();
};

