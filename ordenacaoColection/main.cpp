#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include<bits/stdc++.h> //coletanea se torna dispensavel o uso das bibliotecas acima! obs: não funciona em alguns compiladores


// Bubble

	void bubble(int vetor[], int n)
{
    int k = n;
    int aux;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<k; j++)
        {
            if(vetor[j] > vetor[j+1])
            {
                aux=vetor[j];
                vetor[j]=vetor[j+1];
                vetor[j+1]=aux;
            }
        }
        k--;
    }
}

// Selection

	void selection(int vet[], int n)
{
    int menor, aux;
 	   for(int i = 0; i < n-1; i++)
    {
        menor = i;
        for(int j = i + 1; j < n; j++)
        {
            if(vet[menor] > vet[j])
                menor=j;
        }
        if(i != menor)
        {
            aux= vet[i];
            vet[i]= vet[menor];
            vet[menor]= aux;
        }
    }
}

//Insertion

    void inserction(int vet[], int n)
{
	int j, num_atual;
       for(int i =1; i < 10; i++)
        {
            num_atual = vet[i];
            j = i -1;

            while((j >= 0) && (num_atual < vet[j]))
            {
                 vet[j+1] = vet[j];
                 j--;
            }
            vet[j+1] = num_atual;
       }
}

//Quick

int dividir(int vetor[], int esq, int dir)
{
    int aux;
    int cont = esq;

    for(int i=esq+1; i<=dir; i++)
    {
        if(vetor[i] < vetor[esq])
        {
            cont++;
            aux=vetor[i];
            vetor[i]=vetor[cont];
            vetor[cont]=aux;

        }
    }
    aux=vetor[esq];
    vetor[esq]=vetor[cont];
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[], int esq, int dir)
{
    int pos;
    if(esq < dir)
    {
        pos = dividir(vetor, esq, dir);
        quick(vetor, esq, pos-1);
        quick(vetor, pos+1, dir);

    }
}

//Timsort

using namespace std;
const int RUN = 32;

// essa função classifica a matriz do índice esquerdo para
// para o índice à direita, que é do tamanho no máximo RUN

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

// a função de mesclagem mescla as execuções classificadas
void merge(int vetor[], int l, int m, int r)
{
    // matriz original é dividida em duas partes
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

// função iterativa Timsort para classificar o
// matriz [0 ... n-1] (semelhante à classificação de mesclagem)
void timSort(int vetor[], int n)
{
   // Classifica sub-matrizes individuais do tamanho RUN
    for (int i = 0; i < n; i+=RUN)
        insertionSort(vetor, i, min((i+31), (n-1)));

    // começa a mesclar a partir do tamanho RUN (ou 32). Vai mesclar
    // para formar o tamanho 64, depois 128, 256 e assim por diante ....
    for (int size = RUN; size < n; size = 2*size)
    {
        // escolhe o ponto inicial da sub-matriz esquerda. Nós
        // irá mesclar arr [esquerda .. esquerda + tamanho-1]
        // e arr [esquerda + tamanho, esquerda + 2 * tamanho-1]
        // Após cada mesclagem, aumentamos a esquerda em 2 * tamanho
        for (int left = 0; left < n; left += 2*size)
        {
            // localiza o ponto final do subconjunto esquerdo
            // mid + 1 é o ponto inicial da sub-matriz direita
            int mid = left + size - 1;
            int right = min((left + 2*size - 1), (n-1));

// mescla sub-matriz arr [esquerda ..... média] &
            // arr [médio + 1 .... direita]
            merge(vetor, left, mid, right);
        }
    }
}

// função para imprimir a matriz
void imprimeVetor(int vetor[], int n)  // imprimeVetor
{
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n\n\t");
}
/*
void contadorTempo()
{


}
*/

void geraNumAleatorio(int vetor[], int n)
{

   srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};
      //  printf("%d ", vetor[i]);

    }
}
/*
void contadorTempo(){



}
*/

//INICIO DO PROGRAMA
int main()
{

 int vetor[10];
 int n = 10;

    printf("\n================= ORDENACAO DE DADOS ===================\n\n");

    printf("\n\tNUMEROS ALEATORIOS DESORDENADOS\n");

    geraNumAleatorio(vetor, n);
  //================== IMPRIME VETOR DESORDENADO =============================
     printf("\t");
    imprimeVetor(vetor, n);

      printf("\n\n");

        printf("\n\tNUMEROS ALEATORIOS ORDENADOS\n");
         printf("\n\n");

	//BUBBLE
    printf("\t  Ordenacao - BUBBLE\n");
    bubble(vetor,n);
    printf("\t");
	imprimeVetor(vetor, n);


	//contadorTempo();
	 printf("\n\n");

	 //SELECTION
	printf("\t  Ordenacao - SELECTION\n");
    selection(vetor,n);
    printf("\t");
	imprimeVetor(vetor, n);
	//contadorTempo();
	 printf("\n\n");


     //INSERCTION
	printf("\t  Ordenacao - INSERCTION\n");
    inserction(vetor,n);
    printf("\t");
	imprimeVetor(vetor, n);
	//contadorTempo();
	 printf("\n\n");


    //QUICK
    printf("\t  Ordenacao - QUICK\n");
    quick(vetor, 0, n);
    printf("\t");
	imprimeVetor(vetor, n);
//	contadorTempo();
	 printf("\n\n");


    //TIMSORT
    printf("\t  Ordenacao - TIMSORT\n");
    timSort(vetor, n);
    printf("\t");
	imprimeVetor(vetor, n);
//	contadorTempo();
	 printf("\n\n");

    // TEMPO EXECUÇÃO

 //contaTempo();

  clock_t tempo;
    tempo = clock();

    // código de teste
    for(int i = 0; i < 99999999; ++i) {}
    //fim
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);


    printf("\n\n");

    system("pause");
    return 0;
}
