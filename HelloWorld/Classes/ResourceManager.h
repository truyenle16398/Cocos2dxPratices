#pragma once
#include <string>
#include <map>
#include <iostream>
#include <cocos2d.h>
#include<ui/CocosGUI.h>
USING_NS_CC;
using namespace std;

class ResourceManager
{
private:
	string m_dataFolderPath;
	map<char, Sprite*> m_sprites;
	map<char, ui::Button*> m_buttons;
	map<char, Label*> m_labels;

public:
	ResourceManager* GetInstance();
	void Init(const string path);
	void Load(string fileName);
	Sprite* GetSpriteById(char id);
	ui::Button* GetButtonById(char id);
	Label* GetLableById(char id);


	ResourceManager();
	~ResourceManager();
};

