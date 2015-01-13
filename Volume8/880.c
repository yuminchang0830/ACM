#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    unsigned long long int InputNum;
	unsigned long long int Distance;
	unsigned long long int Molecular, Denominator ;
	unsigned long long int Base;
	unsigned long long int Base2;
    
	while ( scanf("%llu", &InputNum)==1) {
	   Distance = ceil(  sqrt(  0.25 + 2.0 * ( (double) InputNum)) - 0.5);
	   /*
	   Base = ((Distance-1)*Distance)  /2 ;
	   */
  	   Base = ((Distance+1)*Distance)  /2 ;
	   Denominator= (InputNum - (Base - Distance));
	   Molecular  = 1 + Base - InputNum;
	   printf("%llu/%llu\n",Molecular,Denominator);		
	}
    return 0;
}
