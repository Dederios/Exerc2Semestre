#include <stdio.h>
#include <stdlib.h>

int main() {
	int num[10], i = 0, maior = 0, menor = 100;
	
	for (i = 0; i < 10; i++) {
		printf("Digite o %d numero: ", i);
		scanf("%d", &num[i]);
	}
	
	for (i = 0; i < 10; i++) {
		if (num[i] > maior) {
			maior = num[i];
		}
		
		if (num[i] < menor) {
			menor = num[i];
		}
	}
	
	printf("\nMenor numero: %d \nMaior numero: %d", menor, maior);
	return 0;
}
