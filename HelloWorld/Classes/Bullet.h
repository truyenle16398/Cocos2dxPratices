#pragma once
#include "OObject.h"
class Bullet :
	public OObject
{
public:
	void Init();
	void Update(float deltaTime);

	Bullet(Scene * scene);
	~Bullet();
};

