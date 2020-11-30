/*
Projeto de Algoritmos e Estruturas de Dados I - 2020/1 (SI)
Professor: Edmundo Sérgio Spoto
Alunos: Cláudio da Silva Pinheiro Júnior
        Delvo Resende
        Gleidimar Luiz
        Sávio Matheus de Sousa
*/

#include <stdio.h>
#include <stdlib.h>

#include "tad.h"

int validaCpf (char cpf[], int dim){
    int tamanho = dim;

    //Validando tamanho do vetor enviado (11 caracteres caso sejam armazenados apenas numeros ou 14 caso seja armazenada a pontuacao)
    if(tamanho == 11){
        int i;
        //Validando se apenas numeros foram digitados
        for(i = 0; i<=tamanho; i++){
            if(!isdigit(cpf[i])){
                return 1;
            }
        }
    }else{
        return 1;
    }
    //sucesso
    return 0;
}

// cadastrarPaciente cria um Paciente e o retorna
PACIENTE* cadastrarPaciente(){

    PACIENTE *paciente = (PACIENTE*)malloc(sizeof(PACIENTE));
    char *tmp = (char*)malloc(sizeof(char)*30);

	printf("\nInforme o nome do paciente: ");
    fflush(stdin);
    fgets(paciente->nome, sizeof(paciente->nome), stdin);

    printf("Informe a data de nascimento: ");
    fflush(stdin);
	fgets(paciente->dataDeNascimento, sizeof(paciente->dataDeNascimento), stdin);

	printf("Informe o sexo do paciente (M/F): ");
    fflush(stdin);
	fgets(paciente->sexo, sizeof(paciente->sexo), stdin);

	printf("Informe o CPF do paciente: ");
    fflush(stdin);
	fgets(paciente->CPF, sizeof(paciente->CPF), stdin);

	printf("Informe o peso do paciente: ");
    fflush(stdin);
    fgets(tmp, sizeof(tmp), stdin);
    paciente->peso = strtof(tmp, NULL);

	printf("Informe a altura do paciente: ");
    fflush(stdin);
    fgets(tmp, sizeof(char *), stdin);
    paciente->altura = strtof(tmp, NULL);

    free(tmp);
	return paciente;

}

// toString recebe uma struct Paciente e a imprime 
void toString(PACIENTE *paciente){

    printf("\nNome do paciente: %s", paciente->nome);
    printf("Data de nascimento: %s", paciente->dataDeNascimento);
    printf("Sexo do paciente (M/F): %s", paciente->sexo);
    printf("CPF do paciente: %s", paciente->CPF);
    printf("Peso do paciente: %.2f", paciente->peso);
    printf("\nAltura do paciente: %.2f", paciente->altura);

}

void editarPaciente()
{}

void listarPacientes()
{}

void removerPaciente()
{}

void carregarArquivo()
{}

void salvarArquivo()
{}

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
		PACIENTE newPaciente;
			printf("CPF: ");
			scanf("%s", &newPaciente.cpf);
			printf("Nome Completo: ");
			scanf("%s", &newPaciente.nome);
			printf("Telefone: ");
			scanf("%s", &newPaciente.telefone);
			printf("Endereco: ");
			scanf("%s", &newPaciente.endereco);

			//Apenas deixando metodo de insercao anotado, sera necessario definir algumas informacoes como: Iremos utilizar o CPF indicado como a chave?
			inserirPaciente(new LISTAPACIENTES, newPaciente);

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
