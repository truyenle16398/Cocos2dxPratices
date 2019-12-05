#pragma once
#include "OObject.h"
class Rock1 :
	public OObject
{
public:
	void Init();
	void Update(float deltaTime);

	Rock1(Scene* scene);
	~Rock1();
};