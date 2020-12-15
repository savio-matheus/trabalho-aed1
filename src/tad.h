#ifndef TAD_H
#define TAD_H

// Typedefs da lista

enum chaves {
	CPF = 0, NOME, DATA_NASC, SEXO, PESO,
	ALTURA, ENDERECO, CIDADE, ESTADO
};

typedef enum boolean {
	false = 0,
	true = 1
} boolean;

typedef struct paciente {
	char nome[64];
	char dataDeNascimento[11];
	char sexo;
	char CPF[15]; // Considerando o pior caso: "XXX.XXX.XXX-XX"
	char peso[5];
	char altura[5];

	// Endereço
	char endereco[128];
	char cidade[32];
	char estado[3];

	// Contato
	char email[64];
	char telefone[21]; // considerando o pior caso: "+55 (XX) X XXXX-XXXX"
} PACIENTE;

typedef struct registro
{
	PACIENTE p;
	struct registro *prox;
} REGISTRO;

typedef REGISTRO *PONT;

typedef struct lst_pacientes
{
	PONT inicio;
	size_t n; // tamanho da lista
} LISTAPACIENTES;

// typedefs da fila

// Funções da lista encadeada

LISTAPACIENTES *inicializarLista(void);

size_t tamanho(LISTAPACIENTES *lst);

void exibirListaPacientes(LISTAPACIENTES *lst);

PACIENTE *retornaProximoPaciente(LISTAPACIENTES *lst);

PACIENTE *buscaSequencial(LISTAPACIENTES *lst, char s[], enum chaves chave);

void inserirPaciente(LISTAPACIENTES *lst, PACIENTE *paciente);

boolean inserirPacienteListaOrdenada(LISTAPACIENTES *lst, PACIENTE paciente);

void reinicializarLista(LISTAPACIENTES *lst);

boolean excluirPacienteLista(LISTAPACIENTES *lst, char cpf[]);

void excluirLista(LISTAPACIENTES **lst);

// Funções da fila (baseada na lista)

#endif /* TAD_H */
