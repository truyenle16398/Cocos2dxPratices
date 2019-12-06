#include "..\Classes\Bullet.h"
#include "ResourceManager.h"


void Bullet::Init()
{
	this->setSprite(ResourceManager::GetInstance()->GetSpriteById(4));
	this->getSprite()->setScale(0.1);

}

void Bullet::Update(float deltaTime)
{
	this->getSprite()->setPosition(this->getSprite()->getPosition().x + 500 * deltaTime, this->getSprite()->getPosition().y);
}

Bullet::Bullet(Scene * scene)
{
	Init();
}

Bullet::~Bullet()
{
}
