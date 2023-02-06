#include <stdio.h>   
#include <graphics.h>   //easyx图形库
#include<string.h>
#include<stdlib.h>    //字符串处理函数

int Yema, yema;   //全局变量 页码总数和当前页码数
struct student* Head, * Tail, * Now;

//鼠标颜色更换信息函数
void Menucolorclean();    //菜单鼠标移动选择框颜色改变功能
void Searchcolorclean();   //搜索鼠标移动选择框颜色改变功能                          
void Exitcolorclean();    //退出或者返回菜单界面选择框颜色改变功能 中央版本
void Fanyelinecolorclean();   //带页码的翻页界面下划线颜色改变功能   浏览用
void Exitcolorbottomclean();    //退出或者返回菜单界面下划线颜色改变功能 底部版本 查找用   
void Changecolorclean();          //修改总界面的颜色改变    
void Change_changecolorclean();     //修改里边8个选项的界面颜色改变

//单次功能函数
void Menu();   //菜单界面
void Welcome();    //欢迎界面
void view();  //浏览功能
void write();   //写入功能
void search();   //搜索功能
void change();  //修改功能
void Search_chazhaoname();        //search功能下的姓名查找                                           
void Search_chazhaonumber();        //search功能下的学号查找
void Search_paixuname();        //search功能下的姓名排序
void Search_paixunumber();        //search功能下的学号排序
void Change_change();                   //change功能下的修改功能                               
void Change_delete();                   //change功能下的删除功能
void Change_change_studentnumber();           //修改下的8个函数功能
void Change_change_name();
void Change_change_age();
void Change_change_sex();
void Change_change_date();
void Change_change_address();
void Change_change_email();
void Change_change_tel();

//多次功能函数
void turn();   //跳转界面
void Continuetobe();  //鼠标点击继续功能
void Exitandmenumid();   //点击退出或者返回菜单功能 中央版本
void Exitandmenubottom();   //点击退出或者返回菜单  底部版本                    
void Fanyelast();  //点击上一页下一页翻页                                         
void Fanyenext();
void Viewmousemessage();    //浏览界面的鼠标信息检测 还有绘图 打印
void Changemousemessage();   //修改界面的鼠标信息检测 绘图 打印  导入修改/删除函数                                      !!!
void FanyeBiglast();              //浏览界面+修改删除的大翻页 用于修改函数
void FanyeBignext();

//链表函数
struct student* create(); //创立链表并把文件读入链表，返回头指针 只读
void writeinto();    //把更新好的链表写入文件 只写

struct student  //结构体链表
{
	char studentnumber[10];
	char name[10];
	char age[3];
	char sex[3];
	char birthyearmonthday[15];
	char address[100];
	char tel[12];
	char email[30];
	struct student* next;
};

void writeinto()      //将链表写入文件
{
	FILE* f;   //打开文件
	f = fopen("Information.txt", "w");

	for (Now = Head;Now!=NULL;Now=Now->next)
	{
		fprintf(f, "%s ", Now->studentnumber);
		fprintf(f, "%s ", Now->name);
		fprintf(f, "%s ", Now->age);
		fprintf(f, "%s ", Now->sex);
		fprintf(f, "%s ", Now->birthyearmonthday);
		fprintf(f, "%s ", Now->address);
		fprintf(f, "%s ", Now->tel);
		fprintf(f, "%s ", Now->email);
		if (Now->next == NULL) break;
		fputc('\n', f);          //换行操作
	}
	fclose(f);
}

void Change_delete()  //删除功能
{
	if (yema == 1) {
		Now = Head->next;
		free(Head);
		Head = Now;

		writeinto();     //写入文件

		outtextxy(286, 100, _T("删除成功！"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {                                                                                  //这里有错！不知道怎么改
		int i = 1;
		struct student* last, *cur;

		last = Head;   //将上一个标记为头节点开始寻找

		for (i = 1; i < yema - 1; i++)
			last = last->next;     //寻找当前节点的上一个节点 

		cur = last->next;
		last->next = cur->next;
		free(cur);

		writeinto();     //写入文件

		outtextxy(286, 100, _T("删除成功！"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Search_paixuname()
{
	int i = 0, j = 0;
	struct student *cur;
	char temp1[10], temp2[10], temp3[3], temp4[3], temp5[15], temp6[100], temp7[12], temp8[30];
	Head = create();
	Now = Head;

	for (i = 0; i < Yema; i++) {
		cur = Head;
		for (j = 0; j < Yema - i; j++) {
			if (strcmp(Now->name, cur->name) > 0) 
				cur = Now;    //当前最大值所在位置指针
			if (j!=Yema-i-1)
				Now = Now->next;
		}
		strcpy(temp1, cur->studentnumber);        //交换
		strcpy(temp2, cur->name);
		strcpy(temp3, cur->age);
		strcpy(temp4, cur->sex);
		strcpy(temp5, cur->birthyearmonthday);
		strcpy(temp6, cur->address);
		strcpy(temp7, cur->tel);
		strcpy(temp8, cur->email);
		strcpy(cur->studentnumber, Now->studentnumber);
		strcpy(cur->name, Now->name);
		strcpy(cur->age, Now->age);
		strcpy(cur->sex, Now->sex);
		strcpy(cur->birthyearmonthday, Now->birthyearmonthday);
		strcpy(cur->address, Now->address);
		strcpy(cur->tel, Now->tel);
		strcpy(cur->email, Now->email);
		strcpy(Now->studentnumber, temp1);
		strcpy(Now->name, temp2);
		strcpy(Now->age, temp3);
		strcpy(Now->sex, temp4);
		strcpy(Now->birthyearmonthday, temp5);
		strcpy(Now->address, temp6);
		strcpy(Now->tel, temp7);
		strcpy(Now->email, temp8);
		Now = Head;
	}

	Yema = 0;   //清空全局变量
	yema = 0;

	writeinto();   //写入文件
	view();      //浏览的界面打开
}

void Search_paixunumber()
{
	int i = 0, j = 0;
	struct student *cur;
	char temp1[10], temp2[10], temp3[3], temp4[3], temp5[15], temp6[100], temp7[12], temp8[30];
	Head = create();
	Now = Head;

	for (i = 0; i < Yema; i++) {
		cur = Head;
		for (j = 0; j < Yema - i; j++) {
			if (strcmp(Now->studentnumber, cur->studentnumber) > 0) 
				cur = Now;    //当前最大值所在位置指针
			if (j!=Yema-i-1)
				Now = Now->next;
		}
		strcpy(temp1, cur->studentnumber);        //交换
		strcpy(temp2, cur->name);
		strcpy(temp3, cur->age);
		strcpy(temp4, cur->sex);
		strcpy(temp5, cur->birthyearmonthday);
		strcpy(temp6, cur->address);
		strcpy(temp7, cur->tel);
		strcpy(temp8, cur->email);
		strcpy(cur->studentnumber, Now->studentnumber);
		strcpy(cur->name, Now->name);
		strcpy(cur->age, Now->age);
		strcpy(cur->sex, Now->sex);
		strcpy(cur->birthyearmonthday, Now->birthyearmonthday);
		strcpy(cur->address, Now->address);
		strcpy(cur->tel, Now->tel);
		strcpy(cur->email, Now->email);
		strcpy(Now->studentnumber, temp1);
		strcpy(Now->name, temp2);
		strcpy(Now->age, temp3);
		strcpy(Now->sex, temp4);
		strcpy(Now->birthyearmonthday, temp5);
		strcpy(Now->address, temp6);
		strcpy(Now->tel, temp7);
		strcpy(Now->email, temp8);
		Now = Head;
	}

	Yema = 0;   //清空全局变量
	yema = 0;

	writeinto();   //写入文件
	view();      //浏览的界面打开
}

void Change_change_tel()
{
	char s[12];
	InputBox(s, 12,"请输入修改的学生电话");//信息输入

	strcpy(Now->tel, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_sex()
{
	char s[3];
	InputBox(s, 3,"请输入修改的学生性别");//信息输入

	strcpy(Now->sex, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_email()
{
	char s[30];
	InputBox(s, 30, "请输入修改的学生邮箱");//信息输入

	strcpy(Now->email, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_age()
{
	char s[3];
	InputBox(s, 3, "请输入修改的学生年龄");//信息输入

	strcpy(Now->age, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_address()
{
	char s[100];
	InputBox(s, 100, "请输入修改的学生地址");//信息输入

	strcpy(Now->address, s);    //修改
	writeinto();   //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_name()
{
	char s[10];
	InputBox(s, 10, "请输入修改的学生姓名");//信息输入

	strcpy(Now->name, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_date()
{
	char s[15];
	InputBox(s, 15, "请输入修改的学生生日");//信息输入

	strcpy(Now->birthyearmonthday, s);    //修改
	writeinto();     //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Change_change_studentnumber()
{
	char s[10];
	InputBox(s, 10, "请输入修改的学生学号");//信息输入

	strcpy(Now->studentnumber, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));       
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Changemousemessage()               //哎 修改功能鼠标感应
{
	char Temp[7];     //页码转化为字符输出备用中间 Yema
	char temp[7];

	sprintf(Temp, "%d", Yema);
	sprintf(temp, "%d", yema);      //将页码数字信息转化为字符信息方便后续输出
	outtextxy(30, 30, _T("序号："));
	outtextxy(100, 30, temp);
	outtextxy(30, 70, _T("学号："));
	outtextxy(100, 70, Now->studentnumber);
	outtextxy(30, 110, _T("姓名："));
	outtextxy(100, 110, Now->name);
	outtextxy(30, 150, _T("年龄："));
	outtextxy(100, 150, Now->age);
	outtextxy(30, 190, _T("性别："));
	outtextxy(100, 190, Now->sex);
	outtextxy(30, 230, _T("生日："));
	outtextxy(100, 230, Now->birthyearmonthday);
	outtextxy(30, 270, _T("地址："));
	outtextxy(100, 270, Now->address);
	outtextxy(30, 310, _T("电话："));
	outtextxy(100, 310, Now->tel);
	outtextxy(30, 350, _T("邮箱："));
	outtextxy(100, 350, Now->email);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, temp);
	outtextxy(332, 400, Temp);
	outtextxy(256, 427, _T("上一页 / 下一页"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(156, 427, _T("修改信息"));
	outtextxy(400, 427, _T("删除信息"));
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);  //画出基础界面图以及打印当前指针

	/*rectangle(156, 425, 219, 445);
	rectangle(399, 425, 462, 445);*/           //  这个定位框依旧舍不得删

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445) {   //如果鼠标位置在框内
			Changecolorclean(); //将所有边框恢复至白色并设置新的边框为红色
			line(256, 445, 303, 445);//画新的边框
			if (m1.uMsg == WM_LBUTTONDOWN) break; //检测到按下左键结束循环      上一页
		}
		else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445) {
			Changecolorclean();
			line(315, 445, 360, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Changecolorclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Changecolorclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 156 && m1.x <= 219 && m1.y >= 425 && m1.y <= 445) {
			Changecolorclean();
			line(156, 445, 219, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 399 && m1.x <= 462 && m1.y >= 425 && m1.y <= 445) {
			Changecolorclean();
			line(399, 445, 462, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Fanyelinecolorclean();
	}
	turn();//跳转界面 

	if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445)   //检测鼠标点击位置
		FanyeBiglast();
	else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445)
		FanyeBignext();
	else if (m1.x >= 156 && m1.x <= 219 && m1.y >= 425 && m1.y <= 445)
		Change_change();
	else if (m1.x >= 399 && m1.x <= 462 && m1.y >= 425 && m1.y <= 445)
		Change_delete();
	else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
		yema = 0;
		Yema = 0;
		Menu();
	}
}

void Change_change()       //修改里边的8个选项内容  （8个函数？？？我天                              先做连接吧
{
	rectangle(140, 150, 300, 180); rectangle(340, 150, 500, 180);
	outtextxy(186, 157, _T("修改学号")); outtextxy(386, 157, _T("修改生日"));
	rectangle(140, 200, 300, 230); rectangle(340, 200, 500, 230);
	outtextxy(186, 207, _T("修改姓名")); outtextxy(386, 207, _T("修改地址"));
	rectangle(140, 250, 300, 280); rectangle(340, 250, 500, 280);
	outtextxy(186, 257, _T("修改年龄")); outtextxy(386, 257, _T("修改邮箱"));
	rectangle(140, 300, 300, 330); rectangle(340, 300, 500, 330);
	outtextxy(186, 307, _T("修改性别")); outtextxy(386, 307, _T("修改电话"));
	outtextxy(256, 427, _T("点击任意选项继续"));

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 140 && m1.x <= 300 && m1.y >= 150 && m1.y <= 180) {   //如果鼠标位置在框内
			Change_changecolorclean();  //将所有边框恢复至白色并设置新的边框为红色
			rectangle(140, 150, 300, 180);//画新的边框
			if (m1.uMsg == WM_LBUTTONDOWN) break; //检测到按下左键结束循环
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 150 && m1.y <= 180) {
			Change_changecolorclean();
			rectangle(340, 150, 500, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 200 && m1.y <= 230) {
			Change_changecolorclean();
			rectangle(140, 200, 300, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 200 && m1.y <= 230) {
			Change_changecolorclean();
			rectangle(340, 200, 500, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 250 && m1.y <= 280) {
			Change_changecolorclean();
			rectangle(140, 250, 300, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >=250 && m1.y <=280) {
			Change_changecolorclean();
			rectangle(340, 250, 500, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 300 && m1.y <= 330) {
			Change_changecolorclean();
			rectangle(140, 300, 300, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 340 && m1.x <=500 && m1.y >= 300 && m1.y <= 330) {
			Change_changecolorclean();
			rectangle(340, 300, 500, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Change_changecolorclean();
	}
	turn();

	if (m1.x >= 140 && m1.x <= 300 && m1.y >= 150 && m1.y <= 180)   //如果鼠标位置在框内
		Change_change_studentnumber();
	else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 150 && m1.y <= 180)
		Change_change_date();
	else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 200 && m1.y <= 230)
		Change_change_name();
	else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 200 && m1.y <= 230)
		Change_change_address();
	else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 250 && m1.y <= 280)
		Change_change_age();
	else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 250 && m1.y <= 280)
		Change_change_email();
	else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 300 && m1.y <= 330)
		Change_change_sex();
	else Change_change_tel();
}

void FanyeBiglast()
{
	if (yema == 1) {    //页码为1时翻上一页
		yema = Yema;    //跳到页码最大处
		Now = Tail;    //修改当前指针
		turn();   //清空界面

		Changemousemessage();  //一个功能众多的函数
	}
	else {
		yema -= 1;
		turn();   //清空界面

		Now = Head;        //不想写双向重来 只得狗一下计算机了TAT
		int i;
		for (i = 1; i < yema; i++)
			Now = Now->next;     //我聪明起来都佩服我自己系列

		Changemousemessage();
	}
}

void FanyeBignext()
{
	if (yema == Yema) {    //页码为末页时翻下一页
		yema = 1;    //跳到页码最小处
		Now = Head;    //修改当前指针
		turn();   //清空界面

		Changemousemessage();  //一个功能众多的函数
	}
	else {
		Now = Now->next;
		yema += 1;
		turn();   //清空界面
		Changemousemessage();
	}
}

void Search_chazhaonumber()    //学生学号查找功能
{
	int flag = 0;

	struct student* head; //建立头指针
	head = create();    //建立链表 获得头指针 

	char s[10];
	InputBox(s, 10, "请按输入查找的学生学号");//信息输入

	for (Now = head; Now != NULL; Now = Now->next) {
		if (strcmp(Now->studentnumber, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("学号："));
			outtextxy(100, 70, Now->studentnumber);
			outtextxy(30, 110, _T("姓名："));
			outtextxy(100, 110, Now->name);
			outtextxy(30, 150, _T("年龄："));
			outtextxy(100, 150, Now->age);
			outtextxy(30, 190, _T("性别："));
			outtextxy(100, 190, Now->sex);
			outtextxy(30, 230, _T("生日："));
			outtextxy(100, 230, Now->birthyearmonthday);
			outtextxy(30, 270, _T("地址："));
			outtextxy(100, 270, Now->address);
			outtextxy(30, 310, _T("电话："));
			outtextxy(100, 310, Now->tel);
			outtextxy(30, 350, _T("邮箱："));
			outtextxy(100, 350, Now->email);   //画图并且输入信息
			Exitandmenubottom();
		}
		if (Now->next == NULL) break;
	}
	if (flag == 0) {
		turn();   //找不到就清空页面
		outtextxy(286, 100, _T("查无此人"));       //哈哈哈哈这是要笑死我
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Search_chazhaoname()               //学生姓名查找功能
{
	int flag = 0;           //一个后续判断退出的标志

	struct student* head; //建立头指针
	head = create();    //建立链表 获得头指针                              

	char s[10];
	InputBox(s, 10, "请按输入查找的学生姓名");//信息输入

	for (Now = head; Now != NULL; Now = Now->next) {
		if (strcmp(Now->name, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("学号："));
			outtextxy(100, 70, Now->studentnumber);
			outtextxy(30, 110, _T("姓名："));
			outtextxy(100, 110, Now->name);
			outtextxy(30, 150, _T("年龄："));
			outtextxy(100, 150, Now->age);
			outtextxy(30, 190, _T("性别："));
			outtextxy(100, 190, Now->sex);
			outtextxy(30, 230, _T("生日："));
			outtextxy(100, 230, Now->birthyearmonthday);
			outtextxy(30, 270, _T("地址："));
			outtextxy(100, 270, Now->address);
			outtextxy(30, 310, _T("电话："));
			outtextxy(100, 310, Now->tel);
			outtextxy(30, 350, _T("邮箱："));
			outtextxy(100, 350, Now->email);   //画图并且输入信息
			Exitandmenubottom();
		}
		if (Now->next == NULL) break;
	}
	if (flag==0) {
		turn();   //找不到就清空页面
		outtextxy(286, 100, _T("查无此人"));       //哈哈哈哈这是要笑死我
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Exitandmenubottom()                //查找只有底部返回菜单功能
{
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);    //画图

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Exitcolorbottomclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Exitcolorbottomclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Exitcolorbottomclean();
	}
	turn();//跳转界面 

	if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
		yema = 0;
		Yema = 0;
		Menu();
	}
}

void Viewmousemessage()                        //超级大函数
{
	char Temp[7];     //页码转化为字符输出备用中间 Yema
	char temp[7];

	sprintf(Temp, "%d", Yema);
	sprintf(temp, "%d", yema);      //将页码数字信息转化为字符信息方便后续输出
	outtextxy(30, 30, _T("序号："));
	outtextxy(100, 30, temp);
	outtextxy(30, 70, _T("学号："));
	outtextxy(100, 70, Now->studentnumber);
	outtextxy(30, 110, _T("姓名："));
	outtextxy(100, 110, Now->name);
	outtextxy(30, 150, _T("年龄："));
	outtextxy(100, 150, Now->age);
	outtextxy(30, 190, _T("性别："));
	outtextxy(100, 190, Now->sex);
	outtextxy(30, 230, _T("生日："));
	outtextxy(100, 230, Now->birthyearmonthday);
	outtextxy(30, 270, _T("地址："));
	outtextxy(100, 270, Now->address);
	outtextxy(30, 310, _T("电话："));
	outtextxy(100, 310, Now->tel);
	outtextxy(30, 350, _T("邮箱："));
	outtextxy(100, 350, Now->email);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, temp);
	outtextxy(332, 400, Temp);
	outtextxy(256, 427, _T("上一页 / 下一页"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);  //画出基础界面图以及打印当前指针

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445) {   //如果鼠标位置在框内
			Fanyelinecolorclean();//将所有边框恢复至白色并设置新的边框为红色
			line(256, 445, 303, 445);//画新的边框
			if (m1.uMsg == WM_LBUTTONDOWN) break; //检测到按下左键结束循环
		}
		else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445) {
			Fanyelinecolorclean();
			line(315, 445, 360, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Fanyelinecolorclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Fanyelinecolorclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Fanyelinecolorclean();
	}
	turn();//跳转界面 

	if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445)   //检测鼠标点击位置
		Fanyelast();
	else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445)
		Fanyenext();
	else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
		yema = 0;
		Yema = 0;
		Menu();
	}
}

void Fanyelast()  //翻上一页功能                                     
{
	if (yema == 1) {    //页码为1时翻上一页
		yema = Yema;    //跳到页码最大处
		Now = Tail;    //修改当前指针
		turn();   //清空界面

		Viewmousemessage();  //一个功能众多的函数
	}
	else {            
		yema -= 1;
		turn();   //清空界面

		Now = Head;        //不想写双向重来 只得狗一下计算机了TAT
		int i ;
		for (i = 1; i < yema; i++)
			Now = Now->next;     //我聪明起来都佩服我自己系列

		Viewmousemessage();
	}
}

void Fanyenext()
{
	if (yema == Yema) {    //页码为末页时翻下一页
		yema = 1;    //跳到页码最小处
		Now = Head;    //修改当前指针
		turn();   //清空界面

		Viewmousemessage();  //一个功能众多的函数
	}
	else {
		Now =Now->next;
		yema += 1;
		turn();   //清空界面
		Viewmousemessage();
	}
}

struct student* create()  //创立链表并把文件读入链表，返回头指针
{
	FILE* fp;
	fp = fopen("Information.txt", "r");   //打开文件

	struct student* head = NULL, * pnew, * ptail;
	pnew = (struct student*)malloc(sizeof(struct student));

	fscanf(fp, "%s", pnew->studentnumber);    //由于文件eof的神奇机制没法判断空（头指针=NULL无法判断） 故出此下策 （感谢老师周一晚上对于文件eof的指点
	if (feof(fp)) return NULL;                      //我太机智了哈哈哈哈

	fscanf(fp, "%s%s%s%s%s%s%s", pnew->name, pnew->age, pnew->sex, pnew->birthyearmonthday, pnew->address, pnew->tel, pnew->email);
	head = ptail = pnew;                //建立头节点
	Yema++; yema++;        //总页码开始计数,第一页有着落了

	while (!feof(fp)) {        
		pnew = (struct student*)malloc(sizeof(struct student));
		fscanf(fp, "%s%s%s%s%s%s%s%s", pnew->studentnumber, pnew->name, pnew->age, pnew->sex, pnew->birthyearmonthday, pnew->address, pnew->tel, pnew->email);
		ptail->next = pnew;
		ptail = pnew;            //建立剩余节点
		Yema++;
	}
	ptail->next = NULL;
	Head = head;
	Tail = ptail;

	return head;
}

void turn()  //清空界面实现跳转并恢复默认颜色
{
	cleardevice();  
	setlinecolor(WHITE);   //将画线颜色恢复为白色
}

void Continuetobe ()  //鼠标点击继续功能(还顺手清空了画面
{
	MOUSEMSG m0;
	while (m0 = GetMouseMsg(), m0.uMsg != WM_LBUTTONDOWN) continue;
	turn();
}

void Exitandmenumid()   //退出或者返回菜单界面
{
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("返回菜单"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("退出界面"));
	outtextxy(256, 427, _T("点击任意选项继续")); //画出界面

	MOUSEMSG m1;     //获取鼠标实时信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {  //如果在框内
			Exitcolorclean();  //恢复全白框并设置画笔颜色为红
			rectangle(240, 200, 400, 230);   //画出红框
			if (m1.uMsg == WM_LBUTTONDOWN) break;  //检测到点击 退出
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Exitcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Exitcolorclean();   //鼠标在框以外 恢复画框颜色
	}
	turn();

	if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {  //判断点击信息在哪个框
		Yema = 0;
		yema = 0;
		Menu();    //前往菜单
	}
}


void Changecolorclean()            //修改页面的颜色改变
{
	setlinecolor(WHITE);
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);
	setlinecolor(RED);
}

void Change_changecolorclean()    //修改的8个选项根据鼠标位置颜色改变
{
	setlinecolor(WHITE);
	rectangle(140, 150, 300, 180); 
	rectangle(340, 150, 500, 180);
	rectangle(140, 200, 300, 230);
	rectangle(340, 200, 500, 230);
	rectangle(140, 250, 300, 280); 
	rectangle(340, 250, 500, 280);
	rectangle(140, 300, 300, 330); 
	rectangle(340, 300, 500, 330);
	setlinecolor(RED);
}

void Exitcolorbottomclean()   //底部按钮返回菜单颜色改变
{
	setlinecolor(WHITE);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	setlinecolor(RED);
}

void Menucolorclean()  //菜单里边根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	rectangle(240, 350, 400, 380);
	setlinecolor(RED);
}

void Exitcolorclean()  //退出与返回菜单界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	setlinecolor(RED);
}

void Searchcolorclean()  //搜索界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	setlinecolor(RED);
}

void Fanyelinecolorclean()    //翻页+退出菜单的颜色改变
{
	setlinecolor(WHITE);
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	setlinecolor(RED);
}

void view()  //浏览 
{
	struct student *head; //建立头指针
	head = create();    //建立链表 获得头指针 打印头指针

	if (head== NULL) {        //如果文件为空 
		outtextxy(286, 100, _T("信息为空"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {
		Now = Head;
		turn();//跳转界面 

		/*rectangle(256, 425, 303, 445);
		rectangle(315, 425, 362, 445);
		rectangle(241, 453, 304, 473);
		rectangle(314, 453, 378, 473);*/      //舍不得删掉的 搞了好久 的 位置信息 TAT

		Viewmousemessage();    //终极调用函数  
	}
}

void write()  //写入
{
	struct student* head;
	head= create();

	char s[100];
	InputBox(s, 100, "请按照以下格式输入学生信息\n学号 姓名 年龄 性别 生日 地址 电话 邮件");//信息输入

	FILE* f;   //打开文件
	f = fopen("Information.txt", "a");
	if (head!=NULL)
		fputc('\n', f);  //输入文件后的换行操作 好看
	fputs(s, f);
	if (fclose(f))
	{
		outtextxy(283, 207, _T("保存失败！"));
		exit(1);
	}
	outtextxy(283, 207, _T("保存成功！"));

	outtextxy(256, 427, _T("点击任意位置继续"));
	Continuetobe();  //检测鼠标点击并清空页面
	Exitandmenumid();  //退出与返回菜单功能
}

void search()  //搜索的菜单                                                          
{
	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("学号搜索"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("姓名搜索"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("学号排序"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("姓名排序"));
	outtextxy(256, 427, _T("点击任意选项继续")); //画出搜索界面

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180) {   //如果鼠标位置在框内
			Searchcolorclean();//将所有边框恢复至白色并设置新的边框为红色
			rectangle(240, 150, 400, 180);//画新的边框
			if (m1.uMsg == WM_LBUTTONDOWN) break; //检测到按下左键结束循环
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {
			Searchcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Searchcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330) {
			Searchcolorclean();
			rectangle(240, 300, 400, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) break;
		}
		else Searchcolorclean();
	}
	turn();
	if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180)
		Search_chazhaonumber();
	else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230)  //检测鼠标点击位置实现函数跳转
		Search_chazhaoname();
	else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280)
		Search_paixunumber();
	else
		Search_paixuname();
}

void change()   //修改              前边和浏览时一样的套路，重新写终极调用                           
{
	struct student* head; //建立头指针
	head = create();    //建立链表 获得头指针 打印头指针

	if (head == NULL) {        //如果文件为空 
		outtextxy(286, 100, _T("信息为空"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {
		Now = Head;
		turn();//跳转界面 
		Changemousemessage();    //终极调用函数  
	}
}

void Welcome()   //欢迎界面
{
	RECT r1 = { 0, 0, 639, 450 };   //矩形区域指针
	drawtext(_T("欢迎来到学生管理系统"), &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);  //输入标题并放在中间
	outtextxy(256, 427, _T("点击任意位置继续"));  //提示词 
	Continuetobe();
}

void Menu()  //菜单
{
	RECT r3 = { 0, 0, 639, 200 };
	drawtext(_T("菜单"), &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("信息浏览"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("信息录入"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("信息查询"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("信息修改"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("退出程序"));   
	outtextxy(256, 427, _T("点击任意选项继续"));    //画出菜单框架

	MOUSEMSG m1;  //获取鼠标信息
	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180) {   //如果鼠标位置在框内
			Menucolorclean();//将所有边框恢复至白色并设置新的边框为红色
			rectangle(240, 150, 400, 180);//画新的边框
			if (m1.uMsg == WM_LBUTTONDOWN) break; //检测到按下左键结束循环
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {
			Menucolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) break; 
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Menucolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) break; 
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330) {
			Menucolorclean();
			rectangle(240, 300, 400, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) break; 
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 350 && m1.y <= 380) {
			Menucolorclean();
			rectangle(240, 350, 400, 380);
			if (m1.uMsg == WM_LBUTTONDOWN) break; 
		}
		else Menucolorclean();
	}
	turn();
	if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180)  //检测鼠标点击位置实现函数跳转
		view();
	else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230)
		write();
	else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280)
		search();
	else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330)
		change();
}

int main()
{
	initgraph(640, 480);  //窗口

	Welcome();  //欢迎界面

	Menu(); //菜单

	outtextxy(250, 227, _T("欢迎下次使用系统！"));
	outtextxy(256, 427, _T("点击任意位置退出"));   //显示提示语句

	Continuetobe();  //点击退出

	closegraph();

	return 0;
}

