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

	NewQueue->Front = NULL;	// ù ���
	NewQueue->Rear = NULL;	// ������ ���

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
	if (queue->Front == NULL && queue->Rear == NULL)		// ��Ұ� �ϳ��� ���� ��
	{
		queue->Front = node;
		queue->Rear = node;
	}

	else
	{
		queue->Rear->NextNode = node;	// �ڿ� ��Ҹ� �ϳ� �־���
		queue->Rear = node;
	}
}

void Dequeue(Queue* queue)
{
	if (queue->Front == queue->Rear)	// ��Ұ� 1���� ��
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
	while (!QEmpty(queue))	// ť�� ������� ����
	{
		Dequeue(queue);
	}

	free(queue);
}

void PrintQueue(Queue* queue)
{
	Node* HeadCopy = queue->Front;

	if (QEmpty(queue))
		printf("ť�� ������ϴ�.");

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