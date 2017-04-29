#include "MenuScene.h"
#include "GameScene.h"
#include "OptionsScene.h"

USING_NS_CC;

Scene* MenuScene::scene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
{
    // Super init
    if(!Layer::init())
        return false;

    // Set menu position
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto origin = Director::getInstance()->getVisibleOrigin();
    Point middleScreen = Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

    // Add background
    auto background = Sprite::create("game_menu.png");
    background->setPosition(middleScreen);
    this->addChild(background, 0);

    // Add menu items
    auto start = MenuItemImage::create("btn_novo_jogo.png", "btn_novo_jogo_press.png", CC_CALLBACK_1(MenuScene::start, this));
    start->setPosition(Point::ZERO);

    auto options = MenuItemImage::create("btn_opcoes.png", "btn_opcoes_press.png", CC_CALLBACK_1(MenuScene::options, this));
    options->setPosition(Point::ZERO);

    // Create menu
    auto menu = Menu::create(start, options, NULL);
    //menu->alignItemsVertically();
    menu->alignItemsVerticallyWithPadding(visibleSize.height * 0.1);
    menu->setPosition(Point(middleScreen.x, visibleSize.height * 0.35 + origin.y));
    this->addChild(menu, 1);

    //this->setPosition(middleScreen);
    
    return true;
}

void MenuScene::start(cocos2d::Ref* pSender)
{
    auto gameScene = GameScene::scene();
	Director::getInstance()->replaceScene(gameScene);
}

void MenuScene::options(cocos2d::Ref* pSender)
{
	auto optionsScene = OptionsScene::scene();
	Director::getInstance()->pushScene(optionsScene);
}
