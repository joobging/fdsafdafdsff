#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void main(void) {
	queue_t q;
	init_queue(&q);
	char op[5];
	int val;
	while (1) {
		print_queue(&q);
		printf(" >> ");
		scanf_s("%s", op, 5);
		if (op[0] == '+') {
			scanf_s("%d", &val);
			enqueue(&q, val);
		}
		else if (op[0] == '-') {
			val = dequeue(&q);
		}
		else if (op[0] == '0')
			break;
	}
}
