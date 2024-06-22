#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node* NextNode;
} Node;

Node* CreateNode(int data)		// 노드 생성
{
	Node* NewNode = (Node*)malloc(sizeof(Node)); 
	
	NewNode->data = data;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Destroy)		// 노드 해제
{
	free(Destroy);
}

void AppendNode(Node** HEAD, Node* NewNode)		// 노드 새로 추가
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

Node* GetNode(Node* HEAD, int num)   // num번째 노드의 포인터변수를 반환해줌
{
	for (int i = 0; i < num; i++)
	{
		HEAD = HEAD->NextNode;
	}

	return HEAD;
}

int NodeCount(Node* HEAD)		// 노드의 개수를 세서 반환해줌
{
	int count = 1;		// HEAD부터 시작하므로 1부터 시작

	if (HEAD == NULL)		// 만약 0개라면
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

void RemoveNode(Node** HEAD, Node* Remove)   // 특정 위치의 노드를 지워줌
{
	if (*HEAD == Remove)
		*HEAD = Remove->NextNode;

	else
	{
		Node* BeforeRemove = HEAD;

		while (BeforeRemove->NextNode != Remove)
			BeforeRemove = BeforeRemove->NextNode;    // BeforeRemove 다음 노드가 Remove 노드가 됨.

		BeforeRemove->NextNode = Remove->NextNode;    // Remove를 스킵해주면서 연결리스트에서 제외시켜줌
	}

	DestroyNode(Remove);   // 노드를 지워줌
}

void PrintNode(Node* HEAD)  // 연결리스트 출력
{
	for (HEAD; HEAD != NULL; HEAD = HEAD = HEAD->NextNode)
		printf("%d->", HEAD->data);

	printf("NULL \n");
}

void DestroyAllNodes(Node** HEAD)    // 링크드 리스트 전체 삭제하는 함수 
{
	Node* Del = NULL;   // 없앨 노드를 가르키는 변수 선언

	while ((*HEAD) != NULL)
	{
		Del = (*HEAD);
		*HEAD = (*HEAD)->NextNode;
		DestroyNode(Del);
	}
}

int main()
{
	Node* HEAD = NULL;   // HEAD 노드의 주소값을 저장하는 변수 HEAD 선언 
	Node* CurrentNode = NULL;

	AppendNode(&HEAD, CreateNode(10));	// 0번째
	AppendNode(&HEAD, CreateNode(20));	// 1번째
	AppendNode(&HEAD, CreateNode(30));	// 2번째
	AppendNode(&HEAD, CreateNode(40));	// 3번째
	AppendNode(&HEAD, CreateNode(50));	// 4번째

	PrintNode(HEAD);		// 10, 20, 30, 40, 50  

	CurrentNode = GetNode(HEAD, 1);   // 1번째 요소 다음에 노드를 하나 추가할 것임.
	InsertNode(CurrentNode, CreateNode(25));  // 10 20 25 30 40 50

	PrintNode(HEAD);

	CurrentNode = GetNode(HEAD, 0);		// HEAD 삭제(10 삭제)
	RemoveNode(&HEAD, CurrentNode);		// 20, 25, 30, 40, 50

	PrintNode(HEAD);

	DestroyAllNodes(&HEAD);

	PrintNode(HEAD);

	return 0;
}