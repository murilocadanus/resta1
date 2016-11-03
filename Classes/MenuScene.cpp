#include "MenuScene.h"

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

}
