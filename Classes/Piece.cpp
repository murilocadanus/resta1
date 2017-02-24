#include "Piece.h"

USING_NS_CC;

bool Piece::init()
{
	this->initWithFile("button.png");
	// Add events to be used
	this->addEventListener();

	return true;
}

void Piece::setInitialPos(Vec2 initialPos)
{
	// Save the initial position for this piece
	this->initialPos = initialPos;

	// Set the position to sprite
	this->setPosition(initialPos);
}

void Piece::setInitialZOrder(int zOrder)
{
	// Save initial z order based on piece array position
	this->initialZOrder = zOrder;

	// Set sprite z order
	this->setZOrder(zOrder);
}

void Piece::addEventListener()
{
	// Create listener to interpret touch
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	// Validate if this piece is touched
	listener->onTouchBegan = CC_CALLBACK_2(Piece::onTouchBegan, this);

	// Call the move action
	listener->onTouchMoved = CC_CALLBACK_2(Piece::onTouchMoved, this);

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
		this->setZOrder(99);
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
	Vec2 p = touch->getLocation();
	this->setPosition(p);
}

void Piece::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	/*if (touch->getLocationInView()) // Valid move
	{

	}
	else // Ilegal move
	{*/
		this->setPosition(initialPos);
		this->setZOrder(this->initialZOrder);
		CCLOG("onTouchEnded:");
	//}
}