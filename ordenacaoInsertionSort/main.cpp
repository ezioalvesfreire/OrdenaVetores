#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int buscaBinaria(int arranjo[],int tamanho, int valorProcurado) {
	// Na busca binária, espera-se que o vetor esteja ordenado

	int i = 0;
	int f = tamanho -1;
	int meio;
	while (i<=f) {
		meio = (i+f)/2;
		if (arranjo[meio]==valorProcurado)
			return meio;
		else {
			if (valorProcurado>arranjo[meio])
				i=meio+1;
			else
				f=meio-1;
		}
	}
	return -1;
}

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
    int vetor[10];
    int n = 10;

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

    int p,resposta;
    printf("Qual valor a ser procurado?\n");

	scanf("%d", &p);

	resposta=buscaBinaria(vetor,n,p);
	if (resposta==-1)
        printf("O valor procurado nao foi encontrado.");

	else
        printf("O valor procurado encontra-se na posicao %d ", resposta);
        printf("\n\n");

    calculaTempo();

    printf("\n\n\n");

    system("pause>>null");

    return 0;
}
