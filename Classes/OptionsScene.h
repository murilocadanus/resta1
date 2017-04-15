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

USING_NS_CC;

class OptionsScene : public Layer
{
public:
	static Scene* scene();
	virtual bool init();

	CREATE_FUNC(OptionsScene);

	void music(Ref* pSender);
	void effects(Ref* pSender);
	void back(Ref* pSender);
};

#endif //__OPTIONS_SCENE_H__