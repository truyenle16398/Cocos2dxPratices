#include "ResourceManager.h"


ResourceManager* ResourceManager::s_instance = NULL;

ResourceManager * ResourceManager::GetInstance()
{
	if (!s_instance) {
		s_instance = new ResourceManager();
	}
	return s_instance;
}

void ResourceManager::Init(const string path)
{
	this->m_dataFolderPath = path;
	Load(m_dataFolderPath);
}

void ResourceManager::Load(string fileName)
{
	//load all data from Data.bin
	string readFromFile = FileUtils::getInstance()->getStringFromFile(fileName);//store all text in file 
	//log("%s",readFromFile.c_str());

	std::vector<string> vector_lines;//create vector to store line in file
	
	//split by "\n" into line
	char *readFromFileChar = const_cast<char*>(readFromFile.c_str());
	char* line = strtok(readFromFileChar, "\r\n");//split into line
	
	while (line != NULL)
	{
		vector_lines.push_back(line);//push line into vector
		line = strtok(NULL, "\r\n");//continue split
	}

	//split line into 2 string
	string str1, str2, str3;
	for (int i = 0; i < vector_lines.size(); i++)
	{
		istringstream is(vector_lines[i]);
		is >> str1 >> str2;

		if (str1 == "#SPRITE")
		{
			int numOfSprite = stoi(str2);
			while (numOfSprite > 0)
			{
				i++;
				istringstream is(vector_lines[i]);
				is >> str1 >> str2;
				int id = stoi(str2);
				i++;
				istringstream is1(vector_lines[i]);
				is1 >> str1 >> str2;
				string path = str2;
				numOfSprite--;
			}
		}

		else if (str1 == "#BUTTON")
		{
			int numOfButton = stoi(str2);
			while (numOfButton > 0)
			{
				i++;
				istringstream is(vector_lines[i]);
				is >> str1 >> str2;
				int id = stoi(str2);

				i++;
				istringstream is1(vector_lines[i]);
				is1 >> str1 >> str2;
				string path1 = str2;

				i++;
				istringstream is2(vector_lines[i]);
				is2 >> str1 >> str2;
				string path2 = str2;

				numOfButton--;
			}
		}

		else if (str1 == "#FONT")
		{
			int numOfFont = stoi(str2);
			while (numOfFont > 0)
			{
				i++;
				istringstream is(vector_lines[i]);
				is >> str1 >> str2;
				int id = stoi(str2);
				i++;
				istringstream is1(vector_lines[i]);
				is1 >> str1 >> str2;
				string path = str2;

				numOfFont--;
			}
		}

	}

}

Sprite * ResourceManager::GetSpriteById(int id)
{
	return m_sprites[id];
}

ui::Button * ResourceManager::GetButtonById(int id)
{
	return m_buttons[id];
}

Label * ResourceManager::GetLableById(int id)
{
	return m_labels[id];
}


ResourceManager::ResourceManager()
{
}


ResourceManager::~ResourceManager()
{
}
