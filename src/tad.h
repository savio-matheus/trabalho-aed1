#ifndef TAD_H
#define TAD_H

// Typedefs da lista
typedef enum boolean {
	false = 0,
	true = 1
} boolean;

typedef struct{
	char rua[30];
	char bairro[30];
	char cidade[30];
	char estado[2];
} Endereco;

typedef struct{
	char email[30];
    char telefone[11];
} Contato;

typedef struct paciente {
	char nome[40];
	int chave; // apenas para funcionar no código da lista (por enquanto)
	int dado;  // idem
	char dataDeNascimento[10];
	char sexo;
	char CPF[11];
	float peso;
	float altura;
	Endereco endereco;
	Contato contato;
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
} LISTAPACIENTES;

// typedefs da fila

// Funções da lista encadeada

LISTAPACIENTES *inicializarLista(void);

int tamanho(LISTAPACIENTES *lst);

void exibirListaPacientes(LISTAPACIENTES *lst);

PONT buscaSequencial(LISTAPACIENTES *lst, int ch);

PONT buscaSequencialOrdenada(LISTAPACIENTES *lst, int ch);

PONT buscaSequencialExc(LISTAPACIENTES *lst, int d, PONT *ant);

void inserirPaciente(LISTAPACIENTES *lst, PACIENTE paciente);

boolean inserirPacienteListaOrdenada(LISTAPACIENTES *lst, PACIENTE paciente);

void reinicializarLista(LISTAPACIENTES *lst);

boolean excluirPacienteLista(LISTAPACIENTES *lst, int d);

void excluirLista(LISTAPACIENTES **lst);

// Funções da fila (baseada na lista)

#endif /* TAD_H */
