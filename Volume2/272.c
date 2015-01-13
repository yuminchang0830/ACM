/* @JUDGE_ID:50418EN 272 C */
#include <stdio.h>
#include <string.h>

#define SCREEN_LINE_SIZE 80+1

int main(void)
{
  /* Declare Variable for Input String */
  char InputString[SCREEN_LINE_SIZE];
  int SumDoubleQuota;
  int IdxString; 
  int LenInputString;
  
      /*
	freopen("p272_in.txt", "r", stdin);
	freopen("p272_out.txt", "w", stdout);
    */
  
  /* Get String from Standard I/O */
  SumDoubleQuota = 0;
  while ( gets(InputString) != NULL )
  {    
    LenInputString = strlen(InputString);
    for ( IdxString = 0; IdxString < LenInputString; IdxString++) {
	   if ( InputString[IdxString] != '"') {
	      printf("%c", InputString[IdxString]);	   
	   } else  if ( (SumDoubleQuota%2) == 0) {
          SumDoubleQuota++;     
	      printf("%c%c", '`', '`');	   
	   } else {
          SumDoubleQuota++;         
	      printf("%c%c", '\'', '\'');	   
	   }
	}
	printf("\n");
  } 
  
  return 0;
}
