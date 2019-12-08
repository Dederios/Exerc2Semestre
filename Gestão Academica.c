#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
//Bibliotecas

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_ESC 27
#define KEY_ENTER 13
//Declaração de Macros

int Menu();
void cadastro();
void consulta();
void alteracao();
void exclusao();
void relatorio();
//Declaração das funções

void gotoxy(int x, int y)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

int  faltas[10], cont = 0, submenu = 0;
float n1[10], n2[10], media[10];
char data[11], rgm[10][10], nome[10][20], curso[10][20];
//Varíaveis Globais

int main()
{
	strcpy(data,__DATE__);
	setlocale(LC_ALL, "Portuguese");
	int menu = 0;
	do
	{
		system("cls");
		menu = Menu();
		switch (menu)
		{
			case 1:
				cadastro();
				break;
			case 2:
				do
				{
					system("cls");
					printf("(1) Consulta por RGM");
					printf("\n(2) Consulta por nome");
					printf("\n(3) Melhor aluno do curso");
					printf("\n(4) Consulta por curso");
					printf("\n(5) Retornar\n");
					scanf("%d", &submenu);
					consulta();
				}
				while (submenu != 5);
				break;
			case 3:
				alteracao();
				break;
			case 4:
				exclusao();
				break;
			case 5:
				relatorio();
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

int Menu()
{
	int op = 1, key, menu = 0;
	while(1) 
	{
		system("cls");
		printf("Bem Vindo ao programa de Gestão acadêmica\n");
		printf("|=====================================|\n");
		printf("|  Código     |         Opção         |\n");
		printf("|=====================================|\n");
		printf("|     %s      |        Cadastro       |\n", (op == 1) ? "->" : "01");
		printf("|     %s      |        Consulta       |\n", (op == 2) ? "->" : "02");
		printf("|     %s      |        Alteração      |\n", (op == 3) ? "->" : "03");
		printf("|     %s      |        Exclusão       |\n", (op == 4) ? "->" : "04");
		printf("|     %s      |        Relátorio      |\n", (op == 5) ? "->" : "05");
		printf("|     %s      |          Sair         |\n", (op == 6) ? "->" : "06");
		printf("=======================================\n");
		key = getch();
		if(key == KEY_UP && op > 1) 
		{
			op--;
		}
		else if(key == KEY_DOWN && op < 6) 
		{
			op++;
		}
		else if(key == KEY_ESC) 
		{
			system("cls");
			return 6;
		}
		else if(key == KEY_ENTER) 
		{
			menu = op;
			system("cls");
			return menu;
		}
	}
}


void cadastro()
{
	int tamanho = 0;
	char ano[3], contchar[10];
	char dc = 0;
	do
	{
		cont++;
		ano[0] = data[9];
		ano[1] = data[10];
		ano[2] = '\0';
		itoa(cont, contchar, 10);
		rgm[cont][0] = ano[0];
		rgm[cont][1] = ano[1];
		rgm[cont][2] = contchar[0];

		if (cont >= 10)
		{
			rgm[cont][3] = contchar[1];
		}
		rgm[cont][4] = '\0';

		do 
		{
			system("cls");
			printf("RGM: %s\n", rgm[cont]);
			printf("\nNome: ");
			fflush(stdin);
			gets(nome[cont]);
			if (nome[cont][0] == '\0' || nome[cont][0] == ' ')
			{
				printf("\nDigite novamente, sem espaços no começo.\n");
				system("pause");
			} 
			else
			{
				tamanho = strlen(nome[cont]);
				for (int x = 0; x < tamanho; x++)
					nome[cont][x] = toupper(nome[cont][x]);
			}
		}
		while(nome[cont][0] == '\0' || nome[cont][0] == ' ');
	
		do 
		{
			printf("\nCurso: ");
			fflush(stdin);
			gets(curso[cont]);
			if (curso[cont][0] == '\0' || curso[cont][0] == ' ') 
			{
				printf("\nDigite novamente, sem espaços no começo.\n");
				system("pause");
			} 
			else
			{
				tamanho = strlen(curso[cont]);
				for (int x = 0; x < tamanho; x++)
					curso[cont][x] = toupper(curso[cont][x]);
			}			
		} 
		while(curso[cont][0] == '\0' || curso[cont][0] == ' ');
		
		do
		{
			printf("\nDigite o N1: ");
			fflush(stdin);
			scanf("%f", &n1[cont]);
			if (n1[cont] < 0 || n1[cont] > 10)
			{
				printf("\nN1 inválida, digite somente os números de 0 a 10.\n");
				system("pause");
			} 	
		}
		while (n1[cont] < 0 || n1[cont] > 10);
		
		do
		{
			printf("\nDigite o N2: ");
			fflush(stdin);
			scanf("%f", &n2[cont]);
			if (n2[cont] < 0 || n2[cont] > 10)
			{
				printf("\nN2 inválida, digite somente os números de 0 a 10.\n");
				system("pause");
			} 
		}
		while (n2[cont] < 0 || n2[cont] > 10);
		
		media[cont] = (n1[cont]+n2[cont])/2;
		
		do
		{
			printf("\nTotal de faltas: ");
			fflush(stdin);
			scanf("%d", &faltas[cont]);
			if (faltas[cont] < 0 || faltas[cont] > 80) 
			{
				printf("\nO total de faltas não ser menor que 0 e nem maior que 80.\n");	
				system("pause");
			} 
		}
		while (faltas[cont] < 0 || faltas[cont] > 80);
		
		do
		{
			printf("\n\nDeseja continuar? (S/N)\n");
			fflush(stdin);
			scanf("%c", &dc);
		} 
		while (toupper(dc) != 'S' && toupper(dc) != 'N');
	}
	while (toupper(dc) == 'S');
}

void consulta()
{
	int achou = 0, x = 0, notamaior = 0, tamanho = 0, faltastotal = 0, achourgm = 0, id = 0;
	char dc, nconsulta[50], cursoconsulta[50], rgmconsulta[10];
	do 
	{
		switch (submenu)
		{
			case 1:
				system("cls");
				printf("Digite o RGM: ");
				fflush(stdin);
				gets(rgmconsulta);
				for (int i = 0; i <= cont; i++)
				{
					if (strcmp(rgmconsulta,rgm[i])==0) 
					{
						achourgm = 1;
						id = i;
						break;
					}
				}
				if (achourgm != 1)
					printf("\nRGM não encontrado");
				else
				{
					printf("\nNome: %s", nome[id]);
					printf("\nCurso: %s", curso[id]);
					printf("\nMedia Final: %f", media[id]);
					printf("\nTotal de faltas: %d", faltas[id]);
				}
				
				achourgm = 0;
				
				do
				{
					printf("\n\nDeseja continuar? (S/N)\n");
					fflush(stdin);
					scanf("%c", &dc);
				} 
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 2:
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
						printf("\nMedia Final: %f", media[x]);
						printf("\nTotal de faltas: %d", faltas[x]);
					}
				}
				if (achou != 1)
					printf("\nNome não cadastrado");
					
				achou = 0;	
		
				do
				{
					printf("\n\nDeseja continuar? (S/N)\n");
					fflush(stdin);
					scanf("%c", &dc);
				} 
				while (toupper(dc) != 'S' && toupper(dc) != 'N');				
				break;
			case 3:
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
						if (x == 0)	
							notamaior = media[x];
						if (media[x] > notamaior)
							notamaior = media[x];
					}
				}
					
				for (x = 0; x <= cont; x++)
				{
					if (strcmp(cursoconsulta,curso[x])==0)
					{
						if (media[x] >= notamaior)
						{
							printf("\nAluno: %s, Media: %f", nome[x], media[x]);
						}
					}
				}
					
				if (achou != 1)
					printf("\nCurso não encontrado");
					
				achou = 0;	
				
				do
				{
					printf("\n\nDeseja continuar? (S/N)\n");
					fflush(stdin);
					scanf("%c", &dc);
				} 
				while (toupper(dc) != 'S' && toupper(dc) != 'N');		
				break;
			case 4:
				faltastotal = 0;
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
						printf("\nMedia Final: %f", media[x]);
						printf("\nTotal de faltas desse aluno: %d\n", faltas[x]);
						faltastotal = faltastotal + faltas[x];
					}
				}
					
				if (achou != 1)
					printf("\nCurso não encontrado");
				else 
					printf("\nTotal de faltas de todos os alunos do curso: %d", faltastotal);
				
				achou = 0;
				
				do
				{
					printf("\n\nDeseja continuar? (S/N)\n");
					fflush(stdin);
					scanf("%c", &dc);
				} 
				while (toupper(dc) != 'S' && toupper(dc) != 'N');
				break;
			case 5:
				return;
				break;
			default:
				printf("\nOpcão inválida utilize somente os números de 1 a 5\n");
				system("pause");
				return;
		}
	}
	while (toupper(dc) != 'N');
}

void alteracao()
{
	int id = 0, alteracao = 0, tamanho = 0, achourgm = 0;
	char dc, rgmalteracao[10];
	do
	{
		system("cls");
		printf("Entre com o RGM do aluno: ");
		fflush(stdin);
		gets(rgmalteracao);
		for (int i = 0; i <= cont; i++)
		{
			if (strcmp(rgmalteracao,rgm[i])==0)
			{
				achourgm = 1;
				id = i;
				break;
			}
		}
		if (achourgm != 1)
		{
			do
			{
				printf("\n\nRGM não cadastrado");
				printf("\n\nDeseja continuar? (S/N)\n");
				fflush(stdin);
				scanf("%c", &dc);
			} 
			while (toupper(dc) != 'S' && toupper(dc) != 'N');		
		}
		else
		{
			do
			{
				system("cls");
				printf("(1)Alterar nome, atual: %s", nome[id]);
				printf("\n(2)Alterar curso, atual: %s", curso[id]);
				printf("\n(3)Alterar N1, atual: %f", n1[id]);
				printf("\n(4)Alterar N2, atual: %f", n2[id]);
				printf("\n(5)Alterar o total de faltas, atual: %d", faltas[id]);
				printf("\n(6)Voltar\n");
				fflush(stdin);
				scanf("%d", &alteracao);
				switch (alteracao)
				{
					case 1:
						do 
						{
							printf("\nDigite o novo nome: ");
							fflush(stdin);
							gets(nome[id]);
							if (nome[id][0] == '\0' || nome[id][0] == ' ')
							{
								printf("\nDigite novamente, sem espaços no começo.\n");
								system("pause");
							} 
							else
							{
								tamanho = strlen(nome[id]);
								for (int x = 0; x < tamanho; x++)
									nome[id][x] = toupper(nome[id][x]);
							}
						}
						while(nome[id][0] == '\0' || nome[id][0] == ' ');
						break;
					case 2:
						do 
						{
							printf("\nDigite o novo curso: ");
							fflush(stdin);
							gets(curso[id]);
							if (curso[id][0] == '\0' || curso[id][0] == ' ') 
							{
								printf("\nDigite novamente, sem espaços no começo.\n");
								system("pause");
							}
							else
							{
								tamanho = strlen(curso[id]);
								for (int x = 0; x < tamanho; x++)
									curso[id][x] = toupper(curso[id][x]);
							}		
						}
						while(curso[id][0] == '\0' || curso[id][0] == ' ');
						break;
					case 3:
						do
						{
							printf("\nDigite a nova n1: ");
							fflush(stdin);
							scanf("%f", &n1[id]);
							if (n1[id] < 0 || n1[id] > 10)
							{
								printf("\nN1 inválida, digite somente os números de 0 a 10.\n");
								system("pause");
							}
							else
								media[id] = (n1[id]+n2[id])/2; 	
						}
						while (n1[id] < 0 || n1[id] > 10);
						break;
					case 4:
						do
						{
							printf("\nDigite a nova n2: ");
							fflush(stdin);
							scanf("%f", &n2[id]);
							if (n2[id] < 0 || n2[id] > 10)
							{
								printf("\nN2 inválida, digite somente os números de 0 a 10.\n");
								system("pause");
							}
							else
								media[id] = (n1[id]+n2[id])/2; 
						}
						while (n2[id] < 0 || n2[id] > 10);					
						break;
					case 5:
						do
						{
							printf("\nDigite o novo total de faltas: ");
							fflush(stdin);
							scanf("%d", &faltas[id]);
							if (faltas[id] < 0 || faltas[id] > 80) 
							{
								printf("\nO total de faltas não ser menor que 0 e nem maior que 80.\n");	
								system("pause");
							} 
						}
						while (faltas[id] < 0 || faltas[id] > 80);
						break;
					case 6:
						break;
					default:
						printf("\n\nOpção inválida, utilize somente os números de 1 a 6.\n");	
						system("pause");
				}
			}
			while (alteracao != 6);			
		}
		achourgm = 0;
	}
	while (toupper(dc) == 'S' && alteracao != 6);
}

void exclusao()
{
	int id = 0, alteracao = 0, tamanho = 0, exclusao = 0, achourgm = 0;
	char dc, rgmexclusao[10];
	do
	{
		system("cls");
		printf("Entre com o RGM do aluno: ");
		fflush(stdin);
		gets(rgmexclusao);
		for (int i = 0; i <= cont; i++)
		{
			if (strcmp(rgmexclusao,rgm[i])==0)
			{
				achourgm = 1;
				id = i;
				break;
			}
		}
		if (achourgm != 1)
		{
			printf("\n\nRGM não encontrado");
			do
			{
				printf("\n\nDeseja continuar? (S/N)\n");
				fflush(stdin);
				scanf("%c", &dc);
			} 
			while (toupper(dc) != 'S' && toupper(dc) != 'N');
		}
		else
		{
			do
			{
				system("cls");
				printf("Nome: %s", nome[id]);
				printf("\nCurso: %s", curso[id]);
				printf("\nN1: %f", n1[id]);
				printf("\nN2: %f", n2[id]);
				printf("\nTotal de faltas: %d", faltas[id]);
				printf("\n\n(1) Confirmar exclusão");
				printf("\n(2) Voltar\n");
				fflush(stdin);
				scanf("%d", &exclusao);
				if (exclusao == 1)
				{
					strcpy(rgm[id],"\0");
					strcpy(nome[id],"\0");
					strcpy(curso[id],"\0");
					n1[id] = '\0';
					n2[id] = '\0';
					media[id] = '\0';
					faltas[id] = '\0';
					printf("\nAluno excluído com sucesso");
					printf("\n\nDeseja continuar? (S/N)");
					fflush(stdin);
					scanf("%c", &dc);
				}
				else if (exclusao != 1 && exclusao != 2)
				{
					printf("\nOpção inválida, utilize somentes os números (1) e (2)");
					system("pause");
				}
			}
			while(exclusao != 1 && exclusao != 2);	
		}
		achourgm = 0;
	}
	while (toupper(dc) == 'S');
}

void relatorio()
{
	int escolha = 0, i = 0, flag = 0, linha = 3, tamanho = 0, x = 0, achou = 0, id = 0;
	char dc, cursoconsulta[50], ordenado[10][20], aux[20], troca;
	do
	{
		system("cls");
		printf("(1) Relatorio dos reprovados");
		printf("\n(2) Relatorio do curso");
		printf("\n(3) Voltar\n");
		scanf("%d", &escolha);
		
		if (escolha == 1)
		{
			linha = 3;
			system("cls");
			gotoxy(12,1);
			printf("_______________________________________");
			gotoxy(11,2);
			printf("| RGM");
			gotoxy(21,2);
			printf("|Nome");
			gotoxy(36,2);
			printf("|Curso");
			gotoxy(51,2);
			printf("|");
			gotoxy(11,3);
			printf("|_________|______________|______________|");
			
			for (i = 1; i <= cont; i++)
			{
				if (media[i] < 5 && strcmp(nome[i]," ") > 0 || faltas[i] > 40 && strcmp(nome[i]," ") > 0)
				{
					linha++;
					gotoxy(11,linha);					
					printf("|%s", rgm[i]);
					gotoxy(21,linha);					
					printf("|%s", nome[i]);
					gotoxy(36,linha);
					printf("|%s", curso[i]);
					gotoxy(51,linha);
					printf("|");
					linha++;
					gotoxy(11,linha);
					printf("|_________|______________|______________|");
				}
			}
			gotoxy(11,linha+4);
			system("pause");
		}
		else if (escolha == 2)
		{
			troca = 's';
			for (int y = 1; y <= cont; y++)
			{
				strcpy(ordenado[y],nome[y]);
			}

			while (troca == 's')
			{
				troca = 'n';
				for (int x = 1; x < cont; x++)
				{
					if(strcmp(ordenado[x],ordenado[x+1]) == 1) 
					{
						strcpy(aux,ordenado[x]);
						strcpy(ordenado[x],ordenado[x+1]);
						strcpy(ordenado[x+1],aux);
						troca = 's';
					}	
				}
			}
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
				}
			}
			if (achou == 1)
			{
				linha = 3;
				system("cls");
				gotoxy(12,1);
				printf("_______________________________________");
				gotoxy(11,2);
				printf("| RGM");
				gotoxy(21,2);
				printf("|Nome");
				gotoxy(36,2);
				printf("|Media");
				gotoxy(44,2);
				printf("|Faltas");
				gotoxy(51,2);
				printf("|");
				gotoxy(11,3);
				printf("|_________|______________|_______|______|");
				
				for (int j = 1; j <= cont; j++)
				{
					for (i = 1; i <= cont; i++)
					{
						if (strcmp(ordenado[j],nome[i])==0)
						{
							if (strcmp(cursoconsulta,curso[i])==0) 
							{
								linha++;
								gotoxy(11,linha);					
								printf("|%s", rgm[i]);
								gotoxy(21,linha);					
								printf("|%s", nome[i]);
								gotoxy(36,linha);
								printf("|%2.f", media[i]);
								gotoxy(44,linha);
								printf("|%d", faltas[i]);
								gotoxy(51,linha);
								printf("|");
								linha++;
								gotoxy(11,linha);
								printf("|_________|______________|_______|______|");
							}
						}
					}	
				}
				gotoxy(11,linha+4);
				system("pause");
			}
			else
			{
				printf("\nCurso não encontrado\n\n");
				system("pause");
			}			
			achou = 0;
		}
		else if (escolha != 3)
		{
			printf("\n\nOpção inválida, utilize somente os números de 1 a 3\n\n");
			system("pause");
		}
	}
	while (toupper(dc) == 'S' || escolha != 3);
}
