#include "..\Classes\LogoScene.h"
#include "HelloWorldScene.h"
#include<iostream>
using namespace std;

Scene * LogoScene::createScene()
{
	return LogoScene::create();
}

bool LogoScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Scene::init())
	{
		return false;
	}


	auto sprite = Sprite::create("gameloft.png");
	if (sprite != nullptr)
	{
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));//set vi tri cua anh
		this->addChild(sprite, 0);
	}

	scheduleUpdate();
	return true;
}
static int countFrame = 0;
void LogoScene::update(float deltaTime)
{
	countFrame++;
	auto directory = Director::getInstance();
	auto scene = HelloWorld::createScene();
	if (countFrame == 10)
	{
		directory->replaceScene(TransitionFade::create(0.5, scene, Color3B(0, 0, 0)));
		countFrame = 0;
	}
	
}

LogoScene::LogoScene()
{
}
LogoScene::~LogoScene()
{
}
