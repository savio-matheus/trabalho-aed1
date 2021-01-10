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
#if defined (__MINGW32__) || defined(_MSC_VER) // Windows (CMD)
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
int validaPaciente(PACIENTE paciente)
{


	//CPF
	int i;
	//Validando se apenas numeros foram digitados
	// número mágico: 11. Indica o compr. do campo CPF
	for(i = 0; i < 11; i++) {
		if(!isdigit(paciente.CPF[i])) {
			return 1;
		}
	}

	//Sexo
	if(paciente.sexo != 'M' && paciente.sexo != 'F') {
		return 2;
	}

	//Data de nascimento
	int dataNascInt[3];
	if ( sscanf(paciente.dataDeNascimento, "%d/%d/%d", &dataNascInt[0], &dataNascInt[1], &dataNascInt[2]) == 3 ) {

		if ( (dataNascInt[0] > 0 && dataNascInt[0] < 32) && (dataNascInt[1] > 0 && dataNascInt[1] < 13) && (dataNascInt[2] > 1900 && dataNascInt[2] < 2100 ) ) {

		} else {
			return 3;
		}
	} else {
		return 3;
	}

	//sucesso
	return 0;
}

// formularioPaciente cria um Paciente e o retorna
PACIENTE formularioPaciente()
{

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

	int validacaoResult = validaPaciente(paciente);

	do {
		if(validacaoResult == 1) {
			printf("CPF Invalido! \nInforme novamente o CPF do paciente (apenas numeros): ");
			entradaUsuario(paciente.CPF, sizeof(paciente.CPF));
		} else if(validacaoResult == 2) {
			printf("Informacao invalida! \nInforme o sexo do paciente (M/F): ");
			entradaUsuario(&paciente.sexo, sizeof(paciente.sexo));
		} else if(validacaoResult == 3) {
			printf("Data de Nascimento invalida! \nInforme a data de nascimento (formato dd/mm/yyyy): ");
			entradaUsuario(paciente.dataDeNascimento, sizeof(paciente.dataDeNascimento));
		}

		validacaoResult = validaPaciente(paciente);

	} while(validacaoResult > 0);

	return paciente;

}

// toString recebe uma struct Paciente e a imprime
void toString(PACIENTE *paciente)
{

	printf("\nNome do paciente: %s", paciente->nome);
	printf("\nData de nascimento: %s", paciente->dataDeNascimento);
	printf("\nSexo do paciente (M/F): %c", paciente->sexo);
	printf("\nCPF do paciente: %s", paciente->CPF);
	printf("\nPeso do paciente: %s", paciente->peso);
	printf("\nAltura do paciente: %s\n", paciente->altura);

}

void editarPaciente(LISTAPACIENTES *lst)
{
	char cpf[15];
	boolean falhou = false;
	PACIENTE *old = NULL;
	PACIENTE novo;

	do {
		if (falhou) {
			printf("O CPF digitado eh invalido ou nao esta "
				   "cadastrado.\n");
		}

		printf("CPF do paciente a ser editado [0 para cancelar]: ");
		entradaUsuario(cpf, sizeof(cpf));

		if (strcmp("0", cpf) == 0)
			return;
		old = buscaSequencial(lst, cpf, CPF);
		falhou = true;
	} while (old == NULL);

	toString(old);
	novo = formularioPaciente();
	excluirPacienteLista(lst, old->CPF);
	inserirPacienteListaOrdenada(lst, novo);
}

void listarPacientes(LISTAPACIENTES *lista)
{
	PACIENTE *temp;

	while (temp = retornaProximoPaciente(lista), temp != NULL) {
		toString(temp);
	}
}

void removerPaciente(LISTAPACIENTES *lst)
{
	char cpf[15];
	boolean falhou = false;

	do {
		if (falhou) {
			printf("O CPF digitado eh invalido ou nao esta "
				   "cadastrado.\n");
		}

		printf("CPF do paciente a ser removido [0 para cancelar]: ");
		entradaUsuario(cpf, sizeof(cpf));

		if (strcmp("0", cpf) == 0)
			return;
		falhou = true;
	} while (!excluirPacienteLista(lst, cpf));
}

void carregarArquivo(LISTAPACIENTES *lista)
{
	PACIENTE *temp;
	FILE *fp;
	size_t tamanho_arquivo;

	temp = malloc(sizeof(PACIENTE));
	fp = fopen("registros.dat", "rb");
	if (fp == NULL)
		return;

	fread(&tamanho_arquivo, sizeof(size_t), 1, fp);

	if (tamanho_arquivo == 0) {
		goto end;
	}

	while (1 == fread(temp, sizeof(PACIENTE), 1, fp)) {
		inserirPaciente(lista, temp);
	}

end:
	fclose(fp);
	free(temp);
}

void salvarArquivo(LISTAPACIENTES *lista)
{
	PACIENTE *temp;
	FILE *fp;
	size_t tamanho_arquivo;

	fp = fopen("registros.dat", "w+b");
	tamanho_arquivo = sizeof(PACIENTE) * tamanho(lista);

	if (fp == NULL) {
		fprintf(stderr, "Ocorreu um erro ao salvar o arquivo\n");
		exit(1);
	}

	fwrite(&tamanho_arquivo, sizeof(size_t), 1, fp);

	if (tamanho_arquivo == 0) {
		goto end;
	}

	while (temp = retornaProximoPaciente(lista), temp != NULL) {
		fwrite(temp, sizeof(PACIENTE), 1, fp);
	}

end:
	fclose(fp);
}

int painel()
{
	char opcao;
	printf("*******************************************\n");
	printf("** 1 - Cadastrar paciente                **\n");
	printf("** 2 - Atualizar paciente                **\n");
	printf("** 3 - Listar pacientes                  **\n");
	printf("** 4 - Excluir paciente                  **\n");
	printf("** 5 - Limpar a tela                     **\n");
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
	carregarArquivo(lista);

	while(opcao != '0') {

		opcao = painel();
		switch (opcao) {
		case '1':
			// Inserir paciente
			inserirPacienteListaOrdenada(lista, formularioPaciente());
			break;
		case '2':
			// Atualizar paciente
			editarPaciente(lista);
			break;
		case '3':
			// Listar pacientes
			listarPacientes(lista);
			break;
		case '4':
			// Excluir paciente
			removerPaciente(lista);
			break;

		case '5':
			// Limpar a tela do terminal
			limparTela();
			break;

		}

	}

	salvarArquivo(lista);

	return 0;
}
