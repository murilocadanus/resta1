#include "ActionLayer.h"
#include "Piece.h"

USING_NS_CC;

int positionMap[33][4] =
{
										  { 123, 120, 1, 0 }, { 163, 120, 1, 1 }, { 203, 120, 1, 2 },
										  { 123, 160, 1, 3 }, { 163, 160, 1, 4 }, { 203, 160, 1, 5 },
	{ 43, 200, 1, 6 }, { 83, 200, 1, 7 }, { 123, 200, 1, 8 }, { 163, 200, 1, 9 }, { 203, 200, 1, 10 }, { 243, 200, 1, 11 }, { 283, 200, 1, 12 },
	{ 43, 240, 1, 13 }, { 83, 240, 1, 14 }, { 123, 240, 1, 15 }, { 163, 240, 0, -2 }, { 203, 240, 1, 16 }, { 243, 240, 1, 17 }, { 283, 240, 1, 18 },
	{ 43, 280, 1, 19 }, { 83, 280, 1, 20 }, { 123, 280, 1, 21 }, { 163, 280, 1, 22 }, { 203, 280, 1, 23 }, { 243, 280, 1, 24 }, { 283, 280, 1, 25 },
										  { 123, 320, 1, 26 }, { 163, 320, 1, 27 }, { 203, 320, 1, 28 },
										  { 123, 360, 1, 29 }, { 163, 360, 1, 30 }, { 203, 360, 1, 31 }
};

bool ActionLayer::init()
{
	if (!Layer::init())
		return false;

	timeGame = 0;

	// Create level
	this->loadLevel(1);

	// Schedule clock to update game time
	this->schedule(SEL_SCHEDULE(&ActionLayer::tick), 1.0f, CC_REPEAT_FOREVER, 0);

	return true;
}

void ActionLayer::loadLevel(int level)
{
	levelLoaded = false;
	
	// Set menu position
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto middleScreen = Vec2((visibleSize.width + origin.x) / 2, (visibleSize.height + origin.y) / 2);

	// Create background
	auto background = Sprite::create("game_background.png");
	this->addChild(background, 0);
	background->setPosition(middleScreen);

	// Create board pieces
	for (auto i = 0; i < 33; i++)
	{
		// Set position of piece basaed on array map
		auto pos = Vec2(positionMap[i][0], positionMap[i][1]);

		// Dont add the middle piece
		if (i != 16)
		{
			// Create sprite for piece
			auto piece = Piece::create();
			piece->setInitialPos(pos);
			piece->setInitialZOrder(i);

			// Attach piece to layer
			this->addChild(piece);
		}
	}

	// Create time label
	timeLabel = Label::createWithTTF("Tempo: 00:00", "fonts/arial.ttf", 14);
	timeLabel->setColor(Color3B(0, 0, 0));
	timeLabel->setPosition(Vec2(80, 405));
	timeLabel->setRotation(-15.0f);
	this->addChild(timeLabel, 1);

	// Create score label
	score = 0;
	scoreLabel = Label::create("0", "fonts/arial.ttf", 14);
	scoreLabel->setPosition(Vec2(251, 403));
	scoreLabel->setRotation(-15.0f);
	this->addChild(scoreLabel);
}

void ActionLayer::loadSound()
{
	// Todo
}

void ActionLayer::unloadSound()
{
	// Todo
}

void ActionLayer::tick(float dt)
{
	//Increment the time variable by the scheduled interval
	timeGame = timeGame + 1;

	//Get the int value for total seconds
	auto seconds = timeGame;

	//Get the minutes
	int realMinutes = seconds / 60;
	//Get the seconds left over after you find the total minutes
	int realSeconds = seconds % 60;

	char buff[20];
	snprintf(buff, sizeof(buff), "Tempo: %.2d:%.2d", realMinutes, realSeconds);
	std::string buffAsStdStr = buff;

	// Add the string to the label with the calculated minutes and seconds
	timeLabel->setString(buffAsStdStr);
}