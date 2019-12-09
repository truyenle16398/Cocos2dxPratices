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
	static ResourceManager* s_instance;
	string m_dataFolderPath;
	map<int, Sprite*> m_sprites;
	map<int, ui::Button*> m_buttons;
	map<int, Label*> m_labels;
	map<int, ui::LoadingBar*>m_loadings;
	ResourceManager();

public:
	static ResourceManager* GetInstance();
	void Init(const string path);
	void Load(string fileName);

	Sprite* GetSpriteById(int id);
	ui::Button* GetButtonById(int id);
	Label* GetLableById(int id);
	ui::LoadingBar* GetLoadingById(int id);
		
	~ResourceManager();
};

