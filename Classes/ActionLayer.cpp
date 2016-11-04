#include "ActionLayer.h"
#include "Piece.h"

USING_NS_CC;

int positionMap[33][4] =
{
										  { 123, 110, 1, 0 }, { 163, 110, 1, 1 }, { 203, 110, 1, 2 },
										  { 123, 150, 1, 3 }, { 163, 150, 1, 4 }, { 203, 150, 1, 5 },
	{ 43, 190, 1, 6 }, { 83, 190, 1, 7 }, { 123, 190, 1, 8 }, { 163, 190, 1, 9 }, { 203, 190, 1, 10 }, { 243, 190, 1, 11 }, { 283, 190, 1, 12 },
	{ 43, 230, 1, 13 }, { 83, 230, 1, 14 }, { 123, 230, 1, 15 }, { 163, 230, 0, -2 }, { 203, 230, 1, 16 }, { 243, 230, 1, 17 }, { 283, 230, 1, 18 },
	{ 43, 270, 1, 19 }, { 83, 270, 1, 20 }, { 123, 270, 1, 21 }, { 163, 270, 1, 22 }, { 203, 270, 1, 23 }, { 243, 270, 1, 24 }, { 283, 270, 1, 25 },
										  { 123, 310, 1, 26 }, { 163, 310, 1, 27 }, { 203, 310, 1, 28 },
										  { 123, 350, 1, 29 }, { 163, 350, 1, 30 }, { 203, 350, 1, 31 }
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
	background->setScale(1.7f);
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
			piece->setScale(1.7f);
			piece->setPosition(pos);

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