#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int Data;
	struct node* NextNode;
	struct node* BeforeNode;
} Node;

Node* CreateNode(int data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = data;
	NewNode->NextNode = NULL;
	NewNode->BeforeNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Destroy)
{
	int data = Destroy->Data;
	free(Destroy);
	printf("%d ������!\n", data);
}

void AppendNode(Node** HEAD, Node* NewNode)
{
	if (*HEAD == NULL)
	{
		*HEAD = NewNode;
		(*HEAD)->NextNode = *HEAD;
		(*HEAD)->BeforeNode = *HEAD;
	}

	else
	{
		Node* Tail = (*HEAD)->BeforeNode;

		Tail->NextNode = NewNode;
		NewNode->BeforeNode = Tail;

		(*HEAD)->BeforeNode = NewNode;
		NewNode->NextNode = *HEAD;
	}
}

Node* GetNode(Node* HEAD, int num)
{
	for (int i = 0; i < num; i++)
		HEAD = HEAD->NextNode;

	return HEAD;
}

void InsertAfter(Node* Current, Node* Insert)
{
	Node* CurrentNext = Current->NextNode;		// Current�� NextNode�� Insert�� ������� ���̱� ������ ���� NextNode�� ������ ���� ����
	Current->NextNode = Insert;
	Insert->BeforeNode = Current;
	Insert->NextNode = CurrentNext;
}

void RemoveNode(Node** HEAD, Node* Remove)
{
	Node* NextRemove = Remove->NextNode;   // NextRemove�� ���� ����� ���� ���
	Node* BeforeRemove = Remove->BeforeNode;		//  BeforeRemove�� ���� ����� ���� ���

	if (*HEAD == Remove)
	{
		*HEAD = NextRemove;
		(*HEAD)->BeforeNode = BeforeRemove;
		BeforeRemove->NextNode = *HEAD;
	}

	else
	{
		NextRemove->BeforeNode = BeforeRemove;
		BeforeRemove->NextNode = NextRemove;
	}

	Remove->NextNode = NULL;
	Remove->BeforeNode = NULL;

	DestroyNode(Remove);
}

void PrintNode(Node* HEAD)
{
	Node* gotohead = HEAD;

	do
	{
		printf("%d ", gotohead->Data);
		gotohead = gotohead->NextNode;
	} while (gotohead != HEAD);	

	printf("\n");
}

int main()
{
	Node* HEAD = NULL;

	AppendNode(&HEAD, CreateNode(10));		// 0��°
	AppendNode(&HEAD, CreateNode(20));		// 1��°
	AppendNode(&HEAD, CreateNode(30));		// 2��°
	AppendNode(&HEAD, CreateNode(40));		// 3��°
	AppendNode(&HEAD, CreateNode(50));		// 4��°
	AppendNode(&HEAD, CreateNode(60));		// 5��°	
	PrintNode(HEAD);	// 10 20 30 40 50 60 

	RemoveNode(&HEAD, GetNode(HEAD, 2));
	PrintNode(HEAD);   // 10 20 40 50 60

	InsertAfter(GetNode(HEAD, 3), CreateNode(55));
	PrintNode(HEAD);   // 10 20 40 50 55 60

	printf("%d ", HEAD->BeforeNode->Data);

	return 0;
}