#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int i = 0, dc = 0, qtdaluno = 0, x = 0, nota[20], notas = 0;
	char gabarito[11], aluno[20][20], curso[10][20], respostas[20][11], situacao[20][10];
	
	printf("Digite o gabarito: ");
	gets (gabarito);
	
	do 
	{
		qtdaluno++;
		printf("\nDigite o nome do %d aluno: ", qtdaluno);
		fflush(stdin);
		gets(aluno[i]);
		
		printf("\nDigite o curso de %s: ", aluno[i]);
		fflush(stdin);
		gets(curso[i]);
		
		printf("\nDigite as respostas de %s: ", aluno[i]);
		fflush(stdin);
		gets(respostas[i]);
		
		printf("\nDigite 1 para cadastrar mais alunos ou 0 para ver as notas gerais.\n");
		fflush(stdin);
		scanf("%d", &dc);
		i++;
	}
	while (dc == 1);
	
	for (i = 0; i < qtdaluno; i++)
	{
		notas = 0;
		for (x = 0; x <= 10; x++)
		{
			if (respostas[i][x] == gabarito[i])
			{
				notas++;
			}
		}
		nota[i] = notas;
		
		if (nota[i] >= 5)
		{
			strcpy(situacao[i], "aprovado");
		}
		else if (nota[i] < 5)
		{
			strcpy(situacao[i], "reprovado");
		}
	}
	
	for (i = 0; i < qtdaluno; i++)
	{
		printf("\n%s do curso %s, conseguiu %d pontos e foi %s. ", aluno[i], curso[i], nota[i], situacao[i]);
	}
	return 0;
}
