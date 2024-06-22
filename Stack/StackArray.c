#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node	// �����Ҵ� ���� ���� �迭�� ��������
{
	int Data;
} Node;

typedef struct
{
	int Capacity;	// �� �뷮
	int Top;		// ���� ���� �� ����� ��ġ
	Node* Array;	// �Ҵ� ���� �迭�� ù ����� �ּҰ��� ����. �迭�̹Ƿ� +1�� ���� ��� �̵� ����
} ArrayStack;

ArrayStack* CreateStack(int capacity)
{
	ArrayStack* NewStack = (ArrayStack*)malloc(sizeof(ArrayStack));

	NewStack->Capacity = capacity;
	NewStack->Top = -1;		// �迭�� �ε����� 0���� �����̹Ƿ� -1���� ++����.
	NewStack->Array = (Node*)malloc(sizeof(Node) * capacity);

	return NewStack;
}

void DestroyStack(ArrayStack* Stack)
{
	free(Stack->Array);		// �Ҵ�޾Ҵ� �迭 ����
	free(Stack);		// ���� ����ü�� ����
}

void Push(ArrayStack* Stack, int data)
{
	if (Stack->Capacity == (Stack->Top) + 1)	// ���� capacity�� top+1�� ���ٸ� �� �����̹Ƿ� ����
		printf("������ �� á���Ƿ� push �Ұ�! \n");
	
	else
	{
		(Stack->Top) += 1;
		Stack->Array[Stack->Top].Data = data;
	}
}

void Pop(ArrayStack* Stack)
{
	if (IsEmpty(Stack))
	{
		printf("������ ��������Ƿ� pop �Ұ�!\n");
	}

	else
	{
		printf("%d ����!\n", Stack->Array[Stack->Top].Data);
		Stack->Top--;
	}
}

int Top(ArrayStack* Stack)
{
	return Stack->Array[Stack->Top].Data;
}

int IsEmpty(ArrayStack* Stack)
{
	return Stack->Top == -1;
}

int GetSize(ArrayStack* Stack)	// ���� ��� � ����ִ��� ��ȯ
{
	return Stack->Top + 1;
}

int main()
{
	ArrayStack* Stack;		// ���� �迭�� ����ų ���� ����
	int i, capacity = 10;

	Stack = CreateStack(10);	// stack�� ���� ������ ArrayStack ����ü�� �־���

	for (i = 1; i <= 6; i++)
		Push(Stack, i * 10);

	printf("�뷮: %d, ����� ����: %d, ������ ���� �� ��: %d\n", Stack->Capacity, GetSize(Stack), Top(Stack));

	for (i = 7; i <= 10; i++)
		Push(Stack, i * 10);

	Push(Stack, 110);		// �� �� ���Ŀ� ���� �־

	for (i = 0; i <10; i++)	// ���� ��� pop �غ�
		Pop(Stack);

	Pop(Stack);  // �迭�� ��� �� �ѹ� �� Pop �غ�

	if (IsEmpty(Stack))
		printf("������ ��� ������ϴ�.\n");

	DestroyStack(Stack);

	return 0;
}