#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CENT 30001 
#define NUM_COIN_TYPE 5

unsigned long long int CoinType[NUM_COIN_TYPE] = {1, 5, 10, 25, 50};
unsigned long long int MoneyCombination[MAX_CENT] = {0};

int main(void)
{
  int NumCent;
  int IdxNumCent;
  int IdxCoinType;
/*
  freopen("p357_in.txt", "r", stdin);
  freopen("p357_out.txt", "w", stdout);
*/
  
  MoneyCombination[0] = 1; 
  for ( IdxCoinType = 0; IdxCoinType < NUM_COIN_TYPE; IdxCoinType++) {
     for ( IdxNumCent = CoinType[IdxCoinType]; IdxNumCent < MAX_CENT; IdxNumCent++) {
	   MoneyCombination[IdxNumCent]  +=  MoneyCombination[IdxNumCent - CoinType[IdxCoinType]];
	 }
  }
  
  while (scanf("%d", &NumCent)==1) {
    if ( MoneyCombination[NumCent] != 1) {
	   printf("There are %llu ways to produce %d cents change.\n",MoneyCombination[NumCent], NumCent);
	} else {
	   printf("There is only 1 way to produce %d cents change.\n", NumCent);
	}
  }
  

   
   return 0;
}
