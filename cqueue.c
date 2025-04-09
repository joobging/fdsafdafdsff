#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void init_queue(queue_t* q)
{
	q->front = 0;
	q->rear = 0;
}
int is_full(queue_t* q)
{
	return (____________________________);
}
int is_empty(queue_t* q)
{
	return (q->front == q->rear);
}
void enqueue(queue_t* q, elem_t item)
{
	if (is_full(q)) {
		printf("큐가 포화상태입니다");
		return;
	}
	q->rear = ________________________;
	q->data[q->rear] = item;
}

elem_t dequeue(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다");
		return err_elem;
	}
	q->front = ________________________;

	return q->data[q->front];
}

elem_t peek(queue_t* q)
{
	if (is_empty(q)) {
		printf("큐가 비어있습니다");
		return err_elem;
	}
	return q->data[________________________];
}
// 원형큐 출력 함수
void print_queue(queue_t* q)
{
	printf("[");
	for (int i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (________________________) 	    // i가 front 왼쪽
			printf("  --");
		else if (________________________)
			printf("%4d", q->data[i]);  // i가 front와 rear 사이
		else if (________________________)
			printf("%4d", q->data[i]);  //  rear가 앞에 있고 i가 rear보다 왼쪽
		else if (________________________)
			printf("%4d", q->data[i]);  //  rear가 앞에 있고 i가 front보다 오른쪽
		else printf("  --");                // rear와 front 사이
	}
	printf(" ]");
}
