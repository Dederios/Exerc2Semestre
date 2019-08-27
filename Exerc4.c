#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i = 0, dc = 0, qtdaluno = 0, nota[20];
char gabarito[11], aluno[20][20], curso[20][20], respostas[20][11], situacao[20][10]; //Declaração de variáveis Global

void verificar(); //Declaração das funções
void dados();

int main()
{
	printf("Digite o gabarito: ");
	gets (gabarito);
	
	dados();
	verificar();

	for (i = 0; i < qtdaluno; i++)
	{
		printf("\n%s do curso %s, conseguiu %d pontos e foi %s. ", aluno[i], curso[i], nota[i], situacao[i]);
	}
	return 0;	
}

void dados()
{
	int dc = 0;
	
	do 
	{
		qtdaluno++;
		printf("\nDigite o nome do %d aluno: ", qtdaluno);
		fflush(stdin);
		gets(aluno[i]);
		
		printf("\nDigite o curso de %s: ", aluno[i]);
		fflush(stdin);
		gets(curso[i]);
		
		printf("\nDigite o gabarito de %s: ", aluno[i]);
		fflush(stdin);
		gets(respostas[i]);
		
		printf("\nDigite 1 para cadastrar mais alunos ou 0 para ver as notas gerais.\n");
		fflush(stdin);
		scanf("%d", &dc);
		i++;
	}
	while (dc == 1);
}

void verificar()
{
	int x = 0, notas = 0;
	
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
}
