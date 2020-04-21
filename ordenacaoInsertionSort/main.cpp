#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void insertion(int vet[], int n)
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
void geraNumAleatorio(int vetor[], int n){
srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};
      //  printf("%d ", vetor[i]);

   }
}
void imprimeVetor(int vetor[], int n){
    for(int i=0; i < n; i++)/**<  */
    {
        printf("%d ", vetor[i]);
    }
}

void calculaTempo(){
  clock_t tempo;
	tempo = clock();

    // código de teste
	for(int i = 0; i < 99999999; ++i){}
	//fim
	printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);
}

int main()
{
    int vetor[100000];
    int n = 100000;

    printf("\n================= ORDENACAO DE DADOS METODO INSERTION SORT ===================");
    printf("\n\n\n");
    printf("\t\tNUMEROS ALEATORIOS DESORDENADOS");
    printf("\n\n\t\t  ");

    geraNumAleatorio(vetor, n);
//==================== IMPRIME O VETOR DESORDENADO ====================
      imprimeVetor(vetor, n);

    printf("\n\n");

    insertion(vetor, n);

    //printf("\n\n");
    printf("\n\t\tNUMEROS ALEATORIOS ORDENADOS");
    printf("\n\n\t\t  ");
//==================== IMPRIME O VETOR ORDENADO ====================
   imprimeVetor(vetor, n);

    printf("\n\n");

    calculaTempo();

    printf("\n\n\n");

    system("pause>>null");

    return 0;
}
