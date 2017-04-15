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

USING_NS_CC;

class MenuScene : public Layer
{
public:
	static Scene* scene();
	virtual bool init();

	CREATE_FUNC(MenuScene);

	void start(Ref* pSender);
	void options(Ref* pSender);
};

#endif //__MENU_SCENE_H__
