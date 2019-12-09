#include "..\Classes\LogoScene.h"
#include "HelloWorldScene.h"
#include "LoadingScene.h"
#include "MainMenuScene.h"
#include "ResourceManager.h"
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

	auto logo = ResourceManager::GetInstance()->GetSpriteById(2);
		logo->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
		logo->setScale(0.2);
		this->addChild(logo, 0);
		auto scaleBy = ScaleBy::create(2.0f, 2.0f);
		logo->runAction(scaleBy);
	

	this->schedule(schedule_selector(LogoScene::changeScene), 3.0f);
	scheduleUpdate();
	return true;
}

void LogoScene::update(float deltaTime)
{
}

void LogoScene::changeScene(float x)
{
	Director::getInstance()->replaceScene(TransitionFade::create(5, MainMenuScene::createScene(), Color3B(0, 0, 0)));
	/*Chuyen scene*/
}

LogoScene::LogoScene()
{
}

LogoScene::~LogoScene()
{
}
