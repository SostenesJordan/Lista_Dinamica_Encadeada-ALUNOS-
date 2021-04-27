#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "Interface.h"

using namespace std;


void menu() {
	printf("\n#############################################");
	printf("\n           MENU - Lista de informacao      ");
	printf("\n");
	printf("\n");
	printf("\n");
	printf("\n-->  [1] = Matriculas (total)\n   ");
	printf("\n-->  [2] = Adicionar novo aluno\n ");
	printf("\n-->  [3] = Remover aluno\n ");
	printf("\n-->  [4] = Buscar\n  ");
	printf("\n-->  [5] = Situacao do estudante\n ");
	printf("\n-->  [6] = Imprimir lista de alunos\n ");
	printf("\n-->  [7] = calcular a media de todos os alunos\n ");
	printf("\n");
	printf("\nQualquer outra tecla  vai sair\n ");
	printf("\n");
	printf("\n#############################################");
	printf("\n\n\n>> ");
}

int exibe_consulta(struct aluno* al) {
	cout << "Matricula - " << al->matricula;
	cout<<"Nome - "<<al->nome<<endl;
}