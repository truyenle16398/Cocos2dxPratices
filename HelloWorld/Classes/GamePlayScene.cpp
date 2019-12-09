#include "GamePlayScene.h"
#include "ResourceManager.h"
#include "Rock1.h"
#include "Bullet.h"
#include "Dinasour.h"
#include "SimpleAudioEngine.h"
#include <time.h>
#include <vector>
using namespace std;
using namespace CocosDenshion;

static float a = 0;
Dinasour* d;
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
	//Background Audio
	auto audio = SimpleAudioEngine::getInstance();
	audio->playBackgroundMusic("Sounds/ingame.mp3", true);
	//Background
	auto bg = ResourceManager::GetInstance()->GetSpriteById(0);
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, -1);
	
	d = new Dinasour(this);//create Dinasour
	//create rock
	for (int i = 0; i < 20; i++)
	{
		auto r = new Rock1(this);
		this->m_rocks.push_back(r);
		this->addChild(r->getSprite());
		r->getSprite()->setPosition(visibleSize.width , i * visibleSize.height / 20);
		r->getSprite()->setVisible(false);
	}
						   
	//Mouse
	auto listenerMouse = EventListenerTouchOneByOne::create();
	listenerMouse->onTouchBegan = CC_CALLBACK_2(GamePlayScene::OnTouchBegan, this);
	listenerMouse->onTouchMoved = CC_CALLBACK_2(GamePlayScene::OnTouchMoved, this);
	listenerMouse->onTouchEnded = CC_CALLBACK_2(GamePlayScene::OnTouchEnded, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerMouse, this);

	

	//Keyboard
	auto listenerKeyboard = EventListenerKeyboard::create();
	listenerKeyboard->onKeyPressed = CC_CALLBACK_2(GamePlayScene::OnKeyPressed, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(listenerKeyboard, d->getSprite());

	scheduleUpdate();
	return true;
}


void GamePlayScene::OnKeyPressed(EventKeyboard::KeyCode keyCode, Event* event)
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

bool GamePlayScene::OnTouchEnded(Touch * touch, Event * event)
{
	return false;
}

bool GamePlayScene::OnTouchMoved(Touch * touch, Event * event)
{
	d->getSprite()->setPosition(d->getSprite()->getPosition() + touch->getDelta());
	return true;
}

void GamePlayScene::update(float deltaTime)
{
	a += deltaTime;
	auto visibleSize = Director::getInstance()->getVisibleSize();
	d->Update(deltaTime);
	
	int rockSize = this->m_rocks.size();
	int randomNumber = rand() % (rockSize + 1);
	auto moveBy = MoveBy::create(10.0f, Vec2(-1300, 0));
	if (a > 60 * deltaTime)
	{
		for (int i = randomNumber; i < rockSize; i++)
		{
			auto rock = this->m_rocks[i]->getSprite();
			if (!rock->isVisible())
			{
				rock->runAction(moveBy->clone());
				rock->setVisible(true);
				i = rockSize + 10;
				a = 0;
			}
		}
	}
	for (int i = 0; i < rockSize; i++)
	{
		this->m_rocks[i]->Update(deltaTime);
	}
	d->Collision(m_rocks);
}

GamePlayScene::GamePlayScene()
{
}

GamePlayScene::~GamePlayScene()
{
}
