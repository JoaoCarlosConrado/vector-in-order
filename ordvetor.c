#include <stdio.h>
#include <stdlib.h>
#include "ordvetor.h"

VETORORD* VETORD_create(int n, COMP* compara){//Cria um vetor
    VETORORD* vetorord = malloc(sizeof(VETORORD));
    vetorord->comparador = compara;
    vetorord->N = n;//posições do vetor
    vetorord->P = 0;//quantidade de elementos no vetor
    vetorord->elems = malloc(n * sizeof(void *));
    for(int i = 0;i<n;i++){//zera todas as posições do vetor
        vetorord->elems[i] = NULL;
    }
    return vetorord;
}

void VETORD_add(VETORORD* vetor, void* newelem){//adiciona no vetor
    if (vetor->P < vetor->N) {
        if (vetor->P == 0) {
            vetor->elems[0] = newelem;
        }
        else if 
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == -1 || //faz a verificação de acordo com a função do comparador
                vetor->comparador(newelem, vetor->elems[vetor->P-1]) == 0
        ) {
            vetor->elems[vetor->P] = newelem;
        }else {
            for (int i = vetor->P-1; i > -1; i--) {//faz o swap para colocar o item no lugar correto
                if (vetor->comparador(newelem, vetor->elems[i]) == 1) {
                    vetor->elems[i+1] = vetor->elems[i];
                    vetor->elems[i] = newelem;
                }
                else break;
            }
        }
        vetor->P++;
    }
}

void* VETORD_remove(VETORORD* vetor){
    void* aux = vetor->elems[0];
    for(int i = 0;i<vetor->P;i++){//remove o menor e joga todos uma posição atrás
        vetor->elems[i] = vetor->elems[i+1]; 
    }
    vetor->P--;
    return aux;
}
