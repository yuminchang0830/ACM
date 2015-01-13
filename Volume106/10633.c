#include <stdio.h>
#include <stdlib.h>


int main(void)
{

unsigned long long int NminusM;
unsigned long long int NLowBound,NUpperBound;
unsigned long long int N,M;
unsigned long long int IdxDigit;
int NumSolution;

/*
freopen("p10633_in.txt", "r", stdin);
freopen("p10633_out.txt", "w", stdout);
*/


while ( scanf("%llu", &NminusM) ==1)  {
     if ( NminusM == 0) {
          break;
     }
     NLowBound = (NminusM*10)/9 - 10;
     NUpperBound = (NminusM*10)/9 + 10;
     NumSolution = 0; 
     for ( IdxDigit = NLowBound; IdxDigit <= NUpperBound; IdxDigit++) {     
         N = IdxDigit;
         M = N/10;
         if ( (N-M) == NminusM) {           
           if (NumSolution != 0) {
             printf(" ");
           }    
           printf("%llu",N);  
           NumSolution++;
         }
     }
     printf("\n");
}

return 0;
}

