#include "Rock1.h"
#include "ResourceManager.h"



void Rock1::Init()
{
	this->setSprite(ResourceManager::GetInstance()->GetSpriteById(6));
	this->getSprite()->setScale(1.5);
}

void Rock1::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x - 100 * deltaTime, this->getSprite()->getPosition().y);
	if (this->getSprite()->getPosition().x <= 0)
	{
		this->getSprite()->setPosition(Director::getInstance()->getVisibleSize().width , Director::getInstance()->getVisibleSize().height / 2);
	}
}

Rock1::Rock1(Scene* scene)
{
	Init();
	scene->addChild(this->getSprite());
	this->getSprite()->setPosition(Director::getInstance()->getVisibleSize().width , Director::getInstance()->getVisibleSize().height/2);
}

Rock1::~Rock1()
{
}
