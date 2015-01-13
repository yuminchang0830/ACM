#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define MAX_INPUT_NUMBER_LEN 100



int main(void)
{
 char InputString[MAX_INPUT_NUMBER_LEN];
 int LenInputString; 
 int IdxString;
 long long int NumValue;

/*
 freopen("p10473_in.txt", "r", stdin);
 freopen("p10473_out.txt", "w", stdout);
*/
 memset(InputString, '\0', sizeof( InputString[0])*MAX_INPUT_NUMBER_LEN); 
 while ( scanf("%s", InputString) )
 {
    LenInputString = strlen(InputString);
	if ( InputString[0] == '-') {    
	   break;
	}
	if ( (LenInputString > 2) &&  ( (InputString[0] == '0') && (InputString[1] == 'x')) ) {
    
       NumValue = 0;  
	   for ( IdxString = 2; IdxString < LenInputString; IdxString++) {
           NumValue = NumValue << 4;
           switch ( InputString[IdxString])
           {
             case '0':
                      NumValue += 0;
                      break;
             case '1':
                      NumValue += 1;
                      break;
             case '2':
                      NumValue += 2;
                      break;
             case '3':
                      NumValue += 3;
                      break;                  
             case '4':
                      NumValue += 4;
                      break;                  
             case '5':
                      NumValue += 5;
                      break;                  
             case '6':
                      NumValue += 6;
                      break;                  
             case '7':
                      NumValue += 7;
                      break;                  
             case '8':
                      NumValue += 8;
                      break;                  
             case '9':
                      NumValue += 9;
                      break;                  
             case 'a':
             case 'A':                  
                      NumValue += 10;
                      break;                                    
             case 'b':
             case 'B':                  
                      NumValue += 11;
                      break;                  
             case 'c':
             case 'C':                  
                      NumValue += 12;
                      break;                  
             case 'd':
             case 'D':                  
                      NumValue += 13;
                      break;                  
             case 'e':
             case 'E':                  
                      NumValue += 14;
                      break;                  
             case 'f':
             case 'F':                        
                      NumValue += 15;
                      break;                  
             default:                                                                                         
                      break;                                                                                          
           }
       }
	   printf("%lld\n", NumValue);
	} else {       
       	 
	   NumValue = 0;  
	   for ( IdxString = 0; IdxString < LenInputString; IdxString++) {
           NumValue = NumValue *10;
           switch ( InputString[IdxString])
           {
             case '0':
                      NumValue += 0;
                      break;
             case '1':
                      NumValue += 1;
                      break;
             case '2':
                      NumValue += 2;
                      break;
             case '3':
                      NumValue += 3;
                      break;                  
             case '4':
                      NumValue += 4;
                      break;                  
             case '5':
                      NumValue += 5;
                      break;                  
             case '6':
                      NumValue += 6;
                      break;                  
             case '7':
                      NumValue += 7;
                      break;                  
             case '8':
                      NumValue += 8;
                      break;                  
             case '9':
                      NumValue += 9;
                      break;                                          
             default:                                                                                         
                      break;                                                                                          
           }
       }
       printf("0x%X\n", NumValue);
	}
    memset(InputString, '\0', sizeof( InputString[0])*MAX_INPUT_NUMBER_LEN);
 } 

 return 0;
}
