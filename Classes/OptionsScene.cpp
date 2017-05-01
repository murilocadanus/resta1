#include "OptionsScene.h"
#include "MenuScene.h"
#include "SimpleAudioEngine.h"

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

	// Create toggle for music
	auto musicItemOn = MenuItemImage::create("green_pinup.png", "green_pinup.png");
    auto musicItemOff = MenuItemImage::create("green_pinup_press.png", "green_pinup_press.png");
    
	auto itemToggleMusic = MenuItemToggle::createWithCallback([&](Ref* pSender)
    {
        MenuItemToggle *toggleItem = (MenuItemToggle *)pSender;
        
		if (CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() == 0.0f) {
			CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.5f);
            toggleItem->setSelectedIndex(0);
		}
		else {
			CocosDenshion::SimpleAudioEngine::getInstance()->setBackgroundMusicVolume(0.0f);
            toggleItem->setSelectedIndex(1);
		}
	}, musicItemOn, musicItemOff, NULL);
    
    // Check music state to start enable or disabled
    if (CocosDenshion::SimpleAudioEngine::getInstance()->getBackgroundMusicVolume() == 0.0f) itemToggleMusic->setSelectedIndex(1);
    else itemToggleMusic->setSelectedIndex(0);

	// Create toogle for effects
    auto effectsItemOn = MenuItemImage::create("green_pinup.png", "green_pinup.png");
    auto effectsItemOff = MenuItemImage::create("green_pinup_press.png", "green_pinup_press.png");
    
	auto itemToggleEffects = MenuItemToggle::createWithCallback([&](Ref* pSender)
    {
        MenuItemToggle *toggleItem = (MenuItemToggle *)pSender;
        
        if (CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume() == 0.0f) {
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.5f);
            toggleItem->setSelectedIndex(0);
        }
        else {
            CocosDenshion::SimpleAudioEngine::getInstance()->setEffectsVolume(0.0f);
            toggleItem->setSelectedIndex(1);
        }
    }, effectsItemOn, effectsItemOff, NULL);
    
    // Check effects state to start enable or disabled
    if (CocosDenshion::SimpleAudioEngine::getInstance()->getEffectsVolume() == 0.0f) itemToggleEffects->setSelectedIndex(1);
    else itemToggleEffects->setSelectedIndex(0);

	auto backBtn = MenuItemImage::create("btn_voltar.png", "btn_voltar.png", CC_CALLBACK_1(OptionsScene::back, this));

	// Create menus
	auto menuOptions = Menu::create(itemToggleMusic, itemToggleEffects, NULL);
	menuOptions->alignItemsVerticallyWithPadding(visibleSize.height * 0.028);
	menuOptions->setPosition(Point(visibleSize.width * 0.72 + origin.x, visibleSize.height * 0.35 + origin.y));

	auto menuNav = Menu::create(backBtn, NULL);
	menuNav->setPosition(Point(visibleSize.width * 0.25 + origin.x, visibleSize.height * 0.20 + origin.y));
	
	// Add menus to layer
	this->addChild(menuOptions, 1);
	this->addChild(menuNav, 1);

	//this->setPosition(middleScreen);
    
    return true;
}

void OptionsScene::back(cocos2d::Ref* pSender)
{
	Director::getInstance()->popScene();
}
