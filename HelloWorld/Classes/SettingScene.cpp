#include "SettingScene.h"


Scene * SettingScene::createScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	if (!Scene::init())
	{
		return false;
	}

	auto bg = Sprite::create("background.png");//background
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	//this->addChild(bg,-1);

	auto itemSound = MenuItemImage::create("btSound.png", "", CC_CALLBACK_0(SettingScene::SoundCallback, this));
	itemSound->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 30));
	
	auto itemAbout = MenuItemImage::create("btAbout.png", "", CC_CALLBACK_0(SettingScene::AboutCallback, this));
	itemAbout->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 50));

	itemSound->setScale(0.2);
	itemAbout->setScale(0.2);

	auto myMenu = Menu::create(itemSound,itemAbout,nullptr);
	myMenu->setPosition(0, 0);
	this->addChild(myMenu);

	/*Vector<MenuItem*> menuItems;
	menuItems.pushBack(itemSound);
	menuItems.pushBack(itemAbout);

	auto menu */

	

	scheduleUpdate();
	return true;
}

void SettingScene::update(float deltaTime)
{
}

void SettingScene::SoundCallback()
{
	exit(0);
}

void SettingScene::AboutCallback()
{
	exit(0);
}

SettingScene::SettingScene()
{
}


SettingScene::~SettingScene()
{
}
