#include <stdio.h>
#include <stdlib.h>

int main() {
	int n[20], i = 0, aux = 0, aux1 = 0, x = 19;
	
	for (i = 0; i < 20; i++)
	{
		printf("Digite o %d numero: ", i);
		scanf("%d", &n[i]);
	}
	
	printf("\nSequencia normal: ");

	for (i = 0; i < 20; i++)
	{
		printf("%d  ", n[i]);
	}
	
	for (i = 0; i < 10; i++)
	{
		aux = n[i];
		aux1 = n[x];
		n[x] = aux;
		n[i] = aux1;
		x--;
	}
	
	printf("\n\nSequencia invertida: ");
	
	for (i = 0; i < 20; i++)
	{
		printf("%d ", n[i]);
	}
}
