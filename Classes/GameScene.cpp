#include "GameScene.h"
#include "GameOverScene.h"
#include "SimpleAudioEngine.h"

const int boardPermission[33][4][2] =
{
												{ { 2, 1 }, { 8, 3 }, { -1, -1 }, { -1, -1 } }, { { 9, 4 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 0, 1 }, { 10, 5 }, { -1, -1 }, { -1, -1 } },
												{ { 5, 4 }, { 15, 8 }, { -1, -1 }, { -1, -1 } }, { { 16, 9 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 3, 4 }, { 17, 10 }, { -1, -1 }, { -1, -1 } },
	{ { 8, 7 }, { 20, 13 }, { -1, -1 }, { -1, -1 } }, { { 9, 8 }, { 21, 14 }, { -1, -1 }, { -1, -1 } }, { { 0, 3 }, { 6, 7 }, { 10, 9 }, { 22, 15 } }, { { 1, 4 }, { 7, 8 }, { 11, 10 }, { 23, 16 } }, { { 2, 5 }, { 8, 9 }, { 12, 11 }, { 24, 17 } }, { { 9, 10 }, { 25, 18 }, { -1, -1 }, { -1, -1 } }, { { 10, 11 }, { 26, 19 }, { -1, -1 }, { -1, -1 } },
	{ { 15, 14 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 16, 15 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 3, 8 }, { 13, 14 }, { 17, 16 }, { 27, 22 } }, { { 4, 9 }, { 14, 15 }, { 18, 17 }, { 28, 23 } }, { { 5, 10 }, { 15, 16 }, { 19, 18 }, { 29, 24 } }, { { 16, 17 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 17, 18 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	{ { 6, 13 }, { 22, 21 }, { -1, -1 }, { -1, -1 } }, { { 7, 14 }, { 23, 22 }, { -1, -1 }, { -1, -1 } }, { { 8, 15 }, { 20, 21 }, { 24, 23 }, { 30, 27 } }, { { 9, 16 }, { 21, 22 }, { 25, 24 }, { 31, 28 } }, { { 10, 17 }, { 22, 23 }, { 26, 25 }, { 32, 29 } }, { { 11, 18 }, { 23, 24 }, { -1, -1 }, { -1, -1 } }, { { 12, 19 }, { 24, 25 }, { -1, -1 }, { -1, -1 } },
												{ { 15, 22 }, { 29, 28 }, { -1, -1 }, { -1, -1 } }, { { 16, 23 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 17, 24 }, { 27, 28 }, { -1, -1 }, { -1, -1 } },
												{ { 22, 27 }, { 32, 31 }, { -1, -1 }, { -1, -1 } }, { { 23, 28 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 30, 31 }, { 24, 29 }, { -1, -1 }, { -1, -1 } }
};

const float initialBoard[33][4] =
{
												{ .385f, .71f, 1, 0 }, { .51f, .71f, 1, 1 }, { .635f, .71f, 1, 2 },
												{ .385f, .64f, 1, 3 }, { .51f, .64f, 1, 4 }, { .635f, .64f, 1, 5 },
	{ .135f, .57f, 1, 6 }, { .26f, .57f, 1, 7 }, { .385f, .57f, 1, 8 }, { .51f, .57f, 1, 9 }, { .635f, .57f, 1, 10 }, { .76f, .57f, 1, 11 }, { .885f, .57f, 1, 12 },
	{ .135f, .5f, 1, 13 }, { .26f, .5f, 1, 14 }, { .385f, .5f, 1, 15 }, { .51f, .5f, 0, 16 }, { .635f, .5f, 1, 17 }, { .76f, .5f, 1, 18 }, { .885f, .5f, 1, 19 },
	{ .135f, .43f, 1, 20 }, { .26f, .43f, 1, 21 }, { .385f, .43f, 1, 22 }, { .51f, .43f, 1, 23 }, { .635f, .43f, 1, 24 }, { .76f, .43f, 1, 25 }, { .885f, .43f, 1, 26 },
												{ .385f, .36f, 1, 27 }, { .51f, .36f, 1, 28 }, { .635f, .36f, 1, 29 },
												{ .385f, .29f, 1, 30 }, { .51f, .29f, 1, 31 }, { .635f, .29f, 1, 32 }
};

float board[33][4];

GameScene::GameScene()
: isGameOver(false)
{
}

GameScene::~GameScene()
{
	// Stop background music
	CocosDenshion::SimpleAudioEngine::getInstance()->stopBackgroundMusic();

	// Remove pieceListener
	Director::getInstance()->getEventDispatcher()->removeEventListener(pieceListener);
}

Scene* GameScene::scene()
{
	// Create an autorelease object scene
	auto scene = Scene::create();

	// Create this game layer
	auto layer = GameScene::create();

	// Add to the scene this game layer
	scene->addChild(layer);

	// Return created scene
	return scene;
}

bool GameScene::init()
{
	if (!Layer::init())
		return false;

	timeGame = 0;

	// Restart positions
	for (int i = 0; i < 33; i++)
		for (int j = 0; j < 4; j++)
			board[i][j] = initialBoard[i][j];

	// Create level
	this->loadLevel(1);

	// Create event listeners
	this->addEventListener();

	// Schedule clock to update game time
	this->schedule(SEL_SCHEDULE(&GameScene::tick), 1.0f, CC_REPEAT_FOREVER, 0);

	// Create main game loop
	this->scheduleUpdate();

	// Play backgroung music
	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("background.wav", true);

	return true;
}

void GameScene::addEventListener()
{
	// Create listener to interpret touch
	pieceListener = EventListenerTouchOneByOne::create();
	pieceListener->setSwallowTouches(true);

	// Validate if this piece is touched
	pieceListener->onTouchBegan = CC_CALLBACK_2(GameScene::onTouchBegan, this);

	// Call the move action
	pieceListener->onTouchMoved = CC_CALLBACK_2(GameScene::onTouchMoved, this);

	// Call an action to finalize touch
	pieceListener->onTouchEnded = CC_CALLBACK_2(GameScene::onTouchEnded, this);

	Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(pieceListener, 1);
}

void GameScene::tick(float dt)
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

	// Load game over
	if (isGameOver)
	{
		// Create a time only string
		char finalTime[20];
		snprintf(finalTime, sizeof(finalTime), "%.2d:%.2d", realMinutes, realSeconds);
		std::string finalTimeStr = finalTime;

		// Pass time and score to game over scene
		Director::getInstance()->replaceScene(GameOverScene::scene(finalTimeStr, score));
	}
}

void GameScene::update(float dt)
{
}

void GameScene::loadLevel(int level)
{
	levelLoaded = false;
	
	// Set menu position
	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	auto middleScreen = Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y);

	// Create background
	auto background = Sprite::create("game_background.png");
	background->setPosition(middleScreen);
	this->addChild(background, 0);

	// Create board and pieces
	for (auto i = 0; i < 33; i++)
	{
		// Set board position based on resolution
		board[i][0] = visibleSize.width * board[i][0] + origin.x;
		board[i][1] = visibleSize.height * board[i][1] + origin.y;

		// Set position of piece based on board
		auto pos = Point(board[i][0], board[i][1]);

		// Create sprite for piece
		auto piece = Sprite::create("button.png");
		piece->setPosition(pos);
		piece->setTag(i);

		// Hide the centered piece
		if (i == 16)
			piece->setVisible(false);

		// Attach piece to layer
		this->addChild(piece);
	}

	// Create time label
	timeLabel = Label::createWithTTF("Tempo: 00:00", "fonts/arial.ttf", 22);
	timeLabel->setColor(Color3B(0, 0, 0));
	timeLabel->setPosition(Point(visibleSize.width * 0.27 + origin.x, visibleSize.height * 0.8 + origin.y));
	timeLabel->setRotation(-15.0f);
	this->addChild(timeLabel, 1);

	// Create score label
	score = 0;
	scoreLabel = Label::createWithTTF("0", "fonts/arial.ttf", 22);
	scoreLabel->setPosition(Point(visibleSize.width * 0.78 + origin.x, visibleSize.height * 0.8 + origin.y));
	scoreLabel->setRotation(-15.0f);
	this->addChild(scoreLabel);
}

void GameScene::loadSound()
{
	// Todo
}

void GameScene::unloadSound()
{
	// Todo
}

bool GameScene::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// Get touch location
	Vec2 p = touch->getLocation();

	// Iterate pieces array to find touched piece
	for (int i = 0; i < 33; i++)
	{
		// Get tag piece in board i position
		int tag = board[i][3];

		// Check if piece exists in the board
		if (tag != -1)
		{
			// Get piece by tag
			auto piece = static_cast<Sprite*>(this->getChildByTag(tag));

			// Verify if this piece is located at touch position
			if (piece->getBoundingBox().containsPoint(p))
			{
				// Get piece by tag on found position
				selectedPiece = piece;

				// Cache current position to be used as last valid position
				selectedPieceLastPos = i;
				selectedPiece->setLocalZOrder(11);

				return true;
			}
		}
	}
	return false;
}

void GameScene::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	Vec2 p = touch->getLocation();
	selectedPiece->setPosition(p);
}

void GameScene::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	// Get touch release location
	Vec2 releaseTouch = touch->getLocation();

	// Create new piece position(start with last position)
	auto newPos = Vec2(board[selectedPieceLastPos][0], board[selectedPieceLastPos][1]);

	// Iterate over all board spaces to search a valid released position
	for (int i = 0; i < 33; i++)
	{
		// Get board position
		auto boardSpace = Rect(board[i][0] - selectedPiece->getContentSize().width / 2,
						board[i][1] - selectedPiece->getContentSize().height / 2,
						selectedPiece->getContentSize().width,
						selectedPiece->getContentSize().height);

		// Verify if this board position is located at touch release location
		if (boardSpace.containsPoint(releaseTouch))
		{
			// Check if destination is empty and isn't current piece location
			if (!board[i][2] && board[i][3] != selectedPiece->getTag())
			{
				// Check all 4 permissions for last board position
				for (int j = 0; j < 4; j++)
				{
					// Check each position of last position for this release position
					if (boardPermission[selectedPieceLastPos][j][0] == i)
					{
						// Piece to be removed
						auto boardPieceToRemove = boardPermission[selectedPieceLastPos][j][1];

						// Set current piece board position with no piece and no id
						board[selectedPieceLastPos][2] = 0;
						board[selectedPieceLastPos][3] = -1;

						// Remove piece between the move getting tag piece based on board permission
						((Sprite*) this->getChildByTag(board[boardPieceToRemove][3]))->setVisible(false);

						// Set removed piece board position with no piece and no id
						board[boardPieceToRemove][2] = 0;
						board[boardPieceToRemove][3] = -1;

						// Set move board position with piece and piece id
						board[i][2] = 1;
						board[i][3] = selectedPiece->getTag();

						// Set piece position with board position
						newPos = Vec2(board[i][0], board[i][1]);

						// Add the score
						score += 100;
						scoreLabel->setString(std::to_string(score));

						// Play sound effect
						CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("tick.aiff");

						// Set the end of game
						isGameOver = verifyGameOver();

						break;
					}
				}
			}
			break;
		}
	}

	// Set board position to selected piece
	selectedPiece->setPosition(newPos);
	selectedPiece->setLocalZOrder(10);
}

bool GameScene::verifyGameOver()
{
	bool isGameOver = true;

	// Iterate all positions on the board
	for (int i = 0; i < 33; i++)
	{
		// Verify if is a valid piece
		if (board[i][2])
		{
			//Verify if possible moves exists for the pieces around.
			for (int j = 0; j<4; j++)
			{
				if (boardPermission[i][j][0] != -1 && boardPermission[i][j][1] != -1)
				{
					//Take the piece around.
					int pieceAround = boardPermission[i][j][1];

					//Take the possible move for the piece around.
					int pieceToGo = boardPermission[i][j][0];

					//Verify if the move can be done.
					if ((board[pieceToGo][2] == 0 && board[pieceAround][2] == 1))
					{
						//Game continues.
						isGameOver = false;
						break;
					}
				}
			}
		}
	}

	return isGameOver;
}
