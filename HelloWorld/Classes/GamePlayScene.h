#pragma once
#include "D:\Gameloft_Project\HelloWorld\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
USING_NS_CC;

class GamePlayScene :
	public cocos2d::Scene
{
public:
	Sprite* dinasour;
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	CREATE_FUNC(GamePlayScene);
	virtual bool OnTouchBegan(Touch* touch, Event* event);

	GamePlayScene();
	~GamePlayScene();
};

