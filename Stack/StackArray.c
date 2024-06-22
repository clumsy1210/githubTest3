#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node	// 동적할당 받을 스택 배열을 선언해줌
{
	int Data;
} Node;

typedef struct
{
	int Capacity;	// 총 용량
	int Top;		// 현재 가장 위 요소의 위치
	Node* Array;	// 할당 받은 배열의 첫 요소의 주소값을 가짐. 배열이므로 +1로 다음 요소 이동 가능
} ArrayStack;

ArrayStack* CreateStack(int capacity)
{
	ArrayStack* NewStack = (ArrayStack*)malloc(sizeof(ArrayStack));

	NewStack->Capacity = capacity;
	NewStack->Top = -1;		// 배열은 인덱스가 0부터 시작이므로 -1부터 ++해줌.
	NewStack->Array = (Node*)malloc(sizeof(Node) * capacity);

	return NewStack;
}

void DestroyStack(ArrayStack* Stack)
{
	free(Stack->Array);		// 할당받았던 배열 해제
	free(Stack);		// 스택 구조체도 해제
}

void Push(ArrayStack* Stack, int data)
{
	if (Stack->Capacity == (Stack->Top) + 1)	// 만약 capacity가 top+1과 같다면 꽉 찬것이므로 종료
		printf("스택이 꽉 찼으므로 push 불가! \n");
	
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
		printf("스택이 비어있으므로 pop 불가!\n");
	}

	else
	{
		printf("%d 삭제!\n", Stack->Array[Stack->Top].Data);
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

int GetSize(ArrayStack* Stack)	// 현재 요소 몇개 들어있는지 반환
{
	return Stack->Top + 1;
}

int main()
{
	ArrayStack* Stack;		// 스택 배열을 가르킬 변수 선언
	int i, capacity = 10;

	Stack = CreateStack(10);	// stack에 새로 생성한 ArrayStack 구조체를 넣어줌

	for (i = 1; i <= 6; i++)
		Push(Stack, i * 10);

	printf("용량: %d, 요소의 개수: %d, 스택의 가장 위 값: %d\n", Stack->Capacity, GetSize(Stack), Top(Stack));

	for (i = 7; i <= 10; i++)
		Push(Stack, i * 10);

	Push(Stack, 110);		// 꽉 찬 이후에 값을 넣어봄

	for (i = 0; i <10; i++)	// 값을 모두 pop 해봄
		Pop(Stack);

	Pop(Stack);  // 배열을 비운 뒤 한번 더 Pop 해봄

	if (IsEmpty(Stack))
		printf("스택이 모두 비었습니다.\n");

	DestroyStack(Stack);

	return 0;
}