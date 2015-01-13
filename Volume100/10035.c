#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUMBER_STRING 20

int main(void)
{
 unsigned long long int InputNum1, InputNum2;   
 char Addend[MAX_NUMBER_STRING];
 unsigned long long int NumAddend, NumSummand, Carry;
 unsigned long long int DigitAddend, DigitSummand;
 unsigned long long int DivisionFactor;
 int MaxLen;
 int CarryOperationTimes;
 int IdxNum;

 /*
 freopen("p10035_in.txt", "r", stdin);
 freopen("p10035_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 while (  scanf("%llu %llu", &InputNum1, &InputNum2) == 2 )
 { 
    if ( InputNum1 == 0 && InputNum2==0) {
         break;
    }
    /* Variable Initialize*/
    if ( InputNum1 > InputNum2){
	  NumAddend = InputNum1;
	  NumSummand = InputNum2;
	  memset ( Addend, '\0', sizeof(Addend[0])*MAX_NUMBER_STRING);
	  sprintf(Addend, "%llu", NumAddend);
      MaxLen =  strlen(Addend);    
	} else {
	  NumAddend = InputNum2;
	  NumSummand = InputNum1; 
	  memset ( Addend, '\0', sizeof(Addend[0])*MAX_NUMBER_STRING);
	  sprintf(Addend, "%llu", NumAddend);
      MaxLen = strlen(Addend);
	}
	
	Carry = 0;
    CarryOperationTimes = 0;
    DivisionFactor = 1;
	for ( IdxNum = 0; IdxNum < MaxLen; IdxNum++) {
	    DigitAddend =  (( NumAddend / DivisionFactor) % 10);
		DigitSummand =  (( NumSummand /DivisionFactor) % 10);
		/*
		printf("%5u\n", DigitAddend);
		printf("%5u\n", DigitSummand);
		printf("%5u\n",  Carry);
		printf("------\n");
		printf("%5u\n\n", DigitAddend + DigitSummand + Carry);
		*/
		if (  (DigitAddend + DigitSummand + Carry) >= 10) {
		   Carry = 1;
		   CarryOperationTimes++;
		} else {
           Carry = 0;
        }
		DivisionFactor *=10;
	}
	if ( CarryOperationTimes == 0 ) {
	  printf("No carry operation.\n");	
    } else if (   CarryOperationTimes == 1) {
       printf("1 carry operation.\n");     
	} else {
	  printf("%d carry operations.\n", CarryOperationTimes);
	}
 }
 
 return 0;
}
