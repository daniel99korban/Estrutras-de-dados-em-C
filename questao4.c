#include "bibliotecas/ArvoreBinaria.h"

int main(){
    /*4) Modifique o código de árvores para armazenar os dados de estudantes como
    mostrado nas aulas anteriores. Cada nó deve ser inserido tendo como base o 
    número da matrícula.*/
    ArvBin* arvore = criar_arvore();
    struct aluno al;

    strcpy(al.nome, "Teste1"); al.matricula = 5;
    inserir_aluno_arvore(arvore, al);

    strcpy(al.nome, "Teste2"); al.matricula = 3;
    inserir_aluno_arvore(arvore, al);

    strcpy(al.nome, "Teste3"); al.matricula = 6;
    inserir_aluno_arvore(arvore, al);

    strcpy(al.nome, "Teste4"); al.matricula = 4;
    inserir_aluno_arvore(arvore, al);

    strcpy(al.nome, "Teste5"); al.matricula = 1;
    inserir_aluno_arvore(arvore, al);

    strcpy(al.nome, "Teste6"); al.matricula = 2;
    inserir_aluno_arvore(arvore, al);

    preOrdemAluno(arvore);

    system("pause");
    liberar_arvore(arvore);
    return 0;
}