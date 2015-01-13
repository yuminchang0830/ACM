#include <stdio.h>
#include <stdlib.h>



#define MAX_TRANSACTION_VALUE 100;
#define MAX_TRANSACTION_VALUE_PLUS_COINVALUE_FOURTY 140
#define MultipleTimes 20
#define BIGVALUE 65535
#define COINVALUE_ONE  1
#define COINVALUE_TWO  2
#define COINVALUE_FOUR 4
#define COINVALUE_TEN  10
#define	COINVALUE_TWENTY 20
#define	COINVALUE_FOURTY 40	


int KeepTheChangeMinTimes[COINVALUE_FOURTY] =
{
0,1,1,2,1,   /* 0 - 4*/
2,2,3,2,3,   /* 5 - 9 */
1,2,2,3,2,   /* 10 - 14 */
3,3,4,3,4,  /* 15 - 19 */
1,2,2,3,2,  /* 20 - 24*/
3,3,4,3,4,  /* 25 - 29 */
2,3,3,4,3,  /* 30 - 34 */
4,4,5,4,5   /* 31 - 39 */
};


int main(void)
{
	int NumCoinOne, NumCoinTwo,NumCoinFour, NumCoinTen, NumCoinTwenty, NumCoinFourty;
    double TransactionValue;
	int RealTransactionValue = 0;
	int CoinCombination[MAX_TRANSACTION_VALUE_PLUS_COINVALUE_FOURTY];
	int IdxCoinComb = 0;
	int IdxNumCon = 0;
	int UpperBound = MAX_TRANSACTION_VALUE_PLUS_COINVALUE_FOURTY - 1;
	int MinChangeHandTimes = BIGVALUE;

/*
	freopen("p166_in.txt", "r", stdin);
	freopen("p166_out.txt", "w", stdout);
*/


	do {
  	  scanf("%d %d %d %d %d %d", &NumCoinOne, &NumCoinTwo, &NumCoinFour, &NumCoinTen, &NumCoinTwenty, &NumCoinFourty); 
	  if (NumCoinOne == 0 && NumCoinTwo == 0 && NumCoinFour == 0 && NumCoinTen == 0 && NumCoinTwenty == 0 && NumCoinFourty == 0)
	  {
	    break;
	  }
	  scanf(" %lf", &TransactionValue);
	  
	  RealTransactionValue =  (int) ( (TransactionValue+0.01) * MultipleTimes); 
      
      /*printf("%d %d %d %d %d %d\n", NumCoinOne, NumCoinTwo, NumCoinFour, NumCoinTen, NumCoinTwenty,NumCoinFourty);*/
      	    
 
	  if ( NumCoinOne >  100 ) {
	  	NumCoinOne = 100;
	  }	  
	  if ( NumCoinTwo > 50 ) {
	    NumCoinTwo = 50;
	  }
	  if ( NumCoinFour > 25 ) {
	    NumCoinFour = 25;
	  }
	  if ( NumCoinTen > 10 ) {
	  	NumCoinTen = 10;
	  }
	  if ( NumCoinTwenty > 5 ) {
	    NumCoinTwenty = 5;
	  }
	  if ( NumCoinFourty > 3 ) {
	    NumCoinFourty = 3;
	  }	 
	  
	  /*printf("%d %d %d %d %d %d\n", NumCoinOne, NumCoinTwo, NumCoinFour, NumCoinTen, NumCoinTwenty,NumCoinFourty);*/

      for ( IdxCoinComb = 0; IdxCoinComb < MAX_TRANSACTION_VALUE_PLUS_COINVALUE_FOURTY; IdxCoinComb++)
      {
           CoinCombination[IdxCoinComb]=0;
      }
	  
      for ( IdxCoinComb = 1 ; IdxCoinComb <= NumCoinFourty  ; IdxCoinComb++)
	  {
	    CoinCombination[IdxCoinComb*COINVALUE_FOURTY] = IdxCoinComb;
	  }	 

	  for ( IdxNumCon = 1 ; IdxNumCon <= NumCoinTwenty  ; IdxNumCon++)
	  {
	    for ( IdxCoinComb = UpperBound ;  IdxCoinComb > 0; IdxCoinComb--)
	    {
	       if (  (IdxCoinComb + COINVALUE_TWENTY) >= UpperBound)
	       { 
	         continue;
	       }
	       if ( CoinCombination[IdxCoinComb] != 0 ) {
		   	   if (CoinCombination[IdxCoinComb+ COINVALUE_TWENTY] == 0) {
			   	 CoinCombination[IdxCoinComb + COINVALUE_TWENTY] = CoinCombination[IdxCoinComb] + 1;
		   	   } else if ( CoinCombination[IdxCoinComb + COINVALUE_TEN] > (CoinCombination[IdxCoinComb] + IdxNumCon) )			   	
		   	   {
   	       	      CoinCombination[IdxCoinComb + COINVALUE_TWENTY] = CoinCombination[IdxCoinComb] + 1;
		   	   }
	       	}
	    }
	    if ( NumCoinTwenty > 0) {
	    	CoinCombination[COINVALUE_TWENTY] = 1;
	    }
	  }	
	 
	  

	  for ( IdxNumCon = 1 ; IdxNumCon <= NumCoinTen  ; IdxNumCon++)
	  {
	    for ( IdxCoinComb = UpperBound ;  IdxCoinComb > 0; IdxCoinComb--)
	    {
	       if (  (IdxCoinComb + COINVALUE_TEN) >= UpperBound)
	       { 
	         continue;
	       }
	       if ( CoinCombination[IdxCoinComb] != 0 ) {               
                if ( CoinCombination[IdxCoinComb + COINVALUE_TEN] == 0) {
                    CoinCombination[IdxCoinComb + COINVALUE_TEN] = CoinCombination[IdxCoinComb] + 1;
                }  else if (CoinCombination[IdxCoinComb + COINVALUE_TEN] > (CoinCombination[IdxCoinComb] + IdxNumCon) )   {
   	       	      CoinCombination[IdxCoinComb + COINVALUE_TEN]  = CoinCombination[IdxCoinComb] + 1;
  		   	    }
	       }
	    }
	    if ( NumCoinTen > 0) {
	  	CoinCombination[COINVALUE_TEN] = 1;
	    }
	  
	  }

	 


	  for ( IdxNumCon = 1 ; IdxNumCon <= NumCoinFour  ; IdxNumCon++)
	  {
	    for ( IdxCoinComb = UpperBound ;  IdxCoinComb > 0; IdxCoinComb--)
	    {
	       if (  (IdxCoinComb + COINVALUE_FOUR) >= UpperBound)
	       { 
	         continue;
	       }
	       if ( CoinCombination[IdxCoinComb] != 0 ) {              
                if ( CoinCombination[IdxCoinComb + COINVALUE_FOUR] == 0) {
                    CoinCombination[IdxCoinComb + COINVALUE_FOUR] = CoinCombination[IdxCoinComb] + 1;
                }  else if (CoinCombination[IdxCoinComb + COINVALUE_FOUR] > (CoinCombination[IdxCoinComb] + IdxNumCon) )   {
   	       	      CoinCombination[IdxCoinComb + COINVALUE_FOUR]  = CoinCombination[IdxCoinComb] + 1;
  		   	    }
	       }
	    }
	    if ( NumCoinFour > 0) {
	  	CoinCombination[COINVALUE_FOUR] = 1;
	    }
	  }
	  
	  
	   

	  for ( IdxNumCon = 1 ; IdxNumCon <= NumCoinTwo  ; IdxNumCon++)
	  {
	    for ( IdxCoinComb = UpperBound ;  IdxCoinComb > 0; IdxCoinComb--)
	    {
	       if (  (IdxCoinComb + COINVALUE_TWO) >= UpperBound)
	       { 
	         continue;
	       }
	       if ( CoinCombination[IdxCoinComb] != 0 ) {              
                if ( CoinCombination[IdxCoinComb + COINVALUE_TWO] == 0) {
                    CoinCombination[IdxCoinComb + COINVALUE_TWO] = CoinCombination[IdxCoinComb] + 1;
                }  else if (CoinCombination[IdxCoinComb + COINVALUE_TWO] > (CoinCombination[IdxCoinComb] + IdxNumCon) )   {
   	       	      CoinCombination[IdxCoinComb + COINVALUE_TWO]  = CoinCombination[IdxCoinComb] + 1;
  		   	    }
	       }
	    }
	    if ( NumCoinTwo > 0) {
	  	CoinCombination[COINVALUE_TWO] = 1;
	    }
	  }

	  for ( IdxNumCon = 1 ; IdxNumCon <= NumCoinOne  ; IdxNumCon++)
	  {
	    for ( IdxCoinComb = UpperBound ;  IdxCoinComb > 0; IdxCoinComb--)
	    {
	       if (  (IdxCoinComb + COINVALUE_ONE) >= UpperBound)
	       { 
	         continue;
	       }
	       if ( CoinCombination[IdxCoinComb] != 0 ) {              
                if ( CoinCombination[IdxCoinComb + COINVALUE_ONE] == 0) {
                    CoinCombination[IdxCoinComb + COINVALUE_ONE] = CoinCombination[IdxCoinComb] + 1;
                }  else if (CoinCombination[IdxCoinComb + COINVALUE_ONE] > (CoinCombination[IdxCoinComb] + IdxNumCon) )   {
   	       	      CoinCombination[IdxCoinComb + COINVALUE_ONE]  = CoinCombination[IdxCoinComb] + 1;
  		   	    }
	       }
	    }
	    if ( NumCoinOne > 0) {
	  	CoinCombination[COINVALUE_ONE] = 1;
	    }
	  }

	 /*
	  
	  for ( IdxCoinComb = 1; IdxCoinComb < MAX_TRANSACTION_VALUE_PLUS_COINVALUE_FOURTY; IdxCoinComb++)
	  {
          printf("%2d ", CoinCombination[IdxCoinComb]);
          if ( (IdxCoinComb %10) == 0)
          {
               printf("\n");
          }
      }
      printf("\n---\n");
*/	  
	 

	  MinChangeHandTimes = BIGVALUE;
	  for ( IdxCoinComb = (RealTransactionValue + COINVALUE_FOURTY - 1) ; IdxCoinComb >= RealTransactionValue ; IdxCoinComb--)	  	
	  {
        if ( CoinCombination[IdxCoinComb] != 0) {
	    if ( (CoinCombination[IdxCoinComb] + KeepTheChangeMinTimes[IdxCoinComb - RealTransactionValue]) < MinChangeHandTimes ) {
			MinChangeHandTimes = CoinCombination[IdxCoinComb] + KeepTheChangeMinTimes[IdxCoinComb - RealTransactionValue];			
	    }	     
        }
	  }	 
	  

	  printf("%3d\n", MinChangeHandTimes);
	
	  
	} while (1);	


}

