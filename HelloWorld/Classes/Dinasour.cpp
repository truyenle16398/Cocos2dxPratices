#include "Dinasour.h"
#include "ResourceManager.h"
#include "GamePlayScene.h"
#include "Bullet.h"


void Dinasour::Init()
{
	//Init dinasour
	auto dinasourlist = SpriteFrameCache::getInstance();
	dinasourlist->addSpriteFramesWithFile("dinasou.plist", "dinasour1.png");

	this->setSprite(ResourceManager::GetInstance()->GetSpriteById(5));
	this->getSprite()->setScale(0.5);

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
	m_bullets[0]->Update(deltaTime);

	if (m_bullets[0]->getSprite()->isVisible() == false)
	{
		m_bullets[0]->getSprite()->setVisible(true);
		//m_bullets[0]->Update(deltaTime);
		//m_bullets[0]->getSprite()->setVisible(false);
	}

	if (m_bullets[0]->getSprite()->getPosition().x >= Director::getInstance()->getVisibleSize().width)
	{
		m_bullets[0]->getSprite()->setPosition(this->getSprite()->getPosition());
	}

	
}

void Dinasour::Collision(vector<Rock1*>)
{
}

Dinasour::Dinasour(Scene* scene)
{
	Init();
	scene->addChild(this->getSprite(),0);
	this->getSprite()->setPosition(100, Director::getInstance()->getVisibleSize().height / 2);

		Bullet *bullet = new Bullet(scene);
		this->m_bullets.push_back(bullet);
		scene->addChild(m_bullets[0]->getSprite(),0);
		m_bullets[0]->getSprite()->setPosition(this->getSprite()->getPosition());
		//m_bullets[0]->getSprite()->setVisible(false);
	

}

Dinasour::~Dinasour()
{
}
