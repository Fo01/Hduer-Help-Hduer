#include<iostream>
#include<math.h>
#include<graphics.h>
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define max_obj 2
#define MAX_ANGLE 80 //最大角度
#define PI 3.1415926535898

enum MINE_TYPE
{
	//方向
	LEFT,
	RIGHT,
	//状态，正常，伸长，缩短
	M_NORMAL,
	M_LONG,
	M_SHORT,
};

class Obj {
public:
	bool flag;
	int GetX() { return x; }
	int GetY() { return y; }
	int GetValue() { return value; }
	int GetSpeed() { return speed; }
	int GetSize() { return size; }
	int VALUE[6] = { 1000,500,200,600,50,20 };     //大黄金1000，中500，小200；钻石600；大石头50，小石头20
	int SPEED[6] = { 4,7,10,10,2,4 };              //大黄金4，中7，小10；钻石10；大石头2，小石头4
	int SIZE[6] = { 9000,3240,1440,750,2580,1120 };//大黄金9000，中3240，小1440；钻石750；大石头2580，小石头1120
	void pos(Obj mine, int i);    //i用来定位形状
private:
	int value, speed, size, x, y;
};

void Obj::pos(Obj mine, int i) {
	IMAGE img[6];                       //加载图片
	//loadimage(&img[0], L"钻石.png ");
	//loadimage(&img[1], L"大黄金.png ");
//	loadimage(&img[2], L"中黄金.png ");
	//loadimage(&img[3], L"小黄金.png ");
//	loadimage(&img[4], L"大石头.png ");
	//loadimage(&img[5], L"小石头.png ");

	//mine.x = rand() % (width - 100);       //随机生成x坐标
	//mine.y = rand() % (heigth - 300) + 210;//随机生成x坐标
	mine.value = mine.VALUE[i];            //根据i的定位取价值
	mine.speed = mine.SPEED[i];            //根据i的定位取速度
	mine.size = mine.SIZE[i];
	mine.flag = true;                      //初始都是true
	putimage(mine.x, mine.y, &img[i]);
}


class hook {//抓钩类
public:
	hook();//初始化
	void rock();//摆动
	void go();//射出
	friend void back(hook& hook1);//回来
	friend void catch1(hook& hook1);//判定是否抓住
	int distance();//抓钩长度
private:
	int x, y, endx, endy, len, angle, dir, vx, vy;
	int state, index;//纪录抓到的物品下标
};

int hook::distance() {
	int dis = sqrt((double)(x - endx) * (x - endx) + (double)(y - endy) * (y - endy));
	return dis <= len;
}//长度计算

hook::hook() {
	x = WIN_WIDTH / 2 - 30;
	y = 100;
	len = 50;
	endx = x;
	endy = y + len;
	angle = 0;
	dir = RIGHT;
	vx = 0;
	vy = 0;
	state = M_NORMAL;
	index = -1;
}//初始化

void hook::rock()
{
	if (state == M_NORMAL)
	{
		if (dir == RIGHT)
		{
			angle++;
		}
		else
		{
			angle--;
		}
		if (angle > MAX_ANGLE)
		{

			dir = LEFT;
		}
		else if (angle < -MAX_ANGLE)
		{
			dir = RIGHT;
		}
		endx = x + sin(PI / 180 * angle) * len;
		endy = y + cos(PI / 180 * angle) * len;
	}
}//抓钩摆动

void hook::go() {
	if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_DOWN)) && state == M_NORMAL)//正常状态按空格或者方向下键
	{
		vx = sin(PI / 180 * angle) * 10;
		vy = cos(PI / 180 * angle) * 10;
		state = M_LONG;//状态变更为伸长
	}
	if (endx<0 || endx>WIN_WIDTH || endy > WIN_HEIGHT)
	{
		state = M_SHORT;//炒出范围状态变更为缩短
	}
	if (state == M_LONG)//伸长
	{
		endx += vx;
		endy += vy;
	}
}

void catch1(hook& hook1)
{
//	for (int i = 0; i < MAX_MINE; i++)
	{
//		if (mine[i].flag == true &&
//			hook1.endx > mine[i].GetX && hook1.endx < mine[i].GetX + mine[i].GetSize &&
//			hook1.endy>mine[i].GetY && hook1.endy < mine[i].GetY + mine[i].GetSzie)
		{//如果抓住了，下标变化，状态变化
//			hook1.index = i;
//			hook1.state = M_SHORT;
//			break;
		}
	}
}

void back(hook& hook1)
{
	if (hook1.state == M_SHORT && hook1.index == -1)//如果没有抓到东西就直接返回
	{
		hook1.endx -= hook1.vx;
		hook1.endy -= hook1.vy;
		if (hook1.distance()) {
			hook1.state = M_NORMAL;//状态更新为NORMAL
		}
	}
	else if (hook1.state == M_SHORT)//如果抓到了东西
	{
		int vx = 0, vy = 0;
//		vx = mine[hook1.index].GetSpeed * sin(PI / 180 * hook1.angle);//X方向上速度分量
//		vy = mine[hook1.index].GetSpeed * cos(PI / 180 * hook1.angle);//y方向上速度分量
		hook1.endx -= vx;
		hook1.endy -= vy;
		if (hook1.distance())//状态重置
		{
			hook1.state = M_NORMAL;
			hook1.index = -1;
	//		mine[hook1.index].flag = false;
		}
	}
}
/*
int main() {
	initgraph(width, heigth);//设置画布
	srand(GetTickCount());//随机种子
	Obj mine[max_obj];
	hook hook1;
	hook1();
	int i, j;
	for (j = 0; j < max_obj; j++) //内循环把6种图形的位置等信息都确定，贴图；外循环决定每种图形有多少个
		for (i = 0; i < 6; i++)
			mine[j * 6 + i].pos(mine[j * 6 + i], i);
	while (1) {
		hook1.rock();
		hook1.go();
		catch1(hook1);
		back(hook1);

	}
	cin.get();
	closegraph();
	return 0;
}
*/