#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{

int NumCase;
int IdxCase;
int IdxString;

char InputLine[81];
int LenInputLine;
/*
 freopen("p11946_in.txt", "r", stdin);
 freopen("p11946_out.txt", "w", stdout);
*/
 
scanf("%d", &NumCase);
getchar();
while ( gets(InputLine) != NULL) {
      LenInputLine = strlen(InputLine);
      for ( IdxString = 0; IdxString < LenInputLine; IdxString++) {
         
            switch (InputLine[IdxString]) {
               case '0':
                        printf("O", InputLine[IdxString]);
                        break;
               case '1':
                        printf("I", InputLine[IdxString]);
                        break;
               case '2':
                        printf("Z", InputLine[IdxString]);                    
                        break;
               case '3':
                        printf("E", InputLine[IdxString]);                    
                        break;
               case '4':
                        printf("A", InputLine[IdxString]);                    
                        break;
               case '5':
                        printf("S", InputLine[IdxString]);                    
                        break;
               case '6':
                        printf("G", InputLine[IdxString]);                    
                        break;
               case '7':
                        printf("T", InputLine[IdxString]);                    
                        break;
               case '8':
                        printf("B", InputLine[IdxString]);                    
                        break;
               case '9':
                        printf("P", InputLine[IdxString]);                    
                        break;
               default:
                       printf("%c", InputLine[IdxString]);
                       break;                                      
            }
         
      }
      printf("\n");
}
 return 0;
}
