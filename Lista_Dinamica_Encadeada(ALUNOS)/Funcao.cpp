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

// Fun��o reserva um espa�o na memoria
Lista* cria_lista() {
    Lista* li = (Lista*)malloc(sizeof(Lista)); 
    if (li != NULL) {
        *li = NULL;
    }
    return li;
}





//                  Liberar lista
// A fun��o ir� percorrer todos os elementos cadastrados na lista
// Andando em cada posi��o at� a sua ultima posi��o preenchida...
// Quando chegar na ultima ela ser� feito o free(lista) >> LIMPAR LISTA
void libera_lista(Lista* li) {

    if (li == NULL) {
        Elem* no;
        while (*li != NULL)//
        {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
// FIM LIBERA LISTA


//------------------------------------------------------------------------------------------


// Primeiramente a fun��o ir� verificar se a lista tem algum elemento
// Depois com a variavel no que vai receber um valor por vez da lista por meio do while
// E o contador vai receber (cont) a quantidade de loops que foram feitos (cada loop representa um aluno cadastrado)

int tamanho_lista(Lista* li) {

    if (li == NULL) {
        return 0;
    }
    int cont = 0;
    Elem* no = *li;

    while (no != NULL) {
        cont++;
        no = no->prox;
    }



    return cont;
    cout <<" "<< cont;
}
// FIM TAMANHO DA LISTA


//------------------------------------------------------------------------------------------


// Basicamente � a mesma verifica��o que s�o feitas no incio de todas as fun��es...
// Se lista retornar NULL ir� retornar a mesagem que n�o tem elementos.
int lista_vazia(Lista* li) {

    if (li == NULL || *li == NULL) {
        return 1;
    }
    return 0;
}
// FIM LISTA VAZIA


//------------------------------------------------------------------------------------------



// 1� Reserva um novo espa�o para o novo aluno
// ai 'no' (Aluno) vai apontar o elemento anterior para a proxima posi��o
// e esse posi��o vazia vai receber o novo aluno
// Todos os dados ser�o recebidos no arquivo principal.
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
// FIM INSERE ALUNO



//------------------------------------------------------------------------------------------



// Basicamente � a mesma l�gica da fun��o que diz a quantidade de elementos da lista
// A diferen�a � que 'no' (alunos) vai apontar para os dados, e dados ir� apontar para matricula e nome.
// Isso tudo dentro de um loop que ir� percorrer cada aluno e pegar os seus dados imprimindo para o usuario o resultado.
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
//FIM IMPRIMI LISTA



//------------------------------------------------------------------------------------------


// Ela � bem parecida com a de adicionar
// Enquanto o ponteiro move um alemento para frente em forma de fila crescente
// A fun��o de remover funciona como uma fila decrescente.
// Lembrando que a remo��o � feito pelo n� da matricula, ent�o ele vai buscar o valor referente da matricula informada
// ai caso n�o tenha niguem com a matricula informada ele ir� exibir uma mensagem
// ocorrendo tudo certo ele vai da um Free (LIMPAR) no elemento buscado
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
// FIM REMOVE LISTA


//------------------------------------------------------------------------------------------


// 1� ele recebe vai receber um valor de matricula
// e com esse valor ele vai fazer uma busca para ver se o aluno existe
// Ai caso o aluno exista todos os ir�o para o 'no' e ser�o apontados para os seus dados
// feito isso ele vai perguntar se quer adicionar nota do aluno, pq o seus status anterior � de 'cursando...' pois n�o tem notas ainda
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
            cout << "Aluno est� cursando no momento" << endl<<endl;

            cout << "Deseja inserir as notas do aluno? " << endl << "[1] >> SIM || [2] >> NAO -> "; cin >> opcao;
            if (opcao == 1) {
                cout << "Insira a N1 : "; cin >> al->n1;
                cout << "Insira a N2 : "; cin >> al->n2;

                if (al->n1 * 0.4 + al->n2 * 0.6 >= 6) {
                    cout << "Aluno aprovado!" << endl;
                    return 1;
                }
                else
                {
                    cout << "Aluno reprovado!" << endl;
                    return 1;
                }


            }
            if (opcao != 1)
            {
                return 1;
            }

        }

    }
}
// FIM CONSULTA LISTA


//------------------------------------------------------------------------------------------

void liberarLista(Lista* li) {
    free(li);
}