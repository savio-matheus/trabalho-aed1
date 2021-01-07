/*
	Estruturas de dados e funções que trabalham sobre elas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
/*
void exibirListaPacientes(LISTAPACIENTES *lst)
{
	PONT end = lst->inicio;
	while (end != NULL)
	{
		printf("%-10i %-10d %-10s\n", end->p.chave, end->p.dado, end->p.nome);
		end = end->prox;
	}
}
*/

/*
 * Desde que mantida a mesma lista de pacientes, a função retorna o próximo
 * paciente a cada chamada (um por vez), até chegar ao final da
 * lista (retornar NULL).
 * Assume que o último nó sempre aponta para NULL.
*/
PACIENTE *retornaProximoPaciente(LISTAPACIENTES *lst)
{
	static PONT atual = NULL;
	static LISTAPACIENTES *tmp = NULL;

	if (lst == tmp && atual != NULL) {
		atual = atual->prox;
		return &atual->p;
	}

	tmp = lst;
	atual = tmp->inicio;
	return &atual->p;
}

/*
 * Compara a string s com o campo em p determinado pela chave.
 * É uma forma de tornar a ordenação mais flexível, mas deve ter um jeito
 * melhor de fazer isso.
 */
static int compara(PACIENTE *p, char *s, enum chaves chave)
{
	printf("%s ? %s\n", p->CPF, s);
	switch (chave) {
		case CPF:
			return strcmp(p->CPF, s);
		case NOME:
			return strcmp(p->nome, s);
		/*case DATA_NASC:
			return strcmp(p->dataDeNascimento, s);
		case SEXO:
			return strcmp(p->sexo, s);
		case PESO:
			return strcmp(p->peso, s);
		case ALTURA:
			return strcmp(p->altura, s);
		case ENDERECO:
			return strcmp(p->endereco, s);
		case CIDADE:
			return strcmp(p->cidade, s);
		case ESTADO:
			return strcmp(p->estado, s);*/
		default:
			return strcmp(p->CPF, s);
	}
}

PACIENTE *buscaSequencial(LISTAPACIENTES *lst, char s[], enum chaves chave)
{
	PONT pos = lst->inicio;
	while (pos != NULL)
	{
		if (compara(&pos->p, s, chave) == 0)
			return &(pos->p);
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
static PONT buscaSequencialExc(LISTAPACIENTES *lst, char s[],
	PONT *ant, enum chaves ch)
{
	*ant = NULL;
	PONT atual = lst->inicio;
	while ((atual != NULL) && (compara(&atual->p, s, ch) < 0))
	{
		*ant = atual;
		atual = atual->prox;
	}
	if ((atual != NULL) && (compara(&atual->p, s, ch) == 0))
		return atual;
	return NULL;
}

/* funcao que vai inserir um paciente na LISTAPACIENTES, recebe como
*  parâmetros uma lista e um registro completo de um paciente, ou
*  seja todos os dados dentro da struct PACIENTE.
*/
boolean inserirPacienteListaOrdenada(LISTAPACIENTES *lst, PACIENTE paciente)
{
	PONT ant, i;
	i = buscaSequencialExc(lst, paciente.nome, &ant, NOME);
	if (i != NULL)
		return false;
	i = (PONT)calloc(1, sizeof(REGISTRO));
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
boolean excluirPacienteLista(LISTAPACIENTES *lst, char cpf[])
{
	PONT ant = NULL;
	PONT i;

	i = lst->inicio;
	while ((i != NULL) && (compara(&i->p, cpf, CPF) != 0))
	{
		ant = i;
		i = i->prox;
	}

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
void inserirPaciente(LISTAPACIENTES *lst, PACIENTE *paciente)
{
	PONT temp = NULL;

	if (lst->inicio == NULL)
	{
		lst->inicio = (PONT) malloc(sizeof(REGISTRO));
		lst->inicio->prox = NULL;
		lst->inicio->p = *paciente;
		lst->n++;
		return;
	}

	temp = lst->inicio;
	while (temp->prox != NULL)
		temp = temp->prox;

	temp->prox = (PONT) malloc(sizeof(REGISTRO));
	temp = temp->prox;
	temp->p = *paciente;
	temp->prox = NULL;
	lst->n++;
	return;
}


// Fila encadeada ========================================================
