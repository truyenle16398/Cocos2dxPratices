#include "LoadingScene.h"



Scene * LoadingScene::createScene()
{
	return LoadingScene::create();
}

bool LoadingScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto directory = Director::getInstance();

	if (!Scene::init())
	{
		return false;
	}

	//background
	auto bg = Sprite::create("background.png");
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, -1);


	//Nhan vat 1 chay
	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("list.plist", "list.png");
	auto actor = Sprite::create("0_Fallen_Angels_Walking_000.png");
	actor->setPosition(100,100);
	actor->setScale(scale);
	this->addChild(actor, 1);

	Vector<SpriteFrame*>list;
	//duyet cat anh list.png
	for (int  i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			list.pushBack(SpriteFrame::create("list.png", Rect(j * 400, i * 580, 400, 580)));
		}
	}
	list.reverse();
	Animation* animation = Animation::createWithSpriteFrames(list, 0.1f);
	Animate* animate = Animate::create(animation);
	
	actor->runAction(RepeatForever::create(animate));

	scheduleUpdate();
	return true;
}

void LoadingScene::update(float deltaTime)
{
}

LoadingScene::LoadingScene()
{
}

LoadingScene::~LoadingScene()
{
}
