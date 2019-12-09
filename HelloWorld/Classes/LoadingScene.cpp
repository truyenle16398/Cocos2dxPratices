#include "LoadingScene.h"
#include "ui/CocosGUI.h"
#include "ResourceManager.h"
#include "OObject.h"


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

	auto bg = clone(ResourceManager::GetInstance()->GetSpriteById(1));
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, -1);
	/*--------------------------------------*/
	//loading bar

	
	auto loadingBarBG = clone(ResourceManager::GetInstance()->GetSpriteById(7));
	loadingBarBG->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 130));
	this->addChild(loadingBarBG);



	 auto loadingbar = ResourceManager::GetInstance()->GetLoadingById(0);
	//loadingbar->retain();
	loadingbar->setPosition(loadingBarBG->getPosition());
	loadingbar->setPercent(20);
	loadingbar->setDirection(ui::LoadingBar::Direction::LEFT);//chay tu ben trai qua
	addChild(loadingbar);

	auto updateLoadingBar = CallFunc::create([]() {
		//if (loadingbar->getPercent() < 100)
		{
			//loadingbar->setPercent(loadingbar->getPercent() + 1);
		}
	});
	auto sequenceRunUpdateLoadingBar = Sequence::createWithTwoActions(updateLoadingBar, DelayTime::create(0.1f));
	auto repeat = Repeat::create(sequenceRunUpdateLoadingBar, 100);
	loadingbar->runAction(repeat);



	//lable
	auto labelLoading = Label::createWithTTF("LOADING...", "COOPBL.TTF", 30);
	labelLoading->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 125));
	labelLoading->enableShadow();

	auto fadeIn = FadeIn::create(1.0f);
	auto fadeOut = FadeOut::create(1.0f);
	auto seq = Sequence::createWithTwoActions(fadeIn, fadeOut);
	labelLoading->runAction(RepeatForever::create(seq));
	this->addChild(labelLoading);

	scheduleUpdate();
	return true;
}

void LoadingScene::update(float deltaTime)
{
}

LoadingScene::LoadingScene()
{
}

Sprite * LoadingScene::clone(Sprite * sprite)
{
	auto s_clone = Sprite::createWithTexture(sprite->getTexture());
	return s_clone;
}

LoadingScene::~LoadingScene()
{
}
