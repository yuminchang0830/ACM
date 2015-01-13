#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXINPUTCHARS 200


int main(void)
{

int IdxString;
char InputLine[MAXINPUTCHARS];
int LenInputLine;
int DigitsSum;
int IdxOutputChar;

/*
 freopen("p445_in.txt", "r", stdin);
 freopen("p445_out.txt", "w", stdout);
*/

while ( gets(InputLine) != NULL) {
   LenInputLine = strlen(InputLine);  
   DigitsSum = 0;
   if ( LenInputLine != 0) {
        for ( IdxString = 0; IdxString < LenInputLine; IdxString++) {
            if ( InputLine[IdxString] >= '0' && InputLine[IdxString] <= '9') {
               DigitsSum += InputLine[IdxString] - '0';
            } else if (InputLine[IdxString] == '!') {                   
               printf("\n");
            } else {
               for ( IdxOutputChar = 0; IdxOutputChar < DigitsSum; IdxOutputChar++) {  
                   if (InputLine[IdxString] == 'b') {
                       printf(" ");                        
                   } else {
                       printf("%c", InputLine[IdxString]);                           
                   }                         
               }
               DigitsSum = 0;
            }
        }
        printf("\n");
   } else {
     printf("\n");
   }
   memset(InputLine, '\0', sizeof(InputLine[0])*MAXINPUTCHARS);
}

return 0;
}
