#include "Rock1.h"
#include "ResourceManager.h"
#include<time.h>



void Rock1::Init()
{
	auto rock = ResourceManager::GetInstance()->GetSpriteById(6);
	auto cloneRock = Sprite::createWithSpriteFrame(rock->getSpriteFrame());
	setSprite(cloneRock);
	this->getSprite()->setScale(1.5);
}

void Rock1::Update(float deltaTime)
{
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto rock = getSprite();
	if (rock->getPosition().x <= 0)
	{
		rock->setVisible(false);
		rock->stopAllActions();
		rock->setPosition(visibleSize.width, rock->getPosition().y);
	}
}

Rock1::Rock1(Scene* scene)
{
	Init();
}

Rock1::~Rock1()
{
}
