//
//  GameOverScene.h
//  Resta1
//
//  Created by Murilo Costa on 14/4/17.
//  Copyright 2017 WinterLabs. All rights reserved.
//

#ifndef __GAME_OVER_SCENE_H__
#define __GAME_OVER_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameOverScene : public Layer
{
public:
	static Scene* scene(std::string aTimeGame, uint32_t aScore);
	virtual bool init();

	CREATE_FUNC(GameOverScene);

	void back(Ref* pSender);
};

#endif //__GAME_OVER_SCENE_H__