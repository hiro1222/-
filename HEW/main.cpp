//#include <stdio.h>
//#include <time.h>
//#include <stdlib.h>
//#include <vector>
//#include "header.h"
//
//using namespace std;
//
//Bmp* white = NULL;
//
//#define MAP_SIZE       (40)
//#define MINIMUM_SIZE   (5)
//#define AISLE_WIDTH    (3)
//
//enum DIRECTION {
//	VERTICAL,
//	HORIZON
//};
//
//struct Aisle {
//	int startPoint;
//	int endPoint;
//	int line;
//	int direction;
//};
//
//
//
//struct Room {
//	int leftTop_x;
//	int leftTop_y;
//	int width;
//	int haight;
//	vector<int> aisleNum;
//};
//
//class MapGene {
//private:
//	int map[MAP_SIZE][MAP_SIZE]; // 0 = ï«, 1 = ïîâÆ/í òH
//	int geneRoomNum;
//	vector<Room> room;
//	vector<Aisle> aisle;
//public:
//	MapGene();
//	~MapGene();
//	void MakeMap();
//	int MakeDivideLine(int roomNum, int direction);
//	void RoomDivide(int roomNum, int line, int direction);
//	void RoomDig();
//	void AisleDig();
//	void Output();
//};
//
//MapGene::MapGene() {
//	for (int e = 0; e < MAP_SIZE; e++) {
//		for (int f = 0; f < MAP_SIZE; f++) {
//			map[f][e] = 0; // èâä˙âªÅFï«
//		}
//	}
//	geneRoomNum = rand() % 3 + 5;
//	Room tempRoom;
//	tempRoom.leftTop_x = 1;
//	tempRoom.leftTop_y = 1;
//	tempRoom.width = MAP_SIZE - 2;
//	tempRoom.haight = MAP_SIZE - 2;
//	room.push_back(tempRoom);
//}
//
//MapGene::~MapGene() {}
//
//void MapGene::MakeMap() {
//	geneRoomNum -= 1;
//	int roomNum = 0;
//	vector<int> passRoom;
//	for (int e = 0; e < (int)room.size(); e++) {
//		if (room[e].width >= MINIMUM_SIZE * 2 + AISLE_WIDTH
//			|| room[e].haight >= MINIMUM_SIZE * 2 + AISLE_WIDTH) {
//			roomNum++;
//			passRoom.push_back(e);
//		}
//	}
//	roomNum = rand() % roomNum;
//	int direction = 0;
//	if (room[passRoom[roomNum]].width >= (MINIMUM_SIZE * 2 + AISLE_WIDTH)
//		&& room[passRoom[roomNum]].haight >= (MINIMUM_SIZE * 2 + AISLE_WIDTH)) {
//		direction = rand() % 2;
//	}
//	else if (room[passRoom[roomNum]].width >= (MINIMUM_SIZE * 2 + AISLE_WIDTH)) {
//		direction = VERTICAL;
//	}
//	else {
//		direction = HORIZON;
//	}
//	RoomDivide(passRoom[roomNum], MakeDivideLine(passRoom[roomNum], direction), direction);
//	if (geneRoomNum != 0) {
//		MakeMap();
//		return;
//	}
//	RoomDig();
//	AisleDig();
//}
//
//int MapGene::MakeDivideLine(int roomNum, int direction) {
//	int divideLine = (direction == VERTICAL) ? room[roomNum].width : room[roomNum].haight;
//	divideLine -= (MINIMUM_SIZE * 2 + 2);
//	divideLine = rand() % divideLine + MINIMUM_SIZE + 2;
//	return divideLine;
//}
//
//void MapGene::RoomDivide(int roomNum, int line, int direction) {
//	Room room1, room2;
//	Aisle tempAisle;
//
//	if (direction == VERTICAL) {
//		room1.leftTop_y = room2.leftTop_y = room[roomNum].leftTop_y;
//		room1.leftTop_x = room[roomNum].leftTop_x;
//		room2.leftTop_x = room1.leftTop_x + line + 1;
//		room1.haight = room2.haight = room[roomNum].haight;
//		room1.width = line - 2;
//		room2.width = room[roomNum].width - line - 1;
//		tempAisle.startPoint = room[roomNum].leftTop_y - 1;
//		tempAisle.endPoint = room[roomNum].leftTop_y + room[roomNum].haight;
//		tempAisle.line = room[roomNum].leftTop_x + line - 1;
//		tempAisle.direction = VERTICAL;
//	}
//	else {
//		room1.leftTop_x = room2.leftTop_x = room[roomNum].leftTop_x;
//		room1.leftTop_y = room[roomNum].leftTop_y;
//		room2.leftTop_y = room1.leftTop_y + line + 1;
//		room1.width = room2.width = room[roomNum].width;
//		room1.haight = line - 2;
//		room2.haight = room[roomNum].haight - line - 1;
//		tempAisle.startPoint = room[roomNum].leftTop_x - 1;
//		tempAisle.endPoint = room[roomNum].leftTop_x + room[roomNum].width;
//		tempAisle.line = room[roomNum].leftTop_y + line - 1;
//		tempAisle.direction = HORIZON;
//	}
//
//	for (int e = 0; e < room[roomNum].aisleNum.size(); e++) {
//		int idx = room[roomNum].aisleNum[e];
//		if (aisle[idx].direction == direction) {
//			if ((direction == VERTICAL && aisle[idx].line < room[roomNum].leftTop_x)
//				|| (direction == HORIZON && aisle[idx].line < room[roomNum].leftTop_y)) {
//				room1.aisleNum.push_back(idx);
//			}
//			else {
//				room2.aisleNum.push_back(idx);
//			}
//		}
//		else {
//			room1.aisleNum.push_back(idx);
//			room2.aisleNum.push_back(idx);
//		}
//	}
//
//	aisle.push_back(tempAisle);
//	room1.aisleNum.push_back(aisle.size() - 1);
//	room2.aisleNum.push_back(aisle.size() - 1);
//
//	room.erase(room.begin() + roomNum);
//	room.push_back(room1);
//	room.push_back(room2);
//}
//
//void MapGene::RoomDig() {
//	for (int e = 0; e < (int)room.size(); e++) {
//		for (int f = room[e].leftTop_x; f < room[e].leftTop_x + room[e].width; f++) {
//			for (int g = room[e].leftTop_y; g < room[e].leftTop_y + room[e].haight; g++) {
//				map[f][g] = 1;
//			}
//		}
//	}
//}
//
//void MapGene::AisleDig() {
//	int tempRand = 0;
//	for (int e = 0; e < room.size(); e++) {
//		for (int f = 0; f < room[e].aisleNum.size(); f++) {
//			Aisle& a = aisle[room[e].aisleNum[f]];
//			if (a.direction == VERTICAL) {
//				tempRand = rand() % room[e].haight + room[e].leftTop_y;
//				if (a.line < room[e].leftTop_x) {
//					for (int g = 0; g < 2; g++) {
//						map[room[e].leftTop_x - g - 1][tempRand] = 1;
//					}
//				}
//				else {
//					for (int g = 0; g < 2; g++) {
//						map[room[e].leftTop_x + room[e].width + g][tempRand] = 1;
//					}
//				}
//			}
//			else {
//				tempRand = rand() % room[e].width + room[e].leftTop_x;
//				if (a.line < room[e].leftTop_y) {
//					for (int g = 0; g < 2; g++) {
//						map[tempRand][room[e].leftTop_y - g - 1] = 1;
//					}
//				}
//				else {
//					for (int g = 0; g < 2; g++) {
//						map[tempRand][room[e].leftTop_y + room[e].haight + g] = 1;
//					}
//				}
//			}
//		}
//	}
//
//	for (int e = 0; e < aisle.size(); e++) {
//		vector<int> temp;
//		if (aisle[e].direction == VERTICAL) {
//			for (int f = aisle[e].startPoint; f < aisle[e].endPoint; f++) {
//				if (map[aisle[e].line][f] == 1) temp.push_back(f);
//			}
//		}
//		else {
//			for (int f = aisle[e].startPoint; f < aisle[e].endPoint; f++) {
//				if (map[f][aisle[e].line] == 1) temp.push_back(f);
//			}
//		}
//
//		if (temp.size() % 2 == 0) {
//			while (temp.size() > 0) {
//				for (int f = temp[0] + 1; f < temp[1]; f++) {
//					if (aisle[e].direction == VERTICAL)
//						map[aisle[e].line][f] = 1;
//					else
//						map[f][aisle[e].line] = 1;
//				}
//				temp.erase(temp.begin(), temp.begin() + 2);
//			}
//		}
//		else if (temp.size() != 1) {
//			while (temp.size() > 3) {
//				for (int f = temp[0] + 1; f < temp[1]; f++) {
//					if (aisle[e].direction == VERTICAL)
//						map[aisle[e].line][f] = 1;
//					else
//						map[f][aisle[e].line] = 1;
//				}
//				temp.erase(temp.begin(), temp.begin() + 2);
//			}
//			for (int f = temp[0] + 1; f < temp[2]; f++) {
//				if (aisle[e].direction == VERTICAL)
//					map[aisle[e].line][f] = 1;
//				else
//					map[f][aisle[e].line] = 1;
//			}
//		}
//	}
//}
//
//void MapGene::Output() {
//	for (int y = 0; y < MAP_SIZE; y++) {
//		for (int x = 0; x < MAP_SIZE; x++) {
//			if (map[x][y] == 0)
//				printf("Å°"); // ï«
//			else
//				printf("Å@"); // ãÛä‘
//		}
//		printf("\n");
//	}
//}
//
//int main(void)
//{
//	InitConioEx(1280, 720, 1, 1, true);
//
//	white = LoadBmp("pic/white.bmp");
//	SetPalette(white);
//
//	srand((unsigned)time(NULL));
//
//	MapGene* mpG = new MapGene();
//	mpG->MakeMap();
//	mpG->Output();
//
//	delete mpG;
//
//	return 0;
//}

#include"header.h"
using namespace std;
Bmp* white = NULL;

float g_x[200] = {};
float g_y[200] = {};

float x_x = 0;
float x_y = 0;

float solutionX[200] = {};
float solutionY[200] = {};

float GoalRay = 0;


float C_S_X[200] = { 0 };
float C_S_Y[200] = { 0 };
float C_E_X[200] = { 0 };
float C_E_Y[200] = { 0 };
int main() {

	InitConioEx(1280, 720, 1, 1, true);

	//////////////////////////âÊëúê›íË//////////////////////////
	Bmp* title = NULL;

	Bmp* white = NULL;
	Bmp* goal = NULL;

	Bmp* playerUp = NULL;
	Bmp* playerLeft = NULL;
	Bmp* playerDown = NULL;
	Bmp* playerRight = NULL;

	Bmp* KeyBox = NULL;
	Bmp* Key = NULL;

	Bmp* yuka = NULL;
	Bmp* back = NULL;

	Bmp* right1 = NULL;
	Bmp* right2 = NULL;
	Bmp* right3 = NULL;
	Bmp* left1 = NULL;
	Bmp* left2 = NULL;
	Bmp* left3 = NULL;

	Bmp* right1W = NULL;

	Bmp* wall1 = NULL;
	Bmp* wall2 = NULL;
	Bmp* wall3 = NULL;

	Bmp* DL1 = NULL;
	Bmp* DL2 = NULL;
	Bmp* DL3 = NULL;

	Bmp* D1 = NULL;
	Bmp* D2 = NULL;
	Bmp* D3 = NULL;

	Bmp* T1 = NULL;
	Bmp* T2 = NULL;
	Bmp* T3 = NULL;

	title = LoadBmp("pic/title.bmp");
	white = LoadBmp("pic/white.bmp");
	goal = LoadBmp("pic/Goal.bmp");

	playerUp = LoadBmp("pic/player.up.bmp");
	playerLeft = LoadBmp("pic/player.left.bmp");
	playerDown = LoadBmp("pic/player.down.bmp");
	playerRight = LoadBmp("pic/player.right.bmp");

	KeyBox = LoadBmp("pic/KeyBox.bmp");
	Key = LoadBmp("pic/Key.bmp");

	yuka = LoadBmp("pic/yuka.bmp");
	back = LoadBmp("pic/back.bmp");

	right1 = LoadBmp("pic/right.1.bmp");
	right2 = LoadBmp("pic/right.2.bmp");
	right3 = LoadBmp("pic/right.3.bmp");
	left1 = LoadBmp("pic/left.1.bmp");
	left2 = LoadBmp("pic/left.2.bmp");
	left3 = LoadBmp("pic/left.3.bmp");

	right1W = LoadBmp("pic/right.1.W.bmp");

	wall1 = LoadBmp("pic/Wall.1.bmp");
	wall2 = LoadBmp("pic/Wall.2.bmp");
	wall3 = LoadBmp("pic/Wall.3.bmp");

	DL1 = LoadBmp("pic/DoorLock.bmp");
	DL2 = LoadBmp("pic/DoorLock2.bmp");
	DL3 = LoadBmp("pic/DoorLock3.bmp");

	D1 = LoadBmp("pic/Door.bmp");
	D2 = LoadBmp("pic/Door2.bmp");
	D3 = LoadBmp("pic/Door3.bmp");

	T1 = LoadBmp("pic/KeyBox1.bmp");
	T2 = LoadBmp("pic/KeyBox2.bmp");
	T3 = LoadBmp("pic/KeyBox3.bmp");

	SetPalette(title);
	SetPalette(KeyBox);
	SetPalette(D1);
	SetPalette(wall1);
	SetPalette(white);
	SetPalette(goal);
	SetPalette(playerUp);
	/////////////////////////BGM,SEê›íË/////////////////////////


	///////////////////////////êîílê›íË/////////////////////////
	int count = 0;
	int Goal_count = 0;
	int AngleCheck = 0;

	int Key_x;
	int Key_y;

	int x;
	int y;
	int ray_c = 0;
	float x0, y0;
	int Player_X = 1;
	int Player_Y = 1;
	int Goal_X = 0;
	int Goal_Y = 0;

	int bx = 0;
	int by = 0;
	
	int go = 0;

	int WallLong = 0;

	int CC = 0;
	int AC = 0;

	int CT = 0;

	int R = 50;
	int D = 0;

	float Y_ = 0;
	float X_ = 0;

	float N_X;
	float N_Y;

	int X21 = 345;
	int X22 = 1280 - X21;
	int Y21 = 107;
	int a;
	int b;

	int bef_x;
	int bef_y;

	int _up = 50;
	int _right = 345;

	int ab = 0;
	int aa = 0;
	int ad = 0;
	int ac = 0;

	int dx = 0;
	int dy = 0;
	int err = dx - dy;
	int area = 0;
	
	int sx = (aa < ab) ? (1) : (-1);	//Xï˚å¸ÇÃïÑçÜ
	int sy = (ac < ad) ? (1) : (-1);	//Yï˚å¸ÇÃïÑçÜ
	int time_p = 0;//ï`âÊéûä‘

	srand(time(NULL));

	int r = rand();

	int direction = 0;

	int angle = 0;

	float slope[180] = { 0 };


	int col[13][13] = { 0 };

	int map[13][13] = { 0 };
	int panel[13][13] = { 0 };
	//////////////////////////////////////////////////////////////
	bool Start = false;
	bool wall = false;
	bool End = false;
	bool fast = false;
	bool Hit = false;

	bool up = false;
	bool down = false;
	bool right = false;
	bool left = false;

	bool rw1 = false;
	bool rw2 = false;
	bool rw3 = false;

	bool lw1 = false;
	bool lw2 = false;
	bool lw3 = false;

	bool w1 = false;
	bool w2 = false;
	bool w3 = false;

	bool Wall = false;

	bool move = false;

	bool RightTurn = false;
	bool LeftTurn = false;

	bool Player = false;
	bool StartAngle = false;
	bool WallHitCheck = false;

	bool MoveCheck = false;

	bool KeyPic = false;

	bool RC1 = false;
	bool RC2 = false;
	bool RC3 = false;

	bool LC1 = false;
	bool LC2 = false;
	bool LC3 = false;

	int KFC = 0;
	//////////////////////ÉQÅ[ÉÄÉãÅ[ÉväJén//////////////////////
		int X1 = 500;
		int Y1 = 175;
		int Y3 = 150;


		int pe = 0;
		int pa = 0;

		while (InputKeyMouse(VK_RETURN) == 0) {
			DrawBmp(0, 0, title, true);

			PrintFrameBuffer();
			FlipScreen();
		}
	

	while (InputKeyMouse(PK_ESC) == 0) {

		int X2 = 1280 - X1;
		int Y2 = Y1 + Y3;

		

		
		//è„ìÒñ{
		DrawLine(100, 0, X1, Y1, WHITE);
		DrawLine(X2, Y1, 1180, 0, WHITE);

		//â∫ìÒñ{
		DrawLine(0, 720, X1, Y2, WHITE);
		DrawLine(X2, Y2, 1280, 720, WHITE);

		//âúï«
		DrawLine(X1, Y1, X1, Y2, WHITE);
		DrawLine(X2, Y1, X2, Y2, WHITE);

		//âúè∞
		DrawLine(X1, Y1, X2, Y1, WHITE);
		DrawLine(X1, Y2, X2, Y2, WHITE);

		DrawLine(X21, Y21, X22, Y21, WHITE);
		DrawLine(X21, Y21, X21, Y21 + 500, WHITE);
		DrawLine(X22, Y21, X22, Y21 + 500, WHITE);
		
		DrawBmp(0, Y2, yuka, true);
		
		
		DrawLine(170,30,170,30+900, WHITE);
		DrawLine(1110, 30,1110, 30 + 900, WHITE);
		DrawLine(170, 30,1110, 30, WHITE);



		////////////////////////////////////////ï«(âº)///////////////////////////////////////

		
		if (InputKeyMouse(VK_RETURN)) {
	
		}

		
		//////////////////////É}ÉbÉvê∂ê¨ïîï™////////////////////


		//////////////////////////éãäEÅIÅI///////////////////////

		float PX = Player_X;
		float PY = Player_Y;
		float X = (PX * 20) + 10;
		float Y = (PY * 20) + 10;

		///////////////////////////////////////////////////////////////////////////////
		/////////////////////éãäEÇÃämï€/////////////////////
		Wall = false;
		switch (AngleCheck) {
		case 0:
			//è„
			if (map[Player_X - 1][Player_Y - 2] == 1) {
				DrawBmp(X21 + 3, Y21, left1, true);
			}
			if (map[Player_X + 1][Player_Y - 2] == 1) {
				DrawBmp(X2, Y21, right1, true);
			}
			if (map[Player_X - 1][Player_Y - 1] == 1) {
				DrawBmp(170, 30, left2, true);
			}
			if (map[Player_X + 1][Player_Y - 1] == 1) {
				DrawBmp(X22, 30, right2, true);
			}
			if (map[Player_X - 1][Player_Y] == 1) {
				DrawBmp(0, 0, left3, true);
			}
			if (map[Player_X + 1][Player_Y] == 1) {
				DrawBmp(1110, 0, right3, true);
			}
			if (map[Player_X][Player_Y - 3] == 5) {
				if (KeyPic == false) {
					DrawBmp(X1 + 2, Y1, DL1, true);
				}
				else {
					DrawBmp(X1 + 2, Y1, D1, true);
				}
			}
			if (map[Player_X][Player_Y - 3] == 0) {
				DrawBmp(X1 + 2, Y1, wall1, true);
			}
			if (map[Player_X][Player_Y - 3] == 6) {
				DrawBmp(X1 + 40, Y1 + 30, T1, true);
			}
			if (map[Player_X][Player_Y - 2] == 5) {
				if (KeyPic == false) {
					DrawBmp(X21, Y21, DL2, true);
				}
				else {
					DrawBmp(X21, Y21, D2, true);
				}
			}
			if (map[Player_X][Player_Y - 2] == 0) {
				DrawBmp(X21, Y21, wall2, true);
			}
			if (map[Player_X][Player_Y - 2] == 6) {
				DrawBmp(X1 + 2, Y1, T2, true);
			}
			if (map[Player_X][Player_Y - 1] == 5) {
				if (KeyPic == false) {
					DrawBmp(170, 30, DL3, true);
				}
				else {
					DrawBmp(170, 30, D3, true);
				}
			}
			if (map[Player_X][Player_Y - 1] == 0) {
				DrawBmp(170, 30, wall3, true);
			}
			if (map[Player_X][Player_Y - 1] == 6) {
				DrawBmp(X1 - 40, Y1, T3, true);
			}
			break;
		case 1:
			//âE
			if (map[Player_X + 2][Player_Y - 1] == 1) {
				DrawBmp(X21 + 3, Y21, left1, true);
			}
			if (map[Player_X + 2][Player_Y + 1] == 1) {
				DrawBmp(X2, Y21, right1, true);
			}
			if (map[Player_X + 1][Player_Y - 1] == 1) {
				DrawBmp(170, 30, left2, true);
			}
			if (map[Player_X + 1][Player_Y + 1] == 1) {
				DrawBmp(X22, 30, right2, true);
			}
			if (map[Player_X][Player_Y - 1] == 1) {
				DrawBmp(0, 0, left3, true);
			}
			if (map[Player_X][Player_Y + 1] == 1) {
				DrawBmp(1110, 0, right3, true);
			}
			if (map[Player_X + 3][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(X1 + 2, Y1, DL1, true);
				}
				else {
					DrawBmp(X1 + 2, Y1, D1, true);
				}
			}
			if (map[Player_X + 3][Player_Y] == 0) {
				DrawBmp(X1 + 2, Y1, wall1, true);
			}
			if (map[Player_X + 3][Player_Y] == 6) {
				DrawBmp(X1 + 40, Y1 + 30, T1, true);
			}
			if (map[Player_X + 2][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(X21, Y21, DL2, true);
				}
				else {
					DrawBmp(X21, Y21, D2, true);
				}
			}
			if (map[Player_X + 2][Player_Y] == 0) {
				DrawBmp(X21, Y21, wall2, true);
			}
			if (map[Player_X + 2][Player_Y] == 6) {
				DrawBmp(X1 + 2, Y1, T2, true);
			}
			if (map[Player_X + 1][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(170, 30, DL3, true);
				}
				else {
					DrawBmp(170, 30, D3, true);
				}
			}
			if (map[Player_X + 1][Player_Y] == 0) {
				DrawBmp(170, 30, wall3, true);
			}
			if (map[Player_X + 1][Player_Y] == 6) {
				DrawBmp(X1 - 40, Y1, T3, true);
			}
			break;
		case 2:
			//â∫
			if (map[Player_X + 1][Player_Y + 2] == 1) {
				DrawBmp(X21 + 3, Y21, left1, true);
			}
			if (map[Player_X - 1][Player_Y + 2] == 1) {
				DrawBmp(X2, Y21, right1, true);
			}
			if (map[Player_X + 1][Player_Y + 1] == 1) {
				DrawBmp(170, 30, left2, true);
			}
			if (map[Player_X - 1][Player_Y + 1] == 1) {
				DrawBmp(X22, 30, right2, true);
			}
			if (map[Player_X + 1][Player_Y] == 1) {
				DrawBmp(0, 0, left3, true);
			}
			if (map[Player_X - 1][Player_Y] == 1) {
				DrawBmp(1110, 0, right3, true);
			}
			if (map[Player_X][Player_Y + 3] == 0) {
				DrawBmp(X1 + 2, Y1, wall1, true);
			}
			if (map[Player_X][Player_Y + 3] == 6) {
				DrawBmp(X1 + 40, Y1 + 30, T1, true);
			}
			if (map[Player_X][Player_Y + 3] == 5) {
				if (KeyPic == false) {
					DrawBmp(X1 + 2, Y1, DL1, true);
				}
				else {
					DrawBmp(X1 + 2, Y1, D1, true);
				}
			}
			if (map[Player_X][Player_Y + 2] == 0) {
				DrawBmp(X21, Y21, wall2, true);
			}
			if (map[Player_X][Player_Y + 2] == 6) {
				DrawBmp(X1, Y1, T2, true);
			}
			if (map[Player_X][Player_Y + 2] == 5) {
				if (KeyPic == false) {
					DrawBmp(X21, Y21, DL2, true);
				}
				else {
					DrawBmp(X21, Y21, D2, true);
				}
			}
			if (map[Player_X][Player_Y + 1] == 0) {
				DrawBmp(170, 30, wall3, true);
			}
			if (map[Player_X][Player_Y + 1] == 6) {
				DrawBmp(X1 - 40, Y1, T3, true);
			}
			if (map[Player_X][Player_Y + 1] == 5) {
				if (KeyPic == false) {
					DrawBmp(170, 30, DL3, true);
				}
				else {
					DrawBmp(170, 30, D3, true);
				}
			}
			break;
		case 3:
			//ç∂
			if (map[Player_X - 2][Player_Y + 1] == 1) {
				DrawBmp(X21 + 3, Y21, left1, true);
			}
			if (map[Player_X - 2][Player_Y - 1] == 1) {
				DrawBmp(X2, Y21, right1, true);
			}
			if (map[Player_X - 1][Player_Y + 1] == 1) {
				DrawBmp(170, 30, left2, true);
			}
			if (map[Player_X - 1][Player_Y - 1] == 1) {
				DrawBmp(X22, 30, right2, true);
			}
			if (map[Player_X][Player_Y + 1] == 1) {
				DrawBmp(0, 0, left3, true);
			}
			if (map[Player_X][Player_Y - 1] == 1) {
				DrawBmp(1110, 0, right3, true);
			}
			if (map[Player_X - 3][Player_Y] == 0) {
				DrawBmp(X1 + 2, Y1, wall1, true);
			}
			if (map[Player_X - 3][Player_Y] == 6) {
				DrawBmp(X1 + 40, Y1 + 30, T1, true);
			}
			if (map[Player_X - 3][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(X1 + 2, Y1, DL1, true);
				}
				else {
					DrawBmp(X1 + 2, Y1, D1, true);
				}
			}
			if (map[Player_X - 2][Player_Y] == 0) {
				DrawBmp(X21, Y21, wall2, true);
			}
			if (map[Player_X - 2][Player_Y] == 6) {
				DrawBmp(X1, Y1, T2, true);
			}
			if (map[Player_X - 2][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(X21, Y21, DL2, true);
				}
				else {
					DrawBmp(X21, Y21, D2, true);
				}
			}
			if (map[Player_X - 1][Player_Y] == 0) {
				DrawBmp(170, 30, wall3, true);
			}
			if (map[Player_X - 1][Player_Y] == 6) {
				DrawBmp(X1 - 40, Y1, T3, true);
			}
			if (map[Player_X - 1][Player_Y] == 5) {
				if (KeyPic == false) {
					DrawBmp(170, 30, DL3, true);
				}
				else {
					DrawBmp(170, 30, D3, true);
				}
			}
		}


		//É~ÉjÉ}ÉbÉvÇÃçXêVèàóù
		DrawBmp(20, 20, back, true);

		for (int j = 0; j < 260; j += 20) {
			for (int i = 0; i < 260; i += 20) {
				map[0][i / 20] = 2;
				map[12][i / 20] = 2;
				map[j / 20][0] = 2;
				map[j / 20][12] = 2;
				switch (map[i / 20][j / 20]) {
				case 0:
					DrawBmp(i, j, white, false);
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 1:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 2:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 3:
					switch (AngleCheck) {
					case 0:
						DrawBmp(i, j, playerUp, true);
						break;
					case 1:
						DrawBmp(i, j, playerRight, true);
						break;
					case 2:
						DrawBmp(i, j, playerDown, true);
						break;
					case 3:
						DrawBmp(i, j, playerLeft, true);
						break;
					}
					break;
				case 4:
					break;
				case 5:
					DrawBmp(i, j, goal, true);
					break;
				case 6:
					DrawBmp(i, j, KeyBox, true);
					break;
				case 7:
					DrawBmp(i, j, goal, true);
					break;
				}
			}
		}

		//èâä˙ílÇÃê›íË
		if (Start == false) {

			if (fast == true) {
				x = Goal_X;
				y = Goal_Y;
			}
			if (fast == false) {

				r = rand();
				count = r % 5;

				x = 2 + (count * 2);

				r = rand();
				count = r % 5;

				y = 2 + (count * 2);

				fast = true;
			}

			map[x][y] = 3;

			Player_X = x;
			Player_Y = y;

			Start = true;

		}
		//É}ÉbÉvê∂ê¨
		while (End == false) {
			//åäå@ÇËã@ç\Å@ÉzÉäÉzÉä
			if (up != true || down != true || right != true || left != true) {
				r = rand();
				direction = r % 4;
				switch (direction) {
				case 0:
					if (map[x][y - 2] == 0) {
						map[x][y - 1] = 1;
						map[x][y - 2] = 1;
						x = x;
						y -= 2;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						up = true;
					}
					break;
				case 1:
					if (map[x][y + 2] == 0) {
						map[x][y + 1] = 1;
						map[x][y + 2] = 1;
						x = x;
						y += 2;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						down = true;
					}
					break;
				case 2:
					if (map[x + 2][y] == 0) {
						map[x + 1][y] = 1;
						map[x + 2][y] = 1;
						x += 2;
						y = y;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						right = true;
					}
					break;
				case 3:
					if (map[x - 2][y] == 0) {
						map[x - 1][y] = 1;
						map[x - 2][y] = 1;
						x -= 2;
						y = y;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						left = true;
					}
					break;

				default:
					break;

				}

			}
			//élï˚ç«Ç™Ç¡ÇΩÇ∆Ç´ÇÃëŒâû
			if (up == true && down == true && right == true && left == true) {


				r = rand();
				count = r % 5;

				x = 2 + (count * 2);

				r = rand();
				count = r % 5;

				y = 2 + (count * 2);

				if (map[x][y] == 1) {
					up = false;
					down = false;
					right = false;
					left = false;
				}
				else {
					up = true;
					down = true;
					right = true;
					left = true;
				}
			}
			if (Goal_count == 11) {
				map[x][y] = 6;
				Key_x = x;
				Key_y = y;
			}

			//ëSïîå@Ç¡ÇΩÇ©ämîFÅ@ÉàÉVÉbÅI
			if (Goal_count > 23) {
				map[x][y] = 5;
				Goal_X = x;
				Goal_Y = y;
				End = true;
				ClearScreen();
			}
		}


		//É~ÉjÉ}ÉbÉvâBÇµÇÃÉpÉlÉãêªçÏ
		for (int j = 0; j < 260; j += 20) {
			for (int i = 0; i < 260; i += 20) {
				panel[0][i / 20] = 2;
				panel[12][i / 20] = 2;
				panel[j / 20][0] = 2;
				panel[j / 20][12] = 2;
				switch (panel[i / 20][j / 20]) {
				case 0:
					DrawBmp(i, j, white, false);
					break;
				case 1:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 2:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;

				}
			}
		}



		/////////////////////////ÉvÉåÉCÉÑÅ[ëÄçÏ/////////////////////



		//ç≈èâÇÃï˚å¸ÇπÇ¡ÇƒÅ[
		if (StartAngle == false) {
			for (int i = 0; i < 4; ++i) {
				switch (i) {
				case 0:
					if (map[Player_X][Player_Y - 1] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X][Player_Y - 1] = 1;
						panel[Player_X][Player_Y - 2] = 1;

						AngleCheck = 0;
						StartAngle = true;
						break;
					}
					else {

					}
				case 1:
					if (map[Player_X + 1][Player_Y] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X + 1][Player_Y] = 1;
						panel[Player_X + 2][Player_Y] = 1;

						AngleCheck = 1;
						StartAngle = true;
						break;
					}
					else {

					}
				case 2:
					if (map[Player_X][Player_Y + 1] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X][Player_Y + 1] = 1;
						panel[Player_X][Player_Y + 2] = 1;

						AngleCheck = 2;
						StartAngle = true;
						break;
					}
					else {

					}
				case 3:
					if (map[Player_X - 1][Player_Y] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X - 1][Player_Y] = 1;
						panel[Player_X - 2][Player_Y] = 1;

						AngleCheck = 3;
						StartAngle = true;
						break;
					}
					else {

					}
				}
				i = 4;
			}
		}

		if (Player_X == Key_x && Player_Y == Key_y) {
			KFC++;
		}

		if (KFC > 0) {
			KeyPic = true;
		}
		else {
			KeyPic = false;
		}
		
		if (KFC < 0) {
			KFC == 0;
		}

		if (KeyPic == true) {
			DrawBmp(1200, 140, Key, true);
		}
		//ï˚å¸ì]ä∑Åïà⁄ìÆ
		
			if (InputKeyMouse(PK_W)) {
				switch (AngleCheck) {
				case 0:
					//è„ï˚å¸
					if (map[Player_X][Player_Y - 1] == 0) {
						break;
					}

					map[Player_X][Player_Y - 1] = 3;
					map[Player_X][Player_Y] = 1;
					bx = Player_X;
					by = Player_Y;
					Player_Y -= 1;
					move = true;
					break;
				case 1:
					//âEï˚å¸
					if (map[Player_X + 1][Player_Y] == 0) {
						break;
					}
					move = true;
					bx = Player_X;
					by = Player_Y;
					map[Player_X + 1][Player_Y] = 3;
					map[Player_X][Player_Y] = 1;
					Player_X += 1;
					break;
				case 2:
					//â∫ï˚å¸
					if (map[Player_X][Player_Y + 1] == 0) {
						break;
					}
					move = true;
					bx = Player_X;
					by = Player_Y;
					map[Player_X][Player_Y + 1] = 3;
					map[Player_X][Player_Y] = 1;
					Player_Y += 1;
					break;
				case 3:
					//ç∂ï˚å¸
					if (map[Player_X - 1][Player_Y] == 0) {
						break;
					}
					move = true;
					bx = Player_X;
					by = Player_Y;
					map[Player_X - 1][Player_Y] = 3;
					map[Player_X][Player_Y] = 1;
					Player_X -= 1;
					break;
				}

			}
		
		
		
		if (InputKeyMouse(PK_A) && LeftTurn == false) {
			AngleCheck -= 1;
			if (AngleCheck == -1) {
				AngleCheck = 3;
			}
			LeftTurn = true;
		}
		else {
			LeftTurn = false;

		}

		if (InputKeyMouse(PK_D) && RightTurn == false) {
			AngleCheck += 1;
			if (AngleCheck == 4) {
				AngleCheck = 0;
			}
			RightTurn = true;

		}
		else {
			RightTurn = false;

		}

		if (InputKeyMouse(PK_S)) {
			switch (AngleCheck) {
			case 2:
				//è„ï˚å¸
				if (map[Player_X][Player_Y - 1] == 0) {
					break;
				}

				map[Player_X][Player_Y - 1] = 3;
				map[Player_X][Player_Y] = 1;
				Player_Y -= 1;
				break;
			case 3:
				//âEï˚å¸
				if (map[Player_X + 1][Player_Y] == 0) {
					break;
				}

				map[Player_X + 1][Player_Y] = 3;
				map[Player_X][Player_Y] = 1;
				Player_X += 1;
				break;
			case 0:
				//â∫ï˚å¸
				if (map[Player_X][Player_Y + 1] == 0) {
					break;
				}

				map[Player_X][Player_Y + 1] = 3;
				map[Player_X][Player_Y] = 1;
				Player_Y += 1;
				break;
			case 1:
				//ç∂ï˚å¸
				if (map[Player_X - 1][Player_Y] == 0) {
					break;
				}

				map[Player_X - 1][Player_Y] = 3;
				map[Player_X][Player_Y] = 1;
				Player_X -= 1;
				break;
			}

		}

		if (Player_X == Goal_X && Player_Y == Goal_Y) {
			if (KeyPic == true) {
				KFC = 0;
				KeyPic = false;
				Goal_count = 0;
				End = false;
				Start = false;
				StartAngle = false;
				WallHitCheck = false;
				for (int j = 0; j < 260; j += 20) {
					for (int i = 0; i < 260; i += 20) {
						map[i / 20][j / 20] = 0;
						panel[i / 20][j / 20] = 0;
					}
				}
			}
			else {
				map[Player_X][Player_Y] = 5;
				map[bx][by] = 3;
				Player_X = bx;
				Player_Y = by;
			}
		}
		//////////////////////////////////////////////////////////////////////////////

		switch (AngleCheck) {
		case 0:
			//è„ï˚å¸
			if (panel[Player_X][Player_Y - 1] == 0) {
				panel[Player_X][Player_Y - 1] = 1;
				break;
			}
			if (panel[Player_X][Player_Y - 2] == 0&&map[Player_X][Player_Y - 1]==1) {
				panel[Player_X][Player_Y - 2] = 1;
				break;
			}
			break;
		case 1:
			//âEï˚å¸
			if (panel[Player_X + 1][Player_Y] == 0) {
				panel[Player_X + 1][Player_Y] = 1;
				break;
			}
			if (panel[Player_X + 2][Player_Y] == 0 && map[Player_X + 1][Player_Y] == 1) {
				panel[Player_X + 2][Player_Y] = 1;
				break;
			}
			break;
		case 2:
			//â∫ï˚å¸
			if (panel[Player_X][Player_Y + 1] == 0) {
				panel[Player_X][Player_Y + 1] = 1;
				break;
			}
			if (panel[Player_X][Player_Y + 2] == 0 && map[Player_X][Player_Y + 1] == 1) {
				panel[Player_X][Player_Y + 2] = 1;
				break;
			}
			break;
		case 3:
			//ç∂ï˚å¸
			if (panel[Player_X - 1][Player_Y] == 0) {
				panel[Player_X - 1][Player_Y] = 1;
				break;
			}
			if (panel[Player_X - 2][Player_Y] == 0 && map[Player_X - 1][Player_Y] == 1) {
				panel[Player_X - 2][Player_Y] = 1;
				break;
			}
			break;
		}

		////////////////////////////éûä‘ê›íË///////////////////////////

		CT++;

		//////////////////////////////////////////////////////////////
		PrintFrameBuffer();
		FlipScreen();

		ClearScreen();
		
			Sleep(16);
		







	}

	return 0;
}

/*	

		//è„ìÒñ{
		DrawLine(250, 0, 515, 100, WHITE);
		DrawLine(765, 100, 1030, 0, WHITE);
		//â∫ìÒñ{
		DrawLine(0, 720, 515, 300, WHITE);
		DrawLine(765, 300, 1280, 720, WHITE);
		//â∫ãÊêÿÇËê¸
		DrawLine(330, 450, 950, 450, WHITE);
		DrawLine(465, 340, 815, 340, WHITE);
		//è„ãÊêÿÇËê¸
		DrawLine(330, 30, 950, 30, WHITE);
		DrawLine(465, 80, 815, 80, WHITE);
		
		//////////////////////É}ÉbÉvê∂ê¨ïîï™////////////////////
		//É~ÉjÉ}ÉbÉvÇÃçXêVèàóù
		for (int j = 0; j < 260; j+=20) {
			for (int i = 0; i < 260; i+=20) {
				map[0][i/20] = 2;
				map[12][i/20] = 2;
				map[j/20][0] = 2;
				map[j/20][12] = 2;
				switch (map[i/20][j/20]) {
				case 0:
					DrawBmp(i,j,white,true);
					break;
				case 1:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 2:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 3:
					switch (AngleCheck) {
					case 0:
						DrawBmp(i, j, playerUp, true);
						break;
					case 1:
						DrawBmp(i, j, playerRight, true);
						break;
					case 2:
						DrawBmp(i, j, playerDown, true);
						break;
					case 3:
						DrawBmp(i, j, playerLeft, true);
						break;
					}
					break;
				case 4:
					break;
				case 5:
					DrawBmp(i, j, goal, true);
					break;
				}
			}
		}

		//èâä˙ílÇÃê›íË
		if (Start == false) {

			if (fast == false) {

			r = rand();
			count = r % 5;

			x = 2 + (count * 2);

			r = rand();
			count = r % 5;

			y = 2 + (count * 2);

			fast = true;
			}
			if (fast == true) {

			}

			map[x][y] = 3;

			Player_X = x;
			Player_Y = y;

			Start = true;

		}
		//É}ÉbÉvê∂ê¨
		while (End == false) {
			//åäå@ÇËã@ç\Å@ÉzÉäÉzÉä
			if (up != true || down != true || right != true || left != true) {
				r = rand();
				direction = r % 4;
				switch (direction) {
				case 0:
					if (map[x][y - 2] == 0) {
						map[x][y - 1] = 1;
						map[x][y - 2] = 1;
						x = x;
						y -= 2;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						up = true;
					}
					break;
				case 1:
					if (map[x][y + 2] == 0) {
						map[x][y + 1] = 1;
						map[x][y + 2] = 1;
						x = x;
						y += 2;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						down = true;
					}
					break;
				case 2:
					if (map[x + 2][y] == 0) {
						map[x + 1][y] = 1;
						map[x + 2][y] = 1;
						x += 2;
						y = y;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						right = true;
					}
					break;
				case 3:
					if (map[x - 2][y] == 0) {
						map[x - 1][y] = 1;
						map[x - 2][y] = 1;
						x -= 2;
						y = y;

						up = false;
						down = false;
						right = false;
						left = false;

						bef_x = x;
						bef_y = y;

						Goal_count++;

					}
					else {
						left = true;
					}
					break;

				default:
					break;

				}
				
			}
			//élï˚ç«Ç™Ç¡ÇΩÇ∆Ç´ÇÃëŒâû
			if (up == true && down == true && right == true && left == true) {
				
				
				r = rand();
				count = r % 5;

				x = 2 + (count * 2);

				r = rand();
				count = r % 5;

				y = 2 + (count * 2);

				if (map[x][y] == 1) {
					up = false;
					down = false;
					right = false;
					left = false;
				}
				else {
					up = true;
					down = true;
					right = true;
					left = true;
				}
			}
			//ëSïîå@Ç¡ÇΩÇ©ämîFÅ@ÉàÉVÉbÅI
			if (Goal_count > 23) {
				map[x][y] = 5;
				End = true;
			}
		}


		//É~ÉjÉ}ÉbÉvâBÇµÇÃÉpÉlÉãêªçÏ
		for (int j = 0; j < 260; j += 20) {
			for (int i = 0; i < 260; i += 20) {
				panel[0][i / 20] = 2;
				panel[12][i / 20] = 2;
				panel[j / 20][0] = 2;
				panel[j / 20][12] = 2;
				switch (panel[i / 20][j / 20]) {
				case 0:
					DrawBmp(i, j, white, false);
					break;
				case 1:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;
				case 2:
					SetCursorPosition(i, j); PrintString("	", 4);
					break;

				}
			}
		}
		
		/////////////////////////ÉvÉåÉCÉÑÅ[ëÄçÏ/////////////////////

		//ç≈èâÇÃï˚å¸ÇπÇ¡ÇƒÅ[
		if (StartAngle == false) {
			for (int i = 0; i < 4; ++i) {
				switch (i) {
				case 0:
					if (map[Player_X][Player_Y - 1] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X][Player_Y - 1] = 1;
						panel[Player_X][Player_Y - 2] = 1;

						AngleCheck = 0;
						StartAngle = true;
						break;
					}
					else {

					}
				case 1:
					if (map[Player_X + 1][Player_Y] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X + 1][Player_Y] = 1;
						panel[Player_X + 2][Player_Y] = 1;

						AngleCheck = 1;
						StartAngle = true;
						break;
					}
					else {

					}
				case 2:
					if (map[Player_X][Player_Y + 1] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X][Player_Y + 1] = 1;
						panel[Player_X][Player_Y + 2] = 1;

						AngleCheck = 2;
						StartAngle = true;
						break;
					}
					else {

					}
				case 3:
					if (map[Player_X - 1][Player_Y] == 1) {

						panel[Player_X][Player_Y] = 1;
						panel[Player_X - 1][Player_Y] = 1;
						panel[Player_X - 2][Player_Y] = 1;

						AngleCheck = 3;
						StartAngle = true;
						break;
					}
					else {

					}
				}
				i = 4;
			}
		}
		


		//ï˚å¸ì]ä∑Åïà⁄ìÆ
		if (InputKeyMouse(PK_W)) {
			switch (AngleCheck) {
			case 0:
				//è„ï˚å¸
				if (map[Player_X][Player_Y - 1] == 0) {
					break;
				}

				map[Player_X][Player_Y - 1] = 3;
				map[Player_X][Player_Y] = 1;
				Player_Y -= 1;
				break;
			case 1:
				//âEï˚å¸
				if (map[Player_X + 1][Player_Y] == 0) {
					break;
				}

				map[Player_X + 1][Player_Y] = 3;
				map[Player_X][Player_Y] = 1;
				Player_X += 1;
				break;
			case 2:
				//â∫ï˚å¸
				if (map[Player_X][Player_Y + 1] == 0) {
					break;
				}

				map[Player_X][Player_Y + 1] = 3;
				map[Player_X][Player_Y] = 1;
				Player_Y += 1;
				break;
			case 3:
				//ç∂ï˚å¸
				if (map[Player_X - 1][Player_Y] == 0) {
					break;
				}

				map[Player_X - 1][Player_Y] = 3;
				map[Player_X][Player_Y] = 1;
				Player_X -= 1;
				break;
			}
		}
		if (InputKeyMouse(PK_A) && LeftTurn==false) {
			AngleCheck -= 1;
			if (AngleCheck == -1) {
				AngleCheck = 3;
			}
			LeftTurn = true;
		}
		if (InputKeyMouse(PK_D) && RightTurn == false) {
			AngleCheck += 1;
			if (AngleCheck == 4) {
				AngleCheck = 0;
			}
			RightTurn = true;
		}
		if (InputKeyMouse(PK_S)) {
			AngleCheck -= 2;
			if (AngleCheck == -1) {
				AngleCheck = 3;
			}
			if (AngleCheck == -2) {
				AngleCheck = 2;
			}
		}

		if (InputKeyMouse(PK_A) == 0 && LeftTurn == true) {
			LeftTurn = false;
		}
		if (InputKeyMouse(PK_D) == 0 && RightTurn == true) {
			RightTurn = false;
		}


		switch (AngleCheck) {
		case 0:
			panel[Player_X][Player_Y] = 1;
			panel[Player_X][Player_Y - 1] = 1;
			if (map[Player_X][Player_Y - 1] == 1) {

			panel[Player_X][Player_Y - 2] = 1;

			}
			break;
		case 1:
			panel[Player_X][Player_Y] = 1;
			panel[Player_X + 1][Player_Y] = 1;
			if (map[Player_X + 1][Player_Y] == 1) {

				panel[Player_X + 2][Player_Y] = 1;

			}
			break;
		case 2:
			panel[Player_X][Player_Y] = 1;
			panel[Player_X][Player_Y + 1] = 1;
			if (map[Player_X][Player_Y + 1] == 1) {

				panel[Player_X][Player_Y + 2] = 1;

			}
			break;
		case 3:
			panel[Player_X][Player_Y] = 1;
			panel[Player_X - 1][Player_Y] = 1;
			if (map[Player_X - 1][Player_Y] == 1) {

				panel[Player_X - 2][Player_Y] = 1;

			}
			break;
		}

		int X = x + 10;
		int Y = y + 10;


		//DrawCircle(X, Y, 60, 0xFFFFFF, false);


		D = R;
		a = (D - 1);
		b = 0;

		while (a >= b) {
			//âEâÒÇËÇ≈êÖïΩÇ™ÇOìxÅFÇPâÒÇ≈ÇWÉhÉbÉgÅiÇWè€å¿ï™ÅjÇï`Ç≠
			if (0 <= angle && angle < 90) {
				DrawPixel(X + a, Y + b, WHITE);	//ëÊÇPè€å¿ÅFÅ@Å@ÇOÅãÅ`
				DrawLine(X, Y, X + a, Y + b, YELLOW);
			}
			if (45 <= angle && angle < 135) {
				DrawPixel(X + b, Y + a, WHITE);	//ëÊÇQè€å¿ÅFÅ@ÇSÇTÅãÅ`
				DrawLine(X, Y, X + b, Y + a, YELLOW);
			}
			if (90 <= angle && angle < 180) {
				DrawPixel(X - b, Y + a, WHITE);	//ëÊÇRè€å¿ÅFÅ@ÇXÇOÅãÅ`
				DrawLine(X, Y, X - b, Y + a, YELLOW);
			}
			if (135 <= angle && angle < 225) {
				DrawPixel(X - a, Y + b, WHITE);	//ëÊÇRè€å¿ÅFÇPÇRÇTÅãÅ`
				DrawLine(X, Y, X - a, Y + b, YELLOW);
			}
			if (180 <= angle && angle < 270) {
				DrawPixel(X - a, Y - b, WHITE);	//ëÊÇRè€å¿ÅFÇPÇWÇOÅãÅ`
				DrawLine(X, Y, X - a, Y - b, YELLOW);
			}
			if (225 <= angle && angle < 315) {
				DrawPixel(X - b, Y - a, WHITE);	//ëÊÇRè€å¿ÅFÇQÇQÇTÅãÅ`
				DrawLine(X, Y, X - b, Y - a, YELLOW);
			}
			if (270 <= angle && angle < 360) {
				DrawPixel(X + b, Y - a, WHITE);	//ëÊÇRè€å¿ÅFÇQÇVÇOÅãÅ`
				DrawLine(X, Y, X + b, Y - a, YELLOW);
			}
			if ((315 <= angle && angle < 360) || (0 <= angle && angle < 45)) {
				DrawPixel(X + a, Y - b, WHITE);	//ëÊÇRè€å¿ÅFÇRÇPÇTÅãÅ`ÇRÇUÇOÅã
				DrawLine(X, Y, X + a, Y - b, YELLOW);
			}
			D -= (b << 1);
			if (D <= 0) {
				a--;
				D += (a << 1);
			}
			b++;

		}

		DrawBmp(x, y, playerUp, true);
		if (angle > 360) {
			angle = 0;
		}
		if (angle < 0) {
			angle = 360;
		}
		////////////////////////////éûä‘ê›íË///////////////////////////



		//////////////////////////////////////////////////////////////
		PrintFrameBuffer();
		FlipScreen();

		ClearScreen();
		Sleep(16);
	
		
		*/



/*

D = R;
		a = (D - 1);
		b = 0;

		while (a >= b) {
			//âEâÒÇËÇ≈êÖïΩÇ™ÇOìxÅFÇPâÒÇ≈ÇWÉhÉbÉgÅiÇWè€å¿ï™ÅjÇï`Ç≠
			if (0 <= angle && angle < 90) {
				DrawPixel(X + a, Y + b, WHITE);	//ëÊÇPè€å¿ÅFÅ@Å@ÇOÅãÅ`
				DrawLine(X, Y, X + a, Y + b, YELLOW);
			}
			if (45 <= angle && angle < 135) {
				DrawPixel(X + b, Y + a, WHITE);	//ëÊÇQè€å¿ÅFÅ@ÇSÇTÅãÅ`
				DrawLine(X, Y, X + b, Y + a, YELLOW);
			}
			if (90 <= angle && angle < 180) {
				DrawPixel(X - b, Y + a, WHITE);	//ëÊÇRè€å¿ÅFÅ@ÇXÇOÅãÅ`
				DrawLine(X, Y, X - b, Y + a, YELLOW);
			}
			if (135 <= angle && angle < 225) {
				DrawPixel(X - a, Y + b, WHITE);	//ëÊÇRè€å¿ÅFÇPÇRÇTÅãÅ`
				DrawLine(X, Y, X - a, Y + b, YELLOW);
			}
			if (180 <= angle && angle < 270) {
				DrawPixel(X - a, Y - b, WHITE);	//ëÊÇRè€å¿ÅFÇPÇWÇOÅãÅ`
				DrawLine(X, Y, X - a, Y - b, YELLOW);
			}
			if (225 <= angle && angle < 315) {
				DrawPixel(X - b, Y - a, WHITE);	//ëÊÇRè€å¿ÅFÇQÇQÇTÅãÅ`
				DrawLine(X, Y, X - b, Y - a, YELLOW);
			}
			if (270 <= angle && angle < 360) {
				DrawPixel(X + b, Y - a, WHITE);	//ëÊÇRè€å¿ÅFÇQÇVÇOÅãÅ`
				DrawLine(X, Y, X + b, Y - a, YELLOW);
			}
			if ((315 <= angle && angle < 360) || (0 <= angle && angle < 45)) {
				DrawPixel(X + a, Y - b, WHITE);	//ëÊÇRè€å¿ÅFÇRÇPÇTÅãÅ`ÇRÇUÇOÅã
				DrawLine(X, Y, X + a, Y - b, YELLOW);
			}
			D -= (b << 1);
			if (D <= 0) {
				a--;
				D += (a << 1);
			}
			b++;

		}
*/