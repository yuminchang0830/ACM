/* @JUDGE_ID:50418EN 272 C */
#include <stdio.h>
#include <string.h>

#define SCREEN_LINE_SIZE 256+1

int main(void)
{
  /* Declare Variable for Input String */
  char InputString[SCREEN_LINE_SIZE];
  int IdxString; 
  int LenInputString;
  int WordbeSaid;
  int WordStart;
  
      /*
	freopen("p494_in.txt", "r", stdin);
	freopen("p494_out.txt", "w", stdout);
    */
  
  /* Get String from Standard I/O */

  while ( gets(InputString) != NULL )
  { 
    WordStart = 0;    WordbeSaid = 0;
    LenInputString = strlen(InputString);
    for ( IdxString = 0; IdxString < LenInputString; IdxString++) {
	   if (  (InputString[IdxString] >= 'A' && InputString[IdxString] <= 'Z') || ( InputString[IdxString] >= 'a' && InputString[IdxString] <= 'z')   ) {	
          if ( WordStart == 0) {
		     ++WordbeSaid;
			 WordStart = 1;
		  } 
	   } else {
	      WordStart = 0 ;
	   }
	}
	printf("%d\n", WordbeSaid);
  } 
  
  return 0;
}
