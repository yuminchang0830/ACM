#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

/* Prime Table in 100 */

#define NUMPRIMESINHUNDRED 25

int PrimeTable[NUMPRIMESINHUNDRED] = 
{ 2, 3, 5, 7,11,
 13,17,19,23,29,
 31,37,41,43,47,
 53,59,61,67,71,
 73,79,83,89,97};
 
int PrimeTimes[NUMPRIMESINHUNDRED]; 

int main(void)
{

 int NSeries;
 int IdxPrime;
 int IdxNS;
 int LevelN;
 
 while ( scanf("%d", &NSeries) == 1) {
    if ( NSeries == 0) {
         break;
    }
    memset (PrimeTimes, 0, sizeof(PrimeTimes[0])*NUMPRIMESINHUNDRED);
    for ( IdxNS = 2; IdxNS <= NSeries; IdxNS++) {
        LevelN = IdxNS;        
        for ( IdxPrime = 0; LevelN != 1; IdxPrime++) {
           while ( LevelN % PrimeTable[IdxPrime] == 0) {
                 PrimeTimes[IdxPrime]++;
                 LevelN = LevelN /PrimeTable[IdxPrime];
           }
        }        
    }
    printf("%3d! =", NSeries);
    for ( IdxPrime = 0; IdxPrime < NUMPRIMESINHUNDRED; IdxPrime++) {
        if (PrimeTimes[IdxPrime] == 0) {
           break;
        }
        if ( IdxPrime == 15) {
             printf("\n      ");
        }        
        printf("%3d", PrimeTimes[IdxPrime]);
    }
    printf("\n");         
 }
 return 0;
}
