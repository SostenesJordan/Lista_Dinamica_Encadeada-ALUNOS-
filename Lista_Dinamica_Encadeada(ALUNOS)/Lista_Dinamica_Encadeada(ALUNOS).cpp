#include <iostream>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include "Interface.h"

int main()
{
    using namespace std;

    setlocale(LC_ALL, "Portuguese");
    
    Lista* li = cria_lista(); 
    struct aluno dados_aluno;
    int matricula_aluno, posicao;
    int opcao;
	int aux = 0;
    int i = 1;

    while (i == 1)
    {
		system("cls");
		printf("\n#############################################");
		printf("\n           MENU - Lista de informacao      ");
		printf("\n");
		printf("\n");
		printf("\n");
		printf("\n-->  [1] = Total de matriculados\n   ");
		printf("\n-->  [2] = Adicionar novo aluno\n ");
		printf("\n-->  [3] = Remover aluno\n ");
		printf("\n-->  [4] = Buscar\n  ");
		printf("\n-->  [5] = Imprimir lista de alunos\n ");
		printf("\n-->  [6] = Calcular a media de todos os alunos\n ");
		printf("\n				[0] = PARA SAIR\n ");
		printf("\n");
		printf("\n\n ");
		printf("\n");
		printf("\n#############################################");
		printf("\n\n\n>> "); cin >> opcao;


		switch (opcao) {

			case 0:
				cout << "Saindo..." << endl;
				i = 0;
				break;



			case 1:
				cout << "Lista tem :"<< tamanho_lista(li)<<" alunos cadastrados"<<endl;
				//tamanho_lista(li);
				system("pause");
				break;

			case 2:
				cout << "Digite a matricula : "; cin >> dados_aluno.matricula;
				cout << "Digite o nome : "; cin >> dados_aluno.nome;
				insere_aluno_ordenada_matricula(li, dados_aluno);
				system("pause");
				break;

			case 3:
				cout << "Digite a matricula a ser removida: "; cin >> matricula_aluno;
				remove_lista(li, matricula_aluno);
				system("pause");
				break;

			case 4:
				cout << "Digite a matricula a ser buscada: "; cin >> matricula_aluno;
				consulta_lista_mat(li, matricula_aluno, &dados_aluno);
				system("pause");
				break;

			case 5:
				imprime_lista(li);
				system("pause");
				break;

			case 6:
				aux = tamanho_lista(li);

				float nota1, nota2, somanota, mediaaluno, somaclasse = 0;
				float mediaclasse = 0;
				int i, aprovado = 0, reprovado = 0, exame = 0;

				for (i = 1; i <= aux; i++)
				{
					cout << "\n Digite a primeira nota: ";
					cin >> nota1;

					cout << "\n Digite a segunda nota: ";
					cin >> nota2;

					somanota = nota1 + nota2;
					mediaaluno = somanota / 2;

					if (mediaaluno >= 7)
					{
						cout << "\n Aprovado";
						exame++;
					}

					else

					{
						cout << "\n Reprovado";
						reprovado++;
					}

					somaclasse = somaclasse + somanota;
				}

				mediaclasse = somaclasse / (aux * 2);
				cout << "\n A media da classe  foi : " << mediaclasse<<endl;
				system("pause");
		}
    }
    
}

