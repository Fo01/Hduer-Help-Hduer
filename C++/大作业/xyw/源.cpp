#include<iostream>
#include<math.h>
#include<graphics.h>
#define WIN_WIDTH 1280
#define WIN_HEIGHT 720
#define max_obj 2
#define MAX_ANGLE 80 //���Ƕ�
#define PI 3.1415926535898

enum MINE_TYPE
{
	//����
	LEFT,
	RIGHT,
	//״̬���������쳤������
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
	int VALUE[6] = { 1000,500,200,600,50,20 };     //��ƽ�1000����500��С200����ʯ600����ʯͷ50��Сʯͷ20
	int SPEED[6] = { 4,7,10,10,2,4 };              //��ƽ�4����7��С10����ʯ10����ʯͷ2��Сʯͷ4
	int SIZE[6] = { 9000,3240,1440,750,2580,1120 };//��ƽ�9000����3240��С1440����ʯ750����ʯͷ2580��Сʯͷ1120
	void pos(Obj mine, int i);    //i������λ��״
private:
	int value, speed, size, x, y;
};

void Obj::pos(Obj mine, int i) {
	IMAGE img[6];                       //����ͼƬ
	//loadimage(&img[0], L"��ʯ.png ");
	//loadimage(&img[1], L"��ƽ�.png ");
//	loadimage(&img[2], L"�лƽ�.png ");
	//loadimage(&img[3], L"С�ƽ�.png ");
//	loadimage(&img[4], L"��ʯͷ.png ");
	//loadimage(&img[5], L"Сʯͷ.png ");

	//mine.x = rand() % (width - 100);       //�������x����
	//mine.y = rand() % (heigth - 300) + 210;//�������x����
	mine.value = mine.VALUE[i];            //����i�Ķ�λȡ��ֵ
	mine.speed = mine.SPEED[i];            //����i�Ķ�λȡ�ٶ�
	mine.size = mine.SIZE[i];
	mine.flag = true;                      //��ʼ����true
	putimage(mine.x, mine.y, &img[i]);
}


class hook {//ץ����
public:
	hook();//��ʼ��
	void rock();//�ڶ�
	void go();//���
	friend void back(hook& hook1);//����
	friend void catch1(hook& hook1);//�ж��Ƿ�ץס
	int distance();//ץ������
private:
	int x, y, endx, endy, len, angle, dir, vx, vy;
	int state, index;//��¼ץ������Ʒ�±�
};

int hook::distance() {
	int dis = sqrt((double)(x - endx) * (x - endx) + (double)(y - endy) * (y - endy));
	return dis <= len;
}//���ȼ���

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
		else if (angle < -MAX_ANGLE)
		{
			dir = RIGHT;
		}
		endx = x + sin(PI / 180 * angle) * len;
		endy = y + cos(PI / 180 * angle) * len;
	}
}//ץ���ڶ�

void hook::go() {
	if ((GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_DOWN)) && state == M_NORMAL)//����״̬���ո���߷����¼�
	{
		vx = sin(PI / 180 * angle) * 10;
		vy = cos(PI / 180 * angle) * 10;
		state = M_LONG;//״̬���Ϊ�쳤
	}
	if (endx<0 || endx>WIN_WIDTH || endy > WIN_HEIGHT)
	{
		state = M_SHORT;//������Χ״̬���Ϊ����
	}
	if (state == M_LONG)//�쳤
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
		{//���ץס�ˣ��±�仯��״̬�仯
//			hook1.index = i;
//			hook1.state = M_SHORT;
//			break;
		}
	}
}

void back(hook& hook1)
{
	if (hook1.state == M_SHORT && hook1.index == -1)//���û��ץ��������ֱ�ӷ���
	{
		hook1.endx -= hook1.vx;
		hook1.endy -= hook1.vy;
		if (hook1.distance()) {
			hook1.state = M_NORMAL;//״̬����ΪNORMAL
		}
	}
	else if (hook1.state == M_SHORT)//���ץ���˶���
	{
		int vx = 0, vy = 0;
//		vx = mine[hook1.index].GetSpeed * sin(PI / 180 * hook1.angle);//X�������ٶȷ���
//		vy = mine[hook1.index].GetSpeed * cos(PI / 180 * hook1.angle);//y�������ٶȷ���
		hook1.endx -= vx;
		hook1.endy -= vy;
		if (hook1.distance())//״̬����
		{
			hook1.state = M_NORMAL;
			hook1.index = -1;
	//		mine[hook1.index].flag = false;
		}
	}
}
/*
int main() {
	initgraph(width, heigth);//���û���
	srand(GetTickCount());//�������
	Obj mine[max_obj];
	hook hook1;
	hook1();
	int i, j;
	for (j = 0; j < max_obj; j++) //��ѭ����6��ͼ�ε�λ�õ���Ϣ��ȷ������ͼ����ѭ������ÿ��ͼ���ж��ٸ�
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