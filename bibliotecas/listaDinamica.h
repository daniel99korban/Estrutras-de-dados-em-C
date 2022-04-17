#include <stdio.h>
#include <stdlib.h>

#if ! defined(struct_aluno)
#define struct_aluno
struct aluno{
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
#endif

typedef struct no* Lista;

Lista* criar_lista();
void liberar_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int inserir_lista_inicio(Lista *li, struct aluno al);
int inserir_lista_final(Lista* li, struct aluno al);
int inserir_lista_ordenada(Lista *li, struct aluno al);
int remover_lista_inicio(Lista* li);
int remover_lista_final(Lista* li);

int busca_lista_mat(Lista* li, int mat, struct aluno *al);
void imprimir_lista(Lista* li);