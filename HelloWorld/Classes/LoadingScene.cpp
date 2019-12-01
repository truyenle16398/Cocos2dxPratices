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

	auto bg = Sprite::create("background.png");
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, 0);

	auto spriteCache = SpriteFrameCache::getInstance();
	spriteCache->addSpriteFramesWithFile("list.plist", "list.png");
	
	

	auto actor = Sprite::create("0_Fallen_Angels_Walking_000.png");
	actor->setPosition(100,100);
	actor->setScale(scale);
	this->addChild(actor, 1);


	Vector<SpriteFrame*>list;
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_000.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_002.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_004.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_006.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_008.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_010.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_012.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_014.png", Rect(0, 0, 150, 150)));
	list.pushBack(SpriteFrame::create("0_Fallen_Angels_Walking_016.png", Rect(0, 0, 150, 150)));


	auto animation = Animation::createWithSpriteFrames(list, 0.1f);
	auto animate = Animate::create(animation);
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
