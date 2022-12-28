#include <stdlib.h>
#include <stdio.h>
#include "vetor_int.h"

struct array_list * create_int () {
    struct array_list *a = (struct array_list *) malloc(sizeof(struct array_list));
    if (a==0) return 0;
    a->data = (int*) malloc(sizeof(int)*100);
    a->size = 0;
    a->capacity = 100;
    return a;
}

void destroy_list(struct array_list *a) {
    free(a->data);
    free(a);
}

void append_int (struct array_list *a, int x, int *erro) {
    *erro = 1;
    if (a->size==a->capacity) {
        a->capacity = a->capacity+100;
        int *novo = (int*) malloc(sizeof(int) * (a->capacity));
        int *antigo = a->data;
        for (int i = 0; i<a->size; ++i) {
            *(novo+i) = *(antigo+i);
        }
        a->data = novo;
        free(antigo);
    }
    a->data[a->size] = x;
    a->size++;
    *erro = 0;
}

int insert_int (int a[], int tamanho, int capacidade, int x, int ind) {
    if (tamanho != capacidade) {
        for (int i = tamanho++; i > ind; --i) {
            a[i] = a[i-1];
        }
    }
    return tamanho;
}

int remove_int (int a[], int tamanho, int capacidade, int ind) {
    for (int i = ind; i < tamanho; ++i) {
        a[i] = a[i+1];
    }

    return --tamanho;
}

int find_int (int a[], int tamanho, int capacidade, int x) {
    while (tamanho-- && a[tamanho]!=x);
    return tamanho;
}