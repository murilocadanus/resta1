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

  auto visibleSize = Director::getInstance()->getVisibleSize();
  Vec2 origin = Director::getInstance()->getVisibleOrigin();

  // Add background
  auto background = Sprite::create("game_menu.png");
  this->addChild(background, 0);

  // Add menu items
  auto start = MenuItemImage::create("btn_novo_jogo.png", "btn_novo_jogo_press.png", CC_CALLBACK_1(MenuScene::start, this));
  start->setPosition(Vec2(0.0f, -20.0f));

  auto options = MenuItemImage::create("btn_opcoes.png", "btn_opcoes_press.png", CC_CALLBACK_1(MenuScene::options, this));
  options->setPosition(Vec2(0.0f, -70.0f));

  // Create menu
  auto menu = Menu::create(start, options, NULL);
  menu->setPosition(Vec2::ZERO);
  this->addChild(menu, 1);

  // Set menu position
  this->setPosition(Vec2(origin.x + visibleSize.width - background->getContentSize().width / 2,
	  origin.y + background->getContentSize().height / 2));
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