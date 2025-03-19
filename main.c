#include <stdio.h>
#include <stdlib.h>


typedef int elem_t;
struct tag {
	int size;
	elem_t array[100];
};
typedef struct tag arrlist_t;

elem_t get_at(arrlist_t* listp, int indx) {
	return listp->array[indx];
}
int len(arrlist_t* listp) {
	return listp->size;
}

int find(arrlist_t* listp, elem_t e) { // 첫번째 매개변수로 구조체 포인터
	for (int i = 0; i < listp->size; i++) {
		if (listp->array[i] == e)
		return i;
	}
	return -1;
}


elem_t get_next() {
	return rand() % 100;
}


void run_menu(arrlist_t* listp);

void input_list(arrlist_t* listp);
void print_list(arrlist_t* listp);
void add_list(arrlist_t* listp, elem_t val);
void insert_list(arrlist_t* listp, int pos, elem_t val);
elem_t delete_list(arrlist_t* listp, int pos);
elem_t update_list(arrlist_t* listp, int pos, elem_t val);
void hap(arrlist_t* set1, arrlist_t* set2, arrlist_t* result);

void main() {
	arrlist_t set1, set2;
	set1.size = 10;
	set2.size = 20;
	input_list(&set1);
	input_list(&set1);
	print_list(&set1);
	print_list(&set2);
	arrlist_t result;
	hap(&set1, &set2, &result);
	print_list(&result);
}

void run_menu(arrlist_t* listp) {
	int pos;
	elem_t val;
	int menu;

	while (1) {
		printf("\n(1) 끝에 값 추가 \n(2) pos번째에 값 추가\n");
		printf("(3) pos번째 삭제 \n(4) pos번째 값 변경 \n(5) 종료 ");
		printf(" 메뉴선택 => ");
		scanf_s("%d", &menu);
		if (menu == 5) break;
		if (menu > 5 || menu <= 0) continue;
		switch (menu) {
		case 1: printf("끝에 추가할 값: ");
			add_list(listp, get_next());
			//print_list();
			break;
		case 2: printf("추가할 위치: ");
			scanf_s("%d", &pos);
			insert_list(listp, pos, get_next());
			//print_list();
			break;
		case 3: printf("삭제할 위치를 입력하세요..");
			scanf_s("%d", &pos);
			delete_list(listp, pos);
			//print_list();
			break;
		case 4: printf("수정할 위치와 값을 입력하세요..");
			scanf_s("%d %d", &pos, &val);
			update_list(listp, pos, val);
			//print_list();
			break;
		default: // ...;
			break;
		}
		print_list(listp->array);
	}
	print_list(listp->array);
}

void input_list(arrlist_t* listp) {
	for (int i = 0; i < listp->size; ++i) {
		listp->array[i] = get_next();
	}
}
void print_list(arrlist_t* listp) {
	for (int i = 0; i < listp->size; ++i) {
		printf("%3d,", listp->array[i]);
		if (i % 8 == 7)
			printf("\n");
	}
}
void add_list(arrlist_t* listp, elem_t val) {
	printf("값 %d를 리스트 맨 끝에 추가합니다.\n", val);
	listp->array[listp->size++] = val;
}

void insert_list(arrlist_t* listp, int pos, elem_t val) {
	printf("값 %d를 %d 번째에 삽입합니다.\n", val, pos);
	for (int k = listp->size - 1; k >= pos; k--)
		listp->array[k + 1] = listp->array[k];
	listp->array[pos] = val;
	listp->size++;
}
int delete_list(arrlist_t* listp, int pos) {
	int result = listp->array[pos];
	for (int k = pos; k < listp->size - 1; k++)
		listp->array[k] = listp->array[k + 1];
	printf("%d 번째 값을 삭제합니다. 값 = %d\n", pos, result);
	listp->size--;
	return result;
}
int update_list(arrlist_t* listp, int pos, elem_t val) {
	int result = listp->array[pos];
	listp->array[pos] = val;
	printf("%d 번째 값을 %d로 변경합니다. 이전값 = %d\n", pos, val, result);
	return result;
}

void hap(arrlist_t* set1, arrlist_t* set2, arrlist_t* result) {
	result->size = 0; // 처음에는 결과 리스트는 비어 있다
	for (int i = 0; i < len(set1); i++)
		if (find(result, get_at(set1, i)) == -1) // set1에서 새로운 값만
			add_list(result, get_at(set1, i)); // set1을 하나씩 추가
	for (int i = 0; i < len(set2); i++)
		if (find(result, get_at(set2, i)) == -1) // set2에서 새로운 값만
			add_list(result, get_at(set2, i)); // 하나씩 추가
}

void gyo(arrlist_t* set1, arrlist_t* set2, arrlist_t* result) {
	result->size = 0;
	//for(int i = 0; )
}
