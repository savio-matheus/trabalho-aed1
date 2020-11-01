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

int validaCpf (char[] cpf){
    int tamanho = sizeof(cpf);

    //Validando tamanho do vetor enviado (11 caracteres caso sejam armazenados apenas numeros ou 14 caso seja armazenada a pontuacao)
    if(tamanho == 11){
        int i;
        //Validando se apenas numeros foram digitados
        for(i = 0; i<=tamanho; i++){
            if(isdigit(cpf[i]))
                continue;
            else{
                return 1;
            }
    }
    }else{
        return 1;
    }

    //sucesso
    return 0;

}

void cadastrarPaciente()
{}

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
