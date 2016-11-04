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

	positionMap2[0][0] = 123;
	positionMap2[0][1] = 110;
	positionMap2[0][2] = 1;
	positionMap2[0][3] = 0;
	positionMap2[0][4] = 0;

	positionMap2[1][0] = 163;
	positionMap2[1][1] = 110;
	positionMap2[1][2] = 1;
	positionMap2[1][3] = 1;
	positionMap2[1][4] = 1;

	positionMap2[2][0] = 203;
	positionMap2[2][1] = 110;
	positionMap2[2][2] = 1;
	positionMap2[2][3] = 2;
	positionMap2[2][4] = 2;

	positionMap2[3][0] = 123;
	positionMap2[3][1] = 150;
	positionMap2[3][2] = 1;
	positionMap2[3][3] = 3;
	positionMap2[3][4] = 3;

	positionMap2[4][0] = 163;
	positionMap2[4][1] = 150;
	positionMap2[4][2] = 1;
	positionMap2[4][3] = 4;
	positionMap2[4][4] = 4;

	positionMap2[5][0] = 203;
	positionMap2[5][1] = 150;
	positionMap2[5][2] = 1;
	positionMap2[5][3] = 5;
	positionMap2[5][4] = 5;

	positionMap2[6][0] = 43;
	positionMap2[6][1] = 190;
	positionMap2[6][2] = 1;
	positionMap2[6][3] = 6;
	positionMap2[6][4] = 6;

	positionMap2[7][0] = 83;
	positionMap2[7][1] = 190;
	positionMap2[7][2] = 1;
	positionMap2[7][3] = 7;
	positionMap2[7][4] = 7;

	positionMap2[8][0] = 123;
	positionMap2[8][1] = 190;
	positionMap2[8][2] = 1;
	positionMap2[8][3] = 8;
	positionMap2[8][4] = 8;

	positionMap2[9][0] = 163;
	positionMap2[9][1] = 190;
	positionMap2[9][2] = 1;
	positionMap2[9][3] = 9;
	positionMap2[9][4] = 9;

	positionMap2[10][0] = 203;
	positionMap2[10][1] = 190;
	positionMap2[10][2] = 1;
	positionMap2[10][3] = 10;
	positionMap2[10][4] = 10;

	positionMap2[11][0] = 243;
	positionMap2[11][1] = 190;
	positionMap2[11][2] = 1;
	positionMap2[11][3] = 11;
	positionMap2[11][4] = 11;

	positionMap2[12][0] = 283;
	positionMap2[12][1] = 190;
	positionMap2[12][2] = 1;
	positionMap2[12][3] = 12;
	positionMap2[12][4] = 12;

	positionMap2[13][0] = 43;
	positionMap2[13][1] = 230;
	positionMap2[13][2] = 1;
	positionMap2[13][3] = 13;
	positionMap2[13][4] = 13;

	positionMap2[14][0] = 83;
	positionMap2[14][1] = 230;
	positionMap2[14][2] = 1;
	positionMap2[14][3] = 14;
	positionMap2[14][4] = 14;

	positionMap2[15][0] = 123;
	positionMap2[15][1] = 230;
	positionMap2[15][2] = 1;
	positionMap2[15][3] = 15;
	positionMap2[15][4] = 15;

	positionMap2[16][0] = 163;
	positionMap2[16][1] = 230;
	positionMap2[16][2] = 0;
	positionMap2[16][3] = -2;
	positionMap2[16][4] = 16;

	positionMap2[17][0] = 203;
	positionMap2[17][1] = 230;
	positionMap2[17][2] = 1;
	positionMap2[17][3] = 16;
	positionMap2[17][4] = 17;

	positionMap2[18][0] = 243;
	positionMap2[18][1] = 230;
	positionMap2[18][2] = 1;
	positionMap2[18][3] = 17;
	positionMap2[18][4] = 18;

	positionMap2[19][0] = 283;
	positionMap2[19][1] = 230;
	positionMap2[19][2] = 1;
	positionMap2[19][3] = 18;
	positionMap2[19][4] = 19;

	positionMap2[20][0] = 43;
	positionMap2[20][1] = 270;
	positionMap2[20][2] = 1;
	positionMap2[20][3] = 19;
	positionMap2[20][4] = 20;

	positionMap2[21][0] = 83;
	positionMap2[21][1] = 270;
	positionMap2[21][2] = 1;
	positionMap2[21][3] = 20;
	positionMap2[21][4] = 21;

	positionMap2[22][0] = 123;
	positionMap2[22][1] = 270;
	positionMap2[22][2] = 1;
	positionMap2[22][3] = 21;
	positionMap2[22][4] = 22;

	positionMap2[23][0] = 163;
	positionMap2[23][1] = 270;
	positionMap2[23][2] = 1;
	positionMap2[23][3] = 22;
	positionMap2[23][4] = 23;

	positionMap2[24][0] = 203;
	positionMap2[24][1] = 270;
	positionMap2[24][2] = 1;
	positionMap2[24][3] = 23;
	positionMap2[24][4] = 24;

	positionMap2[25][0] = 243;
	positionMap2[25][1] = 270;
	positionMap2[25][2] = 1;
	positionMap2[25][3] = 24;
	positionMap2[25][4] = 25;

	positionMap2[26][0] = 283;
	positionMap2[26][1] = 270;
	positionMap2[26][2] = 1;
	positionMap2[26][3] = 25;
	positionMap2[26][4] = 26;

	positionMap2[27][0] = 123;
	positionMap2[27][1] = 310;
	positionMap2[27][2] = 1;
	positionMap2[27][3] = 26;
	positionMap2[27][4] = 27;

	positionMap2[28][0] = 163;
	positionMap2[28][1] = 310;
	positionMap2[28][2] = 1;
	positionMap2[28][3] = 27;
	positionMap2[28][4] = 28;

	positionMap2[29][0] = 203;
	positionMap2[29][1] = 310;
	positionMap2[29][2] = 1;
	positionMap2[29][3] = 28;
	positionMap2[29][4] = 29;

	positionMap2[30][0] = 123;
	positionMap2[30][1] = 350;
	positionMap2[30][2] = 1;
	positionMap2[30][3] = 29;
	positionMap2[30][4] = 30;

	positionMap2[31][0] = 163;
	positionMap2[31][1] = 350;
	positionMap2[31][2] = 1;
	positionMap2[31][3] = 30;
	positionMap2[31][4] = 31;

	positionMap2[32][0] = 203;
	positionMap2[32][1] = 350;
	positionMap2[32][2] = 1;
	positionMap2[32][3] = 31;
	positionMap2[32][4] = 32;

	return true;
}