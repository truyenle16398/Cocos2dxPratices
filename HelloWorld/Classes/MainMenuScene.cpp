#include "MainMenuScene.h"
#include "ui/CocosGUI.h"
#include "LoadingScene.h"
#include "SettingScene.h"
#include "ResourceManager.h"
#include "Rock1.h"
#include "Bullet.h"


Scene * MainMenuScene::createScene()
{
	return MainMenuScene::create();
}

bool MainMenuScene::init()
{
	auto visibleSize = Director::getInstance()->getVisibleSize();

	if (!Scene::init())
	{
		return false;
	}

	/*auto bg = Sprite::create("background1.png");//background
	auto btPlay = ui::Button::create("btPlay.png");//button play
	auto btSetting = ui::Button::create("btSetting.png");//button setting
	
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	btPlay->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 60));
	btSetting->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 70));
	
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);

	btPlay->setScale(0.5);
	btSetting->setScale(0.45);
	bg->setScale(scale);

	//set event Play & Setting
	btPlay->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN: {
			break;
		}
		case ui::Widget::TouchEventType::ENDED: {
			auto reScene = LoadingScene::createScene();
			Director::getInstance()->replaceScene(TransitionFade::create(2, reScene, Color3B(0, 0, 0)));
			break; }
		default:
			break;
		}
	});

	btSetting->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type) {
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN: {
			break;
		}
		case ui::Widget::TouchEventType::ENDED: {
			Director::getInstance()->replaceScene(SettingScene::create());
			break;
		}
		default:
			break;
		}
	});

	//print screen
	this->addChild(bg);
	this->addChild(btPlay);
	this->addChild(btSetting);*/

	r = new Rock1(this);
	b = new Bullet(this);
	scheduleUpdate();
	return true;
}

void MainMenuScene::update(float deltaTime)
{
	this->r->Update(deltaTime);
	this->b->Update(deltaTime);
}
