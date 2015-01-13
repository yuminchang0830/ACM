/* @JUDGE_ID:50418EN 458 C */
#include <stdio.h>
#include <string.h>

#define SCREEN_LINE_SIZE 80+1

int main(void)
{
  /* Declare Variable for Input String */
  char EncryptedString[SCREEN_LINE_SIZE];
  int IdxString; 
  int LenInputString; 
  
  /*      
  freopen("p458_in.txt", "r", stdin);
  freopen("p458_out.txt", "w", stdout);   
  */
  /* Get EncryptedString from Standard I/O */  
  while ( gets(EncryptedString) != NULL )
  {    
    LenInputString = strlen(EncryptedString);
    for ( IdxString = 0; IdxString < LenInputString; IdxString++) {
	        printf("%c", EncryptedString[IdxString] - 7);	      
	}
	printf("\n");
  } 
  
  return 0;
}
