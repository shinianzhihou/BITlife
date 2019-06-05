#include"stdio.h"
#include"stdlib.h"
#include"string.h" 

struct student {//ѧ����Ϣ�ṹ�嶨��
	char num[20];
	char name[20];
	float score[6];//���Ź��γɼ��Լ�ƽ���ֳɼ�
	int no;
	struct student * next;
};

typedef struct student STU;

STU *head;//ͷָ��Ϊȫ�ֱ��������ڷ���

void Pass();//��¼�����֤
void Login_MFace();//��¼����
void Input_Data();//�ֶ���������
void Insert_Data();//���뺯��
void Save_Data();//������Ϣ���ļ���
void Up_Data();//���ļ��ж�ȡ��Ϣ����������
void Search_Infor();//���Һ���
void S_key(int i);//��ѧ�š���������
void display(STU * p);//��pָ����ָѧ����Ϣ��ʾ����
void Sort_Data();//������
void Sort_num();//����ѧ������
void Sort_marki(int choice);//���յ� choice-2 �ųɼ����򣨰���ƽ���֣�
void Modify_Data();//�޸���Ϣ����
void Modify_key(int j);//���չؼ��֣�ѧ�Ż������������޸�
void Calculate_Average(STU * p);//����pָ����ָѧ����ƽ����
void Delete();//ɾ��ĳ��ѧ������Ϣ
void PRINT(STU * p);//����pָ����ָѧ����������Ϣ
void No_i();//Ϊѧ���������

int main() {
	printf("\n\n\t\t\tд��ʹ��ǰ��\n");
	printf("\t\t\t��¼���û����������Ϊ 000000 �������㣩\n\n\n ");
	system("pause");
	system("cls");
	printf("\n��ӭʹ�óɼ�����ϵͳ��\n");
	Pass();
	system("cls");
	STU * j, *p;
	int n, m;
	int i;
	int flag = 1;
	int choice;
	printf("\n\n��ѡ���������뷽ʽ��\n1->�ֶ�����\n2->�ļ�����\n");
	scanf("%d", &n);
	if (n == 1) Input_Data();
	if (n == 2) Up_Data();
	for (p = head;p->next != NULL;p = p->next) {
		Calculate_Average(p);
	}
	Calculate_Average(p);
	No_i();
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
		case 1:  printf("\nȫ��ѧ����ϢΪ��\n");
			printf("���           ����           ѧ��           ����      ����      Ӣ��      C����     ���ݽṹ  ƽ����\n");
			for (j = head;j != NULL;j = j->next) 
			printf("%-15d%-15s%-15s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", j->no,j->name, j->num, j->score[0], j->score[1], j->score[2], j->score[3], j->score[4], j->score[5]);
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
	printf("1------��ʾȫ��ѧ����Ϣ\n\t\t");
	printf("2------��ѯ��Ϣ\n\t\t");
	printf("3------����\n\t\t");
	printf("4------�޸���Ϣ\n\t\t");
	printf("5------ɾ����Ϣ\n\t\t");
	printf("6------�����Ϣ\n\t\t");
	printf("7------������Ϣ\n\t\t");
	printf("0------�˳�\n\t\t");
	return;
}

void Input_Data() {
	int n = 1;//�ж�������ǵڼ���ѧ�� 
	int flag = 1;//ѭ������ 
	char ch;
	STU * p1;
	p1 = NULL;
	head = NULL;

	head = (STU *)malloc(sizeof(STU));	//����һ���½ڵ�
	head->next = NULL;

	if (head == NULL)		//�ڵ㿪�ٲ��ɹ�
	{
		printf("\n������ʧ�ܣ����Ժ����ԣ�\n");
		return;
	}

	while (flag)
	{//ѭ������
		if (n == 1) {
			printf("\t\t����ѧ����Ϣ\n\t\t�������%d��ѧ������Ϣ��\n", n);
			PRINT(head);

		}
		else {
			p1 = (STU *)malloc(sizeof(STU));
			printf("\t\t����ѧ����Ϣ\n\t\t�������%d��ѧ������Ϣ��\n", n);
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

void Insert_Data() {
	system("cls");
	char ch;
	int flag = 1;
	STU *p;
	p = head;
	printf("\n�밴��ʾ�������ѧ������Ϣ��\n");
	while (flag) {
		p = (STU *)malloc(sizeof(STU));
		if (p == NULL)		//�ڵ㿪�ٲ��ɹ�
		{
			printf("\n������ʧ�ܣ����Ժ����ԣ�\n");
			return;
		}
		PRINT(p);//¼������
		Calculate_Average(p);
		p->next = head;
		head = p;
		if (p != NULL)
			printf("\n����ɹ���\n");
		printf("\n�Ƿ��������?��Y/N)\n");
		scanf("%s", &ch);//��Ҫ�� %s ���������� %c ���������������з� 
		while (ch != 'Y'&&ch != 'N') {
			printf("����������������룺");
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

void Save_Data() {
	FILE * fp;
	STU * p;
	if ((fp = fopen("D:\\StudentData.txt", "w")) == NULL) {
		printf("�޷����ļ�\n");
		exit(1);
	}
	p = head;
	do {
		fprintf(fp, "%3d      %10s    %10s    %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f\n",p->no, p->name, p->num, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5]);
		p = p->next;
	} while (p->next != NULL);//��֤�ļ����һ���ַ����ǻ��з�������˶�ȡ����ʱ���з������� 
	    fprintf(fp, "%3d      %10s    %10s    %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f",p->no, p->name, p->num, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4],p->score[5]);
	printf("����ɹ���\n\n");
	fclose(fp);

}

void No_i() {
	STU * p;
	p=head;
	int i=1;
	while(p->next!=NULL){
		p->no=i;
		i++;
		p=p->next;
	}
	p->no=i;
	return; 
}

void Up_Data() {
	int n = 1;
	char ch;
	FILE * fp;
	STU * p, *q;
	if ((fp = fopen("D:\\StudentData.txt", "r")) == NULL) {
		printf("�޷����ļ�\n");
		exit(1);
	}
	p = (STU*)malloc(sizeof(STU));
	p->next = NULL;
	while (!feof(fp)) {
		if (n == 1) {
			fscanf(fp, "%d%s%s%f%f%f%f%f%f", &p->no,p->name, p->num, &p->score[0], &p->score[1], &p->score[2], &p->score[3], &p->score[4], &p->score[5]);
		}
		else {
			q = (STU*)malloc(sizeof(STU));
			fscanf(fp, "%d%s%s%f%f%f%f%f%f",&q->no, q->name, q->num, &q->score[0], &q->score[1], &q->score[2], &q->score[3], &q->score[4], &p->score[5]);
			q->next = p;
			p = q;
		}
		n += 1;
	}
	head = p;
	fclose(fp);
	printf("��ȡ�ɹ���\n");
	system("pause");
	system("cls");

}

void Search_Infor() {
	int choice;
	system("cls");
	printf("���ҷ�ʽΪ��\n");
	printf("\t\t1.ͨ��ѧ�Ų��ң��Ƽ���\n");
	printf("\t\t2.ͨ����������\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
	    fflush(stdin);//��������� 
		printf("�����������������루1-2����");
		scanf("%d", &choice);
	}
	S_key(choice);
	return;
}

void S_key(int i) {
	system("cls");
	STU *p;
	p = NULL;
	char key[20];
	int choice;
	if (i == 1) {
		printf("������ѧ�ţ�\n");
	}
	else {
		printf("������������\n");
	}

	scanf("%s", key);
	p = head;//�ޱ�ͷ�ڵ������ 
	if (p == NULL) {
		printf("\n�ձ���ѧ�����ݣ�");
	}
	if (i == 1) {
		while (p != NULL&& strcmp(p->num, key)) {//�����ж��������ܵߵ������һ���ڵ�ʱ p �ѿգ��� p->next) 
			p = p->next;
		}
	}
	else {
		while (p != NULL&& strcmp(p->name, key)) {//�����ж��������ܵߵ������һ���ڵ�ʱ p �ѿգ��� p->next) 
			p = p->next;
		}

	}

	if (p == NULL) {
		printf("�Ҳ�����ѧ����");
	}
	else
	{
		display(p);
	}
	printf("�Ƿ�������ң�\n");
	printf("1. ͨ��ѧ�Ų���\n");
	printf("2. ͨ����������\n");
	printf("3. �˳�����\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2 && choice != 3) {
		printf("�����������������루1-3����");
		scanf("%d", &choice);
	}
	switch (choice) {
		case 1:
		case 2:S_key(choice);break;
		case 3:return;
	}
	return;
}

void display(STU * p) {
	printf("���           ����           ѧ��           ����      ����      Ӣ��      C����     ���ݽṹ  ƽ����\n");
	printf("%-15d%-15s%-15s%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f%-10.2f\n", p->no,p->name, p->num, p->score[0], p->score[1], p->score[2], p->score[3], p->score[4], p->score[5]);
	return;
}

void Sort_Data() {
	int choice;
	system("cls");
	printf("����ʽΪ��\n");
	printf("\t\t1.����ѧ������\n");
	printf("\t\t2.���ո����ɼ�����\n");
	printf("\t\t3.�������ĳɼ�����\n");
	printf("\t\t4.����Ӣ��ɼ�����\n");
	printf("\t\t5.����C���Գɼ�����\n");
	printf("\t\t6.�������ݽṹ�ɼ�����\n");
	printf("\t\t7.����ƽ��������\n");
	scanf("%d", &choice);
	while (choice < 1 || choice>7) {
		printf("�����������������루1-7����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Sort_num();break;
	default:Sort_marki(choice - 2);break;
	}
	No_i();
	printf("\n����ɹ�\n");
}

void Sort_num() {
	STU *endpt;	  //����ѭ���Ƚ�
	STU *p;		  //��ʱָ�����
	STU *p1, *p2;
	p1 = (STU *)malloc(sizeof(STU));
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

void Sort_marki(int choice) {
	STU *endpt;	  //����ѭ���Ƚ�
	STU *p;		  //��ʱָ�����
	STU *p1, *p2;

	p1 = (STU *)malloc(sizeof(STU));
	p1->next = head;		   //����һ���ڵ㣬���ڵ�һ���ڵ��ǰ�棨��һ���ڵ�û��ǰ�������ܽ�����ַ��
	head = p1;			       //��headָ��p1�ڵ㣬������ɺ󣬰�p1�ڵ��ͷŵ�

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->score[choice] < p1->next->next->score[choice])	//���ǰ��Ľڵ��ֵ�Ⱥ���ڵ�ļ�ֵС���򽻻�
			{
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
	printf("���ṩ��Ҫ�޸ĵ�ѧ����һ����Ϣ��\n");
	printf("\t\t1.ѧ�ţ��Ƽ���\n");
	printf("\t\t2.����\n");
	scanf("%d", &choice);
	printf("\n");
	while (choice < 1 || choice>2) {
		fflush(stdin); 
		printf("�����������������루1-2����");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Modify_key(1);break;
	case 2:Modify_key(2);break;
	}
}

void Modify_key(int j) {
	STU *p;
	char key[20];
	int choice;
	int i;
	if (j == 1) {
		printf("������ѧ�ţ�\n");
	}
	else {
		printf("������������\n");
	}

	scanf("%s", key);
	p = head;
	if (p == NULL) {
		printf("�ձ���ѧ�����ݣ�");
	}
	if (j == 1) {
		while (p != NULL&&strcmp(p->num, key)) {//���������������
			p = p->next;
		}
		}
	else {
		while (p != NULL&&strcmp(p->name, key)) {//���������������
			p = p->next;
		}

	}

	if (p == NULL) {
		printf("\n�Ҳ�����ѧ����");
	}
	else
	{
		system("cls");
		printf("��Ҫ�޸ĵ�ѧ����ϢΪ��\n");
		display(p);
		printf("\n���޸ĵ���Ŀ�У�\n");
		printf("1.����\t\t5.Ӣ��\t\n");
		printf("2.ѧ��\t\t6.C����\t\n");
		printf("3.����\t\t7.���ݽṹ\t\n");
		printf("4.����\t\t8.����ȫ��\n");
		printf("�������޸���Ŀ��");
		scanf("%d", &i);
		while (i < 1 || i>8) {
			printf("\n�����������������루1-8����");
			scanf("%d", &i);
		}
		printf("\n������Ҫ�޸ĵ�ѧ�����µ����ݣ�\n");
			switch (i) {
			case 1:printf("�������µ�������");
				scanf("%s", p->name);
				break;
			case 2:printf("�������µ�ѧ�ţ�");
				scanf("%s", p->num);
				break;
			case 3:printf("�������µĸ���������");
				scanf("%f", &p->score[0]);
				break;
			case 4:printf("�������µ����ķ�����");
				scanf("%f", &p->score[1]);
				break;
			case 5:printf("�������µ�Ӣ�������");
				scanf("%f", &p->score[2]);
				break;
			case 6:printf("�������µ�C���Է�����");
				scanf("%f", &p->score[3]);
				break;
			case 7:printf("�������µ����ݽṹ������");
				scanf("%f", &p->score[4]);
				break;
			case 8: PRINT(p);
				break;
			}
		Calculate_Average(p);
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
	}

void Calculate_Average(STU * p) {
	float sum = 0.0;
	for (int i = 0;i < 5;i++) {//���
		sum += p->score[i];
	}
	p->score[5] = sum / 5.0;//��ƽ����
}

void Delete() {
	system("cls");
	STU *p, *q;
	char num[20];
	int choice;
	printf("������Ҫɾ����ѧ����ѧ�ţ�\n");
	scanf("%s", num);
	p = head;//�ޱ�ͷ�ڵ������ 
	if (p == NULL) {
		printf("\n�ձ���ѧ�����ݣ�");
	}
	else if (!strcmp(p->num, num)) {
		printf("��Ҫɾ����ѧ������Ϊ��\n");
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
			printf("�Ҳ�����ѧ����");
		}
		else
		{
			printf("��Ҫɾ����ѧ������Ϊ��\n");
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

void PRINT(STU * p) {
	printf("������");
	scanf("%s", p->name);
	printf("ѧ�ţ�");
	scanf("%s", p->num);
	printf("������");
	scanf("%f", &p->score[0]);
	printf("���ģ�");
	scanf("%f", &p->score[1]);
	printf("Ӣ�");
	scanf("%f", &p->score[2]);
	printf("C���ԣ�");
	scanf("%f", &p->score[3]);
	printf("���ݽṹ��");
	scanf("%f", &p->score[4]);

}

