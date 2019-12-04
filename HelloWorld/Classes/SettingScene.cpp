#include "SettingScene.h"
#include "ui/CocosGUI.h"
using namespace cocos2d::ui;

static Layout* l_Sound;
static Layout* l_About;

Scene * SettingScene::createScene()
{
	return SettingScene::create();
}

bool SettingScene::init()
{
	static auto visibleSize = Director::getInstance()->getVisibleSize();
	static Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!Scene::init())
	{
		return false;
	}

	auto bg = Sprite::create("background1.png");//background
	bg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	float scale = MAX(visibleSize.width / bg->getContentSize().width, visibleSize.height / bg->getContentSize().height);
	bg->setScale(scale);
	this->addChild(bg, -1);

	auto itemSound = MenuItemImage::create("btSound.png", "", CC_CALLBACK_0(SettingScene::SoundCallback, this));
	itemSound->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y + 60));

	auto itemAbout = MenuItemImage::create("btAbout.png", "", CC_CALLBACK_0(SettingScene::AboutCallback, this));
	itemAbout->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 80));

	itemSound->setScale(0.5);
	itemAbout->setScale(0.5);

	auto myMenu = Menu::create(itemSound, itemAbout, nullptr);
	myMenu->setPosition(0, 0);
	this->addChild(myMenu);

	/*--------------------------------------------------------------------------*/
	//LAYOUT SOUND
	l_Sound = ui::Layout::create();
	l_Sound->setContentSize(cocos2d::Size(250, 50));
	l_Sound->setPosition(Vec2(0, 0));
	this->addChild(l_Sound);

	//boardSound
	auto board = Sprite::create("board.png");
	board->setScale(0.8);
	board->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//checkbox
	auto checkBox = ui::CheckBox::create("checkBox.png",
		"checkBoxTick_OK.png");
	checkBox->setScale(0.3);
	checkBox->setPosition(Vec2(visibleSize.width / 2 + origin.x + 70, visibleSize.height / 2 + origin.y + 45));
	checkBox->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			break;
		case ui::Widget::TouchEventType::ENDED:
			log("checkbox 1 clicked");
			break;
		default:
			break;
		}
	});

	//slider
	static auto slider = ui::Slider::create();
	slider->loadBarTexture("slider_bar_bg.png");
	slider->loadSlidBallTextures("slider_ball_normal.png", "slider_ball_disable.png");
	slider->loadProgressBarTexture("slider_bar_pressed.png");
	slider->setPercent(30);
	slider->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 60));
	slider->setScale(0.5);
	slider->addClickEventListener([](Ref* event) {
		log("Slider: %d", slider->getPercent());
	});

	//label display info
	auto labelSound = Label::createWithTTF("SOUND:", "COOPBL.TTF", 30);
	labelSound->setPosition(Vec2(visibleSize.width / 2 + origin.x - 25, visibleSize.height / 2 + origin.y + 45));
	labelSound->enableShadow();

	auto labelMusic = Label::createWithTTF("MUSIC:", "COOPBL.TTF", 30);
	labelMusic->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y - 20));
	labelMusic->enableShadow();

	//printf in layout Sound
	l_Sound->addChild(board, 0);
	l_Sound->addChild(labelSound);
	l_Sound->addChild(labelMusic);
	l_Sound->addChild(checkBox);
	l_Sound->addChild(slider);

	l_Sound->setVisible(false);

	/*--------------------------------------------------------------------------*/
	//LAYOUT ABOUT
	l_About = ui::Layout::create();
	l_About->setContentSize(cocos2d::Size(250, 50));
	l_About->setPosition(Vec2(0, 0));
	this->addChild(l_About);

	//boardSound
	auto board1 = Sprite::create("board.png");
	board1->setScale(0.4);
	board1->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	//scrollView
	auto scrollView = ui::ScrollView::create();
	scrollView->setDirection(ui::ScrollView::Direction::VERTICAL);
	scrollView->setContentSize(Size(300, 200));
	scrollView->setInnerContainerSize(Size(1280, 2500));
	scrollView->setBounceEnabled(true);
	scrollView->setPosition(Vec2(100, 200));

	for (int i = 0; i < 10; i++)
	{
		auto label = Label::createWithTTF("MUSIC:", "COOPBL.TTF", 30);
		label->setPosition(Vec2(scrollView->getContentSize().width / 2, i * 20));
		scrollView->addChild(label);
	}

	this->addChild(scrollView);

	//printf in layout About
	//l_About->addChild(scrollView);
	l_About->addChild(board1, 0);
	l_About->setVisible(false);

	/*--------------------------------------------------------------------------*/
	//TextField display PlayerName

	static auto playerName = ui::TextField::create("CLick here to enter Player Name", "COOPBL.TTF", 20);
	playerName->setMaxLengthEnabled(true);
	playerName->setMaxLength(30);
	playerName->setColor(cocos2d::Color3B(255, 6, 6));
	playerName->setPasswordEnabled(false);
	playerName->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height + origin.y - 40));

	playerName->addTouchEventListener([&](Ref* sender, ui::Widget::TouchEventType type)
	{
		log("editing a TextField");
	});
	addChild(playerName);
	//scheduleUpdate();
	return true;
}


void SettingScene::SoundCallback()
{
	if (l_Sound->isVisible() == false) {
		l_Sound->setVisible(true);
	}
	else l_Sound->setVisible(false);

}

void SettingScene::AboutCallback()
{
	if (l_About->isVisible() == false) {
		l_About->setVisible(true);
	}
	else l_About->setVisible(false);
}

SettingScene::SettingScene()
{
}

SettingScene::~SettingScene()
{
}
