#include "GameOverScene.h"
#include "MenuScene.h"

USING_NS_CC;

std::string timeGame;
uint32_t score;

Scene* GameOverScene::scene(std::string aTimeGame, uint32_t aScore)
{
	// Set the game params to be showed
	timeGame = aTimeGame;
	score = aScore;

	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease
	auto layer = GameOverScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
	// Super init
	if (!Layer::init())
		return false;

	// Set menu position
	auto visibleSize = Director::getInstance()->getVisibleSize();
	auto origin = Director::getInstance()->getVisibleOrigin();
	auto middleScreen = Point((visibleSize.width + origin.x) / 2, (visibleSize.height + origin.y) / 2);

	// Add background
	auto background = Sprite::create("game_over.png");
	background->setPosition(middleScreen);
	this->addChild(background, 0);

	// Create time label
	auto timeLabel = Label::createWithTTF(timeGame, "fonts/arial.ttf", 14);
	timeLabel->setColor(Color3B(0, 0, 0));
	timeLabel->setPosition(Point(middleScreen.x, visibleSize.height * 0.27 + origin.y));
	this->addChild(timeLabel, 1);

	// Create score label
	auto scoreLabel = Label::createWithTTF(std::to_string(score), "fonts/arial.ttf", 14);
	scoreLabel->setColor(Color3B(0, 0, 0));
	scoreLabel->setPosition(Point(middleScreen.x, visibleSize.height * 0.4 + origin.y));
	this->addChild(scoreLabel);

	auto back = MenuItemImage::create("btn_voltar.png", "", CC_CALLBACK_1(GameOverScene::back, this));
	back->setPosition(Point::ZERO);

	// Create menus
	auto menuNav = Menu::create(back, NULL);
	menuNav->setPosition(Point(visibleSize.width * 0.25 + origin.x, visibleSize.height * 0.20 + origin.y));

	// Add menus to layer
	this->addChild(menuNav, 1);
}

void GameOverScene::back(cocos2d::Ref* pSender)
{
	Director::getInstance()->replaceScene(MenuScene::scene());
}