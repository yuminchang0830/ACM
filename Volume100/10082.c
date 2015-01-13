#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_CHAR 10001

char KeypadElement[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";


int main(void)
{
 char InputChar; 
 int LenKeypadElement;
 int IdxKE;
 
/* int IdxIL; */
  
/*
 freopen("p10082_in.txt", "r", stdin);
 freopen("p10082_out.txt", "w", stdout);
*/

  LenKeypadElement = strlen(KeypadElement);

  while (scanf("%c",&InputChar) != EOF)
  {
     if ( InputChar == ' ') {
	     printf("%c", ' ');
	     continue;
	   } else if ( InputChar == '\n') {
	     printf("\n");
	     continue;
	   }    
    for ( IdxKE = 1; IdxKE < LenKeypadElement; IdxKE++){
	   if ( InputChar == KeypadElement[IdxKE]) {
	     printf("%c", KeypadElement[IdxKE-1]);
		 break;
	   } 
	}
  }  

 return 0;
}
