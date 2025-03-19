#pragma once
typedef int elem_t;

struct tag {
	int size;
	elem_t array[100];
};
typedef struct tag arrlist_t;


void run_menu(arrlist_t* listp);
void input_list(arrlist_t* listp);
void print_list(arrlist_t* listp);
void add_list(arrlist_t* listp, elem_t val);
void insert_list(arrlist_t* listp, int pos, elem_t val);
elem_t delete_list(arrlist_t* listp, int pos);
elem_t update_list(arrlist_t* listp, int pos, elem_t val);
void hap(arrlist_t* set1, arrlist_t* set2, arrlist_t* result);
elem_t get_at(arrlist_t* listp, int indx);
int len(arrlist_t* listp);
int find(arrlist_t* listp, elem_t e);
elem_t get_next();
