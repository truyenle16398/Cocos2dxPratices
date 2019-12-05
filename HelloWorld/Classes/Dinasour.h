#pragma once
#include "OObject.h"
#include "Rock1.h"
#include <list>
using namespace std;

class Dinasour :
	public OObject
{
private:
	list <OObject*> m_bullets;
public:
	void Init();
	void Update(float deltaTime);
	void Shoot();
	void Collision(vector<Rock1*>);

	Dinasour(Scene* scene);
	~Dinasour();
};

