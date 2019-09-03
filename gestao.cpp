#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

int i = 0, faltas[10], cont = 0;
float n1[10], n2[10], mf[10];
char data[11], rgm[10][10], nome[10][20], curso[10][20], situacao[10][20];
void cadastro(); //Declaração de função

main()
{
	strcpy(data,__DATE__);
	setlocale(LC_ALL, "Portuguese");
	int menu = 0;
	do
	{
		system("cls");
		printf("Bem Vindo ao programa de Gestão acadêmica");
		printf("\n\n(1) Cadastro");
		printf("\n(6) Sair\n");
		scanf("%d", &menu);
		switch (menu)
		{
			case 1:
				cadastro(); //Chamando a função
				break;
			case 6:
				break;
			default:
				printf("\nOpcão inválida utilize somente os números de 1 a 6\n");
				system("pause");
		}
	}
	while (menu != 6);
}

void cadastro() //Função que cadastra o aluno, seu rgm, notas e faltas.
{
	char ano[3], contchar[10];
	int dc = 0;
	do
	{
		system("cls");
		ano[0] = data[9];
		ano[1] = data[10];
		ano[2] = '\0';
		itoa(cont, contchar, 10);
		rgm[i][0] = ano[0];
		rgm[i][1] = ano[1];
		rgm[i][2] = contchar[0];

		if (cont >= 10)
		{
			rgm[i][3] = contchar[1];
		}
		rgm[i][4] = '\0';
		
		printf("RGM: %s\n", rgm[i]);
		
		do 
		{
			printf("\nNome completo: ");
			fflush(stdin);
			gets(nome[i]);
			if (nome[i][0] == '\0' || nome[i][0] == ' ') 
				printf("\nDigite novamente, sem espaços no começo.\n");
		}
		while(nome[i][0] == '\0' || nome[i][0] == ' ');
	
		do 
		{
			printf("\nCurso de %s: ", nome[i]);
			fflush(stdin);
			gets(curso[i]);
			if (curso[i][0] == '\0' || curso[i][0] == ' ') 
				printf("\nDigite novamente, sem espaços no começo.\n");
		} 
		while(curso[i][0] == '\0' || curso[i][0] == ' ');
		
		do
		{
			printf("\nN1: ");
			fflush(stdin);
			scanf("%f", &n1[i]);
			if (n1[i] < 0 || n1[i] > 10) 
				printf("\nN1 inválida, digite somente os números de 0 a 10.\n");
		}
		while (n1[i] < 0 || n1[i] > 10);
		
		do
		{
			printf("\nN2: ");
			fflush(stdin);
			scanf("%f", &n2[i]);
			if (n2[i] < 0 || n2[i] > 10) 
				printf("\nN2 inválida, digite somente os números de 0 a 10.\n");
		}
		while (n2[i] < 0 || n2[i] > 10);
		
		mf[i] = ((n1[i]+n2[i])*2)/3;
		
		do
		{
			printf("\nTotal de faltas: ");
			fflush(stdin);
			scanf("%d", &faltas[i]);
			if (faltas[i] < 0 || faltas[i] > 80) 
				printf("\nO total de faltas não pode exceder 80 e nem menor que 0.\n");	
		}
		while (faltas[i] < 0 || faltas[i] > 80);
		
		if (mf[i] < 5)
		{
			strcpy(situacao[i], "reprovado");
		} 
		else if (faltas[i] > 80)
		{
			strcpy(situacao[i], "reprovado");
		}
		else
		{
			strcpy(situacao[i], "aprovado");
		}

		i++;
		cont++;
		
		do
		{
			printf("\nDeseja continuar? (S/N)");
			fflush(stdin);
			scanf("%c", &dc);
		} 
		while (toupper(dc) != 'S' && toupper(dc) != 'N');
	}
	while (toupper(dc) == 'S');
}
