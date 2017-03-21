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

    int *ptr;
    int op;
    scanf("%i", &op);

    switch(op) {
      case 0: exit(0);
      case 1: fTestar(ptr, 100); break;
      case 2: fTestar(ptr, 10000); break;
      case 3: fTestar(ptr, 100000); break;
      case 4: fTestar(ptr, 1000000); break;
    }
    free(ptr);
  }
}

void fTestar(int *ptr, int MaxTam) {
  int i;

  ptr = (int *) malloc(MaxTam * sizeof(int));

  if(ptr == NULL) { puts("Erro."); exit(0);}

  for(i = 0; i < MaxTam; i++) {
    *(ptr + i) = rand() % MaxTam;
    cadastrado++;
  }
  fMenuOrdenacao(ptr, MaxTam);
}

void fMenuOrdenacao(int *ptr, int MaxTam) {
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
      case 2:fOrdenacao(ptr, MaxTam, 2); break;
      case 3:fOrdenacao(ptr, MaxTam, 3); break;
      case 4:fOrdenacao(ptr, MaxTam, 4); break;
    }
    fMenu();
  }
}

void fExibir(int *ptr, int MaxTam) {
  puts("\n\n");
  int i;
  for(i = 0; i < MaxTam; ++i) {
    printf("[%i] ", ptr[i]);
    visualizado++;
  }
}

void fOrdenacao(int *ptr, int MaxTam, int op) {
  int inicio, fim;
  inicio = 0;
  fim = MaxTam;

  // Atributos para determinar tempo de ordenação
  time_t start, end;
  float tOrdenacao;

  clear;
  fExibir(ptr, MaxTam);

  // Início de contagem do tempo de ordenação
  start = time(NULL);

  if (op == 2) {
    fOrdenacaoInsertionsort(ptr, fim);
  }
  else if(op == 3) {
    fOrdenacaoBubblesort(ptr, fim);
  }
  else if(op == 4) {
    fOrdenacaoQuicksort(ptr, inicio, fim);
  }
  // Término de contagem do tempo de ordenação
  end = time(NULL);
  tOrdenacao = (difftime(end, start) / 1000);

  fExibir(ptr, MaxTam);
  puts("\n");
  printf("\nValores Cadastrados: %i"
         "\nValores Visualizados: %i"
         "\nTempo de ordenação: %f ms", cadastrado, visualizado, tOrdenacao);

  cadastrado = 0;
  visualizado = 0;
  clear_buffer; pause;
}

// Função para Ordenação do tipo Quick Sort
void fOrdenacaoQuicksort(int *ptr, int inicio, int fim) {
  int pivo;

  if(inicio < fim) {
    pivo = fParticionar(ptr, inicio, fim);
    fOrdenacaoQuicksort(ptr, inicio, pivo - 1);
    fOrdenacaoQuicksort(ptr, pivo + 1, fim);
  }
}

int fParticionar(int *ptr, int inicio, int fim) {
  int pivo, i, j;
  int temp;

  i = inicio;
  j = fim + 1;
  pivo = ptr[i];

  while(1) {
    do { ++i; }while(ptr[i] <= pivo && i <= fim);
    do { --j; }while(ptr[j] > pivo);

    if(i >= j) {
      break;
    }else {
      temp = ptr[i];
      ptr[i] = ptr[j];
      ptr[j] = temp;
    }
  }

  temp = ptr[inicio];
  ptr[inicio] = ptr[j];
  ptr[j] = temp;
  return j;
}

void fOrdenacaoBubblesort(int *ptr, int fim) {
  int i, j, aux;
  for (i = 0 ; i < (fim - 1 ); i++) {
    for (j = 0 ; j < fim - i - 1; j++) {
      if (ptr[j] > ptr[j+1]) {
        aux = ptr[j];
        ptr[j] = ptr[j + 1];
        ptr[j + 1] = aux;
      }
    }
  }
}

void fOrdenacaoInsertionsort(int *ptr, int fim) {
  int i, j, aux;
  for (i = 1 ; i <= fim - 1; i++) {
    j = i;

    while(j > 0 && ptr[j] < ptr[j - 1]) {
      aux = ptr[j];
      ptr[j]   = ptr[j - 1];
      ptr[j - 1] = aux;
      j--;
    }
  }
}















/**/
