#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "Interface.h"

using namespace std;

struct elemento {
    struct aluno dados;
    struct elemento* prox;
};

typedef struct elemento Elem;

Lista* cria_lista() {
    Lista* li = (Lista*)malloc(sizeof(Lista));

    if (li != NULL) {
        *li = NULL;
    }
    return li;
}

void libera_lista(Lista* li) {

    if (li == NULL) {
        Elem* no;
        while (*li != NULL)
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanho_lista(Lista* li) {

    if (li == NULL) {
        return 0;
    }
    int cont = 0;
    Elem* no = *li;

    while (li != NULL)
    {
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_vazia(Lista* li) {

    if (li == NULL || *li == NULL) {
        return 1;
    }
    return 0;
}

int insere_aluno_ordenada_matricula(Lista* li, struct aluno al) {

    if (li == NULL) {
        return 0;
    }
    Elem* no = (Elem*)malloc(sizeof(Elem));

    if (no == NULL) {
        return 0;
    }
    no->dados = al;

    if (*li == NULL) {
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else
    {
        Elem* ant = *li; 
        Elem* atual = *li;
        while (atual != NULL && atual->dados.matricula < al.matricula)
        {
            ant = atual;
            atual = atual->prox;
        }
        if (atual == *li) {
            no->prox = *li;
            *li = no;
        }
        else
        {
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

void imprime_lista(Lista* li) {

    if (li == NULL) {
        return;
    }
    Elem* no = *li;
    while (no != NULL)
    {
        cout <<"Matricula - "<< no->dados.matricula<<endl;
        cout << "Nome - " << no->dados.nome<<endl;
        cout << "---------"<<endl;
        no = no->prox;
    }
}

int remove_lista(Lista* li, int mat) {

    if (li == NULL) {
        return 0;
    }
    if (*li == NULL) {
        return 0;
    }
    Elem* ant, *no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        ant = no;
        no = no->prox;
    }
    if (no == NULL) {
        cout << "Elemento referente a :" << mat << "\n nao foi encontrado"<<endl;
        return 0;
    }
    if (no == *li) {

        *li = no->prox;
        cout << "Matricula : " <<mat<<" foi removida..."<< endl;
    }
    free(no);

    return 1;
}

int consulta_lista_mat(Lista* li, int mat, struct aluno* al) {

    if (li == NULL) {
        return 0;
    }
    Elem* no = *li;
    while (no != NULL && no->dados.matricula != mat)
    {
        no = no->prox;
    }
    if (no == NULL) {

        cout << "Aluno nao encontrado!" << endl;
        return 0;
    }
    else
    {
        *al = no->dados;
        
        cout << "Matricula - " << al->matricula << endl;
        cout << "Nome - " << al->nome << endl;

        if (al->n1 == 0 && al->n2 == 0) {
            int opcao;
            cout << "Aluno cursando..." << endl<<endl;

            cout << "Deseja adicionar as notas do aluno ?" << endl << "Digite [1] para SIM || Digite [2] para NAO >> "; cin >> opcao;
            if (opcao == 1) {
                cout << "Digite a nota 1 : "; cin >> al->n1;
                cout << "Digite a nota 2 : "; cin >> al->n2;
            }
            if (al->n1 * 0.4 + al->n2 * 0.6 >= 6) {
                cout << "Aluno aprovado!" << endl;
                return 1;
            }
            if (al->n1 * 0.4 + al->n2 * 0.6 <= 6)
            {
                cout << "Aluno reprovado!" << endl;
                return 1;
            }
        }

    }
}

void liberarLista(Lista* li) {
    free(li);
}