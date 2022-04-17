#include "bibliotecas/ArvoreBinaria.h"
#include "bibliotecas/listaDinamica.h"
#include <time.h>

#define TAM 10
#define semente time(NULL)

int gerar_matricula(){
    return rand() % TAM + 1;
}

int main(){
    //3) Implemente uma função que receba uma lista e a devolva uma árvore binária.
    Lista* minha_lista = criar_lista();
    ArvBin* arvore = criar_arvore();
    struct aluno al;
    
    srand(semente);

    char nome[6], iCaractere[4];

    for(int i=0; i<TAM; i++){
        itoa(i+1, iCaractere, 10);
        strcpy(nome, "Teste"); strcat(nome, iCaractere);
        strcpy(al.nome, nome); 
        al.matricula = gerar_matricula();
        inserir_lista_final(minha_lista, al);
    }

    printf("\nMinha Lista\n");
    imprimir_lista(minha_lista);
    arvore = gerarArvoreBinaria(minha_lista);
    printf("\nMinha Arvore\n");
    preOrdem(arvore);

    printf("\n");
    system("pause");
    liberar_lista(minha_lista);
    liberar_arvore(arvore);
    return 0;
}