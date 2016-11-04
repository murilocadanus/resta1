#include "MenuScene.h"
#include "GameScene.h"
#include "OptionsScene.h"

USING_NS_CC;

Scene* MenuScene::createScene()
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
  auto middleScreen = Vec2((visibleSize.width + origin.x) / 2, (visibleSize.height + origin.y) / 2);

  // Add background
  auto background = Sprite::create("game_menu.png");
  background->setScale(1.7f);
  this->addChild(background, 0);

  // Add menu items
  auto start = MenuItemImage::create("btn_novo_jogo.png", "btn_novo_jogo_press.png", CC_CALLBACK_1(MenuScene::start, this));
  start->setScale(1.7f);
  start->setPosition(Vec2(0.0f, -40.0f));

  auto options = MenuItemImage::create("btn_opcoes.png", "btn_opcoes_press.png", CC_CALLBACK_1(MenuScene::options, this));
  options->setScale(1.7f);
  options->setPosition(Vec2(0.0f, -100.0f));

  // Create menu
  auto menu = Menu::create(start, options, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  this->setPosition(middleScreen);
}

void MenuScene::start(cocos2d::Ref* pSender)
{
	auto gameScene = GameScene::create();
	Director::getInstance()->replaceScene(gameScene);
}

void MenuScene::options(cocos2d::Ref* pSender)
{
	auto optionsScene = OptionsScene::createScene();
	Director::getInstance()->pushScene(optionsScene);
}