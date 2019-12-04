#pragma once
#include "OObject.h"
class Rock :
	public OObject
{
public:
	void Init();
	void Update(float deltaTime);

	Rock(Scene * scene);
	~Rock();
};

