#include <stdio.h>
#include <string.h>

int main(void)
{
unsigned long long int OddNumPerLine;
unsigned long long int SumLastLine;
unsigned long long int Height;
unsigned long long int LastNumber;
 
/*
freopen("p913_in.txt", "r", stdin);
freopen("p913_out.txt", "w", stdout);
*/
 
 while (scanf("%ld", &OddNumPerLine)==1) 
 {  
      Height = ((OddNumPerLine-1)/2)+1;
      LastNumber =  (( Height * Height) - 1) *2 + 1;
	  SumLastLine =  LastNumber * 3 - 6;
      printf("%ld\n", SumLastLine);
 } 
 return 0;
}
