#include "..\Classes\Bullet.h"
#include "ResourceManager.h"


void Bullet::Init()
{
	auto bullet = ResourceManager::GetInstance()->GetSpriteById(4);
	auto cloneBullet = Sprite::createWithSpriteFrame(bullet->getSpriteFrame());
	setSprite(cloneBullet);
	this->getSprite()->setScale(0.1);

}

void Bullet::Update(float deltaTime)
{
	auto move = MoveBy::create(2.0f, Vec2(1000,0));
	this->getSprite()->runAction(move);
}

Bullet::Bullet(Scene * scene)
{
	Init();
}

Bullet::~Bullet()
{
}
