#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>

//Declaração de função
void cadastro();
void consulta();


//Declaração de variáveis globais
int i = 0, faltas[10], cont = 0, submenu = 0;
float n1[10], n2[10], mf[10];
char data[11], rgm[10][10], nome[10][20], curso[10][20], situacao[10][20];

int main()
{
	strcpy(data,__DATE__);
	setlocale(LC_ALL, "Portuguese");
	int menu = 0;
	do
	{
		system("cls");
		printf("Bem Vindo ao programa de Gestão acadêmica");
		printf("\n\n(1) Cadastro");
		printf("\n(2) Consulta");
		printf("\n(6) Sair\n");
		scanf("%d", &menu);
		switch (menu)
		{
			case 1:
				cadastro();
				break;
			case 2:
				do
				{
					system("cls");
					printf("(1) Consulta por RA");
					printf("\n(2) Consulta por nome");
					printf("\n(3) Melhor aluno do curso");
					printf("\n(4) Consulta por curso");
					printf("\n(5) Retornar\n");
					scanf("%d", &submenu);
					consulta();
				}
				while (submenu != 5);
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
	int tamanho = 0;
	char ano[3], contchar[10];
	char dc = 0;
	do
	{
		i++;
		cont++;
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

		do 
		{
			system("cls");
			printf("RGM: %s\n", rgm[i]);
			printf("\nNome: ");
			fflush(stdin);
			gets(nome[i]);
			if (nome[i][0] == '\0' || nome[i][0] == ' ')
			{
				printf("\nDigite novamente, sem espaços no começo.\n");
				system("pause");
			} 
			else
			{
				tamanho = strlen(nome[i]);
				for (int x = 0; x < tamanho; x++)
					nome[i][x] = toupper(nome[i][x]);
			}
		}
		while(nome[i][0] == '\0' || nome[i][0] == ' ');
	
		do 
		{
			printf("\nCurso: ", nome[i]);
			fflush(stdin);
			gets(curso[i]);
			if (curso[i][0] == '\0' || curso[i][0] == ' ') 
			{
				printf("\nDigite novamente, sem espaços no começo.\n");
				system("pause");
			} 
			else
			{
				tamanho = strlen(curso[i]);
				for (int x = 0; x < tamanho; x++)
					curso[i][x] = toupper(curso[i][x]);
			}			
		} 
		while(curso[i][0] == '\0' || curso[i][0] == ' ');
		
		do
		{
			printf("\nN1: ");
			fflush(stdin);
			scanf("%f", &n1[i]);
			if (n1[i] < 0 || n1[i] > 10)
			{
				printf("\nN1 inválida, digite somente os números de 0 a 10.\n");
				system("pause");
			} 	
		}
		while (n1[i] < 0 || n1[i] > 10);
		
		do
		{
			printf("\nN2: ");
			fflush(stdin);
			scanf("%f", &n2[i]);
			if (n2[i] < 0 || n2[i] > 10)
			{
				printf("\nN2 inválida, digite somente os números de 0 a 10.\n");
				system("pause");
			} 
		}
		while (n2[i] < 0 || n2[i] > 10);
		
		mf[i] = ((n1[i]+n2[i])*2)/3;
		
		do
		{
			printf("\nTotal de faltas: ");
			fflush(stdin);
			scanf("%d", &faltas[i]);
			if (faltas[i] < 0 || faltas[i] > 80) 
			{
				printf("\nO total de faltas não pode exceder 80 e nem menor que 0.\n");	
				system("pause");
			} 
		}
		while (faltas[i] < 0 || faltas[i] > 80);
		
		do
		{
			printf("\nDeseja continuar? (S/N)\n");
			fflush(stdin);
			scanf("%c", &dc);
		} 
		while (toupper(dc) != 'S' && toupper(dc) != 'N');
	}
	while (toupper(dc) == 'S');
}

void consulta()
{
	int ra = 0, achou = 0, x = 0, melhores[50], notamaior = 0, tamanho = 0, faltastotal = 0;
	char dc, nconsulta[50], cursoconsulta[50];
	do 
	{
		switch (submenu)
		{
			case 1:
				do
				{
					system("cls");
					printf("Digite o RA: ");
					fflush(stdin);
					scanf("%d", &ra);
					
					if (ra > cont || ra < 1)
						printf("\nRA não encontrado");
					else
					{
						printf("\nNome: %s", nome[ra]);
						printf("\nCurso: %s", curso[ra]);
						printf("\nMedia Final: %f", mf[ra]);
						printf("\nTotal de faltas: %d", faltas[ra]);
					}

					printf("\n\nDeseja continuar? (S/N)\n");
					fflush(stdin);
					scanf("%c", &dc);
				} 
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 2:
				do
				{
					do
					{
						system("cls");
						printf("Entre com o nome: ");
						fflush(stdin);
						gets(nconsulta);
						if (nconsulta[0] == '\0' || nconsulta[0] == ' ')
						{
							printf("\nDigite novamente, sem espaços no começo.\n");
							system("pause");
						}	
						else
						{
							tamanho = strlen(nconsulta);
							for (x = 0; x < tamanho; x++)
								nconsulta[x] = toupper(nconsulta[x]);
						}
					} 
					while(nconsulta[0] == '\0' || nconsulta[0] == ' ');
					
					for (x = 0; x <= cont; x++)
					{
						if (strcmp(nconsulta,nome[x])==0)
						{
							achou = 1;
							printf("\nRGM: %s", rgm[x]);
							printf("\nCurso: %s", curso[x]);
							printf("\nMedia Final: %f", mf[x]);
							printf("\nTotal de faltas: %d", faltas[x]);
						}
					}
					
					if (achou != 1)
						printf("\nNome não cadastrado");
					
					achou = 0;	
					
					printf("\n\nDeseja continuar? (S/N)");
					fflush(stdin);
					scanf("%c", &dc);				
				}
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 3:
				do
				{
					do
					{
						system("cls");
						printf("Entre com o curso: ");
						fflush(stdin);
						gets(cursoconsulta);
						if (cursoconsulta[0] == '\0' || cursoconsulta[0] == ' ')
						{
							printf("\nDigite novamente, sem espaços no começo.\n");
							system("pause");
						}
						else
						{
							tamanho = strlen(cursoconsulta);
							for (x = 0; x < tamanho; x++)
								cursoconsulta[x] = toupper(cursoconsulta[x]);
						}							
					} 
					while(cursoconsulta[0] == '\0' || cursoconsulta[0] == ' ');
					
					for (x = 0; x <= cont; x++)
					{
						if (strcmp(cursoconsulta,curso[x])==0)
						{
							achou = 1;
							if (x == 0)	notamaior = mf[x];
							if (mf[x] > notamaior)	notamaior = mf[x];
						}
					}
					
					for (x = 0; x <= cont; x++)
					{
						if (strcmp(cursoconsulta,curso[x])==0)
						{
							if (mf[x] >= notamaior)
							{
								printf("\nAluno: %s, Media: %f", nome[x], mf[x]);
							}
						}
					}
					
					if (achou != 1)
						printf("\nCurso não encontrado");

					achou = 0;	
					
					printf("\n\nDeseja continuar? (S/N)");
					fflush(stdin);
					scanf("%c", &dc);		
				}
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 4:
				do
				{
					do
					{
						system("cls");
						printf("Entre com o curso: ");
						fflush(stdin);
						gets(cursoconsulta);
						if (cursoconsulta[0] == '\0' || cursoconsulta[0] == ' ')
						{
							printf("\nDigite novamente, sem espaços no começo.\n");
							system("pause");
						}
						else
						{
							tamanho = strlen(cursoconsulta);
							for (x = 0; x < tamanho; x++)
								cursoconsulta[x] = toupper(cursoconsulta[x]);
						}
					} 
					while(cursoconsulta[0] == '\0' || cursoconsulta[0] == ' ');
					
					for (x = 0; x <= cont; x++)
					{
						if (strcmp(cursoconsulta,curso[x])==0)
						{
							achou = 1;
							printf("\nNome: %s", nome[x]);
							printf("\nRGM: %s", rgm[x]);
							printf("\nMedia Final: %f", mf[x]);
							printf("\nTotal de faltas desse aluno: %d\n", faltas[x]);
							faltastotal = faltastotal + faltas[x];
						}
					}
					
					if (achou != 1)
						printf("\nCurso não encontrado");
					else 
						printf("\nTotal de faltas de todos os alunos do curso: %d", faltastotal);
					
					achou = 0;
					printf("\n\nDeseja continuar? (S/N)");
					fflush(stdin);
					scanf("%c", &dc);
				}
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 5:
				break;
			default:
				printf("\nOpcão inválida utilize somente os números de 1 a 6\n");
				system("pause");
		}
	}
	while (toupper(dc) == 'S');
}
