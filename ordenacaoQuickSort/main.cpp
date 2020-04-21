#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>



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
    if(esq<dir)
    {
        pos = dividir(vetor, esq, dir);
        quick(vetor, esq, pos-1);
        quick(vetor, pos+1, dir);

    }
}

void geraNumAleatorio(int vetor[], int n){
 srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};
       // printf("%d ", vetor[i]);

    }
}

void imprimeVetor(int vetor[], int n){
for(int i=0; i < n; i++){
  printf("%d ", vetor[i]);
}

}

int main()
{
int vetor[100000];
int n = 100000;
    printf("\n================= ORDENACAO DE DADOS METODO QUICK SORT ===================\n\n");

     geraNumAleatorio(vetor, n);

    printf("\n\t\t NUMEROS ALEATORIOS DESORDENADOS");
    printf("\n\n\t\t  ");


//================== IMPRIME VETOR DESORDENADO ====================================
    imprimeVetor(vetor, n);

    quick(vetor,0,n);
   printf("\n\n\n\t\t NUMEROS ALEATORIOS ORDENADOS");
    printf("\n\t\t  ");

//================== IMPRIME VETOR DESORDENADO ====================================
    imprimeVetor(vetor, n);

    printf("\n\n\n");

    clock_t tempo;
    tempo = clock();

    //Função que calcula o tempo de execução do programa

    // código de teste
    for(int i = 0; i < 99999999; ++i) {}
    //fim
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);

    printf("\n\n\n");

    system("pause");

    return 0;
}
