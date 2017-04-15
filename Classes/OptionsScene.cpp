#include "OptionsScene.h"
#include "MenuScene.h"

USING_NS_CC;

Scene* OptionsScene::scene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease
	auto layer = OptionsScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool OptionsScene::init()
{
	// Super init
	if (!Layer::init())
		return false;

	// Set menu position
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto middleScreen = Point((visibleSize.width + origin.x) / 2, (visibleSize.height + origin.y) / 2);

	// Add background
	auto background = Sprite::create("game_options.png");
	background->setPosition(middleScreen);
	this->addChild(background, 0);

	// Create menu items
	auto music = MenuItemImage::create("green_pinup_press.png", "", CC_CALLBACK_1(OptionsScene::music, this));
	music->setPosition(Point::ZERO);

	auto effects = MenuItemImage::create("green_pinup_press.png", "", CC_CALLBACK_1(OptionsScene::effects, this));
	effects->setPosition(Point::ZERO);

	auto back = MenuItemImage::create("btn_voltar.png", "", CC_CALLBACK_1(OptionsScene::back, this));
	back->setPosition(Point::ZERO);

	// Create menus
	auto menuOptions = Menu::create(music, effects, NULL);
	menuOptions->setPosition(Vec2::ZERO);

	auto menuNav = Menu::create(back, NULL);
	menuNav->setPosition(Point(visibleSize.width * 0.25 + origin.x, visibleSize.height * 0.20 + origin.y));
	
	// Add menus to layer
	this->addChild(menuOptions, 1);
	this->addChild(menuNav, 1);

	//this->setPosition(middleScreen);
}

void OptionsScene::music(cocos2d::Ref* pSender)
{
	// Todo
}

void OptionsScene::effects(cocos2d::Ref* pSender)
{
	// Todo
}

void OptionsScene::back(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}