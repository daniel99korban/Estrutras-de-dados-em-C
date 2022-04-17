#include <stdio.h>
#include <stdlib.h>
#include "bibliotecas/ArvoreBinaria.h"


#define TAM 10

int main(){
    //2) Escreva uma função que conte a quantidade de nós folhas em uma árvore.
    ArvBin* arvore = criar_arvore();
    int vet[TAM] = {5, 3, 6, 4, 1, 2, 12, 8, 7, 20};

    for(int i=0; i<TAM; i++)
        inserir_arvore(arvore, vet[i]);

    printf("\nElementos da arvore\n");
    emOrdem(arvore);
    
    int qtdNos = contarNoFolha((*arvore));
    printf("\nA arvore binaria possui %d folha(s)\n", qtdNos);
    system("pause");
    liberar_arvore(arvore);
    return 0;
}