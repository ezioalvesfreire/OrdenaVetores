// programa C ++ para executar TimSort.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream> /// cole��o de bibliotecas, mas n�o vem acoplada a stdio, time,stdlib,conio
#include <conio.h>
#include<bits/stdc++.h>/// biblioteca transforma o arquivo em um pr� compilado.
///Obs:mas tentar compilar o c�digo em um compilador que n�o seja o GCC, poder� falhar
//#define min;


//================ METODO DE ORDENACAO TIM-SORT ===================

using namespace std;
const int RUN = 32;


// essa fun��o classifica a matriz do �ndice esquerdo para
// para o �ndice � direita, que � do tamanho no m�ximo RUN
void insertionSort(int vetor[], int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int temp = vetor[i];
        int j = i - 1;
        while (vetor[j] > temp && j >= left)
        {
            vetor[j+1] = vetor[j];
            j--;
        }
        vetor[j+1] = temp;
    }
}

// a fun��o de mesclagem mescla as execu��es classificadas
void merge(int vetor[], int l, int m, int r)
{
    // matriz original � dividida em duas partes
    // matriz esquerda e direita
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = vetor[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = vetor[m + 1 + i];

    int i = 0;
    int j = 0;
    int k = l;

    // depois de comparar, mesclamos esses dois vetores
    // na sub-matriz maior
    while (i < len1 && j < len2)
    {
        if (left[i] <= right[j])
        {
            vetor[k] = left[i];
            i++;
        }
        else
        {
            vetor[k] = right[j];
            j++;
        }
        k++;
    }


// copia os elementos restantes da esquerda, se houver    while (i < len1)
    {
        vetor[k] = left[i];
        k++;
        i++;
    }

    // copia o elemento restante da direita, se houver
    while (j < len2)
    {
        vetor[k] = right[j];
        k++;
        j++;
    }
}

// fun��o iterativa Timsort para classificar o
// matriz [0 ... n-1] (semelhante � classifica��o de mesclagem)
void timSort(int vetor[], int n)
{
   // Classifica sub-matrizes individuais do tamanho RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(vetor, i, min((i+31), (n-1)));

    // come�a a mesclar a partir do tamanho RUN (ou 32). Vai mesclar
    // para formar o tamanho 64, depois 128, 256 e assim por diante ....
    for (int size = RUN; size < n; size = 2*size)
    {
        // escolhe o ponto inicial da sub-matriz esquerda. N�s
        // ir� mesclar arr [esquerda .. esquerda + tamanho-1]
        // e arr [esquerda + tamanho, esquerda + 2 * tamanho-1]
        // Ap�s cada mesclagem, aumentamos a esquerda em 2 * tamanho
        for (int left = 0; left < n; left += 2*size)
        {
            // localiza o ponto final do subconjunto esquerdo
            // mid + 1 � o ponto inicial da sub-matriz direita
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));


// mescla sub-matriz arr [esquerda ..... m�dia] &
            // arr [m�dio + 1 .... direita]
            merge(vetor, left, mid, right);
        }
    }
}


// fun��o para imprimir a matriz
void imprimeVetor(int vetor[], int n)  // imprimeVetor
{
    for (int i = 0; i < n; i++)
        printf("%d  ", vetor[i]);
    printf("\n\n");
}
void geraNumAleatorio(int vetor[], int n){
 srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};

   }
}
void calculaTempo(){
   clock_t tempo;
	tempo = clock();

    // c�digo de teste
	for(int i = 0; i < 99999999; ++i){}
	//fim
	printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}


int main()
{
    int n=100;
    int vetor[100];

 printf("\n================ METODO DE ORDENACAO TIM-SORT ===================\n\n\n");

  geraNumAleatorio(vetor, n);

    printf("\t\t\t  VETOR DESORDENADO\n\n");
    printf("  \t\t ");

//================== IMPRIME VETOR DESORDENADO ====================================
    imprimeVetor(vetor, n);

    timSort(vetor, n);

    printf("\n\t\t\t  VETOR ORDENADO\n\n");
      printf("  \t\t ");

//================== IMPRIME VETOR ORDENADO ====================================
    imprimeVetor(vetor, n);

   calculaTempo();

	  printf("\n\n\n");

    system("pause>>null");
    return 0;
}
