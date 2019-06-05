//���ʽ�ļ���
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h> 
#define STACKINCREMENT 100
#define STACK_INIT_SIZE 20

typedef char Elemtype1;
typedef double Elemtype2;

//��Ϊ����׺���ʽת��Ϊ��׺���ʽ�ͼ����׺���ʽ���õ�ջ��һ����һ�����ַ��ͣ�һ���Ǹ����ͣ�
//����ջ����غ������������к�׺ 1 �����ַ��͵ģ��к�׺ 2 ���Ǹ����� 
typedef struct Stack1 {//����һ���ַ��͵�ջָ�� 
	Elemtype1 *base;
	Elemtype1 *top;
	int stacksize;
} Stack1;


typedef struct Stack2 {//����һ�������͵�ջָ�� 
	Elemtype2 *base;
	Elemtype2 *top;
	int stacksize;
} Stack2;

Elemtype1 Peak1(Stack1 &S) {//ȡ�ַ���ջ��ջ��Ԫ�� 
	if (S.top == S.base) return 0;
	return *(S.top - 1);
}

int StackLength(Stack2 &S) {//�ж���ջ�ĳ��ȣ�ջ��ʱջ��Ϊ 0 
	return S.top - S.base;
}

int InitStack1(Stack1 &S) {//����һ���ַ��͵�ջ 
	S.base = (Elemtype1*)malloc(STACK_INIT_SIZE * sizeof(Elemtype1));
	if (!S.base) {
		return 0;
	}
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return 1;
}

int InitStack2(Stack2 &S) {//����һ�������͵�ջ 
	S.base = (Elemtype2*)malloc(STACK_INIT_SIZE * sizeof(Elemtype2));
	if (!S.base) {
		return 0;
	}
	S.stacksize = STACK_INIT_SIZE;
	S.top = S.base;
	return 1;
}

Elemtype1 Pop1(Stack1 &S) {//�ַ���ջջ��Ԫ�س�ջ������ջ��Ԫ�� 

	if (S.base == S.top) {
		return 0;
	}
	S.top--;
	return *S.top;
}

Elemtype2 Pop2(Stack2 &S) {//������ջջ��Ԫ�س�ջ������ջ��Ԫ�� 

	if (S.base == S.top) {
		return 0;
	}
	S.top--;
	return *S.top;
}

int Push1(Stack1 &S, Elemtype1 e) {//���ַ���Ԫ�� e ��ջ 
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype1 *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Elemtype1));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}

int Push2(Stack2 &S, Elemtype2 e) {//��������Ԫ�� e ��ջ 
	if (S.top - S.base >= S.stacksize) {
		S.base = (Elemtype2 *)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(Elemtype2));
		if (!S.base)exit(OVERFLOW);
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return 1;
}

int Judge(char op)
{   //�������ã� 
	//1.�жϷ��ŵ����ȼ����������ȼ��ĸߵͣ��ֱ𻮷�Ϊ0��1��2��3 ����Խ�����ȼ�Խ�� 
	//2.���ݶ���������ж��ַ��Ƿ�Ϊ'+', '-', '*', '/', '%'��'^' ,���򷵻ط���ֵ 

	switch (op)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
	case '%':
		return 2;
	case '^':
		return 3;
	default:
		return 0;
	}
}

int Change(char *M, char *B)
{
	//����׺���ʽ M ת��Ϊ��׺���ʽ B
	Stack1 S;//SΪ����� 
	InitStack1(S);//����һ���ַ���ջ 
	Push1(S, '#');//ջ����������Ԫ�� #����Ϊ���ȼ���͵�һ������� 
	int i = 0, j = 0;//�ֱ��� i ��j �������׺�ͺ�׺���ʽ���ַ���λ�� 
	char ch;//ch �ƶ�ָʾ��׺���ʽ�е��ַ� 
	ch = M[i];
	while (ch != '\0')
	{
		if (ch == ' ')
			ch = M[++i];
		else if (ch == '(')
		{//������ֱ�ӽ�ջ���ȴ������� 
			Push1(S, ch);
			ch = M[++i];
		}
		else if (ch == ')')
		{//������һ��������֮��������ֱ��д���׺���ʽ
			while (Peak1(S) != '(')
				B[j++] = Pop1(S);
			Pop1(S);//ɾ����ʱջ���� '('
			ch = M[++i];
		}
		else if (Judge(ch))
		{
			char temp;//�����м����
			temp = Peak1(S);
			while (Judge(ch) <= Judge(temp))
			{//���������ȼ����ڵ��� ch �������д���׺���ʽ����ջ 
				B[j++] = temp;
				Pop1(S);
				temp = Peak1(S);
			}
			Push1(S, ch);
			ch = M[++i];
		}
		else if ((ch >= '0'&& ch <= '9') || ch == '.')
		{
			while ((ch >= '0'&& ch <= '9') || ch == '.')
			{
				B[j++] = ch;
				ch = M[++i];
			}
			B[j++] = ' ';
		}
		else
		{
			printf("����\n������Ϣ�����ʽ����δ��ʶ����ַ���\n");
			system("pause");
			exit(1);
		}
	}
	ch = Pop1(S);//���� ch ��ջ��ʣ���ַ�ȫ��д���׺���ʽ��
	while (ch != '#')
	{
		if (ch == '(')
		{//����׺���ʽ������ϣ���ջ����Ȼ����δ��Ե� ( ʱ��˵���������׺���ʽ���Ų�ƥ�� 
			printf("����\n������Ϣ�����ʽ���Ų�ƥ�䣡\n");
			system("pause");
			exit(1);
		}
		else {
			B[j++] = ch;
			ch = Pop1(S);
		}

	}
	B[j++] = '\0';//����׺���ʽ����һ��������־ 
				  //�������� 
}

double Calculate(char *B)
{//�˺������ڼ����׺���ʽ������ֵΪ������
	Stack2 S;
	InitStack2(S);//���ַ�ת��Ϊ���ֲ������ڸ�����ջ�� �����չ���������� 
	char ch;//����ָ���׺���ʽ���ַ� 
	int i = 0;//���������׺���ʽ���±� 
	double integer = 0.0, decimal = 0.0;//�ֱ������洢���ʽ�е��������ֺ�С�������Լ����
	double temp, temp1;//temp ��������������˷��ͼ���ʱ�ȵ���������ָ���������� ,temp1�� c ������ȡ������
	int c;
	while (B[i])
	{
		if (B[i] == ' ')
		{//�Կո񲻽��д��� 
			i++;
			continue;
		}
		else
		{
			switch (B[i])
			{
			case '+':integer = Pop2(S) + Pop2(S);//�ӷ� 
				i++;
				break;
			case '-':temp = Pop2(S);//���� 
				integer = Pop2(S) - temp;
				i++;
				break;
			case '*':integer = Pop2(S)*Pop2(S);//�˷� 
				i++;
				break;
			case '/':temp = Pop2(S);//���� 
				if (temp == 0.0)
				{//����Ϊ 0 
					printf("����\n������Ϣ������������Ϊ�㣡\n");
					system("pause");
					exit(1);
				}
				else
				{
					integer = Pop2(S) / temp;
				}
				i++;
				break;
			case '%':temp = Pop2(S);//ȡ��
				temp1 = Pop2(S);
				if ((int)temp == temp && (int)temp1 == temp1) {
					integer = (int)temp1 % (int)temp;
					i++;

				}
				else {
					printf("����\n������Ϣ��ȡ������ʱ����������Ӧ��Ϊ������\n");
					system("pause");
					exit(1);
				}
				break;
			case '^':temp = Pop2(S);//�˷� 
				integer = pow(Pop2(S), temp);
				i++;
				break;
			default:
			{//��ʱһ����������������� 
				integer = 0.0;
				decimal = 0.0;
				while (B[i] >= '0'&&B[i] <= '9')
				{//��� B[i] Ϊ�������֣���һֱ����ѭ���ۼ� 
					integer = integer*10.0 + B[i] - '0';//������������ 
					i++;
				}
				if (B[i] == '.') {
					i++;
					double n = 0.1;//n ΪС����λ��
					while (B[i] >= '0'&&B[i] <= '9')
					{//�������С������С���������С�����֣���һֱѭ���ۼ� 
						decimal = decimal + (B[i] - '0')*n;
						n = n*0.1;
						i++;
					}
				}
				integer = integer + decimal;//��������С��������ӵ���ջ

			}
			}
			Push2(S, integer);//����������������ջ 
		}

	}
	if (!StackLength(S))
	{//�ж�ջ�Ƿ�գ���ȷ�Ļ�ջ��Ӧ��ֻ�н��������˵�����ʽ���� 
		printf("����\n������Ϣ�����ʽ����\n");
		system("pause");
		exit(1);
	}
	integer = Pop2(S);//�����ջ 

	if (!StackLength(S))
	{//�����ջ��ջӦΪ�� 
		return integer;
	}
	else
	{
		printf("����\n������Ϣ�����ʽ����\n");
		system("pause");
		exit(1);
	}
}

int main(void)
{
	printf("\t\tע�����\n");
	printf("\t1.�����ţ������ž���С���Ŵ���\n");
	printf("\t2.�����ʽ��������ʱ��������Զ��˳�\n");
	printf("\t3.���ʽ��������δ֪����\n");
	printf("\t4.����������Ӣ�����룬��ʹ��Ӣ���е�����\n\n\n");
	system("pause");
	system("cls");
	int flag = 1;
	int choice;
	char a[100];
	char b[100];
	double result;
	while (flag) {
		printf("\n\t������һ����׺���ʽ��\n\t\t");
		fflush(stdin);
		gets(a);
		Change(a, b);
		result = Calculate(b);
		printf("\t=%g\n\n", result);
		printf("\t�Ƿ������\n");
		printf("     1.��     2.��\n");
		scanf("%d", &choice);
		while (choice<1 || choice>2) {
			printf("����������������루1-2����");
			fflush(stdin);
			scanf("%d", &choice);
		}
		switch (choice) {
		case 1:system("cls");break;
		case 2:flag = 0;
			break;
		}

	}


}
