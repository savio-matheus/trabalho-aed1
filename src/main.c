/*
Projeto de Algoritmos e Estruturas de Dados I - 2020/1 (SI)
Professor: Edmundo Sérgio Spoto
Alunos:
	Cláudio da Silva Pinheiro Júnior
	Delvo Resende
	Gleidimar Luiz
	Sávio Matheus de Sousa
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "tad.h"

/*
 * Determina o comando de limpar o terminal de acordo com o SO.
 */
void limparTela(void)
{
 #if defined (__MINGW32__) || defined(_MSC_VER) // Windows
	system("cls");
 #else // Linux e Unix em geral
	system("clear");
 #endif
}

/*
 * Recebe "tamanho_str" caracteres do teclado e armazena em "dest".
 * Se tamanho_str > 1, será adicionado '\0' ao final da string.
 * Caso seja chamada como entradaUsuario(NULL, 0) após um getchar()
 * ou scanf(), adquire a mesma funcionalidade do fflush().
*/
char *entradaUsuario(char *dest, size_t tamanho_str)
{
	const float FATOR_AUMENTO = 1.5;
	int c;

	// Buffer que cresce indefinidamente até a quebra de linha.
	char *buf = malloc(sizeof(char) * 2);
	size_t buf_usado = 0;
	size_t buf_tamanho = 2;
	
	do {
		c = getchar();
		if (buf_usado + 1 >= buf_tamanho) {
			buf_tamanho *= FATOR_AUMENTO;
			buf = realloc(buf, sizeof(char) * buf_tamanho);
		}
		buf_usado++;
		buf[buf_usado - 1] = c;
	} while (c != '\n' && c != EOF);

	if (tamanho_str == 1 && dest != NULL) {
		dest[0] = buf[0];
	} else if (buf_usado <= tamanho_str && dest != NULL) {
		buf[buf_usado - 1] = '\0';
		strncpy(dest, buf, buf_usado);
	} else if (dest != NULL) {
		buf[tamanho_str - 1] = '\0';
		strncpy(dest, buf, tamanho_str);
	}
	
	free(buf);
	return dest;
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
PACIENTE cadastrarPaciente(){

	PACIENTE paciente;

	printf("\nInforme o nome do paciente: ");
	entradaUsuario(paciente.nome, sizeof(paciente.nome));

	printf("Informe a data de nascimento (formato dd/mm/yyyy): ");
	entradaUsuario(paciente.dataDeNascimento, sizeof(paciente.dataDeNascimento));

	printf("Informe o sexo do paciente (M/F): ");
	entradaUsuario(&paciente.sexo, sizeof(paciente.sexo));

	printf("Informe o CPF do paciente (apenas numeros): ");
	entradaUsuario(paciente.CPF, sizeof(paciente.CPF));

	printf("Informe o peso do paciente: ");
	entradaUsuario(paciente.peso, sizeof(paciente.peso));

	printf("Informe a altura do paciente (em centimetros): ");
	entradaUsuario(paciente.altura, sizeof(paciente.altura));

	return paciente;

}

// toString recebe uma struct Paciente e a imprime 
void toString(PACIENTE *paciente){

	printf("\nNome do paciente: %s", paciente->nome);
	printf("\nData de nascimento: %s", paciente->dataDeNascimento);
	printf("\nSexo do paciente (M/F): %c", paciente->sexo);
	printf("\nCPF do paciente: %s", paciente->CPF);
	printf("\nPeso do paciente: %s", paciente->peso);
	printf("\nAltura do paciente: %s\n", paciente->altura);

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
	char opcao;
	printf("*******************************************\n");
	printf("** 1 - Cadastrar paciente                **\n");
	printf("** 2 - Pesquisar paciente                **\n");
	printf("** 3 - Atualizar paciente                **\n");
	printf("** 4 - Listar pacientes                  **\n");
	printf("** 5 - Excluir paciente                  **\n");
	printf("** 0 - SAIR                              **\n");
	printf("*******************************************\n");

	printf("ESCOLHA: ");

	entradaUsuario(&opcao, 1);
	return opcao;
}


int main (void)
{
	char opcao = -1;
	LISTAPACIENTES *lista = inicializarLista();
	while(opcao != '0'){

		opcao = painel();
		switch (opcao)
		{
		case '1':
			// Inserir paciente
			inserirPacienteListaOrdenada(lista, cadastrarPaciente());
			break;
		case '2':
			// Pesquisar paciente
			break;
		case '3':
			// Atualizar paciente
			break;
		case '4':
			// Listar pacientes
			listarPacientes(lista);
			break;
		case '5':
			// Excluir paciente
			break;
		}

	}


	return 0;
}
