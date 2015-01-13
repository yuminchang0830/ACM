#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RANGE 10001

int EulerEquation[MAX_RANGE];
int EulerEquationPrimeOrNot[MAX_RANGE];

int IsPrimeNum(unsigned int number) {    
    unsigned int  IdxN;        
    if (number <= 1) {
       return 0; 
    }    
    for (IdxN=2; IdxN*IdxN<=number; IdxN++) {
        if (number % IdxN == 0) {
           return 0;
        }
    }
    return 1;
}

int main(void)
{
 unsigned int LowBound;
 unsigned int UppBound; 
 unsigned int IdxSeq;
 unsigned int EquSum;
 unsigned int NumPrimeInRange;
 unsigned int Range;
  
/*
 freopen("p10200_in.txt", "r", stdin);
 freopen("p10200_out.txt", "w", stdout);
*/


 for ( IdxSeq = 0 ; IdxSeq < MAX_RANGE; IdxSeq++) {
     EulerEquation[IdxSeq] = IdxSeq*IdxSeq + IdxSeq + 41; 
     EulerEquationPrimeOrNot[IdxSeq]  = IsPrimeNum(EulerEquation[IdxSeq]);  
 }
 
 while ( scanf("%u %u", &LowBound, &UppBound)!=EOF) {
    NumPrimeInRange = 0;
    Range = UppBound - LowBound + 1;
    for ( IdxSeq = LowBound ; IdxSeq <= UppBound; IdxSeq++) {
       if (EulerEquationPrimeOrNot[IdxSeq] == 1) {
          NumPrimeInRange++;                                      
       }
    }
    printf("%.2lf\n", ( ((double) NumPrimeInRange * 100.0 / (double) Range)) +0.000001);
 }  

 return 0;
}
