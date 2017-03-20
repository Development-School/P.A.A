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
#include <sys/time.h> // Biblioteca para trabalhar milisegundos
//#include <windows.h> // Biblioteca para permitir utilização da função Sleep();

//Específicas
#define clear system("cls || clear"); // Definições para limpar a tela.
#define clear_buffer setbuf(stdin, NULL); // Limpar buffer.
#define pause getchar(); // Pausar a tela.

//Diversas
#define delay1x Sleep(2000); // Delay quando imprimir algo.
#define delay2x Sleep(1000); // Delay quando for impremir algo.
#define MaxTam 100000// Quantidade de cadastros disponíveis

int cadastrado;
int visualizado;

int rand();
void fMenu();
void fTestar(int ult);
void fMenuOrdenacao(int item[], int ult);
void fOrdenacao(int item[], int ult, int op);
void fExibir(int item[], int ult);
int fParticionar(int item[], int inicio, int fim);
void fOrdenacaoQuicksort(int item[], int inicio, int fim);
void fOrdenacaoBubblesort(int item[], int fim);
void fOrdenacaoInsertionsort(int item[], int fim);
