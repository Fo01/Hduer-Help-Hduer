#ifndef MINER_H
#define MINER_H
#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define GoldGetted 1
#define DiamondGetted 2
#define StoneGetted 3
using namespace std;

class Miner
{
public:
	IMAGE gold_miner;
	void init(IMAGE& target)
	{
		IMAGE gold_miner(target);   //拷贝构造函数
	}
	Miner()
	{}
	void getting(int state)
	{
		switch (state)
		{
		case GoldGetted:                                                                                  //拿到金子的状态，通过宏定义为1
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\矿工\\rotation.jpg", 100, 200);        //切换矿工表情为正在用力转
			break;
		case DiamondGetted:                                                                               //拿到钻石的状态，通过宏定义为2
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\矿工\\happy.jpg", 100, 200);           //切换矿工表情为开心
			break;
		case StoneGetted:                                                                                 //拿到石头的状态，通过宏定义为3
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\矿工\\sad.jpg", 100, 200);             //切换矿工表情为哭
			break;
		default:
			break;
		}
	}
	void show(){ putimage(450, 0, &gold_miner); }
};
#endif // !MINER_H