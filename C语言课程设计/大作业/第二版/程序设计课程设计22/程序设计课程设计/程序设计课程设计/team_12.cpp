#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>   
#include <graphics.h>   //easyxͼ�ο�
#include <string.h>
#include <stdlib.h>     //�ַ���������



int page1 = 0;    //��ҳ��
int page2 = 0;    //��ǰҳ��

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
void Menu();                     //�˵����桪����������������������4
void Welcome();                  //��ӭ���桪����������������������1
void view();                     //������ܡ�����������������������6
void write();                    //д�빦��
void search();                   //��������
void modify();                   //�޸Ĺ���
void Search_Sname();             //Search�����µ���������
void Search_Snum();              //Search�����µ�ѧ�Ų���
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


//������
void Menucolorclean();    //�˵�����ƶ�ѡ�����ɫ�ı书�ܡ�����������������������5
void Searchcolorclean();   //��������ƶ�ѡ�����ɫ�ı书��
void Exitcolorclean();    //�˳����߷��ز˵�����ѡ�����ɫ�ı书�� ����汾
void Turnpagelinecolorclean();   //��ҳ��ķ�ҳ�����»�����ɫ�ı书��   �����
void Exitcolorbottomclean();    //�˳����߷��ز˵������»�����ɫ�ı书�� �ײ��汾 ������
void Modifycolorclean();          //�޸��ܽ������ɫ�ı�
void Modify_changecolorclean();     //�޸����8��ѡ��Ľ�����ɫ�ı�

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
		Head->prior->next = Head->next;
		Head->next->prior = Head->prior;

		free(Head);

		writeinto();     //д���ļ�

		outtextxy(286, 100, _T("ɾ���ɹ���"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
	}
	else {                                                                                  //�����д���֪����ô��
		int i = 1;
		node* q;

		q = Head;

		for (i = 1; i < page2; i++) {
			q = q->next;
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
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����

	strcpy(p->Info.Sname, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Snum() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ��ѧ��");//��Ϣ����

	strcpy(p->Info.Snum, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sage() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����

	strcpy(p->Info.Sage, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Ssex() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ���Ա�");//��Ϣ����

	strcpy(p->Info.Ssex, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sbirth() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ������");//��Ϣ����

	strcpy(p->Info.Sbirth, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Stel() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ���绰");//��Ϣ����

	strcpy(p->Info.Stel, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Smail() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ�������ʼ�");//��Ϣ����

	strcpy(p->Info.Smail, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

void Modify_Sscore() {
	char s[10];
	InputBox(s, 10, "�������޸ĵ�ѧ���ɼ�");//��Ϣ����

	strcpy(p->sc.DYgrade, s);    //�޸�
	writeinto();    //д���ļ�

	outtextxy(286, 100, _T("�޸ĳɹ���"));
	Exitandmenumid();      //�˳����߷��ز˵���ѡ��
}

//����������������������������������������������������������������search�����µļ�������

void Search_Sname() {
	int flag = 0;

	node* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("�밴������ҵ�ѧ������"));

	for (p = head; p != NULL; p = p->next) {//β��Ϊ�գ����Բ鵽β������
		if (strcmp(p->Info.Sname, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("ѧ�ţ�"));
			outtextxy(100, 70, p->Info.Snum);
			outtextxy(30, 110, _T("������"));
			outtextxy(100, 110, p->Info.Sname);
			outtextxy(30, 150, _T("���䣺"));
			outtextxy(100, 150, p->Info.Sage);
			outtextxy(30, 190, _T("�Ա�"));
			outtextxy(100, 190, p->Info.Ssex);
			outtextxy(30, 230, _T("���գ�"));
			outtextxy(100, 230, p->Info.Sbirth);
			outtextxy(30, 270, _T("�绰��"));
			outtextxy(100, 270, p->Info.Stel);
			outtextxy(30, 310, _T("���䣺"));
			outtextxy(100, 310, p->Info.Smail);
			outtextxy(30, 350, _T("�ɼ���"));
			outtextxy(100, 350, p->sc.DYgrade);
			Exitandmenubottom();
		}
		if (p->next == NULL) break;
	}
	if (flag == 0) {
		turnpage();   //�Ҳ��������ҳ��
		outtextxy(286, 100, _T("����ʧ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��

	}
}

void Search_Snum() {
	int flag = 0;

	node* head;
	head = create();

	char s[10];
	InputBox(s, 10, _T("�밴������ҵ�ѧ��ѧ��"));

	for (p = head; p != NULL; p = p->next) {//β��Ϊ�գ����Բ鵽β������
		if (strcmp(p->Info.Snum, s) == 0) {
			flag++;
			outtextxy(30, 70, _T("ѧ�ţ�"));
			outtextxy(100, 70, p->Info.Snum);
			outtextxy(30, 110, _T("������"));
			outtextxy(100, 110, p->Info.Sname);
			outtextxy(30, 150, _T("���䣺"));
			outtextxy(100, 150, p->Info.Sage);
			outtextxy(30, 190, _T("�Ա�"));
			outtextxy(100, 190, p->Info.Ssex);
			outtextxy(30, 230, _T("���գ�"));
			outtextxy(100, 230, p->Info.Sbirth);
			outtextxy(30, 270, _T("�绰��"));
			outtextxy(100, 270, p->Info.Stel);
			outtextxy(30, 310, _T("���䣺"));
			outtextxy(100, 310, p->Info.Smail);
			outtextxy(30, 350, _T("�ɼ���"));
			outtextxy(100, 350, p->sc.DYgrade);
			Exitandmenubottom();
		}
		if (p->next == NULL) break;
	}
	if (flag == 0) {
		turnpage();   //�Ҳ��������ҳ��
		outtextxy(286, 100, _T("����ʧ��"));
		Exitandmenumid();      //�˳����߷��ز˵���ѡ��
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

	for (i = page1 - 1; i >= 0; i--) {              //˫����ð������
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

	for (i = page1-1; i >=0; i--) {              //˫����ð������
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

void search()  //�����Ĳ˵�                                                          
{
	rectangle(240, 150, 400, 180);
	outtextxy(286, 157, _T("ѧ������"));
	rectangle(240, 200, 400, 230);
	outtextxy(286, 207, _T("��������"));
	rectangle(240, 250, 400, 280);
	outtextxy(286, 257, _T("ѧ������"));
	rectangle(240, 300, 400, 330);
	outtextxy(286, 307, _T("��������"));
	outtextxy(256, 427, _T("�������ѡ�����")); //������������

	MOUSEMSG m1;  //��ȡ�����Ϣ
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


void write()  //д�����
{
	NODE* head;
	head = create();

	char s[100];
	InputBox(s, 100, "�밴�����¸�ʽ����ѧ����Ϣ\nѧ�� ���� ���� �Ա� ���� ��ַ �绰 �ʼ�");//��Ϣ����

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
	node* head;
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
		fputc('\n', f);          //����
	}
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

void Searchcolorclean()  //�����������ʵʱ���λ�û����β�������һ�λ���Ϊ��ɫ
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

//����������������������������������������������������������������������������������������������Ϣ��ʾ��غ���

void Modifymousemessage() {
	char page3[7];     //�������easyxת���ַ���
	char page4[7];

	sprintf(page3, "%d", page1);
	sprintf(page4, "%d", page2);

	outtextxy(30, 30, _T("��ţ�"));
	outtextxy(100, 30, page4);
	outtextxy(30, 70, _T("ѧ�ţ�"));
	outtextxy(100, 70, p->Info.Snum);
	outtextxy(30, 110, _T("������"));
	outtextxy(100, 110, p->Info.Sname);
	outtextxy(30, 150, _T("���䣺"));
	outtextxy(100, 150, p->Info.Sage);
	outtextxy(30, 190, _T("�Ա�"));
	outtextxy(100, 190, p->Info.Ssex);
	outtextxy(30, 230, _T("���գ�"));
	outtextxy(100, 230, p->Info.Sbirth);
	outtextxy(30, 270, _T("�绰��"));
	outtextxy(100, 270, p->Info.Stel);
	outtextxy(30, 310, _T("���䣺"));
	outtextxy(100, 310, p->Info.Smail);
	outtextxy(30, 350, _T("�ɼ���"));
	outtextxy(100, 350, p->sc.DYgrade);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, page4);
	outtextxy(332, 400, page3);
	outtextxy(256, 427, _T("��һҳ / ��һҳ"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(156, 427, _T("�޸���Ϣ"));
	outtextxy(400, 427, _T("ɾ����Ϣ"));
	line(156, 445, 219, 445);
	line(399, 445, 462, 445);
	outtextxy(242, 455, _T("���ز˵�  �˳�����"));
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

	outtextxy(30, 30, _T("��ţ�"));
	outtextxy(100, 30, page4);
	outtextxy(30, 70, _T("ѧ�ţ�"));
	outtextxy(100, 70, p->Info.Snum);
	outtextxy(30, 110, _T("������"));
	outtextxy(100, 110, p->Info.Sname);
	outtextxy(30, 150, _T("���䣺"));
	outtextxy(100, 150, p->Info.Sage);
	outtextxy(30, 190, _T("�Ա�"));
	outtextxy(100, 190, p->Info.Ssex);
	outtextxy(30, 230, _T("���գ�"));
	outtextxy(100, 230, p->Info.Sbirth);
	outtextxy(30, 270, _T("�绰��"));
	outtextxy(100, 270, p->Info.Stel);
	outtextxy(30, 310, _T("���䣺"));
	outtextxy(100, 310, p->Info.Smail);
	outtextxy(30, 350, _T("�ɼ���"));
	outtextxy(100, 350, p->sc.DYgrade);
	outtextxy(308, 400, _T("/"));
	outtextxy(280, 400, page4);
	outtextxy(332, 400, page3);
	outtextxy(256, 427, _T("��һҳ / ��һҳ"));
	line(256, 445, 303, 445);
	line(315, 445, 360, 445);
	outtextxy(242, 455, _T("���ز˵�  �˳�����"));
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
				break;
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
	outtextxy(250, 227, _T("Good Bye��"));
	outtextxy(256, 427, _T("���������˳�ϵͳ"));
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

void Menu() {
	RECT n2 = { 0,0,640,200 };
	int check[4] = { FALSE };
	drawtext(_T("�˵�"), &n2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);

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

	MOUSEMSG m2;

	while (TRUE) {//ѡȡ��ؾ���λ�ã�̽�����λ�ý���
		m2 = GetMouseMsg();

		//��Ϣ���
		if (m2.x >= 240 && m2.x <= 400 && m2.y >= 150 && m2.y <= 180) {   //ѡȡ���x,y��λ�ã�����ڿ���
			Menucolorclean();//�����б߿�ָ�����ɫ�������µı߿�Ϊ��ɫ
			rectangle(240, 150, 400, 180);//���µı߿�
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[0] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 200 && m2.y <= 230) {//��Ϣ¼��
			Menucolorclean();
			rectangle(240, 200, 400, 230);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[1] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 250 && m2.y <= 280) {//��Ϣ��ѯ
			Menucolorclean();
			rectangle(240, 250, 400, 280);
			if (m2.uMsg == WM_LBUTTONDOWN) {
				check[2] = TRUE;
				break;
			}
		}
		else if (m2.x >= 240 && m2.x <= 400 && m2.y >= 300 && m2.y <= 330) {//��Ϣ�޸�
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
		search();
	}
	else if (check[3]) {//��Ϣ�޸�
		//modify();
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

	drawtext(_T("��ӭ����ѧ����Ϣ����ϵͳ"), &n1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//���б���
	outtextxy(256, 427, _T("���������˳�ϵͳ"));

	Continuetobe();
}

void main() {
	initgraph(640, 480);

	Welcome();

	Menu();

	EXIT();

}