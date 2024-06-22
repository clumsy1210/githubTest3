#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node
{
	int Data;
	struct node* NextNode;
} Node;

typedef struct queue
{
	Node* Front;
	Node* Rear;
} Queue;

bool QEmpty(Queue* queue)
{
	return (queue->Front == NULL && queue->Rear == NULL);
}

Queue* CreateQueue()
{
	Queue* NewQueue = (Queue*)malloc(sizeof(Queue));

	NewQueue->Front = NULL;	// 첫 노드
	NewQueue->Rear = NULL;	// 마지막 노드

	return NewQueue;
}

Node* CreateNode(int data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = data;
	NewNode->NextNode = NULL;

	return NewNode;
}

void DestroyNode(Node* Destroy)
{
	free(Destroy);
}


void Enqueue(Queue* queue, Node* node)
{
	if (queue->Front == NULL && queue->Rear == NULL)		// 요소가 하나도 없을 시
	{
		queue->Front = node;
		queue->Rear = node;
	}

	else
	{
		queue->Rear->NextNode = node;	// 뒤에 요소를 하나 넣어줌
		queue->Rear = node;
	}
}

void Dequeue(Queue* queue)
{
	if (queue->Front == queue->Rear)	// 요소가 1개일 때
	{
		DestroyNode(queue->Front);
		queue->Front = NULL;
		queue->Rear = NULL;
	}

	else
	{
		Node* Next = queue->Front->NextNode;
		DestroyNode(queue->Front);
		queue->Front = Next;
	}
	
}

void DestroyQueue(Queue* queue)
{
	while (!QEmpty(queue))	// 큐가 비었을때 까지
	{
		Dequeue(queue);
	}

	free(queue);
}

void PrintQueue(Queue* queue)
{
	Node* HeadCopy = queue->Front;

	if (QEmpty(queue))
		printf("큐가 비었습니다.");

	else
	{
		while (HeadCopy != NULL)
		{
			printf("%d ", HeadCopy->Data);
			HeadCopy = HeadCopy->NextNode;
		}
	}

	printf("\n");
}

int main()
{
	Queue* queue = CreateQueue();

	for (int i = 1; i < 6; i++)
		Enqueue(queue, CreateNode(i * 10));

	PrintQueue(queue);

	while (!QEmpty(queue))
		Dequeue(queue);

	PrintQueue(queue);

	DestroyQueue(queue);

	return 0;
}