#include<iostream>
#include<math.h>
#include<graphics.h>
#define MAX_MINE 12
#define WIN_WIDTH 1000
#define WIN_HEIGHT 700
#define max_obj 2
#define MAX_ANGLE 160 //最大角度
#define MIN_ANGLE 20  //最小角度
#define PI 3.1415926535898
#define MAX_LEN 800
#define soil RGB(188,182,124)

class Obj {
public:
	IMAGE img[6];
	bool flag;
	double getx() { return x; }
	double gety() { return y; }
	double getendx() { return endx; }
	double getendy() { return endy; }
	int getflag() { return flag; }
	int getvalue() { return value; }
	int getspeed() { return speed; }
	int VALUE[6] = { 1000,500,200,600,50,20 };     //大黄金1000，中500，小200；钻石600；大石头50，小石头20         公共价值，价值从这里选
	double SPEED[6] = { 4,7,10,10,2,4 };              //大黄金4，中7，小10；钻石10；大石头2，小石头4                  公共速度，速度从这里选
	int SIZE[6][2] = { 100,60,40,30,60,40,90,54,36,25,43,28 };
	                                               //大黄金100*90，中60*54，小40*36；钻石30*25；大石头60*43，小石头40*28   公共尺寸，尺寸从这里选
	void pos(int i);                     //i用来定位形状，表示是 大黄金，中，小；钻石；大石头，小石头 中的一个 
	void show() { putimage(x, y, &img[key]); }
	void changex(double num) { x = num; }
	void changey(double num) { y = num; }
	Obj()
	{
		loadimage(&img[0], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\钻石.jpg ");
		loadimage(&img[1], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\大黄金.jpg ");
		loadimage(&img[2], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\中黄金.jpg ");
		loadimage(&img[3], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\小黄金.jpg ");
		loadimage(&img[4], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\大石头.jpg ");
		loadimage(&img[5], "C:\\Users\\Fool\\Desktop\\xyw\\矿物\\小石头.jpg ");
	}
private:
	int value, key; //x,y表示左上角的点，endx,endy表示右下角的点
	double x, y, endx, endy, speed;
};

void Obj::pos(int i) {
	key = i; 
	x = rand() % (WIN_WIDTH - 200) + 100;           //随机生成x坐标    100-900
	y = rand() % (WIN_HEIGHT - 400) + 300;          //随机生成y坐标    300-600

	value = VALUE[i];            //根据i的定位取价值
	speed = SPEED[i];            //根据i的定位取速度
	flag = true;                 //初始都是true
	endx = SIZE[key][0]+x;
	endy = SIZE[key][1]+y;
	show();
}

//摆动方向，左，右
#define LEFT 0   
#define RIGHT 1 
//下三个为状态，正常，伸长，缩短，用于给state赋值
#define M_NORMAL 2 
#define M_LONG 3   
#define M_SHORT 4

class hook {//抓钩类
public:
	hook();//初始化
	hook(hook& h);
	void rock();//摆动
	double distance();//抓钩长度

	double getx() { return x; }
	double gety() { return y; }
	double getv() { return v; }
	double getvx() { return vx; }
	double getvy() { return vy; }
	double getendx() { return endx; }
	double getendy() { return endy; }
	int getlen() { return len; }
	int getindex() { return index; }
	int getstate() { return state; }
	int getangle() { return angle; }

	void changevx(double num) { vx = num; }
	void changevy(double num) { vy = num; }
	void changeendx(double num) { endx= num; }
	void changeendy(double num) { endy = num; }
	void changestate(int num) { state = num; }
	void changeindex(int num) { index = num; }
private:
	double x, y, endx, endy, vx, vy, v;
	int len, angle, dir, flag;
	int state, index;//纪录抓到的物品下标
	
};

double hook::distance() {
	double dis = sqrt((double)(x - endx) * (x - endx) + (double)(y - endy) * (y - endy));
	return dis ;
}//长度计算

hook::hook(hook &h) {
	x = h.x;
	y = h.y;
	len = h.len;
	flag = h.flag;
	endx = h.endx;
	endy = h.endy;
	angle = h.angle;
	dir = h.dir;
	v = h.v;
	vx = h.vx;
	vy = h.vy;
	state = h.state;
	index = h.index;
}//初始化

hook::hook() {
	x = WIN_WIDTH / 2 - 40;
	y = 200;
	len = 10;
	flag = 0;
	endx = x;
	endy = y;
	angle = MIN_ANGLE;
	dir = RIGHT;
	v = 10;
	vx = vy = 0;
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
		else if (angle < MIN_ANGLE)
		{
			dir = RIGHT;
		}
	}
}//抓钩摆动

int judge_inside(double x1, double y1, Obj mine[], int key)
{
	if (x1 >= mine[key].getx() && x1 <= mine[key].getendx() && y1 >= mine[key].gety() && y1 <= mine[key].getendy()) return 1;
	return 0;
}

void judge_to_catch(hook& hook1,Obj mine[])       //判断有没有东西被抓住了
{
	double xx = hook1.getendx();
	double yy = hook1.getendy();
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true &&
		   ((judge_inside(xx ,yy ,mine ,i))|| (judge_inside(xx+80, yy, mine, i))|| (judge_inside(xx, yy+87, mine, i))|| (judge_inside(xx+80, yy+87, mine, i))))
		{//如果抓住了，下标变化，状态变化
			hook1.changeindex(i);
			hook1.changestate(M_SHORT);
			mine[i].flag = false;
			break;
		}
	}
}