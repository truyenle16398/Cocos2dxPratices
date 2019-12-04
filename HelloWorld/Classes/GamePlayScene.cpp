#include "GamePlayScene.h"


Scene * GamePlayScene::createScene()
{
	return GamePlayScene::create();
}

bool GamePlayScene::init()
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
	this->addChild(bg, -1);

	//dinasour
	auto dinasourlist = SpriteFrameCache::getInstance();
	dinasourlist->addSpriteFramesWithFile("dinasou.plist", "dinasour1.png");
	dinasour = Sprite::create();
	dinasour->setPosition(Vec2(80,80));
	dinasour->setScale(0.35);
	this->addChild(dinasour);

	Vector<SpriteFrame*>list;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			list.pushBack(SpriteFrame::create("dinasour1.png", Rect(j*450, i*370, 450, 370)));
		}
	}

	list.reverse();
	Animation* animation = Animation::createWithSpriteFrames(list, 0.1f);
	Animate* animate = Animate::create(animation);
	dinasour->runAction(RepeatForever::create(animate));

	//Mouse
	auto listenerMouse = EventListenerTouchOneByOne::create();
	listenerMouse->onTouchBegan = CC_CALLBACK_2(GamePlayScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);
	
	//Keyboard
	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, dinasour);


	scheduleUpdate();
	return true;
}

void GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3,Vec2(dinasour->getPosition().x, dinasour->getPosition().y + 30)));// 1 lan bam di chuyen 30. => s = 30. v tu cho = 100. => t = s/v = 0.3
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(dinasour->getPosition().x, dinasour->getPosition().y - 30)));
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(dinasour->getPosition().x + 30, dinasour->getPosition().y)));
		break;
	}
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(dinasour->getPosition().x - 30, dinasour->getPosition().y)));
		break;
	}
	default:
		break;
	}
}
void GamePlayScene::update(float deltaTime)
{
}

bool GamePlayScene::OnTouchBegan(Touch* touch, Event* event)
{
	double t = sqrt(pow((touch->getLocation().x - dinasour->getPosition().x), 2) + pow((touch->getLocation().y - dinasour->getPosition().y), 2)) / 100;// t = s/v. s la khoang cach 2 diem. v la van toc tu cho = 100
	auto move = MoveTo::create(t, Vec2(touch->getLocation().x, touch->getLocation().y));
	dinasour->runAction(move);
	return true;
}

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}
