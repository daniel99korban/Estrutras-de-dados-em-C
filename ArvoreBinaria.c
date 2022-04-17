#include "bibliotecas/ArvoreBinaria.h"
#include "listaEncadeada.c"
//#include "bibliotecas/listaDinamica.h"

struct No{
    struct aluno al;
    struct No *esq;
    struct No *dir;
};

ArvBin* criar_arvore(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void liberar_no(struct No* no){
    if(no == NULL)
        return;
    liberar_no(no->esq);
    liberar_no(no->dir);
    free(no);
    no = NULL;
}

void liberar_arvore(ArvBin* raiz){
    if(raiz == NULL)
        return;
    liberar_no(*raiz);
    free(raiz);
}

int arvore_vazia(ArvBin *raiz){
    if (raiz == NULL)
        return 1;
    if (*raiz == NULL)
        return 1;
    return 0;
}

int total_nos(ArvBin *raiz){
    if(raiz==NULL)
        return 0;
    if(*raiz == NULL)
        return 0;
    int total_esq = total_nos(&((*raiz)->esq));
    int total_dir = total_nos(&((*raiz)->dir));
    return (total_esq + total_dir + 1);
}

int altura_arvore(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_arvore(&((*raiz)->esq));
    int alt_dir = altura_arvore(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

void preOrdem(ArvBin *raiz){
    if(raiz == NULL)
        return;

    if(*raiz != NULL){
        printf("%d ", (*raiz)->al.matricula);
        preOrdem(&((*raiz)->esq));
        preOrdem(&((*raiz)->dir));
    }
}
void preOrdemAluno(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("Matricula: %d \n", (*raiz)->al.matricula);
        printf("Nome: %s \n", (*raiz)->al.nome);
        printf("Notas: %.1f %.1f %.1f\n", (*raiz)->al.n1, (*raiz)->al.n2, (*raiz)->al.n3);
        printf("=====================\n");
        preOrdemAluno(&((*raiz)->esq));
        preOrdemAluno(&((*raiz)->dir));
    }
}

void emOrdem(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem(&((*raiz)->esq));
        printf("%d ", (*raiz)->al.matricula);
        emOrdem(&((*raiz)->dir));
    }
}

void posOrdem(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem(&((*raiz)->esq));
        posOrdem(&((*raiz)->dir));
        printf("%d ", (*raiz)->al.matricula);
    }
}

int inserir_arvore(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No *novo;
    novo = (struct No*) malloc(sizeof(struct No));
    if (novo == NULL)
        return 0;
    novo->al.matricula = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->al.matricula){
                free(novo);
                return 0;
            }
            if(valor > atual->al.matricula)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (valor > ant->al.matricula)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct No* remover_atual(struct No* atual){
    struct No *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}

int remover_arvore(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No *ant = NULL;
    struct No *atual = *raiz;
    while(atual != NULL){
        if(valor == atual->al.matricula){
            if (valor == (*raiz)->al.matricula)
                *raiz = remover_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remover_atual(atual);
                else
                    ant->esq = remover_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->al.matricula)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int consulta_arvore(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct No* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->al.matricula) 
            return 1;
        if(valor > atual->al.matricula)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int contarNoFolha(struct No* raiz){
    if(raiz==NULL){
        return 0;
    }// verificar nó folha
    if(raiz->esq == NULL && raiz->dir == NULL){
        return 1;
    }
    if(raiz->esq==NULL)// caso não possua sub-arvores a esqueda
        return contarNoFolha(raiz->dir);
    if(raiz->dir==NULL)// caso não possua sub-arvores a direita
        return contarNoFolha(raiz->esq);

    int qtdNoFolha = contarNoFolha(raiz->esq) + contarNoFolha(raiz->dir);
  
    return qtdNoFolha;
}

ArvBin* gerarArvoreBinaria(Lista* minha_lista){
    if(minha_lista == NULL)
        return 0;
    ArvBin* arvore = criar_arvore();
    if(arvore == NULL)
        return 0;
    No* no = (*minha_lista);
    while(no != NULL){
        inserir_arvore(arvore, no->dados.matricula);
        no = no->prox;  
    }
    return arvore;
}

int inserir_aluno_arvore(ArvBin* raiz, struct aluno al){
    if(raiz == NULL)
        return 0;
    struct No *novo;
    novo = (struct No*) malloc(sizeof(struct No));
    if (novo == NULL)
        return 0;
    novo->al = al;
    novo->esq = NULL;
    novo->dir = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct No* atual = *raiz;
        struct No* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(al.matricula == atual->al.matricula){
                free(novo);
                return 0;
            }
            if(al.matricula > atual->al.matricula)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if (al.matricula > ant->al.matricula)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}