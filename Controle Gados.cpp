#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>
#include <locale.h>

void total_leite();
void total_alim();
void leite_apos();
void alim_apos();
void num_abates();

struct abatimento 
{
	int cod;
	int ano;
	float leite;
	float alim;
	char abate;	
};
struct abatimento gado[30];

int cont = 0, gado_abate = 0;
	
int main()
{
	int idade;
	char dc, menu, data[8],ano[3];
	setlocale(LC_ALL, "Portuguese");
	do
	{
		idade = 0;
		cont++;
	    printf("\t\t\t\t\t[Bem vindo a tela de cadastro]");
	    printf("\n\nCódigo da cabeça do gado: ");
	     fflush(stdin);
	    scanf("%d",&gado[cont].cod);
	    
	    printf("\nLitros de Leite produzido por semana: ");
	    fflush(stdin);
        scanf("%f",&gado[cont].leite);
	    
	    printf("\nQuantidade de alimentos ingerido por semana (KG): ");
	    fflush(stdin);
        scanf("%f",&gado[cont].alim);
	    
	    printf("\nAno de Nascimento: ");
	    fflush(stdin);
		scanf("%d",&gado[cont].ano);
	    
	    idade = 2019 - gado[cont].ano;
	    
	    if (idade > 5 || gado[cont].leite < 40)
	    {
	    	gado[cont].abate = 'S';
	    	gado_abate++;
		}
		else if (gado[cont].leite >= 50 && gado[cont].leite <= 70 && gado[cont].alim / 7 > 50)
		{
			gado[cont].abate = 'S';
	    	gado_abate++;
		}
	    else
	    {
	    	gado[cont].abate = 'N';
		}
		do
		{
			printf("\nDeseja continuar ? [S/N]\n");
	    	fflush(stdin);
	    	scanf("%c", &dc);
		}
		while (toupper(dc) != 'S' && toupper(dc) != 'N');
		system("cls");
	}
	while (toupper(dc) == 'S');
		    
	do
	{
		system("cls");
		printf("(A) Quantidade total de leite produzida em uma semana.");
		printf("\n(B) Quantidade total de alimento consumido por semana na fazenda.");
		printf("\n(C) Quantidade total de leite que vai ser produzido por uma semana na fazenda, apos o abate.");
		printf("\n(D) Quantidade total de alimento que vai ser consumido por semana na fazenda, após o abate.");
		printf("\n(E) Numero de cabeças de gado que iriam para o abate.");
	    printf("\n(F) Sair\n");
	    fflush(stdin);
	    scanf("%c",&menu);
	    
	    switch (toupper(menu))
	    {
	    	case 'A':
	    		total_leite();
	    		break;
	    	case 'B':
	    		total_alim();
	    		break;
	    	case 'C':
	    		leite_apos();
	    		break;
	    	case 'D':
	    		alim_apos();
	    		break;
	    	case 'E':
	    		num_abates();
	    		break;
	    	case 'F':
	    		return 0;
	    		break;
	    	default:
	    		printf("\n\nOpcao invalida...\n\n");
	    		system("pause");
		}
	}	
	while (menu != 'F');
}

void total_leite()
{
	float leite_total = 0;
	system("cls");
	for (int i = 1; i <= cont; i++)
		leite_total += gado[i].leite;
			
	printf("--------------------------------------------------------");
	printf("\nTotal de leite produzido por semana na fazenda: %.2f", leite_total);
	printf("\n--------------------------------------------------------\n\n");
	system("pause");
}

void total_alim()
{
	float tot_alim = 0;
	system("cls");
	for (int i = 1; i <= cont; i++)
		tot_alim += gado[i].alim;
	
	printf("--------------------------------------------------------");
	printf("\nTotal de alimento consumido por semana na fazenda: %.2f", tot_alim);
	printf("\n--------------------------------------------------------\n\n");
	system("pause");
}

void leite_apos()
{
	float leite_total = 0;
	system("cls");
	
	for (int i = 1; i <= cont; i++)
	{
		if (gado[i].abate == 'N')
			leite_total += gado[i].leite;		
	}
			
	printf("--------------------------------------------------------");
	printf("\nTotal de leite produzido por semana na fazenda: %.2f", leite_total);
	printf("\n--------------------------------------------------------\n\n");
	system("pause");	
}

void alim_apos()
{
	float tot_alim = 0;
	system("cls");
	for (int i = 1; i <= cont; i++)
	{
		if (gado[i].abate == 'N')
			tot_alim += gado[i].alim;
	}
		
	printf("--------------------------------------------------------");
	printf("\nTotal de alimento consumido por semana na fazenda: %.2f", tot_alim);
	printf("\n--------------------------------------------------------\n\n");
	system("pause");	
}

void num_abates()
{
	system("cls");
	printf("--------------------------------------------------------");
	printf("\nTotal de gados que irão ao abate: %d", gado_abate);
	printf("\n--------------------------------------------------------\n\n");
	system("pause");
}
