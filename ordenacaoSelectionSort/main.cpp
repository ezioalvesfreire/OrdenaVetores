#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int buscaBinaria(int arranjo[],int tamanho, int valorProcurado)
{
    // Na busca binária, espera-se que o vetor esteja ordenado

    int i = 0;
    int f = tamanho -1;
    int meio;
    while (i<=f)
    {
        meio = (i+f)/2;
        if (arranjo[meio]==valorProcurado)
            return meio;
        else
        {
            if (valorProcurado>arranjo[meio])
                i=meio+1;
            else
                f=meio-1;
        }
    }
    return -1;
}

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
    int vetor[10];
    int n =10;

    printf("\n================= ORDENACAO DE DADOS METODO SELECTION SORT ===================\n\n");

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

    printf("\n\n");

    int p,resposta;
    printf("Qual valor a ser procurado?\n");

    scanf("%d", &p);

    resposta=buscaBinaria(vetor,n,p);
    if (resposta==-1)
        printf("O valor procurado nao foi encontrado.");

    else
        printf("O valor procurado encontra-se na posicao %d ", resposta);
    printf("\n\n");

    printf("\n\n\n\n\n\n\n");

    contaTempo();

    printf("\n\n\n");

    system("pause");

    return 0;
}
