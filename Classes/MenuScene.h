//
//  MenuScene.h
//  Resta1
//
//  Created by Murilo Costa on 11/3/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __MENU_SCENE_H__
#define __MENU_SCENE_H__

#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(MenuScene);

	void start(cocos2d::Ref* pSender);
	void options(cocos2d::Ref* pSender);
};

#endif //__MENU_SCENE_H__
