#pragma once
#include <cocos2d.h>
USING_NS_CC;
class OObject
{
private:
	Sprite* m_sprite;
public:
	virtual void Init();
	virtual void Update(float deltaTime);

	OObject();
	~OObject();
};

