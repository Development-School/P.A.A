/*
Atividade

Desenvolver um algoritmo em linguagem C, que satisfaça os segulong intes critérios:
- Criar uma função para gerar valores aleatórios (hand);
*/

//Bibliotecas - Cabeçalhos - Funções e procedimentos - Informações de Continuidade
/**Bibliotecas*/

//Sistema
#include <stdio.h> // Biblioteca I/O
#include <stdlib.h> // Biblioteca para Manipulação de Arquivos
#include <string.h> // Biblioteca para Manipulação de Strings
#include <locale.h> //Biblioteca para permitir acentuação gráfica
#include <time.h> // Biblioteca para manipulação de Tempo (Timer - Horário)
//#include <windows.h> // Biblioteca para permitir utilização da função Sleep();

//Específicas
#define clear system("cls || clear"); // Definições para limpar a tela.
#define clear_buffer setbuf(stdin, NULL); // Limpar buffer.
#define pause getchar(); // Pausar a tela.

int cadastrado;
int visualizado;

int rand();
void fMenu();
void fTestar(int *ptr, int MaxTam);
void fMenuOrdenacao(int *ptr, int MaxTam);
void fExibir(int *ptr, int MaxTam);
void fOrdenacao(int *ptr, int MaxTam, int op);
void fOrdenacaoQuicksort(int *ptr, int inicio, int fim);
int fParticionar(int *ptr, int inicio, int fim);
void fOrdenacaoBubblesort(int *ptr, int fim);
void fOrdenacaoInsertionsort(int *ptr, int fim);

// Compilar dessa forma tbm "gcc -o prog MaxTam.c"
