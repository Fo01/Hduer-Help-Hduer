#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <graphics.h>   //easyx图形库
#include <string.h>
#include <stdlib.h>     //字符串处理函数



int page1 = 0;    //总页码
int page2 = 0;    //当前页码

typedef struct StudentInfo {
	char Sname[20];     //学生姓名
	char Snum[80];
	char Sage[80];
	char Ssex[8];
	char Sbirth[60];
	char Stel[60];
	char Smail[90];
};

typedef struct StudentScore {
	char GSgrade[30];     //高等数学
	char DYgrade[30];     //大学英语
	char XDgrade[30];     //线性代数
};

typedef struct node
{
	StudentInfo Info;
	StudentScore sc;
	struct node* next;
	struct node* prior;
}NODE;

NODE* Head = NULL;
NODE* Last = NULL;
NODE* p = NULL;

//链表相关
NODE* create(); //创立链表并把文件读入链表，返回头指针 只读
void writeinto();    //把更新好的链表写入文件 只写


//n代表矩形区域
//		n1:welcome()
//		n2:Menu()
//m代表鼠标指针
//		m1:Menu()
//		   Exitandmenumid()


//单次功能函数
void Menu();                     //菜单界面————————————4
void Welcome();                  //欢迎界面————————————1
void view();                     //浏览功能————————————6
void write();                    //写入功能
void search();                   //搜索功能
void modify();                   //修改功能
void Search_Sname();             //Search功能下的姓名查找
void Search_Snum();              //Search功能下的学号查找
void Search_Snameorder();        //Search功能下的姓名排序
void Search_Snumorder();         //Search功能下的学号排序
void Modify_all();            //Modify功能下的修改功能
void Modify_delete();            //Modify功能下的删除功能

//修改学生信息的函数
void Modify_Sname();
void Modify_Snum();
void Modify_Sage();
void Modify_Ssex();
void Modify_Sbirth();
void Modify_Stel();
void Modify_Smail();
void Modify_Sscore();


//多次功能函数
void turnpage();                 //跳转界面—————————————3
void Continuetobe();         //鼠标点击继续功能————————————2
void Exitandmenumid();       //点击退出或者返回菜单功能 中央版本——————————————————
void Exitandmenubottom();    //点击退出或者返回菜单  底部版本
void Turnpage_last();        //点击上一页下一页翻页
void Turnpage_next();
void Viewmousemessage();     //浏览界面的鼠标信息检测 还有绘图 打印————————————
void Modifymousemessage();   //修改界面的鼠标信息检测c 绘图 打印  导入修改/删除函数!!!
void Turnpage_Biglast();     //浏览界面+修改删除的大翻页 用于修改函数
void Turnpage_Bignext();
void EXIT();                 //处理退出的函数


//鼠标相关
void Menucolorclean();    //菜单鼠标移动选择框颜色改变功能————————————5
void Searchcolorclean();   //搜索鼠标移动选择框颜色改变功能
void Exitcolorclean();    //退出或者返回菜单界面选择框颜色改变功能 中央版本
void Turnpagelinecolorclean();   //带页码的翻页界面下划线颜色改变功能   浏览用
void Exitcolorbottomclean();    //退出或者返回菜单界面下划线颜色改变功能 底部版本 查找用
void Modifycolorclean();          //修改总界面的颜色改变
void Modify_changecolorclean();     //修改里边8个选项的界面颜色改变

//————————————————————————————————————————————————————————————————————————————————————
//————————————————————————————————————————————————————————————————————————————————————
//————————————————————————————————————————————————————————————————————————————————————

NODE* create() {
	FILE* fp;
	fp = fopen("Info.txt", "r");//只读打开文件

	NODE* p1;//当前
	NODE* tail;//尾
	NODE* head;

	head = NULL;
	tail = NULL;

	p1 = (NODE*)malloc(sizeof(NODE));

	if (feof(fp)) {
		return NULL;
	}

	fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", p1->Info.Sname, p1->Info.Snum, p1->Info.Sage, p1->Info.Ssex, p1->Info.Sbirth, p1->Info.Stel, p1->Info.Smail, p1->sc.GSgrade, p1->sc.DYgrade, p1->sc.XDgrade);
	head = tail = p1;
	head->prior = p1;
	head->next = p1;
	p1->next = head;
	p1->prior = tail;
	page1++;
	page2++;

	while (!feof(fp)) {
		p1 = (NODE*)malloc(sizeof(NODE));
		fscanf(fp, "%s %s %s %s %s %s %s %s %s %s", p1->Info.Sname, p1->Info.Snum, p1->Info.Sage, p1->Info.Ssex, p1->Info.Sbirth, p1->Info.Stel, p1->Info.Smail, p1->sc.GSgrade, p1->sc.DYgrade, p1->sc.XDgrade);
		p1->prior = tail;
		p1->next = head;
		tail->next = p1;
		head->prior = p1;
		tail = p1;
		page1++;
	}
	Head = head;
	Last = tail;
	fclose(fp);

	return head;
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■Modify修改的内容

void Modify_all()
{
	rectangle(140, 150, 300, 180); 
	rectangle(340, 150, 500, 180);
	outtextxy(186, 157, _T("修改学号")); 
	outtextxy(386, 157, _T("修改姓名"));
	rectangle(140, 200, 300, 230); 
	rectangle(340, 200, 500, 230);
	outtextxy(186, 207, _T("修改年龄")); 
	outtextxy(386, 207, _T("修改性别"));
	rectangle(140, 250, 300, 280); 
	rectangle(340, 250, 500, 280);
	outtextxy(186, 257, _T("修改生日")); 
	outtextxy(386, 257, _T("修改电话"));
	rectangle(140, 300, 300, 330); 
	rectangle(340, 300, 500, 330);
	outtextxy(186, 307, _T("修改邮箱")); 
	outtextxy(386, 307, _T("修改成绩"));
	outtextxy(256, 427, _T("点击任意选项继续"));

	MOUSEMSG m1;  //获取鼠标信息
	int check[8] = { FALSE };

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 140 && m1.x <= 300 && m1.y >= 150 && m1.y <= 180) {
			Modify_changecolorclean();
			rectangle(140, 150, 300, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 150 && m1.y <= 180) {
			Modify_changecolorclean();
			rectangle(340, 150, 500, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 200 && m1.y <= 230) {
			Modify_changecolorclean();
			rectangle(140, 200, 300, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 200 && m1.y <= 230) {
			Modify_changecolorclean();
			rectangle(340, 200, 500, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 250 && m1.y <= 280) {
			Modify_changecolorclean();
			rectangle(140, 250, 300, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[4] = TRUE;
				break;
			}
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 250 && m1.y <= 280) {
			Modify_changecolorclean();
			rectangle(340, 250, 500, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[5] = TRUE;
				break;
			}
		}
		else if (m1.x >= 140 && m1.x <= 300 && m1.y >= 300 && m1.y <= 330) {
			Modify_changecolorclean();
			rectangle(140, 300, 300, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[6] = TRUE;
				break;
			}
		}
		else if (m1.x >= 340 && m1.x <= 500 && m1.y >= 300 && m1.y <= 330) {
			Modify_changecolorclean();
			rectangle(340, 300, 500, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[7] = TRUE;
				break;
			}
		}
		else Modify_changecolorclean();
	}
	turnpage();

	if (check[0]) {
		Modify_Snum();
	}
	else if (check[1]) {
		Modify_Sname();
	}
	else if (check[2]) {
		Modify_Sage();
	}
	else if (check[3]) {
		Modify_Ssex();
	}
	else if (check[4]) {
		Modify_Sbirth();
	}
	else if (check[5]) {
		Modify_Stel();
	}
	else if (check[6]) {
		Modify_Smail();
	}
	else {
		Modify_Sscore();
	}
}

void Modify_delete()  //删除功能
{
	if (page2 == 1) {
		Head->prior->next = Head->next;
		Head->next->prior = Head->prior;

		free(Head);

		writeinto();     //写入文件

		outtextxy(286, 100, _T("删除成功！"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {                                                                                  //这里有错！不知道怎么改
		int i = 1;
		node* q;

		q = Head;

		for (i = 1; i < page2; i++) {
			q = q->next;
		}

		q->next->prior = q->prior;
		q->prior->next = q->next;

		free(q);

		writeinto();     //写入文件

		outtextxy(286, 100, _T("删除成功！"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}


void Modify_Sname() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生姓名");//信息输入

	strcpy(p->Info.Sname, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Snum() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生学号");//信息输入

	strcpy(p->Info.Snum, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sage() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生年龄");//信息输入

	strcpy(p->Info.Sage, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Ssex() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生性别");//信息输入

	strcpy(p->Info.Ssex, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sbirth() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生生日");//信息输入

	strcpy(p->Info.Sbirth, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Stel() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生电话");//信息输入

	strcpy(p->Info.Stel, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Smail() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生电子邮件");//信息输入

	strcpy(p->Info.Smail, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sscore() {
	char s[10];
	InputBox(s, 10, "请输入修改的学生成绩");//信息输入

	strcpy(p->sc.DYgrade, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■search功能下的几个函数

void Search_Sname() {
	int flag = 0;

	node* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("请按输入查找的学生姓名"));

	for (p = head; p != NULL; p = p->next) {//尾部为空，所以查到尾部结束
		if (strcmp(p->Info.Sname, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("学号："));
			outtextxy(100, 70, p->Info.Snum);
			outtextxy(30, 110, _T("姓名："));
			outtextxy(100, 110, p->Info.Sname);
			outtextxy(30, 150, _T("年龄："));
			outtextxy(100, 150, p->Info.Sage);
			outtextxy(30, 190, _T("性别："));
			outtextxy(100, 190, p->Info.Ssex);
			outtextxy(30, 230, _T("生日："));
			outtextxy(100, 230, p->Info.Sbirth);
			outtextxy(30, 270, _T("电话："));
			outtextxy(100, 270, p->Info.Stel);
			outtextxy(30, 310, _T("邮箱："));
			outtextxy(100, 310, p->Info.Smail);
			outtextxy(30, 350, _T("成绩："));
			outtextxy(100, 350, p->sc.DYgrade);
			Exitandmenubottom();
		}
		if (p->next == NULL) break;
	}
	if (flag == 0) {
		turnpage();   //找不到就清空页面
		outtextxy(286, 100, _T("查找失败"));
		Exitandmenumid();      //退出或者返回菜单的选项

	}
}

void Search_Snum() {
	int flag = 0;

	node* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("请按输入查找的学生学号"));

	for (p = head; p != NULL; p = p->next) {//尾部为空，所以查到尾部结束
		if (strcmp(p->Info.Snum, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("学号："));
			outtextxy(100, 70, p->Info.Snum);
			outtextxy(30, 110, _T("姓名："));
			outtextxy(100, 110, p->Info.Sname);
			outtextxy(30, 150, _T("年龄："));
			outtextxy(100, 150, p->Info.Sage);
			outtextxy(30, 190, _T("性别："));
			outtextxy(100, 190, p->Info.Ssex);
			outtextxy(30, 230, _T("生日："));
			outtextxy(100, 230, p->Info.Sbirth);
			outtextxy(30, 270, _T("电话："));
			outtextxy(100, 270, p->Info.Stel);
			outtextxy(30, 310, _T("邮箱："));
			outtextxy(100, 310, p->Info.Smail);
			outtextxy(30, 350, _T("成绩："));
			outtextxy(100, 350, p->sc.DYgrade);
			Exitandmenubottom();
		}
		if (p->next == NULL) break;
	}
	if (flag == 0) {
		turnpage();   //找不到就清空页面
		outtextxy(286, 100, _T("查找失败"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Search_Snameorder() {
	int i = 0, j = 0;
	node* k1;
	node* k2;

	Head = create();
	k1 = Head;

	if (Head == NULL) {
		exit(1);
	}

	for (i = page1 - 1; i >= 0; i--) {              //双链表冒泡排序
		k1 = Head;
		for (j = 0; j <= page1 - 1 - i; j++) {
			k2 = k1->next;
			if (strcmp(k1->Info.Sname, k2->Info.Sname) > 0) {
				k1->prior->next = k2;
				k2->next->prior = k1;
				k1->prior = k2;
				k2->next = k1;
				break;
			}
			k1 = k1->next;
		}
	}

	page1 = 0;
	page2 = 0;

	writeinto();
	view();

}

void Search_Snumorder() {
	int i = 0, j = 0;
	node* k1;
	node* k2;

	Head = create();
	k1 = Head;

	if (Head == NULL) {
		exit(1);
	}

	for (i = page1-1; i >=0; i--) {              //双链表冒泡排序
		k1 = Head;
		for (j = 0; j <= page1 - 1 - i; j++) {
			k2 = k1->next;
			if (strcmp(k1->Info.Snum, k2->Info.Snum) > 0) {
				k1->prior->next = k2;
				k2->next->prior = k1;
				k1->prior = k2;
				k2->next = k1;
				break;
			}
			k1 = k1->next;
		}
	}

	page1 = 0;
	page2 = 0;

	writeinto();
	view();

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
	char check[3] = { FALSE };

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180) {
			Searchcolorclean();
			rectangle(240, 150, 400, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {
			Searchcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Searchcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330) {
			Searchcolorclean();
			rectangle(240, 300, 400, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else Searchcolorclean();
	}
	turnpage();
	if (check[0]) {
		Search_Snum();
	}
	else if (check[1]) {
		Search_Sname();
	}
	else if (check[2]) {
		Search_Snumorder();
	}
	else {
		Search_Snameorder();
	}
}


void write()  //写入操作
{
	NODE* head;
	head = create();

	char s[100];
	InputBox(s, 100, "请按照以下格式输入学生信息\n学号 姓名 年龄 性别 生日 地址 电话 邮件");//信息输入

	FILE* f;   //打开文件
	f = fopen("Info.txt", "a");
	if (head != NULL)
		fputc('\n', f);  //换行
	fputs(s, f);
	if (fclose(f))
	{
		outtextxy(283, 207, _T("保存失败！"));
		exit(1);
	}
	outtextxy(283, 207, _T("保存成功！"));

	outtextxy(256, 427, _T("点击任意位置继续"));
	Continuetobe();
	Exitandmenumid();
}

void modify(){
	node* head;
	head = create();

	if (head == NULL) {        //如果文件为空 
		outtextxy(286, 100, _T("信息为空"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {
		p = Head;
		turnpage();//跳转界面 
		Modifymousemessage();
	}
}

void writeinto()      //将链表写入文件
{
	FILE* f;   //打开文件
	f = fopen("Info.txt", "w");

	for (p = Head; p != NULL; p = p->next)
	{
		fprintf(f, "%s ", p->Info.Sname);
		fprintf(f, "%s ", p->Info.Snum);
		fprintf(f, "%s ", p->Info.Sage);
		fprintf(f, "%s ", p->Info.Ssex);
		fprintf(f, "%s ", p->Info.Sbirth);
		fprintf(f, "%s ", p->Info.Stel);
		fprintf(f, "%s ", p->Info.Smail);
		fprintf(f, "%d", p->sc.GSgrade);
		fprintf(f, "%d", p->sc.DYgrade);
		fprintf(f, "%d", p->sc.XDgrade);
		if (p->next == NULL) break;
		fputc('\n', f);          //换行
	}
	fclose(f);
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■翻页相关函数

void Turnpage_Bignext()
{
	if (page2 == page1) {
		page2 = 1;
		p = Head;
		turnpage();

		Modifymousemessage();
	}
	else {
		p = p->next;
		page2++;
		turnpage();   //清空界面
		Modifymousemessage();
	}
}

void Turnpage_Biglast()
{
	if (page2 == 1) {    //页码为1时翻上一页
		page2 = page1;    //跳到页码最大处
		p = Last;    //修改当前指针
		turnpage();   //清空界面

		Modifymousemessage();  //一个功能众多的函数
	}
	else {
		page2--;
		turnpage();   //清空界面

		p = p->prior;

		Modifymousemessage();
	}
}

void Turnpage_next() {
	if (page2 == page1) {
		p = Last;
		p = p->next;
		page2 = 1;
	}
	else {
		p = p->next;
		page2++;
	}
}

void Turnpage_last() {
	if (page2 == 1) {//在第一面的话，前一面翻页到最后一面，但是循环链表尾部置空，所以p=Last
		p = Last;
		page2 = page1;
	}
	else {
		p = p->prior;
		page2--;
	}
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■颜色修改相关的函数

void Modify_changecolorclean()    //修改的8个选项根据鼠标位置颜色改变
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
	setlinecolor(BLUE);
}

void Exitcolorbottomclean()   //底部按钮返回菜单颜色改变
{
	setlinecolor(WHITE);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	setlinecolor(BLUE);
}

void Exitcolorclean()  //退出与返回菜单界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	setlinecolor(BLUE);
}

void Menucolorclean() {
	setlinecolor(WHITE);

	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	rectangle(240, 350, 400, 380);

	setlinecolor(BLUE);
}

void Searchcolorclean()  //搜索界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	setlinecolor(BLUE);
}

void Turnpagelinecolorclean() {
	setlinecolor(WHITE);
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	setlinecolor(BLUE);
}

void Modifycolorclean() {
	setlinecolor(WHITE);
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);
	setlinecolor(BLUE);
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■信息显示相关函数

void Modifymousemessage() {
	char page3[7];     //操作详见easyx转化字符串
	char page4[7];

	sprintf(page3, "%d", page1);
	sprintf(page4, "%d", page2);

	outtextxy(30, 30, _T("序号："));
	outtextxy(100, 30, page4);
	outtextxy(30, 70, _T("学号："));
	outtextxy(100, 70, p->Info.Snum);
	outtextxy(30, 110, _T("姓名："));
	outtextxy(100, 110, p->Info.Sname);
	outtextxy(30, 150, _T("年龄："));
	outtextxy(100, 150, p->Info.Sage);
	outtextxy(30, 190, _T("性别："));
	outtextxy(100, 190, p->Info.Ssex);
	outtextxy(30, 230, _T("生日："));
	outtextxy(100, 230, p->Info.Sbirth);
	outtextxy(30, 270, _T("电话："));
	outtextxy(100, 270, p->Info.Stel);
	outtextxy(30, 310, _T("邮箱："));
	outtextxy(100, 310, p->Info.Smail);
	outtextxy(30, 350, _T("成绩："));
	outtextxy(100, 350, p->sc.DYgrade);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, page4);
	outtextxy(332, 400, page3);
	outtextxy(256, 427, _T("上一页 / 下一页"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(156, 427, _T("修改信息"));
	outtextxy(400, 427, _T("删除信息"));
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);

	MOUSEMSG m1;
	int check[5] = { FALSE };

	while (1) {
		m1 = GetMouseMsg();
		if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445) {
			Modifycolorclean();
			line(256, 445, 303, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445) {
			Modifycolorclean();
			line(315, 445, 360, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Modifycolorclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[4] = TRUE;
				break;
			}
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Modifycolorclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else if (m1.x >= 156 && m1.x <= 219 && m1.y >= 425 && m1.y <= 445) {
			Modifycolorclean();
			line(156, 445, 219, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 399 && m1.x <= 462 && m1.y >= 425 && m1.y <= 445) {
			Modifycolorclean();
			line(399, 445, 462, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else Turnpagelinecolorclean();
	}
	turnpage();//跳转界面 

	if (check[0]) {
		Turnpage_Biglast();
	}
	else if (check[1]) {
		Turnpage_Bignext();
	}
	else if (check[2]) {
		Modify_all();
	}
	else if (check[3]) {
		Modify_delete();
	}
	else if (check[4]) {
		page2 = 0;
		page1 = 0;
		Menu();
	}
}

void Viewmousemessage() {
	char page3[7];     //操作详见easyx转化字符串
	char page4[7];

	sprintf(page3, "%d", page1);
	sprintf(page4, "%d", page2);

	outtextxy(30, 30, _T("序号："));
	outtextxy(100, 30, page4);
	outtextxy(30, 70, _T("学号："));
	outtextxy(100, 70, p->Info.Snum);
	outtextxy(30, 110, _T("姓名："));
	outtextxy(100, 110, p->Info.Sname);
	outtextxy(30, 150, _T("年龄："));
	outtextxy(100, 150, p->Info.Sage);
	outtextxy(30, 190, _T("性别："));
	outtextxy(100, 190, p->Info.Ssex);
	outtextxy(30, 230, _T("生日："));
	outtextxy(100, 230, p->Info.Sbirth);
	outtextxy(30, 270, _T("电话："));
	outtextxy(100, 270, p->Info.Stel);
	outtextxy(30, 310, _T("邮箱："));
	outtextxy(100, 310, p->Info.Smail);
	outtextxy(30, 350, _T("成绩："));
	outtextxy(100, 350, p->sc.DYgrade);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, page4);
	outtextxy(332, 400, page3);
	outtextxy(256, 427, _T("上一页 / 下一页"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);

	MOUSEMSG m1;
	int check[3] = { FALSE };

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 256 && m1.x <= 303 && m1.y >= 425 && m1.y <= 445) {
			Turnpagelinecolorclean();
			line(256, 445, 303, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 315 && m1.x <= 362 && m1.y >= 425 && m1.y <= 445) {
			Turnpagelinecolorclean();
			line(315, 445, 360, 445);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Turnpagelinecolorclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Turnpagelinecolorclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				EXIT();
			}
		}
		else Turnpagelinecolorclean();
	}
	turnpage();//跳转界面 

	if (check[0]) {
		Turnpage_last();
	}
	else if (check[1]) {
		Turnpage_next();
	}
	else if (check[2]) {
		page2 = 0;
		page1 = 0;
		Menu();
	}
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■Exit相关

void Exitandmenubottom()
{
	outtextxy(242, 455, _T("返回菜单  退出程序"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);    //画图

	MOUSEMSG m1;  //获取鼠标信息
	int flag = FALSE;
	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 241 && m1.x <= 304 && m1.y >= 453 && m1.y <= 473) {
			Exitcolorbottomclean();
			line(242, 473, 304, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				flag = TRUE;
				break;
			}
		}
		else if (m1.x >= 314 && m1.x <= 378 && m1.y >= 453 && m1.y <= 473) {
			Exitcolorbottomclean();
			line(315, 473, 377, 473);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else Exitcolorbottomclean();
	}
	turnpage();//跳转界面 

	if (flag) {
		page2 = 0;
		page1 = 0;
		Menu();
	}
}

void Exitandmenumid() {//退出或者返回菜单页面
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("返回菜单"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("退出界面"));
	outtextxy(256, 427, _T("点击任意选项继续"));

	MOUSEMSG m1;     //获取鼠标实时信息
	int check = FALSE;

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {
			Exitcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check= TRUE;
				break;
			}  //检测到点击 退出
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Exitcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else Exitcolorclean();   //鼠标在框以外 恢复画框颜色
	}
	turnpage();

	if (check) {  //返回菜单的话
		page1 = 0;
		page2 = 0;
		Menu();    //前往菜单
	}//就是直接不判断是否选择退出，因为不管判不判断这样的话直接会跳转回main函数结束页面
}

void EXIT() {
	turnpage();
	outtextxy(250, 227, _T("Good Bye！"));
	outtextxy(256, 427, _T("点击任意键退出系统"));
	Continuetobe();
	closegraph();
	exit(0);
}

void view() {//浏览信息
	NODE* head;
	head = create();

	if (head == NULL) {
		outtextxy(286, 100, _T("信息为空"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {
		p = head;
		turnpage();   //清空显示学生信息
		while (true) {
			Viewmousemessage();
		}
	}
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■main中出现的函数

void Menu() {
	RECT n2 = { 0,0,640,200 };
	int check[4] = { FALSE };
	drawtext(_T("菜单"), &n2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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
	outtextxy(256, 427, _T("点击任意选项继续"));    //菜单的页面

	MOUSEMSG m2;

	while (TRUE) {//选取相关矩形位置，探测鼠标位置交互
		m2 = GetMouseMsg();

		//信息浏览
		if (m2.x >= 240 && m2.x <= 400 && m2.y >= 150 && m2.y <= 180) {   //选取鼠标x,y轴位置，如果在框内
			Menucolorclean();//将所有边框恢复至白色并设置新的边框为蓝色
			rectangle(240, 150, 400, 180);//画新的边框
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 200 && m2.y <= 230) {//信息录入
			Menucolorclean();
			rectangle(240, 200, 400, 230);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 250 && m2.y <= 280) {//信息查询
			Menucolorclean();
			rectangle(240, 250, 400, 280);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 300 && m2.y <= 330) {//信息修改
			Menucolorclean();
			rectangle(240, 300, 400, 330);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 350 && m2.y <= 380) {//go back home
			Menucolorclean();
			rectangle(240, 350, 400, 380);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				EXIT();
			}
		}
		else Menucolorclean();//全部变回白色
	}

	turnpage();

	if (check[0]) {//信息浏览
		view();
	}
	else if (check[1]) {//信息写入
		write();
	}
	else if (check[2]) {//信息查询
		search();
	}
	else if (check[3]) {//信息修改
		//modify();
	}
}

void turnpage() {
	cleardevice();//easyx的清空页面函数
	setlinecolor(WHITE);//重置画线颜色
}

void Continuetobe() {
	MOUSEMSG m0;
	while (m0 = GetMouseMsg(), m0.uMsg != WM_LBUTTONDOWN) continue;
	turnpage();
}

void Welcome() {
	RECT n1 = { 0,0,640,480 };//矩形区域指针

	drawtext(_T("欢迎进入学生信息管理系统"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//居中标题
	outtextxy(256, 427, _T("点击任意键退出系统"));

	Continuetobe();
}

void main() {
	initgraph(640, 480);

	Welcome();

	Menu();

	EXIT();

}