#include"stdio.h"
#include"stdlib.h"
#include"string.h" 

struct book {//ͼ����Ϣ�ṹ�嶨��
	char cate[10];//���
	char book[25];//����
	char author[25];//������
	char num[25];//ͼ����
	int date[3];//�������ڣ��� �� �գ�
	float price;//��ļ۸�
	struct book * next;
};

typedef struct book BOOK;

BOOK *head;//ͷָ��Ϊȫ�ֱ��������ڷ���

void Pass();//��¼�����֤
void Login_MFace();//��¼����
void Insert_Data();//���뺯��
void Input_Data();//¼��ͼ����Ϣ
void Save_Data();//������Ϣ���ļ���
void Up_Data();//���ļ��ж�ȡ��Ϣ����������
void Search_Infor();//���Һ���
void S_key(BOOK *q);//�������ߣ���������ţ������ؼ��ֲ��ң����ڽ���м�������
void S_Date();//�����ڲ���
void display(BOOK * p);//��pָ����ָͼ����Ϣ��ʾ����
void Sort_Data();//������
void Sort_num();//����ͼ��������
void Sort_Cate();//����ͼ���������
void Sort_Date();//����ͼ����������
void Sort_Book();//������������ 
void Modify_Data();//�޸���Ϣ����
void Modify_key(int j);//���չؼ��֣��������������������޸�
void Delete();//ɾ��ĳ��ͼ�����Ϣ
void PRINT(BOOK * p);//����pָ����ָͼ���������Ϣ

int main() {
	BOOK * j;
	int  m,n;
	int flag = 1;
	int choice;
	printf("\n\n\t\t\tд��ʹ��ǰ��\n");
	printf("\t\t\t��¼���û����������Ϊ 000000 �������㣩\n\n\n ");
	system("pause");
	system("cls");
	printf("\n��ӭʹ��ͼ�����ϵͳ��\n");
	Pass();
	head = NULL;
	system("cls");
	printf("\n\n��ѡ���������뷽ʽ��\n1->�ֶ�����\n2->�ļ�����\n");
	scanf("%d", &n);
	while (n != 1 && n != 2) {
		printf("\n�����������������루1-2����");
		scanf("%d", &n);
	}
	if (n == 1) Input_Data();
	if (n == 2) Up_Data();

	fflush(stdin);
	while (flag) {
		Login_MFace();
		scanf("%d", &m);
		switch (m) {
		case 0:
			printf("\n�Ƿ񱣴����������ݣ�\n");
			printf("1. ��\n");
			printf("2. ��\n");
			scanf("%d", &choice);
			while (choice != 1 && choice != 2) {
				printf("\n�����������������루1-2����");
				scanf("%d", &choice);
			}
			switch (choice) {
			case 1:Save_Data();break;
			case 2:break;
			}

			flag = 0;break;
		case 1:  printf("\nȫ��ͼ����ϢΪ��\n");
			printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
			for (j = head;j != NULL;j = j->next)
				display(j);
			break;
		case 2: Search_Infor(); break;
		case 3: Sort_Data();break;
		case 4: Modify_Data();break;
		case 5: Delete();break;
		case 6: Insert_Data();break;
		case 7: Save_Data(); break;
		default:printf("\n\nѡ���������������");Login_MFace();break;
		};
		system("pause");
	}
	return 0;
}

void Pass() {
	int i = 0, j = 0;
	char ch;
	char name[10], password[10];
	while (i < 3) {
		printf("\n\t\t\t�û�����");
		gets(name);
		printf("\n\t\t\t��  �룺");
		gets(password);
		if (!strcmp(name, "000000") && !strcmp(password, "000000")) {
			printf("\n\t\t\t��½�ɹ���\n\n");
			system("pause");
			return;
		}
		else {
			printf("\n\t\t\t��½ʧ�ܣ��㻹��%d�λ���\n", 2 - i);
			i++;
		}
	}
	printf("\n\t\t\t���Դ��������꣬���ѱ�ǿ���˳�");
	exit(0);
}

void Login_MFace() {
	system("cls");
	printf("�������ʾѡ����Ӧ�Ĳ�����\n\t\t");
	printf("1------��ʾȫ��ͼ����Ϣ\n\t\t");
	printf("2------��ѯͼ����Ϣ\n\t\t");
	printf("3------����\n\t\t");
	printf("4------�޸�ͼ����Ϣ\n\t\t");
	printf("5------ɾ��ͼ����Ϣ\n\t\t");
	printf("6------���ͼ����Ϣ\n\t\t");
	printf("7------������Ϣ\n\t\t");
	printf("0------�˳�\n\t\t");
	return;
}

void Insert_Data() {
	system("cls");
	char ch;
	int flag = 1;
	BOOK *p;
	p = head;
	printf("\n�밴��ʾ��������ͼ�����Ϣ��\n");
	while (flag) {
		system("cls");
		p = (BOOK *)malloc(sizeof(BOOK));
		if (p == NULL)		//�ڵ㿪�ٲ��ɹ�
		{
			printf("\n������ʧ�ܣ����Ժ����ԣ�\n");
			return;
		}
		PRINT(p);//¼������
		p->next = head;
		head = p;
		if (p != NULL)
			printf("\n����ɹ���\n");
		printf("\n�Ƿ��������?��Y/N)\n");
		fflush(stdin);
		scanf("%c", &ch);
		while (ch != 'Y'&&ch != 'N') {
			printf("\n����������������룺");
			fflush(stdin);
			scanf("%s", &ch);
		}
		switch (ch) {
		case 'Y':break;
		case'N':flag = 0;break;
		}
	}
	return;
}

void Input_Data() {
	int n = 1;//�ж�������ǵڼ���ͼ�� 
	int flag = 1;//ѭ������ 
	char ch;
	BOOK * p1;
	p1 = NULL;
	head = NULL;

	head = (BOOK *)malloc(sizeof(BOOK));	//����һ���½ڵ�
	head->next = NULL;

	if (head == NULL)		//�ڵ㿪�ٲ��ɹ�
	{
		printf("\n������ʧ�ܣ����Ժ����ԣ�\n");
		return;
	}

	while (flag)
	{//ѭ������
		if (n == 1) {
			printf("\t\t����ͼ����Ϣ\n\t\t�������%d��ͼ�����Ϣ��\n", n);
			PRINT(head);

		}
		else {
			p1 = (BOOK *)malloc(sizeof(BOOK));
			printf("\t\t����ͼ����Ϣ\n\t\t�������%d��ͼ�����Ϣ��\n", n);
			PRINT(p1);
			p1->next = head;
			head = p1;
		}
		n++;
		printf("�Ƿ����¼�룿(Y/N)\n");
		fflush(stdin);//��������� 
		scanf("%s", &ch);
		while (ch != 'Y'&&ch != 'N') {
			printf("\n����������������룺");
			scanf("%s", &ch);
		}
		switch (ch) {
		case 'Y':break;
		case'N':flag = 0;break;
		}
		system("cls");
	}
}

void Save_Data() {
	FILE * fp;
	BOOK * p;
	if ((fp = fopen("E:\\ͼ�����ϵͳ\\BookData.txt", "w")) == NULL) {
		printf("\n�޷����ļ�\n");
		exit(1);
	}
	p = head;
	do {
		fprintf(fp, "%12s %20s %12s %10.2f %4d %2d %2d    %10s\n", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
		p = p->next;
	} while (p->next != NULL);//��֤�ļ����һ���ַ����ǻ��з�������˶�ȡ����ʱ���з������� 
	fprintf(fp, "%12s %20s %12s %10.2f %4d %2d %2d    %10s", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
	printf("\n����ɹ���\n");
	fclose(fp);

}

void Up_Data() {
	int n = 1;
	char ch;
	FILE * fp;
	BOOK * p, *q;
	if ((fp = fopen("E:\\ͼ�����ϵͳ\\BookData.txt", "r")) == NULL) {
		printf("\n�޷����ļ�\n");
		exit(1);
	}
	p = (BOOK*)malloc(sizeof(BOOK));
	p->next = NULL;
	while (!feof(fp)) {
		if (n == 1) {
			fscanf(fp, "%s%s%s%f%d%d%d%s", p->num, p->book, p->author, &p->price, &p->date[0], &p->date[1], &p->date[2], p->cate);
		}
		else {
			q = (BOOK*)malloc(sizeof(BOOK));
			fscanf(fp, "%s%s%s%f%d%d%d%s", q->num, q->book, q->author, &q->price, &q->date[0], &q->date[1], &q->date[2], q->cate);
			q->next = p;
			p = q;
		}
		n += 1;
	}
	head = p;
	fclose(fp);
	printf("\n\n�ļ���ȡ�ɹ���\n\n");
	system("pause");
	system("cls");

}

void Search_Infor() {
	int choice;
	system("cls");
	printf("��ѡ����ҷ�ʽΪ��\n");
	printf("\t\t1.ͨ���ؼ��ֲ���\n");
	printf("\t\t2.ͨ�����ڲ���\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n�����������������루1-2����");
		fflush(stdin);//��������� 
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:S_key(head);break;
	case 2:S_Date();break;
	}
	return;
}

void S_Date() {
	system("cls");

	BOOK *p;
	p = NULL;
	int y, m, d;
	int n = 0;//��¼���ҵ���ͼ��ı���
	int choice;
	printf("\n���������ڣ��������Կո��������");
	scanf("%d%d%d", &y, &m, &d);
	p = head;//�ޱ�ͷ�ڵ������ 
	if (p == NULL) {
		printf("\n�ձ���ͼ�����ݣ�");
	}
	else {

	}
	while (p != NULL) {
		if (p->date[0] == y&&p->date[1] == m&&p->date[2] == d) {
			if (n == 0) {
				printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
			}
			display(p);
			n++;
		}
		p = p->next;
	}
	if (n == 0) {
		printf("\n�޴�ͼ�����Ϣ\n");
	}
	printf("\n�Ƿ�������ң�\n");
	printf("1. ��\n");
	printf("2. ��\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n�����������������루1-2����");
		fflush(stdin);
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Search_Infor();break;
	case 2:return;
	}
	return;
}

void S_key(BOOK * q) {
	system("cls");
	BOOK *p, *r, *head1;
	head1 = NULL;//��ʼ������
	p = NULL;
	char key[20];
	int choice;
	int n = 0;//��¼���ҵ���ͼ�����Ŀ
	printf("������ؼ��֣�\n");
	scanf("%s", key);
	p = q;//�ޱ�ͷ�ڵ������ 
	if (p == NULL) {
		printf("\n�ձ���ͼ�����ݣ�");
	}
	while (p != NULL) {
		if (strstr(p->num, key) != NULL || strstr(p->book, key) != NULL || strstr(p->author, key) != NULL) {
			r = (BOOK *)malloc(sizeof(BOOK));
			*r = *p;
			if (n == 0) {
				printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
				r->next == NULL;
				head1 = r;
			}
			else {
				r->next = head1;
				head1 = r;
			}
			n += 1;
			display(p);
		}
		p = p->next;
	}

	if (n == 0) {
		printf("\n�޴�ͼ�����Ϣ\n");
	}
	printf("�Ƿ��ڽ���м������ң�\n");
	printf("1. ��\n");
	printf("2. ��\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n�����������������루1-2����");
		fflush(stdin);
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:S_key(head1);break;
	case 2:return;
	}
	return;
}

void display(BOOK * p) {
	printf("%-12s%-20s%-12s%-10.2f%-4d��%-2d��%-2d��    %-10s\n", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
	return;
}

void Sort_Data() {
	int choice;
	system("cls");
	printf("����ʽΪ��\n");
	printf("\t\t1.������������\n");
	printf("\t\t2.����ͼ���������\n");
	printf("\t\t3.���ձ�Ž�������\n");
	printf("\t\t4.���ճ�����������\n");
	scanf("%d", &choice);
	while (choice < 1 || choice>4) {
		printf("\n�����������������루1-4����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Sort_Book();break;
	case 2:Sort_Cate();break;
	case 3:Sort_num();break;
	case 4:Sort_Date();break;
	}
    printf("\n����ɹ�\n\n");
}

void Sort_Book() {
	BOOK *endpt;	  //����ѭ���Ƚ�
	BOOK *p;		  //��ʱָ�����
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //����һ���ڵ㣬���ڵ�һ���ڵ��ǰ��(��Ϊ��һ���ڵ�û��ǰ�������ܽ�����ַ)
	head = p1;			       //��headָ��p1�ڵ㣬������ɺ�p1�ڵ��ͷŵ�
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->book, p1->next->next->book) > 0) {
				//���ǰ��Ľڵ�Ⱥ���ڵ�Ĵ��򽻻�
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//��headָ�������ĵ�һ���ڵ�
	free(p1);			//�ͷ�p1
	p1 = NULL;
	return;
}

void Sort_num() {
	BOOK *endpt;	  //����ѭ���Ƚ�
	BOOK *p;		  //��ʱָ�����
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //����һ���ڵ㣬���ڵ�һ���ڵ��ǰ��(��Ϊ��һ���ڵ�û��ǰ�������ܽ�����ַ)
	head = p1;			       //��headָ��p1�ڵ㣬������ɺ�p1�ڵ��ͷŵ�
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->num, p1->next->next->num) > 0) {
				//���ǰ��Ľڵ�Ⱥ���ڵ�Ĵ��򽻻�
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//��headָ�������ĵ�һ���ڵ�
	free(p1);			//�ͷ�p1
	p1 = NULL;
	return;
}

void Sort_Cate() {
	BOOK *endpt;	  //����ѭ���Ƚ�
	BOOK *p;		  //��ʱָ�����
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //����һ���ڵ㣬���ڵ�һ���ڵ��ǰ��(��Ϊ��һ���ڵ�û��ǰ�������ܽ�����ַ)
	head = p1;			       //��headָ��p1�ڵ㣬������ɺ�p1�ڵ��ͷŵ�
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->cate, p1->next->next->cate) > 0) {
				//���ǰ��Ľڵ�Ⱥ���ڵ�Ĵ��򽻻�
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//��headָ�������ĵ�һ���ڵ�
	free(p1);			//�ͷ�p1
	p1 = NULL;
	return;
}

void Sort_Date() {
	BOOK *endpt;	  //����ѭ���Ƚ�
	BOOK *p;		  //��ʱָ�����
	BOOK *p1, *p2;

	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //����һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棨��һ���ڵ�û��ǰ�������ܽ�����ַ��
	head = p1;			       //��headָ��p1�ڵ㣬������ɺ󣬰�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->date[0] < p1->next->next->date[0] ||(p1->next->date[0] == p1->next->next->date[0]&& p1->next->date[1] < p1->next->next->date[1]) ||(p1->next->date[0] == p1->next->next->date[0] && p1->next->date[1]== p1->next->next->date[1]&& p1->next->date[2] <p1->next->next->date[2]))
			{ //���ǰ��Ľڵ��ֵ�Ⱥ���ڵ��ʱ��С���򽻻�
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//��headָ�������ĵ�һ���ڵ�
	free(p1);			//�ͷ�p1
	p1 = NULL;
	return;
}

void Modify_Data() {
	int choice;
	system("cls");//����
	printf("���ṩ��Ҫ�޸ĵ�ͼ�����Ϣ��\n");
	printf("\t\t1.����\n");
	printf("\t\t2.������\n");
	printf("\t\t3.���\n");
	scanf("%d", &choice);
	printf("\n");
	while (choice < 1 || choice>3) {
		fflush(stdin);
		printf("�����������������루1-3����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Modify_key(1);break;
	case 2:Modify_key(2);break;
	case 3:Modify_key(3);break;
	}
}

void Modify_key(int j) {
	BOOK *p;
	char key[20];
	int choice;
	int i;
	if (j == 1) {
		printf("������������\n");
	}
	else if (j == 2) {
		printf("��������������\n");
	}
	else {
		printf("�������ţ�\n");
	}

	scanf("%s", key);
	p = head;
	if (p == NULL) {
		printf("�ձ���ͼ�����ݣ�");
	}
	if (j == 1) {
		while (p != NULL&&strcmp(p->book, key)) {//�������ظ������
			p = p->next;
		}
	}
	else if (j == 2) {
		while (p != NULL&&strcmp(p->author, key)) {//�������ظ������
			p = p->next;
		}
	}
	else {
		while (p != NULL&&strcmp(p->num, key)) {//�������ظ������
			p = p->next;
		}
	}

	if (p == NULL) {
		printf("\n�Ҳ�����ͼ�飡");
	}
	else
	{
		system("cls");
		printf("��Ҫ�޸ĵ�ͼ����ϢΪ��\n");
		printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
		display(p);
		printf("\n���޸ĵ���Ŀ�У�\n");
		printf("1.���\t\t5.����\t\n");
		printf("2.����\t\t6.���\t\n");
		printf("3.����\t\t7.����ȫ��\t\n");
		printf("4.�۸�\t\t\n");
		printf("�������޸���Ŀ��");
		scanf("%d", &i);
		while (i < 1 || i>7) {
			printf("\n�����������������루1-7����");
			scanf("%d", &i);
		}
		printf("\n������Ҫ�޸ĵ�ͼ����µ����ݣ�\n");
		switch (i) {
		case 1:printf("�������µı�ţ�");
			scanf("%s", p->num);
			break;
		case 2:printf("�������µ�������");
			scanf("%s", p->book);
			break;
		case 3:printf("�������µ���������");
			scanf("%f", p->author);
			break;
		case 4:printf("�������µļ۸�");
			scanf("%f", &p->price);
			break;
		case 5:printf("�������µ�����(�������Կո��������");
			scanf("%d%d%d", &p->date[0], &p->date[1], &p->date[2]);
			break;
		case 6:printf("�������µ����");
			scanf("%s", p->cate);
			break;
		case 7: PRINT(p);
			break;
		}
	}
	printf("\n�Ƿ�����޸ģ�");
	printf("\n1. �����޸�");
	printf("\n2. �˳��޸�\n����ѡ���ǣ�");
	scanf("%d", &choice);
	while (choice < 1 || choice>2) {
		fflush(stdin);//��������� 
		printf("\n�����������������루1-2����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Modify_Data();break;
	case 2:return;

	}
	return;
}

void Delete() {
	system("cls");
	BOOK *p, *q;
	char num[20];
	int choice;
	printf("������Ҫɾ����ͼ��ı�ţ�\n");
	scanf("%s", num);
	p = head;//�ޱ�ͷ�ڵ������ 
	if (p == NULL) {
		printf("\n�ձ���ͼ�����ݣ�");
	}
	else if (!strcmp(p->num, num)) {
		printf("��Ҫɾ����ͼ������Ϊ��\n");
		printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
		display(p);
		head = p->next;//��һ���ڵ㼴ΪҪɾ���Ľڵ� 
		free(p);
		printf("\nɾ���ɹ���\n");
	}
	else {
		while (p->next != NULL&& strcmp(p->next->num, num)) {//�����ж��������ܵߵ������һ���ڵ�ʱ p �ѿգ��� p->next) 
			p = p->next;
		}

		if (p->next == NULL) {
			printf("�Ҳ�����ͼ�飡");
		}
		else
		{
			printf("��Ҫɾ����ͼ������Ϊ��\n");
			printf("���        ����                ����        �۸�      ��������          ͼ�����\n");
			display(p->next);
			q = p->next;//q ΪҪɾ���Ľڵ� 
			p->next = q->next;
			free(q);
			printf("\nɾ���ɹ���\n");
		}

	}
	printf("\n�Ƿ����ɾ����\n");
	printf("1. ��\n");
	printf("2. ��\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n�����������������루1-2����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Delete();break;
	case 2:return;
	}
	return;
}

void PRINT(BOOK * p) {
	printf("��ţ�");
	scanf("%s", p->num);
	printf("������");
	scanf("%s", p->book);
	printf("���ߣ�");
	scanf("%s", p->author);
	printf("�۸�");
	scanf("%f", &p->price);
	printf("���ڣ��������Կո��������");
	scanf("%d%d%d", &p->date[0], &p->date[1], &p->date[2]);
	printf("ͼ�����");
	scanf("%s", p->cate);

}



