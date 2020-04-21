#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>



void selecao(int vet[], int n)
{

    int menor, aux;

    for(int i=0; i < n-1; i++)
    {
        menor = i;
        for(int j = i+1; j < n; j++)
        {
            if(vet[menor] > vet[j])
                menor=j;
        }
        if(i!=menor)
        {
            aux=vet[i];
            vet[i]=vet[menor];
            vet[menor]=aux;
        }
    }

}

void contaTempo()
{
    clock_t tempo;
    tempo = clock();

    // código de teste
    for(int i = 0; i < 99999999; ++i) {}
    //fim
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);

}

geraNumAleatorio(int vetor[], int n)
{

    srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};
      //  printf("%d ", vetor[i]);

    }
}

imprimeVetor(int vetor[],int n)
{
    for(int i=0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

}

int main()
{
    int vetor[10000];
    int n =10000;

    printf("================= ORDENACAO DE DADOS METODO SELECTION SORT ===================\n\n");

    printf("\n\t\t NUMEROS ALEATORIOS DESORDENADOS");
    printf("\n\n\t\t  ");

    geraNumAleatorio (vetor, n);

    //==================== IMPRIME O VETOR ORDENADO ====================

    imprimeVetor(vetor, n);

    selecao(vetor, n);

    printf("\n\n");
   //==================== IMPRIME O VETOR ORDENADO ====================
    printf("\n\t\t NUMEROS ALEATORIOS ORDENADOS");
    printf("\n\n\t\t  ");

    imprimeVetor(vetor, n);

    printf("\n\n\n\n\n\n\n");

    contaTempo();

    printf("\n\n\n");

    system("pause");

    return 0;
}
