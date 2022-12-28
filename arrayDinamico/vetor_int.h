#ifndef SIMPLE_VECTOR_INT_H
#define SIMPLE_VECTOR_INT_H

struct array_list {
    int * data;
    unsigned int size, capacity;
};

struct array_list * create_int ();

void destroy_list(struct array_list *a);

void append_int (struct array_list *a, int x, int *erro);

int insert_int (int a[], int tamanho, int capacidade, int x, int ind);

int remove_int (int a[], int tamanho, int capacidade, int ind);

int find_int (int a[], int tamanho, int capacidade, int x);

#endif