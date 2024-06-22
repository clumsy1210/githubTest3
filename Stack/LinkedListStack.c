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
	Node* HEAD;	// 맨 아래
	Node* TAIL;	// 맨 위
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
	Node* NewNode = (Node*)malloc(sizeof(Node));	// 노드 생성
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
	if (stack->HEAD == NULL)	// 만약 요소가 없다면
	{
		stack->HEAD = node;
		stack->TAIL = node;
	}

	else
	{
		stack->TAIL->NextNode = node;	// 맨 위 노드의 다음 노드를 새로운 노드로 지정해줌
		stack->TAIL = node;		// TAIL을 새로운 노드로 지정
	}
}

void Pop(Stack* stack)
{
	if (stack->HEAD == NULL)
		printf("더 이상 지울 노드 없음!");

	else if (stack->HEAD == stack->TAIL)	// 만약 요소가 1개라면
	{
		DestroyNode(stack->TAIL);
		stack->HEAD = NULL;
		stack->TAIL = NULL;
	}

	else
	{
		Node* BeforeTail = stack->HEAD;	// 맨 위 노드의 아래 노드를 나타낼 변수 선언

		while (BeforeTail->NextNode != stack->TAIL)
			BeforeTail = BeforeTail->NextNode;

		DestroyNode(stack->TAIL);	// 맨 위 노드 지움
		stack->TAIL = BeforeTail;	// 맨 위를 바로 아래 노드로 지정해줌
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

	while (HEAD2 != NULL)	// 만약 NULL이라면 0개 반환
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
	Stack* stack = CreateStack();	// 스택 생성

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
		printf("스택이 비었습니다\n");

	return 0;
}