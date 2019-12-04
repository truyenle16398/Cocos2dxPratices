#include "..\Classes\LogoScene.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"
#include "MainMenuScene.h"
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
	auto sprite2 = Sprite::create("gameloft2.png");

	if (sprite != nullptr && sprite2 != nullptr)
	{
		sprite->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));//set vi tri cua anh
		sprite->setScale(0.2);

		sprite2->setPosition(Vec2(visibleSize.width /2 + origin.x, visibleSize.height /2 + origin.y));//set vi tri cua anh

		this->addChild(sprite, 0);
		this->addChild(sprite2, 0);

		auto scaleBy = ScaleBy::create(2.0f, 3.0f);
		sprite->runAction(scaleBy);
		
		auto rotateBy = RotateBy::create(2.0f, 360.0f);
		sprite2->runAction(rotateBy);

	}

	this->schedule(schedule_selector(LogoScene::changeScene), 3.0f);
	scheduleUpdate();
	return true;
}

void LogoScene::update(float deltaTime)
{
}

void LogoScene::changeScene(float x)
{
	auto directory = Director::getInstance();
	auto scene = LoadingScene::createScene();
	directory->replaceScene(TransitionFade::create(5, scene, Color3B(0, 0, 0)));
	/*Chuyen scene*/
}

LogoScene::LogoScene()
{
}
LogoScene::~LogoScene()
{
}
