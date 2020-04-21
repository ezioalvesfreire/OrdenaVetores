#include <stdio.h>
#include <stdlib.h>
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

// void bubble é o método para ordenação do vetor
void bubble(int vetor[],int n)
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
void geraNumAleatorio(int vetor[],int n){

srand(time(NULL));
    for(int i = 0; i < n; i++)
    {
        vetor[i] = { rand() % 50};
      //  printf("%d ", vetor[i]);

    }
}
void imprimeVetor(int vetor[], int n){
for(int i=0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
}

void contaTempo(){


}

int main()
{
    int vetor[10];
    int n=10;
    printf("\n================= ORDENACAO DE DADOS METODO BUBBLE SORT ===================\n\n");


    printf("\n\n");
    printf("======================== NUMEROS ALEATORIOS ========================\n");
    printf("\n\n");

    printf("\tNUMEROS ALEATORIOS DESORDENADOS");
    printf("\n\n\t");

    geraNumAleatorio(vetor,n);
    //========================= IMPRIME VETOR DESORDENADO ================
    imprimeVetor(vetor, n);

    printf("\n\n\n\t");

    printf("NUMEROS ALEATORIOS ORDENADOS");
    printf("\n\n\n\t");

    bubble(vetor,n);

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


    printf("\n\n");

    // Função que calcula o tempo de execução

    clock_t tempo;
    tempo = clock();

    // código de teste
    for(int i = 0; i < 99999999; ++i) {}
    //fim
    printf("Tempo:%f",(clock() - tempo) / (double)CLOCKS_PER_SEC);


    printf("\n\n\n");

    system("pause");
    return 0;
}
