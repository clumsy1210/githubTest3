#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	struct node* LeftChild;	 // 아래로 내려가는 child
	struct node* RightSibling;  // 오른쪽 형제
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

void DestroyTree(Node* Root)	// 재귀를 이용
{
	if (Root->RightSibling != NULL)
		DestroyTree(Root->RightSibling);	// 일단 줄에있는 오른쪽 형제들을 전부 지움. 그리고 재귀하여 맨 왼쪽 노드로 돌아옴

	if (Root->LeftChild != NULL)
		DestroyTree(Root->LeftChild);	// 그리고 나서 다음 줄로 내려감

	DestroyNode(Root);
}

void AddChildNode(Node* Parent, Node* Child)
{
	if (Parent->LeftChild == NULL)  // 만약 자식이 없다면
		Parent->LeftChild = Child;

	else
	{
		Node* Cibling = Parent->LeftChild;
		
		while (Cibling->RightSibling != NULL)	// 맨 왼쪽 자식부터 시작하여 오른쪽 형제가 없을때까지 이동
			Cibling = Cibling->RightSibling;

		Cibling->RightSibling = Child;
	}
}

void PrintTree(Node* Node, int Depth)	 // 재귀
{
	for (int i = 0; i < Depth; i++)
		printf("   ");		// 공백 출력

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		PrintTree(Node->LeftChild, Depth + 1);

	if(Node->RightSibling != NULL)
		PrintTree(Node->RightSibling, Depth);
}

int main()
{
	Node* Root = CreateNode('A');	 // 가장 위 노드가 될 뿌리 노드 선언
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