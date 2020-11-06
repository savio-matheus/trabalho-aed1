/*
Projeto de Algoritmos e Estruturas de Dados I - 2020/1 (SI)
Professor: Edmundo Sérgio Spoto
Alunos:
	.
	.
	.
	Sávio Matheus de Sousa
*/

#include <stdio.h>

#include "func.h"
#include "lista.h"

int painel(){
    int opcao;
    printf("*******************************************\n");
    printf("** 1 - Cadastrar paciente                **\n");
    printf("** 2 - Pesquisar paciente                **\n");
    printf("** 3 - Atualizar paciente                **\n");
    printf("** 4 - Excluir paciente                  **\n");
    printf("** 0 - SAIR                              **\n");
    printf("*******************************************\n");

    printf("ESCOLHA: ");
    scanf("%d", &opcao);
    return opcao;
}


int main (void)
{
	int opcao = -1;

	while(opcao != 0){

		opcao = painel;
		switch (opcao)
		{
		case 1:
			// Cadastrar paciente
			break;
		case 2:
			// Pesquisar paciente
			break;
		case 3:
			// Atualizar paciente
			break;
		case 4:
			// Excluir paciente
			break;
		}

	}


	return 0;
}
