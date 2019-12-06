#pragma once
#include "D:\Gameloft_Project\HelloWorld\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
#include "OObject.h"
#include "Rock1.h"
#include "Bullet.h"
#include <vector>
USING_NS_CC;

class GamePlayScene :
	public Scene
{
private:
	OObject* r;
	OObject* b;
	OObject* d;
public:
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);
	virtual void onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event);
	CREATE_FUNC(GamePlayScene);
	virtual bool OnTouchBegan(Touch* touch, Event* event);

	GamePlayScene();
	~GamePlayScene();
};

