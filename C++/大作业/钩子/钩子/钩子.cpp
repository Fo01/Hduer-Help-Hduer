#include <graphics.h>
#include <conio.h>
#include <math.h>
#include <iostream>

#define PI 3.14159265359
using namespace std;

class HOOK
{
    private:
		double x, y;
		int  vx, vy, endx, endy, index, angle, flag;
		IMAGE image_stay, image_rotate;
    public:
		HOOK(int xx, int yy)
		{
			x = xx;
			y = yy;
			vx = 20;
			vy = 20;
			flag = 0;
			angle = 20;
			loadimage(&image_stay, _T("C:\\Users\\Fool\\Desktop\\钩子.jpg"));
		}
		void rotate()
		{
			flag = 0;
			while (1)
			{
				for (angle = 20; angle < 160; angle++)
				{
					rotateimage(&image_rotate, &image_stay, PI / 180 * angle);
					putimage(x, y, &image_rotate);
					Sleep(5);
					judge_to_move();
					if (flag) break;
				}
				if (flag) break;
				for (angle = 160; angle > 20; angle--)
				{
					rotateimage(&image_rotate, &image_stay, PI / 180 * angle);
					putimage(x, y, &image_rotate);
					Sleep(5);
					judge_to_move();
					if (flag) break;
				}
				if (flag) break;
			}
			move();
		}
		void judge_to_move()
		{
			char key;
			if (_kbhit())
			{
				key = _getch();
				if (key == 's' || key == 'S') flag = 1;
			}
		}
		void move()
		{
			for (int i = 0; i < 100; i++)
			{
				x = -cos(angle * PI / 180) * vx + x;
			    y = sin(angle * PI / 180) * vy + y;
				putimage((int)(x), (int)(y), &image_rotate);
				Sleep(30);
				cleardevice();
			}
			for (int i = 99; i >= 0; i--)
			{
				x = cos(angle * PI / 180) * vx + x;
				y = -sin(angle * PI / 180) * vy + y;
				putimage((int)(x), (int)(y), &image_rotate);
				Sleep(30);
				cleardevice();
			}
			rotate();
		}
};



int main()
{
	initgraph(1000, 1000);
	HOOK hook(450,50);
	// 绘图窗口初始化
	
	hook.rotate();
}