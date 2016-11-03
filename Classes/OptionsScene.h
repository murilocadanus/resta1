//
//  Options.h
//  Resta1
//
//  Created by Murilo Costa on 11/3/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __OPTIONS_SCENE_H__
#define __OPTIONS_SCENE_H__

#include "cocos2d.h"

class OptionsScene : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(OptionsScene);
	void music(cocos2d::Ref* pSender);
	void effects(cocos2d::Ref* pSender);
	void back(cocos2d::Ref* pSender);
};

#endif //__OPTIONS_SCENE_H__