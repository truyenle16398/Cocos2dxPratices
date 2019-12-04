#pragma once
#include "OObject.h"
#include "Rock.h"
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
	void Collision(vector<Rock*>);

	Dinasour(Scene* scene);
	~Dinasour();
};

