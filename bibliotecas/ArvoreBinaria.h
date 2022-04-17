#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../bibliotecas/listaDinamica.h"

typedef struct No *ArvBin;

ArvBin* criar_arvore();
void liberar_arvore(ArvBin *raiz);
int inserir_arvore(ArvBin * raiz, int valor);
int remover_arvore(ArvBin * raiz, int valor);
int arvore_vazia(ArvBin * raiz);
int altura_arvore(ArvBin * raiz);
int total_nos(ArvBin *raiz);
int consulta_arvore(ArvBin * raiz, int valor);
void preOrdem(ArvBin* raiz);
void preOrdemAluno(ArvBin *raiz);
void emOrdem(ArvBin* raiz);
void posOrdem(ArvBin* raiz);
int contarNoFolha(struct No* raiz);
ArvBin* gerarArvoreBinaria(Lista* minha_lista);
int inserir_aluno_arvore(ArvBin* raiz, struct aluno al);