#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* NextNode;
} Node;

Node* CreateNode(int data)		// ��� ����
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); 
	
	NewNode->data = data;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Destroy)		// ��� ����
{
	free(Destroy);
}

void AppendNode(Node** HEAD, Node* NewNode)		// ��� ���� �߰�
{
	if (*HEAD == NULL)
	{
		*HEAD = NewNode;
	}

	else
	{
		Node* Tail = *HEAD;

		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;

		Tail->NextNode = NewNode;
	}
}

Node* GetNode(Node* HEAD, int num)   // num��° ����� �����ͺ����� ��ȯ����
{
	for (int i = 0; i < num; i++)
	{
		HEAD = HEAD->NextNode;
	}

	return HEAD;
}

int NodeCount(Node* HEAD)		// ����� ������ ���� ��ȯ����
{
	int count = 1;		// HEAD���� �����ϹǷ� 1���� ����

	if (HEAD == NULL)		// ���� 0�����
		count = 0;

	else
	{
		while (HEAD->NextNode != NULL)
		{
			HEAD = HEAD->NextNode;
			count++;
		}
	}

	return count;
}

void InsertNode(Node* Current, Node* Insert)
{
		Insert->NextNode = Current->NextNode;
		Current->NextNode = Insert;
}

void RemoveNode(Node** HEAD, Node* Remove)   // Ư�� ��ġ�� ��带 ������
{
	if (*HEAD == Remove)
		*HEAD = Remove->NextNode;

	else
	{
		Node* BeforeRemove = HEAD;

		while (BeforeRemove->NextNode != Remove)
			BeforeRemove = BeforeRemove->NextNode;    // BeforeRemove ���� ��尡 Remove ��尡 ��.

		BeforeRemove->NextNode = Remove->NextNode;    // Remove�� ��ŵ���ָ鼭 ���Ḯ��Ʈ���� ���ܽ�����
	}

	DestroyNode(Remove);   // ��带 ������
}

void PrintNode(Node* HEAD)  // ���Ḯ��Ʈ ���
{
	for (HEAD; HEAD != NULL; HEAD = HEAD = HEAD->NextNode)
		printf("%d->", HEAD->data);

	printf("NULL \n");
}

void DestroyAllNodes(Node** HEAD)    // ��ũ�� ����Ʈ ��ü �����ϴ� �Լ� 
{
	Node* Del = NULL;   // ���� ��带 ����Ű�� ���� ����

	while ((*HEAD) != NULL)
	{
		Del = (*HEAD);
		*HEAD = (*HEAD)->NextNode;
		DestroyNode(Del);
	}
}

int main()
{
	Node* HEAD = NULL;   // HEAD ����� �ּҰ��� �����ϴ� ���� HEAD ���� 
	Node* CurrentNode = NULL;

	AppendNode(&HEAD, CreateNode(10));	// 0��°
	AppendNode(&HEAD, CreateNode(20));	// 1��°
	AppendNode(&HEAD, CreateNode(30));	// 2��°
	AppendNode(&HEAD, CreateNode(40));	// 3��°
	AppendNode(&HEAD, CreateNode(50));	// 4��°

	PrintNode(HEAD);		// 10, 20, 30, 40, 50  

	CurrentNode = GetNode(HEAD, 1);   // 1��° ��� ������ ��带 �ϳ� �߰��� ����.
	InsertNode(CurrentNode, CreateNode(25));  // 10 20 25 30 40 50

	PrintNode(HEAD);

	CurrentNode = GetNode(HEAD, 0);		// HEAD ����(10 ����)
	RemoveNode(&HEAD, CurrentNode);		// 20, 25, 30, 40, 50

	PrintNode(HEAD);

	DestroyAllNodes(&HEAD);

	PrintNode(HEAD);

	return 0;
}