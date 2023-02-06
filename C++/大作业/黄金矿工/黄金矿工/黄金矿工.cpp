#include<stdio.h>
#include<math.h>
#include<graphics.h>//easyx 包含头文件，可以使用提供的接口，函数
#define WIN_WIDTH 1080
#define WIN_HEIGHT 640
#define MAX_IMAGE 11  //最大图片数量
#define MAX_MINE 10   //最大物品数量
#define MAX_ANGLE 80 //最大角度
#define PI 3.1415926535898
//int a,char b
enum MINE //枚举图片数组下标
{
	i_gold = 1,
	i_money = 3,
	i_soledown = 5,
	i_soleup = 7,
	i_stone = 9,
	i_bk = MAX_IMAGE - 1,
};
enum MINE_TYPE //物品类型枚举
{
	GOLD,
	MONEY,
	STONE,
	//方向
	LEFT,
	RIGHT,
	//状态，正常，伸长，缩短
	M_NOMAL,
	M_LONG,
	M_SHORT,
};
struct Sole //角色信息
{
	int x;//贴图位置
	int y;
	int width;//图片宽高
	int height;
	int coin;//金币
}sole;
struct Mine //物品
{
	int x;
	int y;
	int szie; //边界判断
	bool flag;//是否存在
	int type;//物品类型，石头，金块，钱袋
	int gold;//物品价值
}mine[MAX_MINE];
struct Hook //钩子
{
	int x;
	int y;
	int endx;
	int endy;
	int len;//长度
	int angle;//角度
	int dir;//摆动方向
	int vx;//速度分量
	int vy;
	int state;
	int index;//记录抓到的物品下标
}hook;
IMAGE img[MAX_IMAGE];
int distance(Hook hook);
//初始化数据
void GameInit()
{
	//创建窗口 init 初始化  graphics图形界面
	initgraph(WIN_WIDTH, WIN_HEIGHT, SHOWCONSOLE);
	//设置随机数种子
	srand(GetTickCount());
	//加载图片
	for (int i = 0; i < MAX_IMAGE - 1; i++)
	{
		char temp[25] = "";
		sprintf(temp, "./images/%d.jpg", i);
		if (i <= 1)
		{
			loadimage(&img[i], temp, 73, 62);//注意：字符集问题
		}
		else
		{
			loadimage(&img[i], temp);//注意：字符集问题
		}

	}
	loadimage(&img[i_bk], "./images/bk.jpg", WIN_WIDTH, WIN_HEIGHT - 120);
	//初始化角色信息
	sole.width = 140;
	sole.height = 120;
	sole.x = WIN_WIDTH / 2 - sole.width / 2;//x轴居中
	sole.y = 0;
	sole.coin = 0;

	//初始化物品信息
	for (int i = 0; i < MAX_MINE; i++)
	{
		mine[i].flag = true;
		mine[i].gold = rand() % 200 + 1;
		mine[i].szie = 60;
		mine[i].type = rand() % 3;
		mine[i].x = rand() % (WIN_WIDTH - 60);
		mine[i].y = rand() % (WIN_HEIGHT - 150) + 150;
	}
	//初始化钩子
	hook.x = sole.x + 40;
	hook.y = sole.y + 100;
	hook.len = 50;
	hook.endx = hook.x;
	hook.endy = hook.y + hook.len;
	hook.angle = 0;
	hook.dir = RIGHT;
	hook.vx = 0;
	hook.vy = 0;
	hook.state = M_NOMAL;
	hook.index = -1;
}
//游戏绘制
void GameDraw()
{
	//绘制背景
	putimage(0, 120, &img[i_bk]);
	//绘制角色背景颜色
	setfillcolor(RGB(255, 208, 52));
	solidrectangle(0, 0, WIN_WIDTH, 120);
	//绘制角色
	putimage(sole.x, sole.y, &img[i_soledown - 1], SRCAND);//知道为啥减1不？
	putimage(sole.x, sole.y, &img[i_soledown], SRCPAINT);
	//绘制物品
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true)
		{
			switch (mine[i].type)
			{
			case GOLD:
				putimage(mine[i].x, mine[i].y, &img[i_gold - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_gold], SRCPAINT);
				break;
			case MONEY:
				putimage(mine[i].x, mine[i].y, &img[i_money - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_money], SRCPAINT);
				break;
			case STONE:
				putimage(mine[i].x, mine[i].y, &img[i_stone - 1], SRCAND);
				putimage(mine[i].x, mine[i].y, &img[i_stone], SRCPAINT);
				break;
			}
		}
	}
	//绘制钩子
	setlinecolor(BROWN);
	setlinestyle(PS_SOLID, 5);
	line(hook.x, hook.y, hook.endx, hook.endy);

	//绘制分数
	char score[30] = "";
	sprintf(score, "分数：%d", sole.coin);
	settextcolor(WHITE);
	setbkmode(TRANSPARENT);
	settextstyle(50, 0, "楷体");
	outtextxy(20, 20, score);
}
//钩子摆动
void HookRock()
{
	if (hook.state == M_NOMAL)
	{
		if (hook.dir == RIGHT)
		{
			hook.angle++;
		}
		else
		{
			hook.angle--;
		}
		if (hook.angle > MAX_ANGLE)
		{
			hook.dir = LEFT;
		}
		else if (hook.angle < -MAX_ANGLE)
		{
			hook.dir = RIGHT;
		}
		//角度转弧度  360 2pai  180  PI  
		hook.endx = hook.x + sin(PI / 180 * hook.angle) * hook.len;
		hook.endy = hook.y + cos(PI / 180 * hook.angle) * hook.len;
	}

}

//游戏控制
void GameControl(int speed)
{
	if (GetAsyncKeyState(VK_SPACE) && hook.state == M_NOMAL)
	{
		//按键，求出速度分量
		hook.vx = sin(PI / 180 * hook.angle) * speed;
		hook.vy = cos(PI / 180 * hook.angle) * speed;
		hook.state = M_LONG;
	}
	//碰到边界返回
	if (hook.endx<0 || hook.endx>WIN_WIDTH || hook.endy > WIN_HEIGHT)
	{
		hook.state = M_SHORT;
	}
	if (hook.state == M_LONG)
	{
		hook.endx += hook.vx;
		hook.endy += hook.vy;
	}
	else if (hook.state == M_SHORT)
	{
		hook.endx -= hook.vx;
		hook.endy -= hook.vy;
		//缩短完成
		if (distance(hook))
		{
			hook.state = M_NOMAL;
		}
	}
	//接下来就是让hook.endx 加上hook.vx
	printf("%d %d\n", hook.vx, hook.vy);
}
void JudgeGrap()
{
	//判断抓到那个物品
	for (int i = 0; i < MAX_MINE; i++)
	{
		if (mine[i].flag == true &&
			hook.endx > mine[i].x && hook.endx<mine[i].x + mine[i].szie &&
			hook.endy>mine[i].y && hook.endy < mine[i].y + mine[i].szie)
		{
			hook.index = i;
			break;
		}
	}
	//如果抓到了
	if (hook.index != -1)
	{
		hook.state = M_SHORT;
		mine[hook.index].x = hook.endx;
		mine[hook.index].y = hook.endy;
		//缩短完成
		if (distance(hook))
		{
			mine[hook.index].flag = false;
			hook.index = -1;
			hook.state = M_NOMAL;
		}
	}
}
//void main 
int main()
{
	GameInit();
	DWORD t1, t2;
	t1 = t2 = GetTickCount();
	BeginBatchDraw();
	while (1)
	{
		if (t2 - t1 > 15)
		{
			HookRock();
			t1 = t2;
		}
		t2 = GetTickCount();
		GameDraw();
		FlushBatchDraw();
		GameControl(10);
		JudgeGrap();
		//防止闪退
	}
	return 0;
}
int distance(Hook hook)
{
	int dis = sqrt((float)(hook.x - hook.endx) * (hook.x - hook.endx) + (hook.y - hook.endy) * (hook.y - hook.endy));
	return dis <= hook.len;
}
