struct aluno {
    int matricula;
    char nome[30];
    float n1 = 0;
    float n2 = 0;
    float media;
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);

int insere_aluno_ordenada_matricula(Lista* li, struct aluno al);

void imprime_lista(Lista* li);

int remove_lista(Lista* li, int mat);

int consulta_lista_mat(Lista* li, int mat, struct aluno* al);

void liberarLista(Lista* li);











