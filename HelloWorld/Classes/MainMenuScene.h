#pragma once
#include "D:\Gameloft_Project\HelloWorld\cocos2d\cocos\2d\CCScene.h"
#include <cocos2d.h>
#include "OObject.h"
USING_NS_CC;

class MainMenuScene :
	public Scene
{
private:
	OObject* r;
	OObject* b;
public:
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);

	CREATE_FUNC(MainMenuScene);
};

