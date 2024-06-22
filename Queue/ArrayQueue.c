#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct node
{
	int Data;
} Node;

typedef struct queue
{
	int Rear;
	int Front;
	int Capacity;
	Node* Array;	// �迭�� ù ��Ҹ� ����Ŵ
} Queue;

Queue* CreateQueue(int capacity)
{
	Queue* NewQueue = (Queue*)malloc(sizeof(Queue));
	Node* NewNode = (Node*)malloc(sizeof(Node) * (capacity + 1));	// �Է¹��� ũ�⿡ +1

	NewQueue->Rear = 0;
	NewQueue->Front = 0;
	NewQueue->Capacity = capacity;
	NewQueue->Array = NewNode;

	return NewQueue;
}

void DestroyQueue(Queue* Destroy)
{
	free(Destroy->Array);		// �Ҵ�޾Ҵ� �迭 ����
	free(Destroy);		// ���� ����ü�� ����
}

bool QueueFull(Queue* queue)
{
	if (queue->Rear == queue->Capacity)	 // ���� ���� �迭�� ���κп� �ִٸ�
		return (queue->Front == 0);	 // ���� ����� 0�� Front���� Ȯ��, Front�� 0�̸� ������

	else
		return (queue->Rear+1 == queue->Front);	// Rear�� ����ִ� ����, ���� ������ Front�� �迭�� �� ����
}
// ��� �ִ� �Ͱ� �� ������ �����ϱ� ���� �Ϻη� �� ���� ��������. �׷��� ���ϴ� �纸�� 1�� �� �������ذ�.	
// �� ������ ����ִ� Rear�� ������ Front�� �� ����. �׷��� enqueue ����� ���� ���� ������ Rear�� �ƴϰ� �� ���� ���� ������ Rear.

bool QueueEmpty(Queue* queue)
{
	return(queue->Rear == queue->Front);
}


void Enqueue(Queue* queue, int data)
{
	int num = queue->Rear;

	if (queue->Rear == queue->Capacity)	 // ���� �迭�� ������ �ε������� ���ٸ� �ٽ� ó������ ���ư�
		queue->Rear = 0;

	else
		queue->Rear++;

	queue->Array[num].Data = data;
}

void Dequeue(Queue* queue)
{
	int num = queue->Front;

	if (queue->Front == queue->Capacity)	 // ���� �迭�� ������ �ε������� ���ٸ� �ٽ� ó������ ���ư�
		queue->Front = 0;

	else
		queue->Front++;

	printf("%d ���� \n", queue->Array[num].Data);
}

int main()
{
	Queue* queue = CreateQueue(5);

	for (int i = 1; i < 6; i++)
		Enqueue(queue, i * 10);

	for (int i = 0; i < 5; i++)
		printf("%d ", queue->Array[i].Data);	// 10 20 30 40 50
	// ���� Rear�� ������� �ε��� 5�� ����. 6��°

	printf("\n");

	if (QueueFull)
		printf("ť�� �� á���ϴ�\n");

	printf("Front: %d, Rear: %d\n", queue->Front, queue->Rear);	 // 0, 5

	while (!QueueEmpty(queue))
		Dequeue(queue);

	printf("Front: %d, Rear: %d\n", queue->Front, queue->Rear);  // 5, 5

	return 0;

}
