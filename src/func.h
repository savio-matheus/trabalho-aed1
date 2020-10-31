#ifndef FUNCIONALIDADE_H
#define FUNCIONALIDADE_H

// Typedefs

// Funções expostas para o main.c. Elas devem chamar outras funções dentro de func.c
void cadastrarPaciente();
void editarPaciente();
void listarPacientes();
void removerPaciente();

/*
Funções do CRUD consultas. Não implementar por enquanto.
void cadastrar_consulta();
void editar_consulta();
void listar_consultas();
void remover_consulta();
*/

void carregarArquivo();
void salvarArquivo();

#endif /* FUNCIONALIDADE_H */
