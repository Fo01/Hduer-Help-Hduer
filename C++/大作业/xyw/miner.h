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
		IMAGE gold_miner(target);   //�������캯��
	}
	Miner()
	{}
	void getting(int state)
	{
		switch (state)
		{
		case GoldGetted:                                                                                  //�õ����ӵ�״̬��ͨ���궨��Ϊ1
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\��\\rotation.jpg", 100, 200);        //�л��󹤱���Ϊ��������ת
			break;
		case DiamondGetted:                                                                               //�õ���ʯ��״̬��ͨ���궨��Ϊ2
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\��\\happy.jpg", 100, 200);           //�л��󹤱���Ϊ����
			break;
		case StoneGetted:                                                                                 //�õ�ʯͷ��״̬��ͨ���궨��Ϊ3
			loadimage(&gold_miner, "C:\\Users\\Fool\\Desktop\\xyw\\��\\sad.jpg", 100, 200);             //�л��󹤱���Ϊ��
			break;
		default:
			break;
		}
	}
	void show(){ putimage(450, 0, &gold_miner); }
};
#endif // !MINER_H