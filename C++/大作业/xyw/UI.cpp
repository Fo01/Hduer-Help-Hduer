#define _CRT_SECURE_NO_DEPRECATE
#include <graphics.h>
#include <conio.h>
#include <iostream>
#include <thread>
#include <time.h>
#include <Windows.h>
#include "miner.h"
#include "计时器.h"
#include "钩子和黄金等.h"

int flag_TIME = 0;
IMAGE bg;
hook h;
int score = 0;

IMAGE tmp;
Miner zyx;

void ZYX()
{
	while(!flag_TIME) zyx.show();
}

void Countdown()
{
	int i = 60, t;
	TCHAR now1[2];
	TCHAR now2[5];

	t = time(NULL);
	while (i >= 0)
	{
		outtextxy(800, 5, _T("目标得分:3000"));
		outtextxy(10, 40, _T("得分："));
		outtextxy(10, 5, _T("剩余"));
		sprintf(now1, "%d", i);

		if (i < 10) outtextxy(75, 4, now1);
		else outtextxy(68, 4, now1);
		outtextxy(110, 5, _T("秒"));

		sprintf(now2, "%d", score);
		outtextxy(100, 40, now2);

		if (t != time(NULL)) i--;
		t = time(NULL);
	}
	flag_TIME = 1;
}

void go(hook hook1, Obj mine[], IMAGE type, int num)
{
	if (hook1.getstate() == M_NORMAL)//正常状态按空格或者方向下键
	{
		hook1.changevx(-cos(PI / 180 * hook1.getangle()) * hook1.getv());
		hook1.changevy( sin(PI / 180 * hook1.getangle()) * hook1.getv());
		hook1.changestate(M_LONG);//状态变更为伸长
	}
	while (hook1.getstate() == M_LONG && hook1.distance() <= MAX_LEN)//伸长
	{
		//putimage(450, 0, &zyx.gold_miner);
		hook1.changeendx(hook1.getendx() + hook1.getvx());
		hook1.changeendy(hook1.getendy() + hook1.getvy());
		int xx = hook1.getendx();
		int yy = hook1.getendy();
		if (xx < 0 || xx > WIN_WIDTH || yy > WIN_HEIGHT)           //伸长到底了，需要返回了
		{
			hook1.changestate(M_SHORT);//超出范围状态变更为缩短
			h = hook1;
			return;
		}

		putimage(hook1.getendx(), hook1.getendy(), &type);
		judge_to_catch(hook1, mine);
		Sleep(10);
		if (flag_TIME) break;

		putimage(0, 200, &bg);
		line(500, 200, hook1.getendx() + 40, hook1.getendy() + 43.5);
		if (flag_TIME) break;
		Sleep(20);
		for (int i = 0; i < num; i++) { if (mine[i].getflag()) mine[i].show(); }		//需要重新再输出一遍矿物

		if (hook1.getindex() != -1)   //抓到东西了返回
		{
			cout << hook1.getindex() << endl;
			h = hook1;
			return;
		}
	}
}

void back(hook& hook1, Obj mine[], IMAGE type)        //钩子从伸长状态返回
{
	if (hook1.getstate() == M_SHORT && hook1.getindex() == -1)//如果没有抓到东西就直接返回
	{
		cout << hook1.getindex() << "   11111" << endl;
		while (hook1.distance() >= hook1.getlen())
		{
			hook1.changeendx(hook1.getendx() - hook1.getvx());
			hook1.changeendy(hook1.getendy() - hook1.getvy());
			putimage(0, 200, &bg);
			line(500, 200, hook1.getendx() + 40, hook1.getendy() + 43.5);
			putimage(hook1.getendx(), hook1.getendy(), &type);
			for (int i = 0; i < MAX_MINE; i++) { if (mine[i].getflag()) mine[i].show(); }
		}
		hook1.changestate(M_NORMAL);//状态更新为NORMAL
	}
	else if (hook1.getstate() == M_SHORT)//如果抓到了东西
	{
		//cout << hook1.getindex() << "   22222" << endl;
		double vx = 0, vy = 0;
		int key = hook1.getindex();
		if (key == 4 || key == 5) zyx.getting(3);
		else if (key <= 2) zyx.getting(1);
		else zyx.getting(2);
		while (hook1.distance() >= hook1.getlen())
		{
			vx = -mine[hook1.getindex()].getspeed() * cos(PI / 180 * hook1.getangle());//X方向上速度分量
			vy =  mine[hook1.getindex()].getspeed() * sin(PI / 180 * hook1.getangle());//y方向上速度分量
			hook1.changeendx(hook1.getendx() - vx);
			hook1.changeendy(hook1.getendy() - vy);
			mine[hook1.getindex()].changex(mine[hook1.getindex()].getx() - vx);
			mine[hook1.getindex()].changey(mine[hook1.getindex()].gety() - vy);        //一同操作猛如虎的计算当前面积
			cout << hook1.getendx() << "   " << hook1.getendy() << endl;
            putimage(0, 200, &bg);                                                     //清屏
			line(500, 200, hook1.getendx() + 40, hook1.getendy() + 43.5);
			mine[hook1.getindex()].show();                                             //东西被拿上来
			putimage(hook1.getendx(), hook1.getendy(), &type);                         //钩子移动
			//putimage(450, 0, &zyx.gold_miner);
			for (int i = 0; i < MAX_MINE; i++) { if (mine[i].getflag()) mine[i].show(); }  //判重
			if (flag_TIME) break;
		}

		//算分模块
		score += mine[hook1.getindex()].getvalue();
		
		hook1.changestate(M_NORMAL);
		hook1.changeindex(-1);
		putimage(0, 200, &bg);
	}
}

int judge_to_move()
{
	if (GetAsyncKeyState(VK_SPACE) || GetAsyncKeyState(VK_DOWN)) return 1;
	else return 0;
}

void background()
{
	IMAGE gamebackground;
	while (flag_TIME == 0)
	{
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb1.jpg", 1000, 200); putimage(0, 0, &gamebackground); Sleep(100);
		if (flag_TIME) break;
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb2.jpg", 1000, 200); putimage(0, 0, &gamebackground); Sleep(100);
		if (flag_TIME) break;
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb3.jpg", 1000, 200); putimage(0, 0, &gamebackground); Sleep(100);
		if (flag_TIME) break;
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb4.jpg", 1000, 200); putimage(0, 0, &gamebackground); Sleep(100);
		if (flag_TIME) break;
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb5.jpg", 1000, 200); putimage(0, 0, &gamebackground); Sleep(100);
		if (flag_TIME) break;
		loadimage(&gamebackground, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb6.jpg", 1000, 200); putimage(0, 0, &gamebackground);//Sleep(5000);
		if (flag_TIME) break;
	}
}

int main()
{
	//第一个界面菜单的背景和两按钮------------------------------------------------------------------
	// 第一个界面开始
	loadimage(&tmp, "C:\\Users\\Fool\\Desktop\\xyw\\矿工\\happy.jpg", 100, 200);
	zyx.init(tmp);
	loadimage(&bg, "C:\\Users\\Fool\\Desktop\\xyw\\背景\\gb.jpg", 1000, 500);
	initgraph(1000, 700);
	setbkcolor(soil);     //设置背景色为土壤颜色，防止钩子旋转时出现黑色裂缝
	IMAGE beginning;//开始背景
	loadimage(&beginning, "C:\\Users\\Fool\\Desktop\\xyw\\beginning.jpg", 1000, 500);
	putimage(0, 0, &beginning);
	IMAGE start;//开始按钮
	loadimage(&start, "C:\\Users\\Fool\\Desktop\\xyw\\start.jpg", 250, 100);
	putimage(150, 550, &start);
	IMAGE quit;//退出按钮
	loadimage(&quit, "C:\\Users\\Fool\\Desktop\\xyw\\quit.jpg", 250, 100);
	putimage(600, 550, &quit);

	int flag = 0;
	MOUSEMSG m;		// 鼠标操作
	while (1)
	{
		m = GetMouseMsg();
		switch (m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if (m.x >= 150 && m.x <= 400 && m.y >= 550 && m.y <= 650)
			{
				flag = 1;
				settextstyle(32, 0, _T("Consolas"));
				outtextxy(250, 660, _T("let's go!!!Left-click to go next."));
			}
			if (m.x >= 600 && m.x <= 850 && m.y >= 550 && m.y <= 650)
			{
				closegraph();
				return 0;
			}
			break;
		case WM_RBUTTONDOWN:
			RECT r = { 0,0,1000,700 };
			cleardevice();
			settextstyle(150, 0, _T("Consolas"));
			drawtext(_T("Goodbye!"), &r, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			while (1)
			{
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN)break;
			}
			closegraph();
			return 0;
		}
		if (flag == 1) break;
	}


	//第二个界面规则-------------------------------------------------------------------------------------
	//cleardevice();
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)break;
	}
	IMAGE rules;
	loadimage(&rules, "C:\\Users\\Fool\\Desktop\\xyw\\rules.jpg", 1000, 700);
	putimage(0, 0, &rules);
	settextcolor(HSLtoRGB(900, 900, 1600));
	setbkmode(TRANSPARENT);
	settextstyle(32, 0, _T("Consolas"));
	outtextxy(320, 620, _T("Left-click to go next."));

	//第三个界面分数------------------------------------------------------------------------------------
	//cleardevice();
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) break;
	}
	IMAGE rules2;
	loadimage(&rules2, "C:\\Users\\Fool\\Desktop\\xyw\\rules2.jpg", 1000, 700);
	putimage(0, 0, &rules2);


	//第四个界面游戏-----------------------------------------------------------------------------------
	int duration = 0;
	IMAGE gamebackground;

	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN) break;
	}
	cleardevice();

	flag = 0;
	Obj mine[MAX_MINE];
	hook hook1;

	thread task1(Countdown);
	thread task2(background);
	thread task3(ZYX);
	task1.detach();  //子线程加入，为计时器和主界面同时进行
	task2.detach();  //子线程加入，为背景图片的一直切换
	task3.detach();  //子线程加入，为打工人干活

	srand(GetTickCount());//随机种子
	for (int j = 0; j < max_obj; j++) //内循环把6种图形的位置等信息都确定，贴图；外循环决定每种图形有多少个
		for (int i = 0; i < 6; i++)
			mine[j * 6 + i].pos(i);       //让幕布上出现物品，且仅出现一次就行

	IMAGE image_rotate, image_stay;

	loadimage(&image_stay, _T("C:\\Users\\Fool\\Desktop\\xyw\\钩子.jpg"));
	while (1)
	{
		putimage(450, 0, &zyx.gold_miner);
		hook1.rock();   //一起摇摆
		rotateimage(&image_rotate, &image_stay, PI / 180 * hook1.getangle(), soil);
		putimage(hook1.getendx(), hook1.getendy(), &image_rotate);
		line(500, 200, hook1.getendx() + 40, hook1.getendy() + 43.5);
		if (flag_TIME) break;
		if (judge_to_move())      //如果有输入什么东西，就开始伸缩
		{
			if (flag_TIME) break;
			go(hook1, mine, image_rotate, MAX_MINE);      //退出之后总是莫名其妙初始化
			hook1 = h;
			if (flag_TIME) break;
			back(hook1, mine, image_rotate);
			if (flag_TIME) break;
			for (int i = 0; i < MAX_MINE; i++) { if (mine[i].getflag()) mine[i].show(); }
			if (flag_TIME) break;
		}
	}
	setbkmode(TRANSPARENT);
	settextstyle(64, 0, _T("Jim"));
	if (score>=3000) outtextxy(250, 350, _T("YOU WIN!!!"));
	else outtextxy(250, 350, _T("YOU LOSE..."));



	//第五个界面结算分数------------------------------------------------------------------------------------
	//cleardevice();
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)break;
	}
	IMAGE summary;
	loadimage(&summary, "C:\\Users\\Fool\\Desktop\\xyw\\content.jpg", 1000, 700);
	putimage(0, 0, &summary);
	IMAGE scores;
	loadimage(&scores, "C:\\Users\\Fool\\Desktop\\xyw\\scores.jpg", 300, 100);
	putimage(200, 350, &scores);
	setbkmode(TRANSPARENT);
	settextcolor(HSLtoRGB(200, 600, 600));
	settextstyle(64, 0, _T("consolas"));
	outtextxy(100, 500, _T("Right-click to end the game!"));

	TCHAR now[5];
	sprintf(now, "%d", score);
	outtextxy(600,370, now);
	//右键结束


	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_RBUTTONDOWN)break;
	}
	closegraph();

}