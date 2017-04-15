//
//  GameScene.h
//  Resta1
//
//  Created by Murilo Costa on 11/3/16.
//  Copyright 2016 WinterLabs. All rights reserved.
//

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

USING_NS_CC;

class GameScene : public Layer
{
public:
	GameScene();
	virtual ~GameScene();
	virtual bool init();
	static Scene* scene();
	CREATE_FUNC(GameScene);
	
private:
	void loadLevel(int level);
	void loadSound();
	void unloadSound();
	bool verifyGameOver();
	
	void addEventListener();
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);

	void tick(float dt);
	virtual void update(float dt);

	EventListenerTouchOneByOne *pieceListener;
	bool levelLoaded;
	uint32_t timeGame;
	uint32_t score;
	Label *timeLabel;
	Label *scoreLabel;
	Sprite background;
	Sprite *selectedPiece;
	int selectedPieceLastPos;
	bool isGameOver;
};

#endif //__GAME_SCENE_H__