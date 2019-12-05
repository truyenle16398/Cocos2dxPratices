#include "..\Classes\Bullet.h"
#include "ResourceManager.h"


void Bullet::Init()
{
	this->setSprite(ResourceManager::GetInstance()->GetSpriteById(4));
	this->getSprite()->setScale(0.2);

}

void Bullet::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x + 300 * deltaTime, this->getSprite()->getPosition().y);
	if (this->getSprite()->getPosition().x >= Director::getInstance()->getVisibleSize().width )
	{
		this->getSprite()->setPosition(0, Director::getInstance()->getVisibleSize().height / 2);
	}
}

Bullet::Bullet(Scene * scene)
{
	Init();
	scene->addChild(this->getSprite());
	this->getSprite()->setPosition(0, Director::getInstance()->getVisibleSize().height / 2);
}

Bullet::~Bullet()
{
}
