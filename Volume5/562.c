/* @JUDGE_ID:50418EN 562 C */

#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT_OF_COINS 101

enum ElementInSet {
    NumberNotExist = 0,
	NumberIsExist = 1
};

int compare( const void *arg1, const void *arg2 )
{
	int a,b;
	a = *(int*) arg1;
	b = *(int*) arg2;
	return (a-b);
}

void CalcMinDiffTwoCoinSet(int NumOfCoin, int TotalValueOfCoins, int CoinValueList[])
{

   int IdxCoinValue,IdxCoinPermut;
   int AccumValue;	     
   int *CoinPermutation = NULL;
   int HalfTotalValue = TotalValueOfCoins/2;
   int currentCoinValue;
     
   /* Initialize Coin Permutation Array  */
   CoinPermutation = (int *) calloc( TotalValueOfCoins+1, sizeof(int));
   CoinPermutation[0] = NumberIsExist;       
   
   /* construct the Coin Permuation Array. If number is a liner combination in CoinValueList set, We mark it is exist in coin permuation */
   for ( IdxCoinValue = 0, AccumValue = 0  ; IdxCoinValue < NumOfCoin; IdxCoinValue++ ) {   	
   	   /* Accumulate the Coin Value and then count the line combination in coin value   */
   	   currentCoinValue =  CoinValueList[IdxCoinValue]; 
	   AccumValue += currentCoinValue;   	   
	   
	   for ( IdxCoinPermut = AccumValue ;  IdxCoinPermut > 0  ; IdxCoinPermut-- ) {
			if ( CoinPermutation[IdxCoinPermut] == NumberIsExist) {						
				   CoinPermutation[IdxCoinPermut + currentCoinValue] = NumberIsExist;
			}
	   }
	   /* Off Course, Element in CoinValue list is liner combination of CoinValue.*/
	   CoinPermutation[CoinValueList[IdxCoinValue]] = NumberIsExist;	   
   }    
   /*output the mininum different  of two coin set to screen. */
   for ( IdxCoinPermut = HalfTotalValue ; IdxCoinPermut >= 0 ; IdxCoinPermut-- ) {
		if (CoinPermutation[IdxCoinPermut] == NumberIsExist) {                                           
			printf("%d\n", (TotalValueOfCoins - IdxCoinPermut - IdxCoinPermut));
			break;
		}
	}	

    free(CoinPermutation);
   
}

int main()
{
    int NumOfTestCase; /* Number of Test Case*/
	int NumOfCoin; /* Number of Coins */
	int IdxTestCase;
	int IdxCoinCount;	
	int TotalValueOfCoins;
	int CoinValueList[MAX_COUNT_OF_COINS];

	/*  Get input & output from/to TXT file to replace standrd I/O */
    
    /*
	freopen("p562_in.txt", "r", stdin);
	freopen("p562_out.txt", "w", stdout);
	*/
	
	
	
	scanf("%d", &NumOfTestCase);
	for ( IdxTestCase = 0 ; IdxTestCase < NumOfTestCase ; IdxTestCase++ ) {
		/* Got Number of Coins from I/O */
		scanf("%d", &NumOfCoin);
		
		/* printf("NumOfCoin=%d\n", NumOfCoin); */
		
		if ( NumOfCoin != 0)
		{
		
		/*  initialize Total Value of Coin before counting */
		TotalValueOfCoins = 0;
		for ( IdxCoinCount = 0 ; IdxCoinCount < NumOfCoin ; IdxCoinCount++ ) {
			scanf("%d", &CoinValueList[IdxCoinCount] );			
			TotalValueOfCoins += CoinValueList[IdxCoinCount];
		}
		
		if ( NumOfCoin == 1  || TotalValueOfCoins == 0 ) {
			printf("%d\n", TotalValueOfCoins);
		} else {
		
		/* sorting input coin value list */
		qsort(CoinValueList, NumOfCoin, sizeof(CoinValueList[0]), compare);

		/* Calculate mininum different  of two coin set */
		CalcMinDiffTwoCoinSet(NumOfCoin , TotalValueOfCoins, CoinValueList);			
		}
      } else {
              printf("%d\n", 0);
      }
	}
	
	return 0;
}
