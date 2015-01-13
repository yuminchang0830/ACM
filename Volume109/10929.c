#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_NUMBER 1002

int main(void)
{
 char InputNumber[MAX_INPUT_NUMBER]; 
 long long int TestNumber;
 int LenInputerNumber;
 int IdxNum,IdxDigits;
 int IsMultipleEleven;
 int Odds;
 int Evens;

/*
 freopen("p10929_in.txt", "r", stdin);
 freopen("p10929_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 
 while (1)
 {
     memset(InputNumber, '\0', sizeof(InputNumber[0])*MAX_INPUT_NUMBER);   
     gets(InputNumber);
     LenInputerNumber = strlen (InputNumber);
     if ( LenInputerNumber <= 10) {
	    TestNumber = atoll(InputNumber);
	    if ( TestNumber == 0) {
	       break;
	    }
	    if ( (TestNumber % 11) != 0) {
	      printf("%s is not a multiple of 11.\n",InputNumber);
	    } else {
	      printf("%s is a multiple of 11.\n",InputNumber);
	    }
     } else {
        IsMultipleEleven = 1;    
        Odds = Evens = 1;
        for (IdxNum = LenInputerNumber- 1, IdxDigits = 1; IdxNum >= 0; IdxNum--, IdxDigits++) {
             if ( IdxDigits % 2) {
                Odds += InputNumber[IdxNum] - '0';
             } else {
                Evens  += InputNumber[IdxNum] - '0';
             }           
        }
        if ( (abs(Odds - Evens)%11) != 0 ) {
           IsMultipleEleven = 0;    
        }         
        
        if  ( IsMultipleEleven == 1) {
          printf("%s is a multiple of 11.\n",InputNumber);   
        } else {
          printf("%s is not a multiple of 11.\n",InputNumber);     
        }           
     }
 }
 return 0;
}
