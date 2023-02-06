#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>   
#include <graphics.h>   //easyxͼ�ο�
#include <string.h>
#include <stdlib.h>     //�ַ���������



int page1 = 0;    //��ҳ��
int page2 = 0;    //��ǰҳ��
int root = 0;     //�Ƿ�������˽�ʦ�˺�
int key = 0;      //�ж��ǲ����ɽ�ʦ�ķ���

typedef struct StudentInfo {
	char Sname[20];     //ѧ������
	char Snum[80];
	char Sage[80];
	char Ssex[8];
	char Sbirth[60];
	char Stel[60];
	char Smail[90];
};

typedef struct StudentScore {
	char GSgrade[30];     //�ߵ���ѧ
	char DYgrade[30];     //��ѧӢ��
	char XDgrade[30];     //���Դ���
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

//�������
NODE* create(); //�����������ļ�������������ͷָ�� ֻ��
void writeinto();    //�Ѹ��ºõ�����д���ļ� ֻд


//n�����������
//		n1:welcome()
//		n2:Menu()
//m�������ָ��
//		m1:Menu()
//		   Exitandmenumid()


//���ι��ܺ���
void Login(int a);
void Menu();                     //�˵����桪����������������������4
void Menu_Student();
void Menu_Teacher();
void Welcome();                  //��ӭ���桪����������������������1
void view();                     //������ܡ�����������������������6
void write();                    //д�빦��
void search_T();                 //��������_��ʦ��
void modify();                   //�޸Ĺ���
void Search_Sname();             //Search�����µ���������
void Search_Snum_S();              //Search�����µ�ѧ�Ų���_ѧ����
void Search_Snum_T();              //Search�����µ�ѧ�Ų���_��ʦ��
void Search_Snameorder();        //Search�����µ���������
void Search_Snumorder();         //Search�����µ�ѧ������
void Modify_all();            //Modify�����µ��޸Ĺ���
void Modify_delete();            //Modify�����µ�ɾ������

//�޸�ѧ����Ϣ�ĺ���
void Modify_Sname();
void Modify_Snum();
void Modify_Sage();
void Modify_Ssex();
void Modify_Sbirth();
void Modify_Stel();
void Modify_Smail();
void Modify_Sscore();


//��ι��ܺ���
void turnpage();                 //��ת���桪������������������������3
void Continuetobe();         //������������ܡ�����������������������2
void Exitandmenumid();       //����˳����߷��ز˵����� ����汾������������������������������������
void Exitandmenubottom();    //����˳����߷��ز˵�  �ײ��汾
void Turnpage_last();        //�����һҳ��һҳ��ҳ
void Turnpage_next();
void Viewmousemessage();     //�������������Ϣ��� ���л�ͼ ��ӡ������������������������
void Modifymousemessage();   //�޸Ľ���������Ϣ���c ��ͼ ��ӡ  �����޸�/ɾ������!!!
void Turnpage_Biglast();     //�������+�޸�ɾ���Ĵ�ҳ �����޸ĺ���
void Turnpage_Bignext();
void EXIT();                 //�����˳��ĺ���
int Judge();
void Turn(int a);


//������
void Menucolorclean_Menu();    //�˵�����ƶ�ѡ�����ɫ�ı书�ܡ�����������������������5
void Menucolorclean_Student();    //�˵�����ƶ�ѡ�����ɫ�ı书�ܣ�ѧ�����桪����������������������5
void Menucolorclean_Teacher();    //�˵�����ƶ�ѡ�����ɫ�ı书�ܣ���ʦ���桪����������������������5
void Searchcolorclean();  //��������ƶ�ѡ�����ɫ�ı书��_��ʦ��
void Searchcolorclean_S();//��������ƶ�ѡ�����ɫ�ı书��_ѧ����
void Exitcolorclean();    //�˳����߷��ز˵�����ѡ�����ɫ�ı书�� ����汾
void Turnpagelinecolorclean();   //��ҳ��ķ�ҳ�����»�����ɫ�ı书��   �����
void Exitcolorbottomclean();    //�˳����߷��ز˵������»�����ɫ�ı书�� �ײ��汾 ������
void Modifycolorclean();          //�޸��ܽ������ɫ�ı�
void Modify_changecolorclean();     //�޸����8��ѡ��Ľ�����ɫ�ı�

//������Ϣ
#define UI1()                               \
	outtextxy(150, 70, _T("ѧ�ţ�"));       \
	outtextxy(200, 70, p->Info.Snum);      \
	outtextxy(30, 70, _T("������"));        \
	outtextxy(80, 70, p->Info.Sname);      \
	outtextxy(30, 110, _T("���䣺"));       \
	outtextxy(80, 110, p->Info.Sage);		\
	outtextxy(300, 70, _T("�Ա�"));		\
	outtextxy(350, 70, p->Info.Ssex);		\
	outtextxy(150, 110, _T("���գ�"));		\
	outtextxy(200, 110, p->Info.Sbirth);	\
	outtextxy(30, 150, _T("�绰��"));		\
	outtextxy(80, 150, p->Info.Stel);		\
	outtextxy(30, 190, _T("���䣺"));		\
	outtextxy(80, 190, p->Info.Smail);		\
	outtextxy(30, 230, _T("�ɼ���"));		\
	outtextxy(100, 270, _T("��ѧӢ��"));		\
	outtextxy(120, 310, p->sc.DYgrade);		\
	outtextxy(190, 270, _T("�ߵ���ѧ"));		\
	outtextxy(210, 310, p->sc.GSgrade);		\
	outtextxy(280, 270, _T("���Դ���"));		\
	outtextxy(300, 310, p->sc.XDgrade);		\
	
#define UI2()								\
	outtextxy(30, 30, _T("��ţ�"));        \
	outtextxy(80, 30, page4);              \
	UI1()									\
	outtextxy(308, 400, _T("/"));			\
	outtextxy(280, 400, page4);				\
	outtextxy(332, 400, page3);				\
	outtextxy(256, 427, _T("��һҳ / ��һҳ"));	\
	line(256, 445, 303, 445);					\
	line(315, 445, 360, 445);					\
	outtextxy(242, 455, _T("���ز˵�  �˳�����"));	\
	line(242, 473, 304, 473);						\
	line(315, 473, 377, 473);						\

#define judge()
    
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������
//������������������������������������������������������������������������������������������������������������������������������������������������������������������������

NODE* create() {
	FILE* fp;
	fp = fopen("Info.txt", "r");//ֻ�����ļ�

	NODE* p1;//��ǰ
	NODE* tail;//β
	NODE* head;

	head = NULL;
	tail = NULL;

	p1 = (NODE*)malloc(sizeof(NODE));

	if (fgetc(fp)==EOF) {
		return NULL;
	}

	rewind(fp);//ָ���Ƶ��ļ�ͷ����Ȼ�Ļ������ȡ˳��ʹ���һλ

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

//����������������������������������������������������������������Modify�޸ĵ�����

void Modify_all()
{
	rectangle(140, 150, 300, 180); 
	rectangle(340, 150, 500, 180);
	outtextxy(186, 157, _T("�޸�ѧ��")); 
	outtextxy(386, 157, _T("�޸�����"));
	rectangle(140, 200, 300, 230); 
	rectangle(340, 200, 500, 230);
	outtextxy(186, 207, _T("�޸�����")); 
	outtextxy(386, 207, _T("�޸��Ա�"));
	rectangle(140, 250, 300, 280); 
	rectangle(340, 250, 500, 280);
	outtextxy(186, 257, _T("�޸�����")); 
	outtextxy(386, 257, _T("�޸ĵ绰"));
	rectangle(140, 300, 300, 330); 
	rectangle(340, 300, 500, 330);
	outtextxy(186, 307, _T("�޸�����")); 
	outtextxy(386, 307, _T("�޸ĳɼ�"));
	outtextxy(256, 427, _T("�������ѡ�����"));

	MOUSEMSG m1;  //��ȡ�����Ϣ
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

void Modify_delete()  //ɾ������
{
	if (page2 == 1) {
		NODE* q = Head;
		Head = q->next;
		q->prior->next = q->next;
		q->next->prior = q->prior;

		free(q);

		writeinto();     //д���ļ�

		outtextxy(286, 100, _T("ɾ���ɹ���"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
	else {                                                                                  //�����д���֪����ô��
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

		writeinto();     //д���ļ�

		outtextxy(286, 100, _T("ɾ���ɹ���"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
}


void Modify_Sname() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sname, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Snum() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ��ѧ��");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	RECT n3 = { 0,0,640,200 };
	int a = -1, flag = 0;
    NODE* head;
	a = -1;
	head = create();
	for (p = head; ; p = p->next) {   //��ѧ��
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
		drawtext(_T("��ѧ���Ѵ��ڣ�"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Exitandmenumid();
	}

	strcpy(p->Info.Snum, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sage() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sage, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Ssex() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ���Ա�");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	strcpy(p->Info.Ssex, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sbirth() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	strcpy(p->Info.Sbirth, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Stel() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ���绰");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}

	strcpy(p->Info.Stel, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Smail() {
	char s[50] = { 0 };
	char s1[50];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����
	if (sscanf(s, "%s", s1) != 1) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}
	strcpy(p->Info.Smail, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sscore() {
	char s[50] = { 0 };
	char s1[50],s2[50],s3[50] = { 0 };
	InputBox(s, 50, "�������޸ĵ�ѧ���ɼ�����Ӣ���ߴ���������");//��Ϣ����
	if (sscanf(s, "%s %s %s", s1,s2,s3) != 3) {
		outtextxy(286, 100, _T("�޸�ʧ�ܣ�"));
		Exitandmenumid();
	}
	strcpy(p->sc.DYgrade, s1);    //
	strcpy(p->sc.XDgrade, s2);
	strcpy(p->sc.GSgrade, s3);
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

//����������������������������������������������������������������search�����µļ�������

void Search_Sname() {
	int flag = 0;
	int a = -1;

	NODE* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("�밴������ҵ�ѧ������"));

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
		turnpage();   //�Ҳ��������ҳ��
		outtextxy(286, 100, _T("����ʧ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
}

void Search_Snum_T() {
	int flag = 0;
	int a = -1;

	NODE* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("�밴������ҵ�ѧ������"));

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
		turnpage();   //�Ҳ��������ҳ��
		outtextxy(286, 100, _T("����ʧ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
}

void Search_Snum_S() {
	RECT n3 = { 0,0,640,200 };
	char s[100];
	
	int flag = 0;
	int a = -1;
	int cnt = 0;
	NODE* head;

	while (root != 1 && cnt < 3)        //���ǽ�ʦȨ�ޣ������������ҪС��3��
	{
		InputBox(s, 100, "������ѧ��ѧ��");
	    int lenth = strlen(s) + 1;
		a = -1;
		head = create();
		for (p = head; ; p = p->next) {   //��ѧ��
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

		if (flag == 0) {              //�ж�ѧ�źϷ���
			drawtext(_T("�����ڴ��˻���"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else
		{
			cleardevice();
			char c[100];
			InputBox(c, 100, "����������");
			flag = 0;
			for (int i = 0; i < lenth; i++)
			{
				if (c[i] != s[i]) flag = 1;
				if (flag) break;
			}
			if (flag) drawtext(_T("�������"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			else break;
		}
		cnt++;
	}

    if (flag != 0) {
		turnpage();   //�Ҳ��������ҳ��
		outtextxy(286, 100, _T("����ʧ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
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

void search_T()  //�����Ĳ˵�                                                          
{
	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("ѧ������"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("��������"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("ѧ������"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("��������"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("�����ϲ�"));
	outtextxy(256, 427, _T("�������ѡ�����")); //������������

	MOUSEMSG m1;  //��ȡ�����Ϣ
	char check[4] = { FALSE };

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 150 && m1.y <= 180) {//ѧ��
			Searchcolorclean();
			rectangle(240, 150, 400, 180);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {//����
			Searchcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {//ѧ������
			Searchcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 300 && m1.y <= 330) {//��������
			Searchcolorclean();
			rectangle(240, 300, 400, 330);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check[3] = TRUE;
				break;
			}
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 350 && m1.y <= 380) {//�����ϲ�
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


void write()  //д�����
{
	NODE* head;
	head = create();

	char s[100] = { 0 };
	char s1[100], s2[100], s3[100], s4[100], s5[100], s6[100], s7[100], s8[100], s9[100], s10[100] = { 0 };
	InputBox(s, 100, "�밴�����¸�ʽ����ѧ����Ϣ\n���� ѧ�� ���� �Ա� ���� �绰 �ʼ� �����ɼ� ��Ӣ�ɼ� �ߴ��ɼ�");//��Ϣ����
    if (sscanf(s, "%s %s %s %s %s %s %s %s %s %s", s1,s2,s3,s4,s5,s6,s7,s8,s9,s10) != 10) {
	   	outtextxy(286, 100, _T("¼��ʧ�ܣ�"));
		Exitandmenumid();
	}

	RECT n3 = { 0,0,640,200 };
	int a = -1, flag = 0;
	a = -1;
	head = create();
	for (p = head; ; p = p->next) {   //��ѧ��
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
		drawtext(_T("��ѧ���Ѵ��ڣ�"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		Exitandmenumid();
	}

	FILE* f;   //���ļ�
	f = fopen("Info.txt", "a");
	if (head != NULL)
		fputc('\n', f);  //����
	fputs(s, f);
	if (fclose(f))
	{
		outtextxy(283, 207, _T("����ʧ�ܣ�"));
		exit(1);
	}
	outtextxy(283, 207, _T("����ɹ���"));

	outtextxy(256, 427, _T("�������λ�ü���"));
	Continuetobe();
	Exitandmenumid();
}

void modify(){
	NODE* head;
	head = create();

	if (head == NULL) {        //����ļ�Ϊ�� 
		outtextxy(286, 100, _T("��ϢΪ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
	else {
		p = Head;
		turnpage();//��ת���� 
		Modifymousemessage();
	}
}

void writeinto()      //������д���ļ�
{
	FILE* f;   //���ļ�
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
		fputc('\n', f);          //����
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

//������������������������������������������������������������������������������������������ҳ��غ���

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
		turnpage();   //��ս���
		Modifymousemessage();
	}
}

void Turnpage_Biglast()
{
	if (page2 == 1) {    //ҳ��Ϊ1ʱ����һҳ
		page2 = page1;    //����ҳ�����
		p = Last;    //�޸ĵ�ǰָ��
		turnpage();   //��ս���

		Modifymousemessage();  //һ�������ڶ�ĺ���
	}
	else {
		page2--;
		turnpage();   //��ս���

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
	if (page2 == 1) {//�ڵ�һ��Ļ���ǰһ�淭ҳ�����һ�棬����ѭ������β���ÿգ�����p=Last
		p = Last;
		page2 = page1;
	}
	else {
		p = p->prior;
		page2--;
	}
}

//����������������������������������������������������������������ɫ�޸���صĺ���

void Modify_changecolorclean()    //�޸ĵ�8��ѡ��������λ����ɫ�ı�
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

void Exitcolorbottomclean()   //�ײ���ť���ز˵���ɫ�ı�
{
	setlinecolor(WHITE);
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);
	setlinecolor(BLUE);
}

void Exitcolorclean()  //�˳��뷵�ز˵��������ʵʱ���λ�û����β�������һ�λ���Ϊ��ɫ
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

void Searchcolorclean()  //�����������ʵʱ���λ�û����β�������һ�λ���Ϊ��ɫ
{
	setlinecolor(WHITE);
	rectangle(240, 150, 400, 180);
	rectangle(240, 200, 400, 230);
	rectangle(240, 250, 400, 280);
	rectangle(240, 300, 400, 330);
	rectangle(240, 350, 400, 380);
	setlinecolor(BLUE);
}

void Searchcolorclean_S()  //�����������ʵʱ���λ�û����β�������һ�λ���Ϊ��ɫ
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

//����������������������������������������������������������������������������������������������Ϣ��ʾ��غ���

void Modifymousemessage() {
	char page3[7];     //�������easyxת���ַ���
	char page4[7];

	sprintf(page3, "%d", page1);
	sprintf(page4, "%d", page2);

	UI2();
	
	outtextxy(156, 427, _T("�޸���Ϣ"));
	outtextxy(400, 427, _T("ɾ����Ϣ"));
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
	turnpage();//��ת���� 

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
	char page3[7];     //�������easyxת���ַ���
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
	turnpage();//��ת���� 

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

//������������������������������������������������������������������������������������Exit���

void Exitandmenubottom()
{
	outtextxy(242, 455, _T("���ز˵�  �˳�����"));
	line(242, 473, 304, 473);
	line(315, 473, 377, 473);    //��ͼ

	MOUSEMSG m1;  //��ȡ�����Ϣ
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
	turnpage();//��ת���� 

	if (flag) {
		page2 = 0;
		page1 = 0;
		Menu();
	}
}

void Exitandmenumid() {//�˳����߷��ز˵�ҳ��
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("���ز˵�"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("�˳�����"));
	outtextxy(256, 427, _T("�������ѡ�����"));

	MOUSEMSG m1;     //��ȡ���ʵʱ��Ϣ
	int check = FALSE;

	while (TRUE) {
		m1 = GetMouseMsg();
		if (m1.x >= 240 && m1.x <= 400 && m1.y >= 200 && m1.y <= 230) {
			Exitcolorclean();
			rectangle(240, 200, 400, 230);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				check= TRUE;
				break;
			}  //��⵽��� �˳�
		}
		else if (m1.x >= 240 && m1.x <= 400 && m1.y >= 250 && m1.y <= 280) {
			Exitcolorclean();
			rectangle(240, 250, 400, 280);
			if (m1.uMsg == WM_LBUTTONDOWN) {
				break;
			}
		}
		else Exitcolorclean();   //����ڿ����� �ָ�������ɫ
	}
	turnpage();

	if (check) {  //���ز˵��Ļ�
		page1 = 0;
		page2 = 0;
		Menu();    //ǰ���˵�
	}//����ֱ�Ӳ��ж��Ƿ�ѡ���˳�����Ϊ�����в��ж������Ļ�ֱ�ӻ���ת��main��������ҳ��
}

void EXIT() {
	turnpage();
	LOGFONT a;
	gettextstyle(&a);
	settextstyle(100, 0, _T("Consolas"));
	outtextxy(120, 177, _T("Good Bye��"));
	settextstyle(30, 0, _T("Consolas"));
	outtextxy(180, 427, _T("���������˳�ϵͳ"));
	settextstyle(&a);
	Continuetobe();
	closegraph();
	exit(0);
}

void view() {//�����Ϣ
	NODE* head;
	head = create();

	if (head == NULL) {
		outtextxy(286, 100, _T("��ϢΪ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
	else {
		p = head;
		turnpage();   //�����ʾѧ����Ϣ
		while (true) {
			Viewmousemessage();
		}
	}
}

//������������������������������������������������������������������������������������main�г��ֵĺ���
void Login(int m)
{
	//1��ʾ������ʦϵͳ��½
	//2��ʾ����ѧ��ϵͳ��½
	int cnt = 0;
	while (root != 1 && cnt < 3)
	{
		RECT n3 = { 0,0,640,200 };
		char s[100];
		char s1[5];
		if (m == 1)
		{
            InputBox(s, 100, "�������ʦ�˻�");
			if (s[0] == 'S' && s[1] == 'i' && s[2] == 'r')
			{
				cleardevice();
				char c[100];
				InputBox(c, 100, "����������");
				if (c[0] == 'S' && c[1] == 'i' && c[2] == 'r') break;
				else drawtext(_T("�������"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
			}
			else drawtext(_T("�����ڴ��˻���"), &n3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
		}
		else 
		{
            
		}
		cnt++;
	}
	if (cnt >= 3)
	{
		RECT n1 = { 0,0,640,480 };//��������ָ��

		drawtext(_T("�����������Σ������½��룡"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//���б���
		outtextxy(256, 427, _T("������������"));

		Continuetobe();
		Menu();
	}
	cleardevice();
}

void Menu_Student() {
	RECT n4 = { 0,0,640,200 };
	int check[4] = { FALSE };
	drawtext(_T("�˵�"), &n4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("��Ϣ��ѯ"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("�����ϲ�"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("�˳�����"));
	outtextxy(256, 427, _T("�������ѡ�����"));    //�˵���ҳ��

	MOUSEMSG m4;

	while (TRUE) {//ѡȡ��ؾ���λ�ã�̽�����λ�ý���
		m4 = GetMouseMsg();

		if (m4.x >= 240 && m4.x <= 400 && m4.y >= 150 && m4.y <= 180) {//��Ϣ��ѯ
			Menucolorclean_Student();
			rectangle(240, 150, 400, 180);
			if (m4.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m4.x >= 240 && m4.x <= 400 && m4.y >= 250 && m4.y <= 280) {//�ϼ��˵�
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
		else Menucolorclean_Student();//ȫ����ذ�ɫ
	}

	turnpage();
    if (check[1]) {//��Ϣ��ѯ
		key = 0;
		Search_Snum_S();
	}
	else if (check[2]) {//������һ��
		Turn(1);
	}
}

void Menu_Teacher() {
	Login(1);
	RECT n3 = { 0,0,640,200 };
	int check[4] = { FALSE };

	root = 1;
	drawtext(_T("�ѻ�ý�ʦȨ�ޣ�������˵�"), &n3, DT_CENTER | DT_VCENTER| DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("��Ϣ���"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("��Ϣ¼��"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("��Ϣ��ѯ"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("��Ϣ�޸�"));
	rectangle(240, 350, 400, 380);
	outtextxy(286, 357, _T("�˳�����"));
	outtextxy(256, 427, _T("�������ѡ�����"));    //�˵���ҳ��

	MOUSEMSG m3;

	while (TRUE) {//ѡȡ��ؾ���λ�ã�̽�����λ�ý���
		m3 = GetMouseMsg();

		//��Ϣ���
		if (m3.x >= 240 && m3.x <= 400 && m3.y >= 150 && m3.y <= 180) {   //ѡȡ���x,y��λ�ã�����ڿ���
			Menucolorclean_Teacher();//�����б߿�ָ�����ɫ�������µı߿�Ϊ��ɫ
			rectangle(240, 150, 400, 180);//���µı߿�
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 200 && m3.y <= 230) {//��Ϣ¼��
			Menucolorclean_Teacher();
			rectangle(240, 200, 400, 230);
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 250 && m3.y <= 280) {//��Ϣ��ѯ
			Menucolorclean_Teacher();
			rectangle(240, 250, 400, 280);
			if (m3.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m3.x >= 240 && m3.x <= 400 && m3.y >= 300 && m3.y <= 330) {//��Ϣ�޸�
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
		else Menucolorclean();//ȫ����ذ�ɫ
	}

	turnpage();

	if (check[0]) {//��Ϣ���
		view();
	}
	else if (check[1]) {//��Ϣд��
		write();
	}
	else if (check[2]) {//��Ϣ��ѯ
		key = 2;
		search_T();
	}
	else if (check[3]) {//��Ϣ�޸�
		modify();
	}
}

void Menu() {
	RECT n2 = { 0,0,640,200 };
	int check[2] = { FALSE };
	drawtext(_T("��ѡ������ϵͳ"), &n2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("��ʦϵͳ"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("ѧ��ϵͳ"));

	MOUSEMSG m2;

	while (TRUE) {//ѡȡ��ؾ���λ�ã�̽�����λ�ý���
		m2 = GetMouseMsg();

		//��Ϣ���
		if (m2.x >= 240 && m2.x <= 400 && m2.y >= 150 && m2.y <= 180) {   //ѡȡ���x,y��λ�ã�����ڿ���
			Menucolorclean_Menu();//�����б߿�ָ�����ɫ�������µı߿�Ϊ��ɫ
			rectangle(240, 150, 400, 180);//���µı߿�
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 200 && m2.y <= 230) {//��Ϣ¼��
			Menucolorclean_Menu();
			rectangle(240, 200, 400, 230);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else Menucolorclean_Menu();//ȫ����ذ�ɫ
	}

	turnpage();

	if (check[0]) {//�����ʦϵͳ
		Menu_Teacher();
	}
	else if (check[1]) {//����ѧ��ϵͳ
		Menu_Student();
	}
}

void turnpage() {
	cleardevice();//easyx�����ҳ�溯��
	setlinecolor(WHITE);//���û�����ɫ
}

void Continuetobe() {
	MOUSEMSG m0;
	while (m0 = GetMouseMsg(), m0.uMsg != WM_LBUTTONDOWN) continue;
	turnpage();
}

void Welcome() {
	RECT n1 = { 0,0,640,480 };//��������ָ��

	LOGFONT a;
	gettextstyle(&a);

	settextstyle(30,0, _T("Consolas"));
	drawtext(_T("��ӭ����ѧ����Ϣ����ϵͳ"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//���б���
	outtextxy(180, 427, _T("������������ϵͳ"));
	settextstyle(&a);
	

	Continuetobe();
}

void main() {
	initgraph(640, 480);

	Welcome();

	Menu();

	EXIT();

}