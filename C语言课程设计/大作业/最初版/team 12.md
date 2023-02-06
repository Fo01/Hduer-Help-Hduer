# 学生信息管理系统

## 1.变量

### 1.1学生相关信息

```c
char Sname[20];     //学生姓名
char Snum[8];
char Sage[8];
char Ssex[8];
char Sbirth;
int Stel;
char Smail[30];
char address[100];

//成绩
int GSgrade;     //高等数学
int DYgrade;     //大学英语
int XDgrade;     //线性代数
```

### 1.2其他变量

```c
int page1;    //总页码
int page2;    //当前页码
```



## 1.3结构体c

```c
struct student* create(); //创立链表并把文件读入链表，返回头指针 只读
void writeinto();    //把更新好的链表写入文件 只写
```



## 2.函数

### 2.1信息管理系统单次功能函数

```c
void Menu();                     //菜单界面
void Welcome();                  //欢迎界面
void view();                     //浏览功能
void write();                    //写入功能
void search();                   //搜索功能
void change();                   //修改功能
void Search_Sname();             //Search功能下的姓名查找
void Search_Snum();              //Search功能下的学号查找
void Search_Snameorder();        //Search功能下的姓名排序
void Search_Snumorder();         //Search功能下的学号排序
void Modify_change();            //Modify功能下的修改功能
void Modify_delete();            //Modify功能下的删除功能

//修改学生信息的函数
void Modify_Sname();
void Modify_Snum();
void Modify_Sage();
void Modify_Ssex();
void Modify_Sbrith();
void Modify_Stel();
void Modify_Smail();
void Modify_Saddress();
```



### 2.2信息管理系统多次功能函数

```c
void turn();                 //跳转界面
void Continuetobe();         //鼠标点击继续功能
void Exitandmenumid();       //点击退出或者返回菜单功能 中央版本
void Exitandmenubottom();    //点击退出或者返回菜单  底部版本
void Turnpage_last();        //点击上一页下一页翻页
void Turnpage_next();
void Viewmousemessage();     //浏览界面的鼠标信息检测 还有绘图 打印
void Changemousemessage();   //修改界面的鼠标信息检测c 绘图 打印  导入修改/删除函数!!!
void Turnpage_Biglast();     //浏览界面+修改删除的大翻页 用于修改函数
void Turnpage_Bignext();
```





### 2.3鼠标相关

```c
void Menucolorclean();    //菜单鼠标移动选择框颜色改变功能
void Searchcolorclean();   //搜索鼠标移动选择框颜色改变功能
void Exitcolorclean();    //退出或者返回菜单界面选择框颜色改变功能 中央版本
void Fanyelinecolorclean();   //带页码的翻页界面下划线颜色改变功能   浏览用
void Exitcolorbottomclean();    //退出或者返回菜单界面下划线颜色改变功能 底部版本 查找用
void Changecolorclean();          //修改总界面的颜色改变
void Change_changecolorclean();     //修改里边8个选项的界面颜色改变
```



### 2.4用到的Easyx库函数

```c
//——————————————————————1——————绘制矩形
void rectangle(
	int left,     //左侧x轴坐标
	int top,      //顶层y轴坐标
	int right,    //右侧x轴坐标
	int bottom    //底层y轴坐标
);


//——————————————————————2——————填充字符串
void outtextxy(
	int x,      //字符串在x轴位置
	int y,      //字符串在y轴位置
	LPCTSTR str
);
void outtextxy(
	int x,
	int y,
	TCHAR c
);


//——————————————————————3——————输入框
bool InputBox(
	LPTSTR	pString,
	int		nMaxCount,
	LPCTSTR	pPrompt = NULL,
	LPCTSTR	pTitle = NULL,
	LPCTSTR	pDefault = NULL,
	int		width = 0,
	int		height = 0,
	bool	bHideCancelBtn = true
);
//举例：
InputBox(s, 10, "请按输入查找的学生学号");

//
```



## 3.库

```c
#include <stdio.h>   
#include <graphics.h>   //easyx图形库
#include<string.h>
#include<stdlib.h>      //字符串处理函数
```



## 4.函数实现

### 4.1 void Menu()

```c
void Menu{
    welcome();        //进入欢迎页面
    
}
```





