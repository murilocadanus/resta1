#include "ControlLayer.h"

USING_NS_CC;

int positionMap2[33][5];

int permissionMap[33][4][2] =
{
									{ { 2, 1 }, { 8, 3 }, { -1, -1 }, { -1, -1 } }, { { 9, 4 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 0, 1 }, { 10, 5 }, { -1, -1 }, { -1, -1 } },
									{ { 5, 4 }, { 15, 8 }, { -1, -1 }, { -1, -1 } }, { { 16, 9 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 3, 4 }, { 17, 10 }, { -1, -1 }, { -1, -1 } },
	{ { 8, 7 }, { 20, 13 }, { -1, -1 }, { -1, -1 } }, { { 9, 8 }, { 21, 14 }, { -1, -1 }, { -1, -1 } }, { { 0, 3 }, { 6, 7 }, { 10, 9 }, { 22, 15 } }, { { 1, 4 }, { 7, 8 }, { 11, 10 }, { 23, 16 } }, { { 2, 5 }, { 8, 9 }, { 12, 11 }, { 24, 17 } }, { { 9, 10 }, { 25, 18 }, { -1, -1 }, { -1, -1 } }, { { 10, 11 }, { 26, 19 }, { -1, -1 }, { -1, -1 } },
	{ { 15, 14 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 16, 15 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 3, 8 }, { 13, 14 }, { 17, 16 }, { 27, 22 } }, { { 4, 9 }, { 14, 15 }, { 18, 17 }, { 28, 23 } }, { { 5, 10 }, { 15, 16 }, { 19, 18 }, { 29, 24 } }, { { 16, 17 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 17, 18 }, { -1, -1 }, { -1, -1 }, { -1, -1 } },
	{ { 6, 13 }, { 22, 21 }, { -1, -1 }, { -1, -1 } }, { { 7, 14 }, { 23, 22 }, { -1, -1 }, { -1, -1 } }, { { 8, 15 }, { 20, 21 }, { 24, 23 }, { 30, 27 } }, { { 9, 16 }, { 21, 22 }, { 25, 24 }, { 31, 28 } }, { { 10, 17 }, { 22, 23 }, { 26, 25 }, { 32, 29 } }, { { 11, 18 }, { 23, 24 }, { -1, -1 }, { -1, -1 } }, { { 12, 19 }, { 24, 25 }, { -1, -1 }, { -1, -1 } },
									{ { 15, 22 }, { 29, 28 }, { -1, -1 }, { -1, -1 } }, { { 16, 23 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 17, 24 }, { 27, 28 }, { -1, -1 }, { -1, -1 } },
									{ { 22, 27 }, { 32, 31 }, { -1, -1 }, { -1, -1 } }, { { 23, 28 }, { -1, -1 }, { -1, -1 }, { -1, -1 } }, { { 30, 31 }, { 24, 29 }, { -1, -1 }, { -1, -1 } }
};

bool ControlLayer::init()
{
	if (!Layer::init())
		return false;

	this->setTouchEnabled(true);

	return true;
}