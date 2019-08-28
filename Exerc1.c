#include <stdio.h>
#include <stdlib.h>

int main() {
	int e[10], i = 0, maior = 0, menor = 100;
	
	for (i = 0; i < 10; i++)
	{
		printf("Digite o %d numero: ", i);
		scanf("%d", &e[i]);
	}
	for (i = 0; i < 10; i++)
	{
		if (e[i] > maior)
		{
			maior = e[i];
		}
		if (e[i] < menor)
		{
			menor = e[i];
		}
	}
	printf("\nMenor numero: %d \nMaior numero: %d", menor, maior);
	return 0;
}
