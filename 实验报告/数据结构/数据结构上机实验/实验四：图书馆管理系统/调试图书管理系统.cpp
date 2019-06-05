#include"stdio.h"
#include"stdlib.h"
#include"string.h" 

struct book {//图书信息结构体定义
	char cate[10];//类别
	char book[25];//书名
	char author[25];//作者名
	char num[25];//图书编号
	int date[3];//出版日期（年 月 日）
	float price;//书的价格
	struct book * next;
};

typedef struct book BOOK;

BOOK *head;//头指针为全局变量，便于访问

void Pass();//登录身份验证
void Login_MFace();//登录界面
void Insert_Data();//插入函数
void Input_Data();//录入图书信息
void Save_Data();//保存信息到文件中
void Up_Data();//从文件中读取信息并建立链表
void Search_Infor();//查找函数
void S_key(BOOK *q);//按（作者，书名，编号）所含关键字查找，可在结果中继续查找
void S_Date();//按日期查找
void display(BOOK * p);//将p指针所指图书信息显示出来
void Sort_Data();//排序函数
void Sort_num();//按照图书编号排序
void Sort_Cate();//按照图书类别排序
void Sort_Date();//按照图书日期排序
void Sort_Book();//按照书名排序 
void Modify_Data();//修改信息函数
void Modify_key(int j);//按照关键字（书名或作者名）检索修改
void Delete();//删除某本图书的信息
void PRINT(BOOK * p);//输入p指针所指图书的所有信息

int main() {
	BOOK * j;
	int  m,n;
	int flag = 1;
	int choice;
	printf("\n\n\t\t\t写在使用前：\n");
	printf("\t\t\t登录的用户名和密码均为 000000 （六个零）\n\n\n ");
	system("pause");
	system("cls");
	printf("\n欢迎使用图书管理系统：\n");
	Pass();
	head = NULL;
	system("cls");
	printf("\n\n请选择数据输入方式：\n1->手动输入\n2->文件导入\n");
	scanf("%d", &n);
	while (n != 1 && n != 2) {
		printf("\n输入有误，请重新输入（1-2）：");
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
			printf("\n是否保存操作后的数据？\n");
			printf("1. 是\n");
			printf("2. 否\n");
			scanf("%d", &choice);
			while (choice != 1 && choice != 2) {
				printf("\n输入有误，请重新输入（1-2）：");
				scanf("%d", &choice);
			}
			switch (choice) {
			case 1:Save_Data();break;
			case 2:break;
			}

			flag = 0;break;
		case 1:  printf("\n全部图书信息为：\n");
			printf("编号        书名                作者        价格      出版日期          图书类别\n");
			for (j = head;j != NULL;j = j->next)
				display(j);
			break;
		case 2: Search_Infor(); break;
		case 3: Sort_Data();break;
		case 4: Modify_Data();break;
		case 5: Delete();break;
		case 6: Insert_Data();break;
		case 7: Save_Data(); break;
		default:printf("\n\n选择错误，请重新输入");Login_MFace();break;
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
		printf("\n\t\t\t用户名：");
		gets(name);
		printf("\n\t\t\t密  码：");
		gets(password);
		if (!strcmp(name, "000000") && !strcmp(password, "000000")) {
			printf("\n\t\t\t登陆成功！\n\n");
			system("pause");
			return;
		}
		else {
			printf("\n\t\t\t登陆失败，你还有%d次机会\n", 2 - i);
			i++;
		}
	}
	printf("\n\t\t\t尝试次数已用完，您已被强制退出");
	exit(0);
}

void Login_MFace() {
	system("cls");
	printf("请根据提示选择相应的操作：\n\t\t");
	printf("1------显示全部图书信息\n\t\t");
	printf("2------查询图书信息\n\t\t");
	printf("3------排序\n\t\t");
	printf("4------修改图书信息\n\t\t");
	printf("5------删除图书信息\n\t\t");
	printf("6------添加图书信息\n\t\t");
	printf("7------保存信息\n\t\t");
	printf("0------退出\n\t\t");
	return;
}

void Insert_Data() {
	system("cls");
	char ch;
	int flag = 1;
	BOOK *p;
	p = head;
	printf("\n请按提示输入新入图书的信息：\n");
	while (flag) {
		system("cls");
		p = (BOOK *)malloc(sizeof(BOOK));
		if (p == NULL)		//节点开辟不成功
		{
			printf("\n链表创建失败，请稍后再试！\n");
			return;
		}
		PRINT(p);//录入数据
		p->next = head;
		head = p;
		if (p != NULL)
			printf("\n插入成功！\n");
		printf("\n是否继续插入?（Y/N)\n");
		fflush(stdin);
		scanf("%c", &ch);
		while (ch != 'Y'&&ch != 'N') {
			printf("\n输入错误，请重新输入：");
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
	int n = 1;//判断输入的是第几本图书 
	int flag = 1;//循环条件 
	char ch;
	BOOK * p1;
	p1 = NULL;
	head = NULL;

	head = (BOOK *)malloc(sizeof(BOOK));	//开辟一个新节点
	head->next = NULL;

	if (head == NULL)		//节点开辟不成功
	{
		printf("\n链表创建失败，请稍后再试！\n");
		return;
	}

	while (flag)
	{//循环输入
		if (n == 1) {
			printf("\t\t输入图书信息\n\t\t请输入第%d本图书的信息：\n", n);
			PRINT(head);

		}
		else {
			p1 = (BOOK *)malloc(sizeof(BOOK));
			printf("\t\t输入图书信息\n\t\t请输入第%d本图书的信息：\n", n);
			PRINT(p1);
			p1->next = head;
			head = p1;
		}
		n++;
		printf("是否继续录入？(Y/N)\n");
		fflush(stdin);//清除缓存区 
		scanf("%s", &ch);
		while (ch != 'Y'&&ch != 'N') {
			printf("\n输入错误，请重新输入：");
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
	if ((fp = fopen("E:\\图书管理系统\\BookData.txt", "w")) == NULL) {
		printf("\n无法打开文件\n");
		exit(1);
	}
	p = head;
	do {
		fprintf(fp, "%12s %20s %12s %10.2f %4d %2d %2d    %10s\n", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
		p = p->next;
	} while (p->next != NULL);//保证文件最后一个字符不是换行符，解决了读取数据时换行符的问题 
	fprintf(fp, "%12s %20s %12s %10.2f %4d %2d %2d    %10s", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
	printf("\n保存成功！\n");
	fclose(fp);

}

void Up_Data() {
	int n = 1;
	char ch;
	FILE * fp;
	BOOK * p, *q;
	if ((fp = fopen("E:\\图书管理系统\\BookData.txt", "r")) == NULL) {
		printf("\n无法打开文件\n");
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
	printf("\n\n文件读取成功！\n\n");
	system("pause");
	system("cls");

}

void Search_Infor() {
	int choice;
	system("cls");
	printf("请选择查找方式为：\n");
	printf("\t\t1.通过关键字查找\n");
	printf("\t\t2.通过日期查找\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n输入有误，请重新输入（1-2）：");
		fflush(stdin);//清除缓存区 
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
	int n = 0;//记录查找到的图书的本数
	int choice;
	printf("\n请输入日期（年月日以空格隔开）：");
	scanf("%d%d%d", &y, &m, &d);
	p = head;//无表头节点的链表 
	if (p == NULL) {
		printf("\n空表，无图书数据！");
	}
	else {

	}
	while (p != NULL) {
		if (p->date[0] == y&&p->date[1] == m&&p->date[2] == d) {
			if (n == 0) {
				printf("编号        书名                作者        价格      出版日期          图书类别\n");
			}
			display(p);
			n++;
		}
		p = p->next;
	}
	if (n == 0) {
		printf("\n无此图书的信息\n");
	}
	printf("\n是否继续查找：\n");
	printf("1. 是\n");
	printf("2. 否\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n输入有误，请重新输入（1-2）：");
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
	head1 = NULL;//初始化操作
	p = NULL;
	char key[20];
	int choice;
	int n = 0;//记录查找到的图书的数目
	printf("请输入关键字：\n");
	scanf("%s", key);
	p = q;//无表头节点的链表 
	if (p == NULL) {
		printf("\n空表，无图书数据！");
	}
	while (p != NULL) {
		if (strstr(p->num, key) != NULL || strstr(p->book, key) != NULL || strstr(p->author, key) != NULL) {
			r = (BOOK *)malloc(sizeof(BOOK));
			*r = *p;
			if (n == 0) {
				printf("编号        书名                作者        价格      出版日期          图书类别\n");
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
		printf("\n无此图书的信息\n");
	}
	printf("是否在结果中继续查找：\n");
	printf("1. 是\n");
	printf("2. 否\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n输入有误，请重新输入（1-2）：");
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
	printf("%-12s%-20s%-12s%-10.2f%-4d年%-2d月%-2d日    %-10s\n", p->num, p->book, p->author, p->price, p->date[0], p->date[1], p->date[2], p->cate);
	return;
}

void Sort_Data() {
	int choice;
	system("cls");
	printf("排序方式为：\n");
	printf("\t\t1.按照书名排序\n");
	printf("\t\t2.按照图书类别排序\n");
	printf("\t\t3.按照编号进行排序\n");
	printf("\t\t4.按照出版日期排序\n");
	scanf("%d", &choice);
	while (choice < 1 || choice>4) {
		printf("\n输入有误，请重新输入（1-4）：");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Sort_Book();break;
	case 2:Sort_Cate();break;
	case 3:Sort_num();break;
	case 4:Sort_Date();break;
	}
    printf("\n排序成功\n\n");
}

void Sort_Book() {
	BOOK *endpt;	  //控制循环比较
	BOOK *p;		  //临时指针变量
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //增加一个节点，放在第一个节点的前面(因为第一个节点没有前驱，不能交换地址)
	head = p1;			       //让head指向p1节点，排序完成后，p1节点释放掉
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->book, p1->next->next->book) > 0) {
				//如果前面的节点比后面节点的大，则交换
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//让head指向排序后的第一个节点
	free(p1);			//释放p1
	p1 = NULL;
	return;
}

void Sort_num() {
	BOOK *endpt;	  //控制循环比较
	BOOK *p;		  //临时指针变量
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //增加一个节点，放在第一个节点的前面(因为第一个节点没有前驱，不能交换地址)
	head = p1;			       //让head指向p1节点，排序完成后，p1节点释放掉
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->num, p1->next->next->num) > 0) {
				//如果前面的节点比后面节点的大，则交换
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//让head指向排序后的第一个节点
	free(p1);			//释放p1
	p1 = NULL;
	return;
}

void Sort_Cate() {
	BOOK *endpt;	  //控制循环比较
	BOOK *p;		  //临时指针变量
	BOOK *p1, *p2;
	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //增加一个节点，放在第一个节点的前面(因为第一个节点没有前驱，不能交换地址)
	head = p1;			       //让head指向p1节点，排序完成后，p1节点释放掉
	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (strcmp(p1->next->cate, p1->next->next->cate) > 0) {
				//如果前面的节点比后面节点的大，则交换
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//让head指向排序后的第一个节点
	free(p1);			//释放p1
	p1 = NULL;
	return;
}

void Sort_Date() {
	BOOK *endpt;	  //控制循环比较
	BOOK *p;		  //临时指针变量
	BOOK *p1, *p2;

	p1 = (BOOK *)malloc(sizeof(BOOK));
	p1->next = head;		   //增加一个节点，放在第一个节点的前面（第一个节点没有前驱，不能交换地址）
	head = p1;			       //让head指向p1节点，排序完成后，把p1节点释放掉

	for (endpt = NULL; endpt != head; endpt = p)
	{
		for (p = p1 = head; p1->next->next != endpt; p1 = p1->next)
		{
			if (p1->next->date[0] < p1->next->next->date[0] ||(p1->next->date[0] == p1->next->next->date[0]&& p1->next->date[1] < p1->next->next->date[1]) ||(p1->next->date[0] == p1->next->next->date[0] && p1->next->date[1]== p1->next->next->date[1]&& p1->next->date[2] <p1->next->next->date[2]))
			{ //如果前面的节点键值比后面节点的时间小，则交换
				p2 = p1->next->next;
				p1->next->next = p2->next;
				p2->next = p1->next;
				p1->next = p2;
				p = p1->next->next;
			}
		}
	}
	p1 = head;
	head = head->next;		//让head指向排序后的第一个节点
	free(p1);			//释放p1
	p1 = NULL;
	return;
}

void Modify_Data() {
	int choice;
	system("cls");//清屏
	printf("请提供您要修改的图书的信息：\n");
	printf("\t\t1.书名\n");
	printf("\t\t2.作者名\n");
	printf("\t\t3.编号\n");
	scanf("%d", &choice);
	printf("\n");
	while (choice < 1 || choice>3) {
		fflush(stdin);
		printf("输入有误，请重新输入（1-3）：");
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
		printf("请输入书名：\n");
	}
	else if (j == 2) {
		printf("请输入作者名：\n");
	}
	else {
		printf("请输入编号：\n");
	}

	scanf("%s", key);
	p = head;
	if (p == NULL) {
		printf("空表，无图书数据！");
	}
	if (j == 1) {
		while (p != NULL&&strcmp(p->book, key)) {//不考虑重复的情况
			p = p->next;
		}
	}
	else if (j == 2) {
		while (p != NULL&&strcmp(p->author, key)) {//不考虑重复的情况
			p = p->next;
		}
	}
	else {
		while (p != NULL&&strcmp(p->num, key)) {//不考虑重复的情况
			p = p->next;
		}
	}

	if (p == NULL) {
		printf("\n找不到此图书！");
	}
	else
	{
		system("cls");
		printf("您要修改的图书信息为：\n");
		printf("编号        书名                作者        价格      出版日期          图书类别\n");
		display(p);
		printf("\n可修改的项目有：\n");
		printf("1.编号\t\t5.日期\t\n");
		printf("2.书名\t\t6.类别\t\n");
		printf("3.作者\t\t7.以上全部\t\n");
		printf("4.价格\t\t\n");
		printf("请输入修改项目：");
		scanf("%d", &i);
		while (i < 1 || i>7) {
			printf("\n输入有误，请重新输入（1-7）：");
			scanf("%d", &i);
		}
		printf("\n请输入要修改的图书的新的数据：\n");
		switch (i) {
		case 1:printf("请输入新的编号：");
			scanf("%s", p->num);
			break;
		case 2:printf("请输入新的书名：");
			scanf("%s", p->book);
			break;
		case 3:printf("请输入新的作者名：");
			scanf("%f", p->author);
			break;
		case 4:printf("请输入新的价格：");
			scanf("%f", &p->price);
			break;
		case 5:printf("请输入新的日期(年月日以空格隔开）：");
			scanf("%d%d%d", &p->date[0], &p->date[1], &p->date[2]);
			break;
		case 6:printf("请输入新的类别：");
			scanf("%s", p->cate);
			break;
		case 7: PRINT(p);
			break;
		}
	}
	printf("\n是否继续修改：");
	printf("\n1. 继续修改");
	printf("\n2. 退出修改\n您的选择是：");
	scanf("%d", &choice);
	while (choice < 1 || choice>2) {
		fflush(stdin);//清除缓冲区 
		printf("\n输入有误，请重新输入（1-2）：");
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
	printf("请输入要删除的图书的编号：\n");
	scanf("%s", num);
	p = head;//无表头节点的链表 
	if (p == NULL) {
		printf("\n空表，无图书数据！");
	}
	else if (!strcmp(p->num, num)) {
		printf("您要删除的图书数据为：\n");
		printf("编号        书名                作者        价格      出版日期          图书类别\n");
		display(p);
		head = p->next;//第一个节点即为要删除的节点 
		free(p);
		printf("\n删除成功！\n");
	}
	else {
		while (p->next != NULL&& strcmp(p->next->num, num)) {//两个判断条件不能颠倒（最后一个节点时 p 已空，无 p->next) 
			p = p->next;
		}

		if (p->next == NULL) {
			printf("找不到此图书！");
		}
		else
		{
			printf("您要删除的图书数据为：\n");
			printf("编号        书名                作者        价格      出版日期          图书类别\n");
			display(p->next);
			q = p->next;//q 为要删除的节点 
			p->next = q->next;
			free(q);
			printf("\n删除成功！\n");
		}

	}
	printf("\n是否继续删除：\n");
	printf("1. 是\n");
	printf("2. 否\n");
	scanf("%d", &choice);
	while (choice != 1 && choice != 2) {
		printf("\n输入有误，请重新输入（1-2）：");
		scanf("%d", &choice);
	}
	switch (choice) {
	case 1:Delete();break;
	case 2:return;
	}
	return;
}

void PRINT(BOOK * p) {
	printf("编号：");
	scanf("%s", p->num);
	printf("书名：");
	scanf("%s", p->book);
	printf("作者：");
	scanf("%s", p->author);
	printf("价格：");
	scanf("%f", &p->price);
	printf("日期（年月日以空格隔开）：");
	scanf("%d%d%d", &p->date[0], &p->date[1], &p->date[2]);
	printf("图书类别：");
	scanf("%s", p->cate);

}



