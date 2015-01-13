#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_NUMBER 10001

int compare( const void *arg1, const void *arg2 )
{
	int a,b;
	a = *(long long int*) arg1;
	b = *(long long int*) arg2;
	return (a-b);
}

int main(void)
{
 long long int Num; 
 long long int NumArray[MAX_INPUT_NUMBER];
 int NumInArray = 0;
 long long int Median;


 while (scanf("%lld", &Num) == 1)   
 {
   NumArray[NumInArray] = Num;   
   NumInArray++;
   if ( NumInArray < 1) {
      printf("%lld\n",Num);      
   } else {      
      qsort(NumArray, NumInArray, sizeof(NumArray[0]), compare);
	  if ( ( (NumInArray) %2) == 0) {
	     Median = ( NumArray[NumInArray/2] + NumArray[ (NumInArray/2)-1])/2;
	  } else {
	     Median = NumArray[NumInArray/2];
	  }
   }   
   printf("%lld\n", Median);
   
 }


 
 return 0;
}
