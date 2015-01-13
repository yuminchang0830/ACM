#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
  int NumCase;
  int IdxCase;
  int IdxDigit;
  unsigned long long int NumN;
  int DigitArray[1000];
  int LenDigiArray;
  int Redundant;
  int ConditionMeet;
 
    
/*
  freopen("p993_in.txt", "r", stdin);
  freopen("p993_out.txt", "w", stdout);
*/
  scanf("%d", &NumCase);
  for ( IdxCase = 0; IdxCase < NumCase; IdxCase++) {
     scanf("%d", &NumN);	
	 Redundant = NumN;
	 LenDigiArray = 0;
	 ConditionMeet = 1;

	 if ( NumN ==1) {
          printf("1\n");
          continue;
     } 
            
	 while (Redundant!=1) {
	    ConditionMeet = 0;
	    for ( IdxDigit = 9; IdxDigit >= 2; IdxDigit--) {
		   if ( (Redundant % IdxDigit) == 0) {
		      DigitArray[LenDigiArray] = IdxDigit;
			  LenDigiArray++;
			  Redundant = Redundant / IdxDigit;
			  ConditionMeet = 1;
		      break;
		   }
		}	
        if (ConditionMeet == 0) {
		   break;
        }		
	 }	 
	 if ( ConditionMeet ==1) {
	    for ( IdxDigit = LenDigiArray-1; IdxDigit >= 0; IdxDigit--) {
		  printf("%d", DigitArray[IdxDigit]);
		}
		printf("\n");
	 } else {
	   printf("-1\n");
	 }

  }      
   

   
   return 0;
}
