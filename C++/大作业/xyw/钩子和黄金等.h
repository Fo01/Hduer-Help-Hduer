#include<iostream>
#include<math.h>
#include<graphics.h>
#define MAX_MINE 12
#define WIN_WIDTH 1000
#define WIN_HEIGHT 700
#define max_obj 2
#define MAX_ANGLE 160 //���Ƕ�
#define MIN_ANGLE 20  //��С�Ƕ�
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
	int VALUE[6] = { 1000,500,200,600,50,20 };     //��ƽ�1000����500��С200����ʯ600����ʯͷ50��Сʯͷ20         ������ֵ����ֵ������ѡ
	double SPEED[6] = { 4,7,10,10,2,4 };              //��ƽ�4����7��С10����ʯ10����ʯͷ2��Сʯͷ4                  �����ٶȣ��ٶȴ�����ѡ
	int SIZE[6][2] = { 100,60,40,30,60,40,90,54,36,25,43,28 };
	                                               //��ƽ�100*90����60*54��С40*36����ʯ30*25����ʯͷ60*43��Сʯͷ40*28   �����ߴ磬�ߴ������ѡ
	void pos(int i);                     //i������λ��״����ʾ�� ��ƽ��У�С����ʯ����ʯͷ��Сʯͷ �е�һ�� 
	void show() { putimage(x, y, &img[key]); }
	void changex(double num) { x = num; }
	void changey(double num) { y = num; }
	Obj()
	{
		loadimage(&img[0], "C:\\Users\\Fool\\Desktop\\xyw\\����\\��ʯ.jpg ");
		loadimage(&img[1], "C:\\Users\\Fool\\Desktop\\xyw\\����\\��ƽ�.jpg ");
		loadimage(&img[2], "C:\\Users\\Fool\\Desktop\\xyw\\����\\�лƽ�.jpg ");
		loadimage(&img[3], "C:\\Users\\Fool\\Desktop\\xyw\\����\\С�ƽ�.jpg ");
		loadimage(&img[4], "C:\\Users\\Fool\\Desktop\\xyw\\����\\��ʯͷ.jpg ");
		loadimage(&img[5], "C:\\Users\\Fool\\Desktop\\xyw\\����\\Сʯͷ.jpg ");
	}
private:
	int value, key; //x,y��ʾ���Ͻǵĵ㣬endx,endy��ʾ���½ǵĵ�
	double x, y, endx, endy, speed;
};

void Obj::pos(int i) {
	key = i; 
	x = rand() % (WIN_WIDTH - 200) + 100;           //�������x����    100-900
	y = rand() % (WIN_HEIGHT - 400) + 300;          //�������y����    300-600

	value = VALUE[i];            //����i�Ķ�λȡ��ֵ
	speed = SPEED[i];            //����i�Ķ�λȡ�ٶ�
	flag = true;                 //��ʼ����true
	endx = SIZE[key][0]+x;
	endy = SIZE[key][1]+y;
	show();
}

//�ڶ���������
#define LEFT 0   
#define RIGHT 1 
//������Ϊ״̬���������쳤�����̣����ڸ�state��ֵ
#define M_NORMAL 2 
#define M_LONG 3   
#define M_SHORT 4

class hook {//ץ����
public:
	hook();//��ʼ��
	hook(hook& h);
	void rock();//�ڶ�
	double distance();//ץ������

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
	int state, index;//��¼ץ������Ʒ�±�
	
};

double hook::distance() {
	double dis = sqrt((double)(x - endx) * (x - endx) + (double)(y - endy) * (y - endy));
	return dis ;
}//���ȼ���

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
}//��ʼ��

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
}//��ʼ��

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
}//ץ���ڶ�

int judge_inside(double x1, double y1, Obj mine[], int key)
{
	if (x1 >= mine[key].getx() && x1 <= mine[key].getendx() && y1 >= mine[key].gety() && y1 <= mine[key].getendy()) return 1;
	return 0;
}

void judge_to_catch(hook& hook1,Obj mine[])       //�ж���û�ж�����ץס��
{
	double xx = hook1.getendx();
	double yy = hook1.getendy();
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true &&
		   ((judge_inside(xx ,yy ,mine ,i))|| (judge_inside(xx+80, yy, mine, i))|| (judge_inside(xx, yy+87, mine, i))|| (judge_inside(xx+80, yy+87, mine, i))))
		{//���ץס�ˣ��±�仯��״̬�仯
			hook1.changeindex(i);
			hook1.changestate(M_SHORT);
			mine[i].flag = false;
			break;
		}
	}
}