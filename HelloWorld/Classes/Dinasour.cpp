#include "Dinasour.h"
#include "ResourceManager.h"
#include "GamePlayScene.h"
#include "Bullet.h"

static float a = 0;
void Dinasour::Init()
{
	//Init dinasour
	auto dinasourlist = SpriteFrameCache::getInstance();
	dinasourlist->addSpriteFramesWithFile("dinasou.plist", "dinasour1.png");

	this->setSprite(ResourceManager::GetInstance()->GetSpriteById(5));
	this->getSprite()->setScale(0.4);

	Vector<SpriteFrame*>list;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			list.pushBack(SpriteFrame::create("dinasour1.png", Rect(j * 450, i * 370, 450, 370)));
		}
	}

	list.reverse();
	Animation* animation = Animation::createWithSpriteFrames(list, 0.1f);
	Animate* animate = Animate::create(animation);
	this->getSprite()->runAction(RepeatForever::create(animate));
}

void Dinasour::Update(float deltaTime)
{
	this->Shoot(deltaTime);
	
}

void Dinasour::Shoot(float deltaTime)
{
	a += deltaTime;
	for (int i = 0; i < m_bullets.size(); i++)
	{
		if (m_bullets[i]->getSprite()->isVisible() == false && a >= 15 * deltaTime)
		{
			m_bullets[i]->getSprite()->setVisible(true);
			m_bullets[i]->getSprite()->setPosition(this->getSprite()->getPosition());
			m_bullets[i]->Update(deltaTime);
			a = 0;
		}
		if (m_bullets[i]->getSprite()->getPosition().x >= Director::getInstance()->getVisibleSize().width)
		{
			m_bullets[i]->getSprite()->stopAllActions();
			m_bullets[i]->getSprite()->setVisible(false);
			m_bullets[i]->getSprite()->setPosition(Vec2(this->getSprite()->getPosition().x, this->getSprite()->getPosition().y));
		}
		
	}
}

void Dinasour::Collision(vector<Rock1*> rocks)
{
	for (int i = 0; i < rocks.size(); i++)
	{
		auto rock = rocks[i]->getSprite();
		for (int i = 0; i < m_bullets.size(); i++)
		{
			auto bullet = this->m_bullets[i]->getSprite();
			if (bullet->getBoundingBox().intersectsRect(rock->getBoundingBox())
				&& rock->isVisible() && bullet->isVisible())
			{
				bullet->setVisible(false);
				rock->setVisible(false);
				rock->setPosition(rock->getPosition().x, -100);
				bullet->setPosition(bullet->getPosition().x, 1000);
			}
		}
	}
}

Dinasour::Dinasour(Scene* scene)
{
	Init();
	scene->addChild(this->getSprite(),0);
	this->getSprite()->setPosition(100, Director::getInstance()->getVisibleSize().height / 2);

	for (int i = 0; i < 10; i++)
	{
		Bullet *bullet = new Bullet(scene);
		this->m_bullets.push_back(bullet);
		scene->addChild(m_bullets[i]->getSprite(), 0);
		m_bullets[i]->getSprite()->setVisible(false);
	}
}

Dinasour::~Dinasour()
{
}
