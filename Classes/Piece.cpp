#include "Piece.h"

USING_NS_CC;

bool Piece::init()
{
	this->initWithFile("button.png");
	// Add events to be used
	this->addEventListener();

	return true;
}

void Piece::addEventListener()
{
	// Create listener to interpret touch
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	// Validate if this piece is touched
	listener->onTouchBegan = CC_CALLBACK_2(Piece::onTouchBegan, this);

	// Call an action to finalize touch
	listener->onTouchEnded = CC_CALLBACK_2(Piece::onTouchEnded, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 1);
}

bool Piece::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	CCLOG("onTouchBegan:");
	Vec2 p = touch->getLocation();
	Rect rect = this->getBoundingBox();

	if (rect.containsPoint(p))
	{
		this->setScale(2.0f);
		return true; // to indicate that we have consumed it.
	}
	else
	{
		CCLOG("false");
		return false; // we did not consume this event, pass thru.
	}
}

void Piece::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	CCLOG("onTouchMoved:");
}

void Piece::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	this->setScale(1.7f);
	CCLOG("onTouchEnded:");
}