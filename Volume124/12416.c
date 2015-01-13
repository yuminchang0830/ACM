#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR_IN_ONE_LINE (1024*1024)

int main(void)
{
char InputLine[MAX_CHAR_IN_ONE_LINE];
int NumSpace;
int MaxNumSpace;
int NumChange;
int LenInputLine;
int IdxString;
int IdxSpace;
 
/*
 freopen("p12416_in.txt", "r", stdin);
 freopen("p12416_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */

 while (  gets(InputLine) )
 { 
    LenInputLine = strlen(InputLine);	
	MaxNumSpace = 0;
	NumChange = 0;
	NumSpace = 0;
    for ( IdxString = 0; IdxString < LenInputLine; IdxString++) {	  
	  if ( InputLine[IdxString] == ' ') {
	    NumSpace++; 
	  } else {
	    if ( NumSpace > MaxNumSpace) {
		   MaxNumSpace =  NumSpace;		 
		}
		NumSpace = 0;
	  }	  
	}
	/*
	printf("max=%d\n", MaxNumSpace);
	*/
	if ( MaxNumSpace >=2) {
       while ( MaxNumSpace!= 1) {
	     if ( (MaxNumSpace %2) == 0) {
	        MaxNumSpace = MaxNumSpace/2;
	        NumChange++;
	     } else {
	        MaxNumSpace = ((MaxNumSpace-1)/2) + 1;
		    NumChange++;
	     }
       }   
	} else {
       NumChange = 0;    
    } 
    printf("%d\n",NumChange);	
 } 
 return 0;
}
