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
	Node* Array;	// 배열의 첫 요소를 가르킴
} Queue;

Queue* CreateQueue(int capacity)
{
	Queue* NewQueue = (Queue*)malloc(sizeof(Queue));
	Node* NewNode = (Node*)malloc(sizeof(Node) * (capacity + 1));	// 입력받은 크기에 +1

	NewQueue->Rear = 0;
	NewQueue->Front = 0;
	NewQueue->Capacity = capacity;
	NewQueue->Array = NewNode;

	return NewQueue;
}

void DestroyQueue(Queue* Destroy)
{
	free(Destroy->Array);		// 할당받았던 배열 해제
	free(Destroy);		// 스택 구조체도 해제
}

bool QueueFull(Queue* queue)
{
	if (queue->Rear == queue->Capacity)	 // 만약 지금 배열의 끝부분에 있다면
		return (queue->Front == 0);	 // 다음 요소인 0이 Front인지 확인, Front가 0이면 꽉찬것

	else
		return (queue->Rear+1 == queue->Front);	// Rear은 비어있는 공간, 다음 공간이 Front면 배열이 꽉 찬것
}
// 비어 있는 것과 꽉 찬것을 구분하기 위해 일부로 빈 공간 만들어놓음. 그래서 원하는 양보다 1개 더 생성해준것.	
// 꽉 찬것은 비어있는 Rear의 다음이 Front면 꽉 찬것. 그래서 enqueue 연산시 값을 넣은 공간이 Rear이 아니고 값 넣은 다음 공간이 Rear.

bool QueueEmpty(Queue* queue)
{
	return(queue->Rear == queue->Front);
}


void Enqueue(Queue* queue, int data)
{
	int num = queue->Rear;

	if (queue->Rear == queue->Capacity)	 // 만약 배열의 마지막 인덱스까지 갔다면 다시 처음으로 돌아감
		queue->Rear = 0;

	else
		queue->Rear++;

	queue->Array[num].Data = data;
}

void Dequeue(Queue* queue)
{
	int num = queue->Front;

	if (queue->Front == queue->Capacity)	 // 만약 배열의 마지막 인덱스까지 갔다면 다시 처음으로 돌아감
		queue->Front = 0;

	else
		queue->Front++;

	printf("%d 삭제 \n", queue->Array[num].Data);
}

int main()
{
	Queue* queue = CreateQueue(5);

	for (int i = 1; i < 6; i++)
		Enqueue(queue, i * 10);

	for (int i = 0; i < 5; i++)
		printf("%d ", queue->Array[i].Data);	// 10 20 30 40 50
	// 지금 Rear은 빈공간인 인덱스 5에 있음. 6번째

	printf("\n");

	if (QueueFull)
		printf("큐가 꽉 찼습니다\n");

	printf("Front: %d, Rear: %d\n", queue->Front, queue->Rear);	 // 0, 5

	while (!QueueEmpty(queue))
		Dequeue(queue);

	printf("Front: %d, Rear: %d\n", queue->Front, queue->Rear);  // 5, 5

	return 0;

}
