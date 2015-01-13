#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TernarySize 40
#define TernaryBase 3

void StringReserse(char *dst, char *source)
{
  int idxString;
  int BackIdx;
  int len = strlen(source);
  BackIdx = len - 1;
  for ( idxString = 0; idxString < len; idxString++) {
     dst[idxString] = source[BackIdx];
     BackIdx--;     
  }
}

int main(void)
{
 long long int DecimalNumber;   
 char Ternary[TernarySize];
 char ReverseTernary[TernarySize];
 int IdxTernaryDigit;
 long long int Carry, Remainder;
 long long int  Divider;
 
 /*
 freopen("p11185_in.txt", "r", stdin);
 freopen("p11185_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 while (  scanf("%lld", &DecimalNumber) == 1 )
 { 
    if ( DecimalNumber < 0 ) {
         break;
    }
	memset (Ternary, '\0', sizeof(Ternary[0]) * TernarySize);
	memset (ReverseTernary, '\0', sizeof(ReverseTernary[0]) * TernarySize);
	IdxTernaryDigit = 0;
	while (1) {
	    Divider = DecimalNumber / TernaryBase;
	    Remainder = DecimalNumber % TernaryBase;
		if ( Divider == 0 ) {	
           if (   (Remainder != 0) || (IdxTernaryDigit == 0) ) {
              Ternary[IdxTernaryDigit] = '0' +  (char) (Remainder);    
           }	
		   break;
		}		
	    Ternary[IdxTernaryDigit] = '0' +  (char) (Remainder);		  
		DecimalNumber = Divider;
	    IdxTernaryDigit++;
	}	
	StringReserse (ReverseTernary, Ternary);
	printf("%s\n", ReverseTernary);    
 } 
 return 0;
}
