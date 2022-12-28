#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vetor_int.h"

void printf_vector(struct array_list *a) {
    printf(" (%u %u) { ", a->size, a->capacity);
    for (int i = 0; i<a->size; i++) {
        printf("%d ", *(a+i));
    }
    printf("}\n");
}

int main (){
    clock_t inicio, fim;
    struct array_list *a1 = create_int();
    int erro;

    inicio = clock();

    for (int i = 0; i<201; ++i) {
        append_int(a1, i*3, &erro);
        if (erro) {
            printf("Erro de memoria!\n");
            break; 
        }
    }

    fim = clock();

    printf_vector(a1);
    
    destroy_list(a1);

    printf("\n");

    double tempo = (fim-inicio)/(CLOCKS_PER_SEC/1000.0);
    printf("Tempo decorrido: %lfms\n", tempo);

    return 0;
}