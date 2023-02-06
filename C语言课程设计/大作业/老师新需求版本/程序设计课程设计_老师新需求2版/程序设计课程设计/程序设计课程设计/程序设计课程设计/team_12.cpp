#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>   
#include <graphics.h>   //easyx图形库
#include <string.h>
#include <stdlib.h>     //字符串处理函数



int page1 = 0;    //总页码
int page2 = 0;    //当前页码
int root = 0;     //是否输入过了教师账号
int key = 0;      //判断是不是由教师的返回

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

typedef struct NODE
{
	StudentInfo Info;
	StudentScore sc;
	struct NODE* next;
	struct NODE* prior;
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
void Login(int a);
void Menu();                     //菜单界面————————————4
void Menu_Student();
void Menu_Teacher();
void Welcome();                  //欢迎界面————————————1
void view();                     //浏览功能————————————6
void write();                    //写入功能
void search_T();                 //搜索功能_教师版
void modify();                   //修改功能
void Search_Sname();             //Search功能下的姓名查找
void Search_Snum_S();              //Search功能下的学号查找_学生版
void Search_Snum_T();              //Search功能下的学号查找_老师版
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
int Judge();
void Turn(int a);


//鼠标相关
void Menucolorclean_Menu();    //菜单鼠标移动选择框颜色改变功能————————————5
void Menucolorclean_Student();    //菜单鼠标移动选择框颜色改变功能，学生界面————————————5
void Menucolorclean_Teacher();    //菜单鼠标移动选择框颜色改变功能，老师界面————————————5
void Searchcolorclean();  //搜索鼠标移动选择框颜色改变功能_教师版
void Searchcolorclean_S();//搜索鼠标移动选择框颜色改变功能_学生版
void Exitcolorclean();    //退出或者返回菜单界面选择框颜色改变功能 中央版本
void Turnpagelinecolorclean();   //带页码的翻页界面下划线颜色改变功能   浏览用
void Exitcolorbottomclean();    //退出或者返回菜单界面下划线颜色改变功能 底部版本 查找用
void Modifycolorclean();          //修改总界面的颜色改变
void Modify_changecolorclean();     //修改里边8个选项的界面颜色改变

//界面信息
#define UI1()                               \
	outtextxy(150, 70, _T("学号："));       \
	outtextxy(200, 70, p->Info.Snum);      \
	outtextxy(30, 70, _T("姓名："));        \
	outtextxy(80, 70, p->Info.Sname);      \
	outtextxy(30, 110, _T("年龄："));       \
	outtextxy(80, 110, p->Info.Sage);		\
	outtextxy(300, 70, _T("性别："));		\
	outtextxy(350, 70, p->Info.Ssex);		\
	outtextxy(150, 110, _T("生日："));		\
	outtextxy(200, 110, p->Info.Sbirth);	\
	outtextxy(30, 150, _T("电话："));		\
	outtextxy(80, 150, p->Info.Stel);		\
	outtextxy(30, 190, _T("邮箱："));		\
	outtextxy(80, 190, p->Info.Smail);		\
	outtextxy(30, 230, _T("成绩："));		\
	outtextxy(100, 270, _T("大学英语"));		\
	outtextxy(120, 310, p->sc.DYgrade);		\
	outtextxy(190, 270, _T("高等数学"));		\
	outtextxy(210, 310, p->sc.GSgrade);		\
	outtextxy(280, 270, _T("线性代数"));		\
	outtextxy(300, 310, p->sc.XDgrade);		\
	
#define UI2()								\
	outtextxy(30, 30, _T("序号："));        \
	outtextxy(80, 30, page4);              \
	UI1()									\
	outtextxy(308, 400, _T("/"));			\
	outtextxy(280, 400, page4);				\
	outtextxy(332, 400, page3);				\
	outtextxy(256, 427, _T("上一页 / 下一页"));	\
	line(256, 445, 303, 445);					\
	line(315, 445, 360, 445);					\
	outtextxy(242, 455, _T("返回菜单  退出程序"));	\
	line(242, 473, 304, 473);						\
	line(315, 473, 377, 473);						\

#define judge()
    
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

	if (fgetc(fp)==EOF) {
		return NULL;
	}

	rewind(fp);//指针移到文件头，不然的话后面读取顺序就错了一位

	fscanf(fp, "%s%s%s%s%s%s%s%s%s%s ", p1->Info.Sname, p1->Info.Snum, p1->Info.Sage, p1->Info.Ssex, p1->Info.Sbirth, p1->Info.Stel, p1->Info.Smail, p1->sc.GSgrade, p1->sc.DYgrade, p1->sc.XDgrade);
	head = tail = p1;
	head->prior = p1;
	head->next = p1;
	p1->next = head;
	p1->prior = tail;
	page1++;
	page2++;

	while (!feof(fp)) {
		p1 = (NODE*)malloc(sizeof(NODE));
		if (fscanf(fp, "%s%s%s%s%s%s%s%s%s%s", p1->Info.Sname, p1->Info.Snum, p1->Info.Sage, p1->Info.Ssex, p1->Info.Sbirth, p1->Info.Stel, p1->Info.Smail, p1->sc.GSgrade, p1->sc.DYgrade, p1->sc.XDgrade) != 10) {
			break;
		}
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
		NODE* q = Head;
		Head = q->next;
		q->prior->next = q->next;
		q->next->prior = q->prior;

		free(q);

		writeinto();     //写入文件

		outtextxy(286, 100, _T("删除成功！"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
	else {                                                                                  //这里有错！不知道怎么改
		int i = 1;
		NODE* q;

		q = Head;

		for (i = 1; i < page2; i++) {
			q = q->next;
		}
		if (page2 == page1) {
			Last = q->prior;
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
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生姓名");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sname, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Snum() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生学号");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	RECT n3 = { 0,0,640,200 };
	int a = -1, flag = 0;
    NODE* head;
	a = -1;
	head = create();
	for (p = head; ; p = p->next) {   //找学号
		if (p == head) {
			a++;
		}
		if (strcmp(p->Info.Snum, s) == 0) {
			flag++;
		}
		if (a) {
			break;
		}
	}

	if (flag)
	{
		drawtext(_T("该学号已存在！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Exitandmenumid();
	}

	strcpy(p->Info.Snum, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sage() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生年龄");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sage, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Ssex() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生性别");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	strcpy(p->Info.Ssex, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sbirth() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生生日");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sbirth, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Stel() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生电话");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}

	strcpy(p->Info.Stel, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Smail() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "请输入修改的学生邮箱");//信息输入
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}
	strcpy(p->Info.Smail, s);    //修改
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

void Modify_Sscore() {
	char s[50] = { 0 };
	char s1[50],s2[50],s3[50] = { 0 };
	InputBox(s, 50, "请输入修改的学生成绩（大英、线代、高数）");//信息输入
	if (sscanf(s, "%s %s %s", s1,s2,s3) != 3) {
		outtextxy(286, 100, _T("修改失败！"));
		Exitandmenumid();
	}
	strcpy(p->sc.DYgrade, s1);    //
	strcpy(p->sc.XDgrade, s2);
	strcpy(p->sc.GSgrade, s3);
	writeinto();    //写入文件

	outtextxy(286, 100, _T("修改成功！"));
	Exitandmenumid();      //退出或者返回菜单的选项
}

//■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■search功能下的几个函数

void Search_Sname() {
	int flag = 0;
	int a = -1;

	NODE* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("请按输入查找的学生姓名"));

	for (p = head;; p = p->next) {
		if (p == head) {
			a++;
		}
		if (strcmp(p->Info.Sname, s) == 0) {
			flag++;
			UI1();
			Exitandmenubottom();
		}
	}
	if (flag == 0) {
		turnpage();   //找不到就清空页面
		outtextxy(286, 100, _T("查找失败"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Search_Snum_T() {
	int flag = 0;
	int a = -1;

	NODE* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("请按输入查找的学生姓名"));

	for (p = head;; p = p->next) {
		if (p == head) {
			a++;
		}
		if (strcmp(p->Info.Sname, s) == 0) {
			flag++;
			UI1();
			Exitandmenubottom();
		}
	}
	if (flag == 0) {
		turnpage();   //找不到就清空页面
		outtextxy(286, 100, _T("查找失败"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}
}

void Search_Snum_S() {
	RECT n3 = { 0,0,640,200 };
	char s[100];
	
	int flag = 0;
	int a = -1;
	int cnt = 0;
	NODE* head;

	while (root != 1 && cnt < 3)        //不是教师权限，且输入次数需要小于3次
	{
		InputBox(s, 100, "请输入学生学号");
	    int lenth = strlen(s) + 1;
		a = -1;
		head = create();
		for (p = head; ; p = p->next) {   //找学号
			if (p == head) {
				a++;
			}
			if (strcmp(p->Info.Snum, s) == 0) {
				flag++;
			}
			if (a) {
				break;
			}
		}

		if (flag == 0) {              //判断学号合法性
			drawtext(_T("不存在此账户！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else
		{
			cleardevice();
			char c[100];
			InputBox(c, 100, "请输入密码");
			flag = 0;
			for (int i = 0; i < lenth; i++)
			{
				if (c[i] != s[i]) flag = 1;
				if (flag) break;
			}
			if (flag) drawtext(_T("密码错误！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			else break;
		}
		cnt++;
	}

    if (flag != 0) {
		turnpage();   //找不到就清空页面
		outtextxy(286, 100, _T("查找失败"));
		Exitandmenumid();      //退出或者返回菜单的选项
	}

	flag = 0; a = -1;
	head = create();
	for (p = head; ; p = p->next) {
		if (p == head) {
			a++;
		}
		if (strcmp(p->Info.Snum, s) == 0) {
			flag++;
			UI1();
			Exitandmenubottom();
		}
		if (a) {
			break;
		}
	}
	
}

void Search_Snameorder() {

	Head = create();

	if (Head == NULL) {
		exit(1);
	}

	int cnt = 0;
	NODE** tmp = (NODE**)malloc(sizeof(NODE*) * page1);
	NODE* p1 = Head;
	tmp[cnt++] = p1;

	while (p1 != Last) {
		p1 = p1->next;
		tmp[cnt++] = p1;
	}

	int i, j;
	for (i = 0; i < cnt - 1; i++) {
		for (j = 0; j < cnt - i - 1; j++) {
			if (strcmp(tmp[j]->Info.Sname, tmp[j + 1]->Info.Sname) > 0) {
				NODE* t = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = t;
			}
		}
	}

	for (i = 0; i < cnt; i++) {
		if (i == 0) {
			tmp[i]->next = tmp[i + 1];
			tmp[i]->prior = tmp[cnt - 1];
			continue;
		}
		else if (i == cnt - 1) {
			tmp[i]->next = tmp[0];
			tmp[i]->prior = tmp[i - 1];
			continue;
		}
		tmp[i]->next = tmp[i + 1];
		tmp[i]->prior = tmp[i - 1];
	}

	Head = tmp[0];
	Last = tmp[cnt - 1];

	free(tmp);

	page1 = 0;
	page2 = 0;

	writeinto();
	view();

}

void Search_Snumorder() {
	Head = create();

	if (Head == NULL) {
		exit(1);
	}

	int cnt = 0;
	NODE** tmp = (NODE**)malloc(sizeof(NODE*) * page1);
	NODE* p1 = Head;
	tmp[cnt++] = p1;

	while (p1 != Last) {
		p1 = p1->next;
		tmp[cnt++] = p1;
	}

	int i, j;
	for (i = 0; i < cnt - 1; i++) {
		for (j = 0; j < cnt - i - 1; j++) {
			if (strcmp(tmp[j]->Info.Snum, tmp[j + 1]->Info.Snum) > 0) {
				NODE* t = tmp[j];
				tmp[j] = tmp[j + 1];
				tmp[j + 1] = t;
			}
		}
	}

	for (i = 0; i < cnt; i++) {
		if (i == 0) {
			tmp[i]->next = tmp[i + 1];
			tmp[i]->prior = tmp[cnt - 1];
			continue;
		}
		else if (i == cnt - 1) {
			tmp[i]->next = tmp[0];
			tmp[i]->prior = tmp[i - 1];
			continue;
		}
		tmp[i]->next = tmp[i + 1];
		tmp[i]->prior = tmp[i - 1];
	}

	Head = tmp[0];
	Last = tmp[cnt - 1];

	free(tmp);

	page1 = 0;
	page2 = 0;

	writeinto();
	view();
}

void Turn(int m)
{
	if (m == 1)
	{
		Menu();
	}
	else if (m == 2)
	{
		Menu_Student();
	}
	else if (m == 3)
	{
		Menu_Teacher();
	}
//	else if (m==4)
}

void search_T()  //搜索的菜单                                                          
{
	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("学号搜索"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("姓名搜索"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("学号排序"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("姓名排序"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("返回上层"));
	outtextxy(256, 427, _T("点击任意选项继续")); //画出搜索界面

	MOUSEMSG m1;  //获取鼠标信息
	char check[4] = { FALSE };

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180) {//学号
			Searchcolorclean();
			rectangle(240, 150, 400, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {//姓名
			Searchcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {//学号排序
			Searchcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330) {//姓名排序
			Searchcolorclean();
			rectangle(240, 300, 400, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 350 && m1.y <= 380) {//返回上层
			Searchcolorclean();
			rectangle(240, 350, 400, 380);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else Searchcolorclean();
	}
	turnpage();
	if (check[0]) {
		Search_Snum_T();
	}
	else if (check[1]) {
		Search_Sname();
	}
	else if (check[2]) {
		Search_Snumorder();
	}
	else if (check[3]) {
		Search_Snameorder();
	}
	else
	{
		if (key == 0) Turn(2);
		else Turn(3);
	}
}


void write()  //写入操作
{
	NODE* head;
	head = create();

	char s[100] = { 0 };
	char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100], s8[100], s9[100], s10[100] = { 0 };
	InputBox(s, 100, "请按照以下格式输入学生信息\n姓名 学号 年龄 性别 生日 电话 邮件 高数成绩 大英成绩 线代成绩");//信息输入
    if (sscanf(s, "%s %s %s %s %s %s %s %s %s %s", s1,s2,s3,s4,s5,s6,s7,s8,s9,s10) != 10) {
	   	outtextxy(286, 100, _T("录入失败！"));
		Exitandmenumid();
	}

	RECT n3 = { 0,0,640,200 };
	int a = -1, flag = 0;
	a = -1;
	head = create();
	for (p = head; ; p = p->next) {   //找学号
		if (p == head) {
			a++;
		}
		if (strcmp(p->Info.Snum, s2) == 0) {
			flag++;
		}
		if (a) {
			break;
		}
	}

	if (flag)
	{
		drawtext(_T("该学号已存在！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Exitandmenumid();
	}

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
	NODE* head;
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

	for (p = Head; p != Last; p = p->next)
	{
		fprintf(f, "%s ", p->Info.Sname);
		fprintf(f, "%s ", p->Info.Snum);
		fprintf(f, "%s ", p->Info.Sage);
		fprintf(f, "%s ", p->Info.Ssex);
		fprintf(f, "%s ", p->Info.Sbirth);
		fprintf(f, "%s ", p->Info.Stel);
		fprintf(f, "%s ", p->Info.Smail);
		fprintf(f, "%s ", p->sc.GSgrade);
		fprintf(f, "%s ", p->sc.DYgrade);
		fprintf(f, "%s ", p->sc.XDgrade);
		fputc('\n', f);          //换行
	}
	fprintf(f, "%s ", p->Info.Sname);
	fprintf(f, "%s ", p->Info.Snum);
	fprintf(f, "%s ", p->Info.Sage);
	fprintf(f, "%s ", p->Info.Ssex);
	fprintf(f, "%s ", p->Info.Sbirth);
	fprintf(f, "%s ", p->Info.Stel);
	fprintf(f, "%s ", p->Info.Smail);
	fprintf(f, "%s ", p->sc.GSgrade);
	fprintf(f, "%s ", p->sc.DYgrade);
	fprintf(f, "%s ", p->sc.XDgrade);
	fputc('\n', f); // p == Last
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

void Menucolorclean_Student() {
	setlinecolor(WHITE);

	rectangle(240, 150, 400, 180);
	rectangle(240, 250, 400, 280);
	rectangle(240, 350, 400, 380);

	setlinecolor(BLUE);
}

void Menucolorclean_Teacher() {
	setlinecolor(WHITE);

	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	rectangle(240, 350, 400, 380);

	setlinecolor(BLUE);
}

void Menucolorclean_Menu() {
	setlinecolor(WHITE);

	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);

	setlinecolor(BLUE);
}

void Searchcolorclean()  //搜索界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	rectangle(240, 350, 400, 380);
	setlinecolor(BLUE);
}

void Searchcolorclean_S()  //搜索界面根据实时鼠标位置画矩形并设置下一次画框为红色
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 250, 400, 280);
	rectangle(240, 350, 400, 380);
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

	UI2();
	
	outtextxy(156, 427, _T("修改信息"));
	outtextxy(400, 427, _T("删除信息"));
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);

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

	UI2();

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
				EXIT();
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
	LOGFONT a;
	gettextstyle(&a);
	settextstyle(100, 0, _T("Consolas"));
	outtextxy(120, 177, _T("Good Bye！"));
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(180, 427, _T("点击任意键退出系统"));
	settextstyle(&a);
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
void Login(int m)
{
	//1表示来自老师系统登陆
	//2表示来自学生系统登陆
	int cnt = 0;
	while (root != 1 && cnt < 3)
	{
		RECT n3 = { 0,0,640,200 };
		char s[100];
		char s1[5];
		if (m == 1)
		{
            InputBox(s, 100, "请输入教师账户");
			if (s[0] == 'S' && s[1] == 'i' && s[2] == 'r')
			{
				cleardevice();
				char c[100];
				InputBox(c, 100, "请输入密码");
				if (c[0] == 'S' && c[1] == 'i' && c[2] == 'r') break;
				else drawtext(_T("密码错误！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			else drawtext(_T("不存在此账户！"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else 
		{
            
		}
		cnt++;
	}
	if (cnt >= 3)
	{
		RECT n1 = { 0,0,640,480 };//矩形区域指针

		drawtext(_T("次数超过三次，请重新进入！"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//居中标题
		outtextxy(256, 427, _T("点击任意键继续"));

		Continuetobe();
		Menu();
	}
	cleardevice();
}

void Menu_Student() {
	RECT n4 = { 0,0,640,200 };
	int check[4] = { FALSE };
	drawtext(_T("菜单"), &n4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("信息查询"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("返回上层"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("退出程序"));
	outtextxy(256, 427, _T("点击任意选项继续"));    //菜单的页面

	MOUSEMSG m4;

	while (TRUE) {//选取相关矩形位置，探测鼠标位置交互
		m4 = GetMouseMsg();

		if (m4.x >= 240 && m4.x <= 400 && m4.y >= 150 && m4.y <= 180) {//信息查询
			Menucolorclean_Student();
			rectangle(240, 150, 400, 180);
			if (m4.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m4.x >= 240 && m4.x <= 400 && m4.y >= 250 && m4.y <= 280) {//上级菜单
			Menucolorclean_Student();
			rectangle(240, 250, 400, 280);
			if (m4.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m4.x >= 240 && m4.x <= 400 && m4.y >= 350 && m4.y <= 380) {//go back home
			Menucolorclean_Student();
			rectangle(240, 350, 400, 380);
			if (m4.uMsg == WM_LBUTTONDOWN) {
				EXIT();
			}
		}
		else Menucolorclean_Student();//全部变回白色
	}

	turnpage();
    if (check[1]) {//信息查询
		key = 0;
		Search_Snum_S();
	}
	else if (check[2]) {//返回上一级
		Turn(1);
	}
}

void Menu_Teacher() {
	Login(1);
	RECT n3 = { 0,0,640,200 };
	int check[4] = { FALSE };

	root = 1;
	drawtext(_T("已获得教师权限，请浏览菜单"), &n3, DT_CENTER | DT_VCENTER| DT_SINGLELINE);

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

	MOUSEMSG m3;

	while (TRUE) {//选取相关矩形位置，探测鼠标位置交互
		m3 = GetMouseMsg();

		//信息浏览
		if (m3.x >= 240 && m3.x <= 400 && m3.y >= 150 && m3.y <= 180) {   //选取鼠标x,y轴位置，如果在框内
			Menucolorclean_Teacher();//将所有边框恢复至白色并设置新的边框为蓝色
			rectangle(240, 150, 400, 180);//画新的边框
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 200 && m3.y <= 230) {//信息录入
			Menucolorclean_Teacher();
			rectangle(240, 200, 400, 230);
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 250 && m3.y <= 280) {//信息查询
			Menucolorclean_Teacher();
			rectangle(240, 250, 400, 280);
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 300 && m3.y <= 330) {//信息修改
			Menucolorclean_Teacher();
			rectangle(240, 300, 400, 330);
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 350 && m3.y <= 380) {//go back home
			Menucolorclean_Teacher();
			rectangle(240, 350, 400, 380);
			if (m3.uMsg == WM_LBUTTONDOWN) {
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
		key = 2;
		search_T();
	}
	else if (check[3]) {//信息修改
		modify();
	}
}

void Menu() {
	RECT n2 = { 0,0,640,200 };
	int check[2] = { FALSE };
	drawtext(_T("请选择进入的系统"), &n2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("教师系统"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("学生系统"));

	MOUSEMSG m2;

	while (TRUE) {//选取相关矩形位置，探测鼠标位置交互
		m2 = GetMouseMsg();

		//信息浏览
		if (m2.x >= 240 && m2.x <= 400 && m2.y >= 150 && m2.y <= 180) {   //选取鼠标x,y轴位置，如果在框内
			Menucolorclean_Menu();//将所有边框恢复至白色并设置新的边框为蓝色
			rectangle(240, 150, 400, 180);//画新的边框
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 200 && m2.y <= 230) {//信息录入
			Menucolorclean_Menu();
			rectangle(240, 200, 400, 230);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else Menucolorclean_Menu();//全部变回白色
	}

	turnpage();

	if (check[0]) {//进入教师系统
		Menu_Teacher();
	}
	else if (check[1]) {//进入学生系统
		Menu_Student();
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

	LOGFONT a;
	gettextstyle(&a);

	settextstyle(30,0, _T("Consolas"));
	drawtext(_T("欢迎进入学生信息管理系统"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//居中标题
	outtextxy(180, 427, _T("点击任意键进入系统"));
	settextstyle(&a);
	

	Continuetobe();
}

void main() {
	initgraph(640, 480);

	Welcome();

	Menu();

	EXIT();

}