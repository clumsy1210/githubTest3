#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int Data;
	struct node* NextNode;
} Node;

typedef struct stack
{
	Node* HEAD;	// �� �Ʒ�
	Node* TAIL;	// �� ��
} Stack;

Stack* CreateStack()
{
	Stack* NewStack = (Stack*)malloc(sizeof(Stack));

	NewStack->HEAD = NULL;
	NewStack->TAIL = NULL;

	return NewStack;
}

Node* CreateNode(int data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));	// ��� ����
	NewNode->Data = data;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* node)
{
	free(node);
}

void Push(Stack* stack, Node* node)
{
	if (stack->HEAD == NULL)	// ���� ��Ұ� ���ٸ�
	{
		stack->HEAD = node;
		stack->TAIL = node;
	}

	else
	{
		stack->TAIL->NextNode = node;	// �� �� ����� ���� ��带 ���ο� ���� ��������
		stack->TAIL = node;		// TAIL�� ���ο� ���� ����
	}
}

void Pop(Stack* stack)
{
	if (stack->HEAD == NULL)
		printf("�� �̻� ���� ��� ����!");

	else if (stack->HEAD == stack->TAIL)	// ���� ��Ұ� 1�����
	{
		DestroyNode(stack->TAIL);
		stack->HEAD = NULL;
		stack->TAIL = NULL;
	}

	else
	{
		Node* BeforeTail = stack->HEAD;	// �� �� ����� �Ʒ� ��带 ��Ÿ�� ���� ����

		while (BeforeTail->NextNode != stack->TAIL)
			BeforeTail = BeforeTail->NextNode;

		DestroyNode(stack->TAIL);	// �� �� ��� ����
		stack->TAIL = BeforeTail;	// �� ���� �ٷ� �Ʒ� ���� ��������
		BeforeTail->NextNode = NULL;
	}

}

int Top(Stack* stack)
{
	return stack->TAIL->Data;
}

int GetSize(Stack* stack)
{
	int count = 0;
	Node* HEAD2 = stack->HEAD;

	while (HEAD2 != NULL)	// ���� NULL�̶�� 0�� ��ȯ
	{
		count++;
		HEAD2 = HEAD2->NextNode;
	}
	
	return count;
}

int IsEmpty(Stack* stack)
{
	return stack->HEAD == NULL;
}

int main()
{
	Stack* stack = CreateStack();	// ���� ����

	for (int i = 1; i < 6; i++)
	{
		Push(stack, CreateNode(i * 10));	// 10 20 30 40 50
	}

	printf("Top: %d, Size: %d\n", Top(stack), GetSize(stack));	// Top: 50, Size: 5

	for (int i = 1; i < 6; i++)
	{
		Pop(stack);	// 10 20 30 40 50
	}

	if (IsEmpty(stack))
		printf("������ ������ϴ�\n");

	return 0;
}