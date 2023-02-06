#include<iostream>
#include<math.h>
#include<graphics.h>
#define WIN_WIDTH 1080
#define WIN_HEIGHT 640
#define MAX_IMAGE 11  //���ͼƬ����
#define MAX_MINE 10   //�����Ʒ����
#define MAX_ANGLE 80 //���Ƕ�
#define PI 3.1415926535898

enum MINE_TYPE
{
	GOLD,
	DIAMOND,
	STONE,
	//����
	LEFT,
	RIGHT,
	//״̬���������쳤������
	M_NORMAL,
	M_LONG,
	M_SHORT,
};

class hook {
public:
	hook();
	void rock();
	void go();
	friend void back(hook& hook1);
	friend void catch1(hook& hook1);
	int distance();
private:
	int x, y, endx, endy, len, angle, dir, vx, vy;
	int state, index;//��¼ץ������Ʒ�±�
};

int hook::distance() {
	int dis = sqrt((double)(x - endx) * (x - endx) + (double)(y - endy) * (y - endy));
	return dis <= len;
}

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
}

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
}

void hook::go() {
	if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_DOWN)) && state == M_NORMAL)
	{
		vx = sin(PI / 180 * angle) * 10;
		vy = cos(PI / 180 * angle) * 10;
		state = M_LONG;
	}
	if (endx<0 || endx>WIN_WIDTH || endy > WIN_HEIGHT)
	{
		state = M_SHORT;
	}
	if (state == M_LONG)
	{
		endx += vx;
		endy += vy;
	}
}
/*
void catch1(hook& hook1)
{
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true &&
			hook1.endx > mine[i].x && hook1.endx < mine[i].x + mine[i].szie &&
			hook1.endy > mine[i].y && hook1.endy < mine[i].y + mine[i].szie)
		{
			hook1.index = i;
			break;
		}
	}
}
*/
void back(hook& hook1)
{
	if (hook1.state == M_SHORT && hook1.index == -1)
	{
		hook1.endx -= hook1.vx;
		hook1.endy -= hook1.vy;
		if (hook1.distance()) {
			hook1.state = M_NORMAL;
		}
	}
	else if (hook1.state == M_SHORT)
	{
		hook1.endx -= 1;
		hook1.endy -= 1;
		if (hook1.distance())
		{
			hook1.state = M_NORMAL;
		}
	}
}