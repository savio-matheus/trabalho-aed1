#ifndef LISTA_H
#define LISTA_H

/* Structs e typedefs */

/**
 * criei este tipo para simular  um tipo boolean 
 * utilizado na função com retorno int 
 * e utilizar as define false e true 
 * */
typedef enum boolean {
	false = 0,
	true = 1
} boolean;

/** 
 *  struct para armazenar os dados de um paciente
 *  chave é o dado principal do paciente (identificador do paciente)
 *  será usado para procuarar um paciente
 *  aqui pode ser criado outros dados
 *  pode inserir uma nova struct, ENDERECO por exemplo
 * */

typedef struct paciente
{
	int chave;
	int dado; // dado e uma informacao qualquer do paciente, aqui utilizei para ordenar a lista de pacientes
			  // foi utilizado para localizar onde inserir um novo paciente ordenado
			  // a ordenacao pode ocorrer por outro valor: chave, nome
	char cpf[11];
	char endereco[150]; //Utilizando apenas uma string para definir o endereco do paciente, pode ser substituido no futuro por uma struct contendo os dados separadamente.
	char telefone[11]; //Telefone com padrao de 11 digitos, sendo ddd + telefone com 9 digitos).
	char nome[40];

} PACIENTE;

/* essa struct aux contem um registro de um paciente
   e um ponteiro *prox que servirá para percorrer uma lista de pacientes
 */
typedef struct registro
{
	PACIENTE p;
	struct registro *prox;
} REGISTRO;

/* PONT é um ponteiro para o inicio da lista */
typedef REGISTRO *PONT;

typedef struct lst_pacientes
{
	PONT inicio;
} LISTAPACIENTES;


/* Funções */

LISTAPACIENTES *inicializarLista(void);

int tamanho(LISTAPACIENTES *lst);

void exibirListaPacientes(LISTAPACIENTES *lst); // abstrair

PONT buscaSequencial(LISTAPACIENTES *lst, int ch);

PONT buscaSequencialOrdenada(LISTAPACIENTES *lst, int ch);

PONT buscaSequencialExc(LISTAPACIENTES *lst, int d, PONT *ant);

void inserirPaciente(LISTAPACIENTES *lst, PACIENTE paciente);

boolean inserirPacienteListaOrdenada(LISTAPACIENTES *lst, PACIENTE paciente);

void reinicializarLista(LISTAPACIENTES *lst);

boolean excluirPacienteLista(LISTAPACIENTES *lst, int d);

void excluirLista(LISTAPACIENTES **lst);

#endif /* LISTA_H */
