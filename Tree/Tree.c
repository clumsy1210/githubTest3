#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* LeftChild;	 // �Ʒ��� �������� child
	struct node* RightSibling;  // ������ ����
	char Data;
} Node;

Node* CreateNode(char data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->LeftChild = NULL;
	NewNode->RightSibling = NULL;
	NewNode->Data = data;

	return NewNode;
}

void DestroyNode(Node* Destroy)
{
	free(Destroy);
}

void DestroyTree(Node* Root)	// ��͸� �̿�
{
	if (Root->RightSibling != NULL)
		DestroyTree(Root->RightSibling);	// �ϴ� �ٿ��ִ� ������ �������� ���� ����. �׸��� ����Ͽ� �� ���� ���� ���ƿ�

	if (Root->LeftChild != NULL)
		DestroyTree(Root->LeftChild);	// �׸��� ���� ���� �ٷ� ������

	DestroyNode(Root);
}

void AddChildNode(Node* Parent, Node* Child)
{
	if (Parent->LeftChild == NULL)  // ���� �ڽ��� ���ٸ�
		Parent->LeftChild = Child;

	else
	{
		Node* Cibling = Parent->LeftChild;
		
		while (Cibling->RightSibling != NULL)	// �� ���� �ڽĺ��� �����Ͽ� ������ ������ ���������� �̵�
			Cibling = Cibling->RightSibling;

		Cibling->RightSibling = Child;
	}
}

void PrintTree(Node* Node, int Depth)	 // ���
{
	for (int i = 0; i < Depth; i++)
		printf("   ");		// ���� ���

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		PrintTree(Node->LeftChild, Depth + 1);

	if(Node->RightSibling != NULL)
		PrintTree(Node->RightSibling, Depth);
}

int main()
{
	Node* Root = CreateNode('A');	 // ���� �� ��尡 �� �Ѹ� ��� ����
	Node* B = CreateNode('B');
	Node* C = CreateNode('C');
	Node* D = CreateNode('D');
	Node* E = CreateNode('E');
	Node* F = CreateNode('F');
	Node* G = CreateNode('G');
	Node* H = CreateNode('H');
	Node* I = CreateNode('I');
	Node* J = CreateNode('J');
	Node* K = CreateNode('K');

	AddChildNode(Root, B);
		AddChildNode(B, C);
		AddChildNode(B, D);
		AddChildNode(D, E);
		AddChildNode(D, F);

	AddChildNode(Root, G);
		AddChildNode(G, H);

	AddChildNode(Root, I);
		AddChildNode(I, J);
			AddChildNode(J, K);


	PrintTree(Root, 0);

	PrintLevel(Root, 3);

	DestroyTree(Root);

	return 0;
}