//
//  ActionLayer.h
//  Resta1
//
//  Created by Murilo Costa on 11/3/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __ACTION_LAYER_H__
#define __ACTION_LAYER_H__

#include "cocos2d.h"

class ActionLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(ActionLayer);

private:
	void loadLevel(int level);
	void loadSound();
	void unloadSound();
	void tick(float dt);

	bool levelLoaded;
	uint32_t timeGame;
	uint8_t score;
	cocos2d::Label *timeLabel;
	cocos2d::Label *scoreLabel;
	cocos2d::Sprite background;
};

#endif //__ACTION_LAYER_H__