/*
	Estruturas de dados e funções que trabalham sobre elas.
*/

#include <stdio.h>
#include <stdlib.h>

#include "tad.h"

// Lista encadeada =======================================================

/* Inicializa a lista atribuindo NULL para o inicio da lista, ou seja,
uma lista sem elementos */
LISTAPACIENTES *inicializarLista(void)
{
	LISTAPACIENTES *lst = (LISTAPACIENTES *) malloc(sizeof(*lst));
	lst->inicio = NULL;
	lst->n = 0;
	printf("Lista Criada!\n");
	return lst;
}
/* para mostrar o tamanho da lista */
size_t tamanho(LISTAPACIENTES *lst)
{
	return lst->n;
}
/* Para exibir a lista de pacientes: aqui por enquanto a chave, o dado e o
nome do paciente */
void exibirListaPacientes(LISTAPACIENTES *lst)
{
	PONT end = lst->inicio;
	while (end != NULL)
	{
		printf("%-10i %-10d %-10s\n", end->p.chave, end->p.dado, end->p.nome);
		end = end->prox;
	}
}

PONT buscaSequencial(LISTAPACIENTES *lst, int ch)
{
	PONT pos = lst->inicio;
	while (pos != NULL)
	{
		if (pos->p.chave == ch)
			return pos;
		pos = pos->prox;
	}
	return NULL;
}

PONT buscaSequencialOrdenada(LISTAPACIENTES *lst, int ch)
{
	PONT pos = lst->inicio;
	while (pos != NULL) {
		if (pos->p.chave == ch)
			return pos;
		pos = pos->prox;
	}

	return NULL;
}

/* localiza na lista de pacientes - aqui foi utilizado p.dado da struct
*  paciente - qual posicao sera inserido o novo paciente se o dado ja
*  existir return NULL e nao insere o novo paciente com a chave repetida
*  precisa implementar um retorno informando que aquela chave (ou paciente)
*  ja esta cadastrado.
*/
PONT buscaSequencialExc(LISTAPACIENTES *lst, int d, PONT *ant)
{
	*ant = NULL;
	PONT atual = lst->inicio;
	while ((atual != NULL) && (atual->p.dado < d))
	{
		*ant = atual;
		atual = atual->prox;
	}
	if ((atual != NULL) && (atual->p.dado == d))
		return atual;
	return NULL;
}

/* funcao que vai inserir um paciente na LISTAPACIENTES, recebe como
*  parâmetros uma lista e um registro completo de um paciente, ou
*  seja todos os dados dentro da struct PACIENTE.
*/
boolean inserirPacienteListaOrdenada(LISTAPACIENTES *lst, PACIENTE paciente)
{
	//int ch = paciente.chave; (não utilizada)
	int d = paciente.dado;
	PONT ant, i;
	i = buscaSequencialExc(lst, d, &ant);
	if (i != NULL)
		return false;
	i = (PONT)malloc(sizeof(REGISTRO));
	i->p = paciente;
	//memcpy(&i->p, &paciente, sizeof(paciente));
	if (ant == NULL)
	{
		i->prox = lst->inicio;
		lst->inicio = i;
	}
	else
	{
		i->prox = ant->prox;
		ant->prox = i;
	}
	lst->n++;
	return true;
}

/*apaga toda a lista  */
void reinicializarLista(LISTAPACIENTES *lst)
{
	PONT fim = lst->inicio;
	while (fim != NULL)
	{
		PONT apagar = fim;
		fim = fim->prox;
		free(apagar);
	}
	lst->inicio = NULL;
	lst->n = 0;
	printf("\nLISTA VAZIA\n");
}
/* exclui um paciente da lista e libera memoria
* primeiro procura na lista se o paciente existe
*/
boolean excluirPacienteLista(LISTAPACIENTES *lst, int d)
{
	PONT ant, i;
	i = buscaSequencialExc(lst, d, &ant);
	if (i == NULL)
		return false;
	if (ant == NULL)
		lst->inicio = i->prox;
	else
		ant->prox = i->prox;
	free(i);
	lst->n--;
	return true;
}

/*
*  Desaloca a memória atribuída à lista. O ponteiro para ponteiro serve
*  para tornar possível mudar o valor da variável para NULL.
*/
void excluirLista(LISTAPACIENTES **lst)
{
	if (*lst == NULL) {
		return;
	}
	reinicializarLista(*lst);
	free(*lst);
	*lst = NULL;
	printf("Lista excluida!\n");
}

/*
* Insere novo paciente ao final da lista (deve estar inicializada),
* sem checar por dados repetidos.
*/
void inserirPaciente(LISTAPACIENTES *lst, PACIENTE paciente)
{
	PONT temp = NULL;

	if (lst->inicio == NULL)
	{
		lst->inicio = (PONT) malloc(sizeof(REGISTRO));
		lst->inicio->prox = NULL;
		lst->inicio->p = paciente;
		lst->n++;
		return;
	}

	temp = lst->inicio;
	while (temp->prox != NULL)
		temp = temp->prox;

	temp->prox = (PONT) malloc(sizeof(REGISTRO));
	temp = temp->prox;
	temp->p = paciente;
	temp->prox = NULL;
	lst->n++;
	return;
}


// Fila encadeada ========================================================
