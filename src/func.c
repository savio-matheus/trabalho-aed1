/*
	Funções que implementam as funcionalidades do
	programa e são chamadas na main(), e outras que não se
	encaixam nos outros módulos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "tad.h"
#include "func.h"

typedef struct{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char estado[30];
} Endereco;

typedef struct{
	char email[30];
    char telefone[30];
} Contato;

typedef struct{
	char nome[30];
    char dataDeNascimento[30];
    char sexo[30];
    char CPF[16];
	float peso;
	float altura;
    Endereco endereco;
	Contato contato;
} Paciente;


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
Paciente* cadastrarPaciente(){

    Paciente *paciente = (Paciente*)malloc(sizeof(Paciente));
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
void toString(Paciente *paciente){

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
