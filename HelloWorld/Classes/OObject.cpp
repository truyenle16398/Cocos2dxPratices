#include "OObject.h"



void OObject::Init()
{
}

void OObject::Update(float deltaTime)
{
}

void OObject::setSprite(Sprite * sprite)
{
	this->m_sprite = sprite;
}

Sprite * OObject::getSprite()
{
	return this->m_sprite;
}

OObject::OObject()
{
}

OObject::~OObject()
{
}
