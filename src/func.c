/*
	Funções que implementam as funcionalidades do
	programa e são chamadas na main(), e outras que não se
	encaixam nos outros módulos.
*/

#include <stdio.h>

#include "tad.h"
#include "func.h"

struct paciente {
	int idade;
	Vetor cpf;
	Vetor nome;
	Vetor senha;
};

struct profissional {
	int clinica;
	Vetor nome;
	Vetor crm;
	Vetor especialidade;
	Vetor senha;
};

struct consulta {
	Vetor cpfPaciente;
	Vetor crmProfissional;
	Vetor data;
	Vetor sintomas;
	Vetor diagnostico;
};

struct admn {
	Vetor nome;
	Vetor senha;
	Vetor cpf;
};
