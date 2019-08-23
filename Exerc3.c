#include <stdio.h>
#include <stdlib.h>

int main() {
	int n[10], i = 0, numeromenor = 0, numeromaior = 0, alunos = 0;
	float alturamaior = 0, alturamenor = 4.0, altura[10];
	
	printf("Digite o numero de alunos: ");
	scanf("%d", &alunos);
	
	for (i = 0; i < alunos; i++)
	{
		printf("\nDigite o numero do aluno: ");
		fflush(stdin);
		scanf("%d", &n[i]);
		printf("Digite a altura do aluno: ");
		fflush(stdin);
		scanf("%f", &altura[i]);
		printf("\n");
		
		if (altura[i] > alturamaior )
		{
			alturamaior = altura[i];
			numeromaior = n[i];	
		}
		
		if (altura[i] < alturamenor)
		{
			alturamenor = altura[i];
			numeromenor = n[i];
		}
	}
	
	printf("\nO numero do menor aluno: %d com o tamanho de %.2f", numeromenor, alturamenor);
	printf("\nO numero do maior aluno: %d com o tamanho de %.2f", numeromaior, alturamaior);
}
