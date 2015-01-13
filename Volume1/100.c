/* @JUDGE_ID:50418EN 100 C */

#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_NUMBER 1000000

unsigned long NumberList[MAX_INPUT_NUMBER+1];

int Count3Nplus1cycles (int N)
{
  unsigned long CountResult = 0;
  if ( (N <= MAX_INPUT_NUMBER)) {
  	if ( NumberList[N] != 0) {
    	return NumberList[N];
  	} else {
  	   if ( N % 2)	{
	   	 CountResult = 1 + Count3Nplus1cycles(3*N+1);
       } else {
         CountResult = 1 + Count3Nplus1cycles(N/2);
       }	
	   NumberList[N] = CountResult;
	   return CountResult;
  	}	
  } else {
    if ( N % 2)	{
	  	 CountResult = 1 + Count3Nplus1cycles(3*N+1);
     } else {
         CountResult = 1 + Count3Nplus1cycles(N/2);
     }	
	 return CountResult;

  }
}

int main(void) 
{
  
  unsigned long LowBound, UpperBound, switchtemp;
  int NumInputDigits = 0;
  int IdxNumList = 0;
  int SwitchFlag = 0;
  int MaxCycleLen = 0;
  int CountResult = 0;

      
/*
	freopen("p100_in.txt", "r", stdin);
	freopen("p100_out.txt", "w", stdout);
*/

  /* Initialize the Number List */
  memset(NumberList, 0, MAX_INPUT_NUMBER+1);
  for ( IdxNumList = 1, CountResult = 1; IdxNumList <= MAX_INPUT_NUMBER; IdxNumList*=2)
  {
      NumberList[IdxNumList] = CountResult;
	  CountResult++;
  }

  /*Count Input Data */
  while(1)
  {
     /* Get Input form standard I/O*/	 
     NumInputDigits  = scanf("%d %d", &LowBound , &UpperBound);
	 if ( NumInputDigits != 2 )
	 {
	 	break;
	 }	     
	 /* Make sure UpperBound is bigger than Low Bound */
	 SwitchFlag = 0;
	 if ( LowBound > UpperBound) {
	 	switchtemp = LowBound;
		LowBound = UpperBound;
		UpperBound = switchtemp;
	 	SwitchFlag = 1;
	 }
	 
	 /* Calculate Maxmium Cycle Length */	 
     MaxCycleLen = 0; 
     for ( IdxNumList = LowBound; IdxNumList <= UpperBound; IdxNumList++)
     {
        CountResult =  Count3Nplus1cycles( IdxNumList );
	    if ( CountResult > MaxCycleLen)
	    {
	       MaxCycleLen = CountResult;
	    }    
     }
	 
	 /* Output format by checking UpperBound & LowBound's value */
	 if (SwitchFlag == 1)
	 {
    	 printf("%d %d %d\n", UpperBound , LowBound , MaxCycleLen);		
	 } else {
	     printf("%d %d %d\n", LowBound , UpperBound , MaxCycleLen);		
	 }
	 
  }   
  return 0;
}
