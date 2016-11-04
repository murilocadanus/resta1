//
//  Piece.h
//  Resta1
//
//  Created by Murilo Costa on 11/4/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __PIECE_H__
#define __PIECE_H__

#include "cocos2d.h"

class Piece : public cocos2d::Sprite
{
public:
	CREATE_FUNC(Piece);

private:
	bool init();
	void addEventListener();
	bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
};

#endif //__PIECE_H__