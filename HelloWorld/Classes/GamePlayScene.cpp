#include "GamePlayScene.h"
#include "ResourceManager.h"
#include "Rock1.h"
#include "Bullet.h"
#include "Dinasour.h"
#include <time.h>

vector<Rock1*> vectorRock;

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

	//Background
	auto bg = ResourceManager::GetInstance()->GetSpriteById(0);
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, -1);
	
	d = new Dinasour(this);//create Dinasour

	r = new Rock1(this);//create Rock

	//Mouse
	auto listenerMouse = EventListenerTouchOneByOne::create();
	listenerMouse->onTouchBegan = CC_CALLBACK_2(GamePlayScene::OnTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);

	//Keyboard
	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(GamePlayScene::onKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, d->getSprite());

	scheduleUpdate();
	return true;
}

void GamePlayScene::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
{
	switch (keyCode)
	{
	case EventKeyboard::KeyCode::KEY_UP_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3,Vec2(d->getSprite()->getPosition().x, d->getSprite()->getPosition().y + 30)));// 1 lan bam di chuyen 30. => s = 30. v tu cho = 100. => t = s/v = 0.3
		break;
	}
	case EventKeyboard::KeyCode::KEY_DOWN_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(d->getSprite()->getPosition().x, d->getSprite()->getPosition().y - 30)));
		break;
	}
	case EventKeyboard::KeyCode::KEY_RIGHT_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(d->getSprite()->getPosition().x + 30, d->getSprite()->getPosition().y)));
		break;
	}
	case EventKeyboard::KeyCode::KEY_LEFT_ARROW: {
		event->getCurrentTarget()->runAction(MoveTo::create(0.3, Vec2(d->getSprite()->getPosition().x - 30, d->getSprite()->getPosition().y)));
		break;
	}
	default:
		break;
	}
}

bool GamePlayScene::OnTouchBegan(Touch* touch, Event* event)
{
	double t = sqrt(pow((touch->getLocation().x - d->getSprite()->getPosition().x), 2) + pow((touch->getLocation().y - d->getSprite()->getPosition().y), 2)) / 100;// t = s/v. s la khoang cach 2 diem. v la van toc tu cho = 100
	auto move = MoveTo::create(t, Vec2(touch->getLocation().x, touch->getLocation().y));
	d->getSprite()->runAction(move);
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	r->Update(deltaTime);
	d->Update(deltaTime);
}

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}
