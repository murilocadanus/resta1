#include "GameScene.h"
#include "ActionLayer.h"
#include "ControlLayer.h"

USING_NS_CC;

Scene* GameScene::create()
{
	// Create scene
	auto scene = Scene::create();

	// Create action layer
	auto actionLayer = ActionLayer::create();

	// Create control layer
	auto controlLayer = ControlLayer::create();

	// Add layers as childs to scene
	scene->addChild(actionLayer);
	scene->addChild(controlLayer);

	// Return scene
	return scene;
}