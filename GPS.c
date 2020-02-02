#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

void trajeto(int dp[10][10], int origem[100], int destino[100], int cont, int totalcusto);
int verificao(int origem, int destino);
void dadosTrajeto(int dp[10][10], int origem[100], int destino[100], int custo[100], int distancia[100], int cont);
void guiaTuristico(int destino);
char *cidade(int num);

int main() {
	setlocale(LC_ALL, "Portuguese");
  char dc = 'N';
	int origem[100], destino[100], erro = 0, distancia[100], custo[100], totalcusto = 0, percursototal = 0, cont = 0, x = 0, escolha = 0;
	int dp[10][10] = {{-2,107,140,429,72,2981,1427,422,325,408},
					 {100,-2,223,495,164,3029,1379,432,257,396,},
					 {125,170,-2,306,212,2885,1547,0,0,592,},
					 {400,450,250,-2,587,-1,1815,813,740,835},
					 {70,150,200,450,-2,3032,1398,531,421,414},
					 {980,990,990,-1,995,-2,4306,-1,2938,3309},
					 {450,450,475,500,450,600,-2,1697,1478,980},
					 {350,240,75,600,500,-1,600,-2,0,730},
					 {400,250,75,175,375,600,650,75,-2,497},
					 {375,350,350,400,325,750,600,550,400,-2}};
					 
	printf("Bem vindo ao sistema de GPS.\n\n");
	do
	{
		printf("\tCidades Disponiveis\n\n");
		printf("\t(0) São Paulo \t(1) Sorocaba \n\t(2) Taubate \t(3) Rio \n\t(4) Santos \t(5) Natal \n\t(6) Pelotas \t(7) Barretos \n\t(8) Bauru \t(9) Curitiba");
		if (toupper(dc) == 'N')
		{
			if (totalcusto != 0)
				printf("\n\n\tDistância total percorrida: %dKM \n\n\tValor total percorrido: R$%d", percursototal, totalcusto);
				
			printf("\n\n1-Novo percurso\n2-Finalizar\n");
			scanf("%d", &escolha);	
		}
		if (escolha == 2)
      break;
		else
		{
			do
			{
				trajeto(dp, origem, destino, cont, totalcusto);
				erro = verificao(origem[cont],destino[cont]);
			}
			while(erro == 1);
		
			dadosTrajeto(dp, origem, destino, custo, distancia, cont);
			
			percursototal += distancia[cont];
			totalcusto += custo[cont];
			
			cont++;
			
			do
			{
				printf("\n\nDeseja fazer mais um percurso ? (S/N)\n");
				fflush(stdin);
				scanf("%c",&dc);
			}
			while(toupper(dc) != 'S' && toupper(dc) != 'N');
			system("cls");	
		}
	}
	while(escolha == 1);
	system("cls");
	for (int i = 0; i < cont; i++)
	{
		if(dp[origem[i]][destino[i]] == -1)
		{
			continue;
		}
		else
		{
			x++;
			printf("O %dº percurso foi de %s até %s", x, cidade(origem[i]), cidade(destino[i]));
			printf("\nDistância: %dKM", distancia[i]);
			printf("\nCusto: R$%d\n\n", custo[i]);
		}
	}
	printf("\n\tDistância total: %dKM \n\tValor total: R$%d", percursototal, totalcusto);
	return 0;
}

void trajeto(int dp[10][10], int origem[100], int destino[100], int cont, int totalcusto) {
	if(cont < 1 || totalcusto == 0)
	{
		printf("\n\nEntre com o ID da cidade de origem: ");
		fflush(stdin);
		scanf("%d",&origem[cont]);
		printf("\nEntre com o ID da cidade de destino: ");
		fflush(stdin);
		scanf("%d",&destino[cont]);
	}
	else
	{
		if(dp[origem[cont-1]][destino[cont-1]] == -1)
			origem[cont] = origem[cont-1];
		else
			origem[cont] = destino[cont-1];
		
		printf("\n\nID da Cidade Atual: %d", origem[cont]);
		printf("\n\nEntre com o ID da cidade de destino: ");
		fflush(stdin);
		scanf("%d",&destino[cont]);
	}
}
	
int verificao(int origem, int destino) {
	int erro = 0;
	if(origem > 9 || origem < 0)
	{
		printf("\nCidade de origem inválida");
		erro = 1;
	}
	else if (destino > 9 || destino < 0)
	{
		printf("\nCidade de destino inválida");
		erro = 1;
	}
	else if(origem == destino)
	{
		printf("\nAs cidades não podem ser a mesma");
		erro = 1;
	}	
	return erro;
}

void dadosTrajeto(int dp[][10], int origem[100], int destino[100], int custo[100], int distancia[100], int cont)
{
	if(dp[origem[cont]][destino[cont]] == 0 || dp[destino[cont]][origem[cont]] == 0)
	{
		printf("\nCidade vizinha, o custo é de uma taxa fixa de R$75.00");
		custo[cont] = 75;
		distancia[cont] = 0;
	}
	else if(dp[origem[cont]][destino[cont]] == -1)
	{
		printf ("\nO trajeto não é realizado pela empresa.");
		custo[cont] = 0;
		distancia[cont] = 0;
	}
	else if(destino[cont] == 0 || origem[cont] == 9)
	{
		system("cls");
		printf("O percurso %s de até %s é de: %dKM", cidade(origem[cont]), cidade(destino[cont]), dp[destino[cont]][origem[cont]]);
		printf("\nO custo desse percurso foi: R$%d", dp[origem[cont]][destino[cont]]);		
		distancia[cont] = dp[destino[cont]][origem[cont]];
		custo[cont] = dp[origem[cont]][destino[cont]];
		guiaTuristico(destino[cont]);
	}
	else
	{
		system("cls");
		printf("O percurso %s de até %s é de: %dKM", cidade(origem[cont]), cidade(destino[cont]), dp[origem[cont]][destino[cont]]);
		printf("\nO custo desse percurso foi: R$%d", dp[destino[cont]][origem[cont]]);
		distancia[cont] = dp[origem[cont]][destino[cont]];
		custo[cont] = dp[destino[cont]][origem[cont]];
		guiaTuristico(destino[cont]);
	}
}

void guiaTuristico(int destino)
{
	switch (destino)
	{
		case 4:
			printf("\n\n\tOrquidário Municipal de Santos");
			printf("\n\n\tInaugurado em 1945, é um parque zoobotânico com 22.240m² \n\tque mistura características de belos jardins e aspectos de matas naturais.");
			printf("\n\tDispõe de uma floresta urbana e exuberante, cuidadosamente plantada e cultivada.\n");
			break;
		case 5:
			printf("\n\n\tUm show de história pode ser apreciado por quem visita este lugar.");
			printf("\n\tOs guias são muito bem preparados e divertidos(em especial, um chamado Neif)\n");
			break;
		case 6:
			printf("\n\n\tPontos Turisticos");
			printf("\n\n\tLocalizada em frente ao Mercado Central, foi elaborada pelo desenhista e aquarelista Dominique Pineau.");
			printf("\n\tConcebido inicialmente como escola municipal pelos herdeiros do tenente Coronel Eliseu Antunes Maciel.");
			break;
		case 7:
			printf("\n\n\tO Parque Peão de Boiadeiros de Barretos foi inaugurado em 1985,");
			printf("\n\té mais uma obra do renomado arquiteto Oscar Niemeyer e tem mais de 30 mil lugares.");
			break;
		case 9:
			printf("\n\n\tJardim Botânico ");
			printf("\n\n\tUm dos cartões postais mais famosos do Brasil, o Jardim Botânico \n\tfunciona como um centro de pesquisas da flora do Paraná.");
			break;
	}
}

char *cidade(int num)
{
	switch (num)
	{
		case 0:
			return (char*)"São Paulo";
		case 1:
			return (char*)"Sorocaba";
		case 2:
			return (char*)"Taubate";
		case 3:
			return (char*)"Rio";
		case 4:
			return (char*)"Santos";
		case 5:
			return (char*)"Natal";
		case 6:
			return (char*)"Pelotas";
		case 7:
			return (char*)"Barretos";
		case 8:
			return (char*)"Bauru";
		case 9:
			return (char*)"Curitiba";
	}
}
