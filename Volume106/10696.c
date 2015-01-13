#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_NUMBER 1002

int CalcF91(int Value)
{
   if ( Value <= 100) {
       return CalcF91(CalcF91(Value+11));
   } else {
       return (Value - 10);
   }
}

int main(void)
{

 int InputerNumber;
 
/*
 freopen("p10696_in.txt", "r", stdin);
 freopen("p10696_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 
 while (1)
 {     
     scanf("%d", &InputerNumber);
	 if ( InputerNumber == 0) {
	    break;
	 }
	 printf("f91(%d) = %d\n", InputerNumber, CalcF91(InputerNumber));
    
 }
 return 0;
}
