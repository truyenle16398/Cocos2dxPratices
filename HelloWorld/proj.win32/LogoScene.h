#pragma once
#include "D:\Gameloft_Project\HelloWorld\cocos2d\cocos\2d\CCScene.h"
#include "cocos2d.h"
USING_NS_CC;
class LogoScene :
	public cocos2d::Scene
{
public:
	static Scene* createScene();
	virtual bool init();
	void update(float deltaTime);
	CREATE_FUNC(LogoScene);
	LogoScene();
	~LogoScene();
};

