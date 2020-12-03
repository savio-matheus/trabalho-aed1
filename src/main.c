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
#include <ctype.h>

#include "tad.h"

/*
 * No CMD (Windows), o comando de limpar o terminal é "cls", enquanto
 * em outros terminais utiliza-se "clear". O trecho abaixo compila
 * condicionalmente a função limparTela() de acordo com o sistema operacional.
 * O Powershell (Windows) aceita os dois comandos.
 */
void limparTela(void)
{
 #if defined (__MINGW32__) || defined(_MSC_VER) // Windows
    system("cls");
 #else // Linux e Unix em geral
    system("clear");
 #endif
}


//Valida dados informados antes de efetivar o cadastro do paciente.
int validaPaciente(PACIENTE *paciente){


    //CPF
        int i;
        //Validando se apenas numeros foram digitados
        // número mágico: 11. Indica o compr. do campo CPF
        for(i = 0; i<=11; i++){
            if(!isdigit(paciente->CPF[i])){
                return 1;
            }
        }

    //Sexo
        if(paciente->sexo != 'M' && paciente->sexo != 'F'){
            return 2;
        }

    //Data de nascimento
    int dataNascInt[3];
    if ( sscanf(paciente->dataDeNascimento, "%d/%d/%d", &dataNascInt[0], &dataNascInt[1], &dataNascInt[2]) == 3 ){
    
     if ( (dataNascInt[0] > 0 && dataNascInt[0] < 32) && (dataNascInt[1] > 0 && dataNascInt[1] < 13) && (dataNascInt[2] > 1900 && dataNascInt[2] < 2100 ) ){
        
     } else {
        return 3;
    }
} else {
    return 3;
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

    printf("Informe a data de nascimento (formato dd/mm/yyyy): ");
    fflush(stdin);
	fgets(paciente->dataDeNascimento, sizeof(paciente->dataDeNascimento), stdin);

	printf("Informe o sexo do paciente (M/F): ");
    fflush(stdin);
	fgets(paciente->sexo, sizeof(paciente->sexo), stdin);

	printf("Informe o CPF do paciente (apenas numeros): ");
    fflush(stdin);
	fgets(paciente->CPF, sizeof(paciente->CPF), stdin);

	printf("Informe o peso do paciente: ");
    fflush(stdin);
    fgets(tmp, sizeof(tmp), stdin);

	printf("Informe a altura do paciente (em centimetros): ");
    fflush(stdin);
    fgets(tmp, sizeof(char *), stdin);

    free(tmp);
	return paciente;

}

// toString recebe uma struct Paciente e a imprime 
void toString(PACIENTE *paciente){

    printf("\nNome do paciente: %s", paciente->nome);
    printf("Data de nascimento: %s", paciente->dataDeNascimento);
    printf("Sexo do paciente (M/F): %c", paciente->sexo);
    printf("CPF do paciente: %s", paciente->CPF);
    printf("Peso do paciente: %s", paciente->peso);
    printf("\nAltura do paciente: %s", paciente->altura);

}

void editarPaciente()
{}

void listarPacientes(LISTAPACIENTES *lista)
{
    PACIENTE *temp;

    while (temp = retornaProximoPaciente(lista), temp != NULL) {
        toString(temp);
    }
}

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
    printf("** 4 - Listar pacientes                  **\n");
    printf("** 5 - Excluir paciente                  **\n");
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

		opcao = painel();
		switch (opcao)
		{
		case 1:
            // Inserir paciente
			break;
		case 2:
			// Pesquisar paciente
			break;
		case 3:
			// Atualizar paciente
			break;
		case 4:
			// Listar pacientes
			break;
        case 5:
            // Excluir paciente
            break;
		}

	}


	return 0;
}
