//
//  ControlLayer.h
//  Resta1
//
//  Created by Murilo Costa on 11/3/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __CONTROL_LAYER_H__
#define __CONTROL_LAYER_H__

#include "cocos2d.h"

class ControlLayer : public cocos2d::Layer
{
public:
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(ControlLayer);
};

#endif //__CONTROL_LAYER_H__