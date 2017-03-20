#include "library.h"

void fMenu() {
  while(1) {//Enquanto x for verdadeiro ...
    clear_buffer;
    clear;
    puts("\n\n");
    printf("\n------------------------------------------------------------------------------\n\n");
    printf("\t\t\tORDENAÇÃO DE SEQUENCIAS NUMÉRICAS - \n\n");
    printf("\t\t\t4 - [1.000.000]\n");
    printf("\t\t\t3 - [100.000]\n");
    printf("\t\t\t2 - [10.000]\n");
    printf("\t\t\t1 - [100]\n");
    printf("\t\t\t0 - Sair\n");
    printf("\n------------------------------------------------------------------------------\n");

    int op;
    scanf("%i", &op);

    switch(op) {
      case 0: exit(0);
      case 1: fTestar(100); break;
      case 2: fTestar(10000); break;
      case 3: fTestar(100000); break;
      case 4: fTestar(1000000); break;
    }
  }
}

void fTestar(int ult) {
  int i, item[ult];

  for(i = 0; i < ult; i++) {
    item[i] = rand() % ult;
    cadastrado++;
  }
  fMenuOrdenacao(item, ult);
}

void fExibir(int item[], int ult) {
  puts("\n\n");
  int i;
  for(i = 0; i < ult; ++i) {
    printf("[%i] ", item[i]);
    visualizado++;
  }
}

void fMenuOrdenacao(int item[], int ult) {
  while(1) {
    clear_buffer;
    clear;
    puts("\n\n");
    printf("\n------------------------------------------------------------------------------\n\n");
    printf("\t\t\tSELECIONE QUAL TIPO DE ORDENAÇÃO\n\n");
    printf("\t\t\t4 - Quick Sort\n");
    printf("\t\t\t3 - Insertion Sort\n");
    printf("\t\t\t2 - Bubble Sort\n");
    printf("\t\t\t1 - Voltar ao menu principal\n");
    printf("\t\t\t0 - Sair\n");
    printf("\n------------------------------------------------------------------------------\n");
    int op;
    scanf("%ld", &op);

    switch(op) {
      case 0:exit(0);
      case 1:fMenu();
      case 2:fOrdenacao(item, ult, 2); break;
      case 3:fOrdenacao(item, ult, 3); break;
      case 4:fOrdenacao(item, ult, 4); break;
    }
    fMenu();
  }
}

void fOrdenacao(int item[], int ult, int op) {
  int inicio, fim;
  inicio = 0;
  fim = ult;

  // Atributos para determinar tempo de ordenação
  time_t start, end;
  float tOrdenacao;

  clear;
  fExibir(item, ult);

  // Início de contagem do tempo de ordenação
  start = time(NULL);

  if (op == 2) {
    fOrdenacaoInsertionsort(item, fim);
  }
  else if(op == 3) {
    fOrdenacaoBubblesort(item, fim);
  }
  else if(op == 4) {
    fOrdenacaoQuicksort(item, inicio, fim);
  }
  // Término de contagem do tempo de ordenação
  end = time(NULL);
  tOrdenacao = (difftime(end, start) / 1000);

  fExibir(item, ult);
  puts("\n");
  printf("\nValores Cadastrados: %i"
         "\nValores Visualizados: %i"
         "\nTempo de ordenação: %f ms", cadastrado, visualizado, tOrdenacao);

  cadastrado = 0;
  visualizado = 0;
  clear_buffer; pause;
}

// Função para Ordenação do tipo Quick Sort
void fOrdenacaoQuicksort(int item[], int inicio, int fim) {
  int pivo;

  if(inicio < fim) {
    pivo = fParticionar(item, inicio, fim);
    fOrdenacaoQuicksort(item, inicio, pivo - 1);
    fOrdenacaoQuicksort(item, pivo + 1, fim);
  }
}

int fParticionar(int item[], int inicio, int fim) {
  int pivo, i, j;
  int temp;

  i = inicio;
  j = fim + 1;
  pivo = item[i];

  while(1) {
    do { ++i; }while(item[i] <= pivo && i <= fim);
    do { --j; }while(item[j] > pivo);

    if(i >= j) {
      break;
    }else {
      temp = item[i];
      item[i] = item[j];
      item[j] = temp;
    }
  }

  temp = item[inicio];
  item[inicio] = item[j];
  item[j] = temp;
  return j;
}

void fOrdenacaoBubblesort(int item[], int fim) {
  int i, j, aux;
  for (i = 0 ; i < (fim - 1 ); i++) {
    for (j = 0 ; j < fim - i - 1; j++) {
      if (item[j] > item[j+1]) {
        aux = item[j];
        item[j] = item[j + 1];
        item[j + 1] = aux;
      }
    }
  }
}

void fOrdenacaoInsertionsort(int item[], int fim) {
  int i, j, aux;
  for (i = 1 ; i <= fim - 1; i++) {
    j = i;

    while(j > 0 && item[j] < item[j - 1]) {
      aux = item[j];
      item[j]   = item[j - 1];
      item[j - 1] = aux;

      j--;
    }
  }
}















/**/
