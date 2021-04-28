/*------------------------------------------------------------------------------*/
#include<stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
/*------------------------------------------------------------------------------*/
#define TAMANHO 10000
/*------------------------------------------------------------------------------*/
int vetor[TAMANHO];
int vetorB[TAMANHO];
int vetorS[TAMANHO];
int vetorI[TAMANHO];
/*------------------------------------------------------------------------------*/
int menu();
void imprimir(int *v);
void carregarExemplo();
void carregarExemplos();
void bolha (int *v);
void selecao (int *v);
void insercao (int *v);
/*------------------------------------------------------------------------------*/
main()
{
	while(menu());
}
/*------------------------------------------------------------------------------*/
int menu()
{
	int opcao;
	clock_t Ticks[2];
	int fImprimir = 0;
	
	system("cls");
	printf("\n Digite:");
	printf("\n   0. Para Sair ");
	printf("\n   1.Bolha ");
	printf("\n   2.Selecao ");
	printf("\n   3.Insercao ");
	printf("\n   4.Executar os 3 algoritmos ");
	printf("\n");
	scanf("%d",&opcao);
	switch(opcao)
	{
		case 0:return 0;
		case 1:
		{
		  carregarExemplo();
		  /*-------------------------------------------------------*/		  
		  if(fImprimir)
		  {
		     printf("Antes da Ordenacao \n");
		     imprimir(vetor);		 
		  }
		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          bolha(vetor);
          Ticks[1] = clock();
          double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("Tempo gasto: %g ms.", Tempo);		  
		  /*-------------------------------------------------------*/
 		  if(fImprimir)
		  {
		     printf("Depois da Ordenacao \n");
		     imprimir(vetor);
	      }
		  /*-------------------------------------------------------*/		  
 		  printf("\nPressione qualquer tecla para continuar");		  
		  system("pause");
		  return 1;
		}
		case 2:
		{ 
          carregarExemplo();
		  /*-------------------------------------------------------*/		  
		  if(fImprimir)
		  {
		     printf("Antes da Ordenacao \n");
		     imprimir(vetor);		 
		  }
		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          selecao(vetor);
          Ticks[1] = clock();
          double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("Tempo gasto: %g ms.", Tempo);		  
		  /*-------------------------------------------------------*/
 		  if(fImprimir)
		  {
		     printf("Depois da Ordenacao \n");
		     imprimir(vetor);
	      }
		  /*-------------------------------------------------------*/		  
		  printf("\nPressione qualquer tecla para continuar");		  
		  system("pause");
		  return 1;
		}		
    	case 3:
		{ 
          carregarExemplo();
		  /*-------------------------------------------------------*/		  
		  if(fImprimir)
		  {
		     printf("Antes da Ordenacao \n");
		     imprimir(vetor);		 
		  }
		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          insercao(vetor);
          Ticks[1] = clock();
          double Tempo = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("Tempo gasto: %g ms.", Tempo);		  
		  /*-------------------------------------------------------*/
 		  if(fImprimir)
		  {
		     printf("Depois da Ordenacao \n");
		     imprimir(vetor);
	      }
		  /*-------------------------------------------------------*/		  
		  printf("\nPressione qualquer tecla para continuar");		  
		  system("pause");
		  return 1;
		}
    	case 4:
		{ 
          carregarExemplos();
		  /*-------------------------------------------------------*/		  
		  if(fImprimir)
		  {
		     printf("Antes da Ordenacao \n");
		     printf("[BOLHA]\n");
		     imprimir(vetorB);	
			 printf("[SELECAO]\n");
		     imprimir(vetorS);	
			 printf("[INSERCAO]\n");
		     imprimir(vetorI);		 
		  }
		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          bolha(vetorB);
          Ticks[1] = clock();
          double TempoB = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("[BOLHA] Tempo gasto: %g ms.\n", TempoB);		  
		  /*-------------------------------------------------------*/
  		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          insercao(vetorI);
          Ticks[1] = clock();
          double TempoI = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("[INSERCAO] Tempo gasto: %g ms.\n", TempoI);		  
		  /*-------------------------------------------------------*/
		  /*-------------------------------------------------------*/		  
          Ticks[0] = clock();
          selecao(vetorS);
          Ticks[1] = clock();
          double TempoS = (Ticks[1] - Ticks[0]) * 1000.0 / CLOCKS_PER_SEC;
          printf("[SELECAO] Tempo gasto: %g ms.\n", TempoS);		  
		  /*-------------------------------------------------------*/
 		  if(fImprimir)
		  {
		     printf("Depois da Ordenacao \n");
		     printf("[BOLHA]\n");
		     imprimir(vetorB);	
			 printf("[SELECAO]\n");	 
		     imprimir(vetorS);	
			 printf("[INSERCAO]\n"); 
		     imprimir(vetorI);		 
	      }
		  /*-------------------------------------------------------*/		  
		  printf("\nPressione qualquer tecla para continuar");		  
		  system("pause");
		  return 1;
		}
		
		default:
			printf("\nDigite uma opcao VALIDA! ");
			return 1;
	}	
}
/*------------------------------------------------------------------------------*/
void imprimir(int *v)
{
  int i;
  for(i=0; i < TAMANHO; i++)
     printf("%i\n",v[i]);
}
/*------------------------------------------------------------------------------*/
void carregarExemplo()
{
  int i;
  for(i=0; i < TAMANHO; i++)
     vetor[i]= rand() % 100;
}
/*------------------------------------------------------------------------------*/
void carregarExemplos()
{
  int i;
  for(i=0; i < TAMANHO; i++)
  {
  	    int a = rand() % 100;
		vetorB[i]= a;
		vetorS[i]= a;
		vetorI[i]= a;
  }
   
}
/*------------------------------------------------------------------------------*/
/*
Algoritmo de Ordenacao Bolha
*/
void bolha (int *v)
{
    int troca=1;
    int i=0;
    int aux;
    while (troca)
    {
        troca = 0;
        while (i < TAMANHO - 1)
        {
            if (v[i] > v[i+1])
            {
                aux = v[i];
                v[i] = v[i+1];
                v[i+1] = aux;
                troca = 1;
            }
            i++;
        }
        i = 0;
    }
}
/*
Algoritmo de Ordenacao Selecao
*/
void selecao (int *v)
{
    int i,j,aux, minimo, pos_minimo;
    for (i=0; i < TAMANHO-1; i++)
    {
        minimo = v[i];
        pos_minimo = i;
        for (j=i+1; j < TAMANHO; j++) // Passo 1 
        {
            if (minimo > v[j])
            {
                minimo = v[j];
                pos_minimo = j;
            }
        }
        if (pos_minimo != i)  // Passo 2
        {
            aux = v[pos_minimo];
            v[pos_minimo] = v[i];
            v[i] = aux;
        }
    }
}
/*
Algoritmo de Ordenacao Insercao
*/
void insercao (int *v)
{
    int i, j, aux;
    for (i=0; i<TAMANHO-1; i++)
    {
        j=i+1;
        while (v[j-1]>v[j] && j > 0)
        {
            aux = v[j-1];
            v[j-1]=v[j];
            v[j]=aux;
            j--;
        }
    }
}


