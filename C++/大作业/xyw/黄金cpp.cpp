#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <ctime>
#include <time.h>
using namespace std;

class Obj {
public:
	void initobj(int value = 0, int speed = 0) { this->value = value; this->speed = speed; }
	int GetValue() {
		return value;
	}
	int GetSpeed() {
		return speed;
	}
	int GetPos_x() {
		return pos_x;
	}
	int GetPos_y() {
		return pos_y;
	}
	int pos_x;
	int pos_y;
private:
	int value;
	int speed;
};

class Diamond :public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\钻石.jpg"));
		pos_x = rand() % 1200;
		pos_y = rand() % 290 + 400;
		putimage(pos_x, pos_y, &img);
	}
};

class Big_Gold : public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\大黄金.jpg"));
		pos_x = rand() % 690 + 10;
		pos_y = rand() % 150 + 350;
		putimage(pos_x, pos_y, &img);
	}
};

class Middle_Gold : public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\中黄金.jpg"));
		pos_x = rand() % 500 + 700;
		pos_y = rand() % 100 + 250;
		putimage(pos_x, pos_y, &img);
	}
};

class Small_Gold : public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\小黄金.jpg"));
		pos_x = rand() % 1200;
		pos_y = rand() % 100 + 150;
		putimage(pos_x, pos_y, &img);
	}
};

class Big_Stone : public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\大石头.jpg"));
		pos_x = rand() % 600 + 600;
		pos_y = rand() % 350 + 150;
		putimage(pos_x, pos_y, &img);
	}
};

class Small_Stone : public Obj {
public:
	void pos() {
		IMAGE img;
		loadimage(&img, _T("C:\\Users\\Fool\\Desktop\\xyw\\矿物\\小石头.jpg"));
		pos_x = rand() % 550 + 10;
		pos_y = rand() % 300 + 350;
		putimage(pos_x, pos_y, &img);
	}
};