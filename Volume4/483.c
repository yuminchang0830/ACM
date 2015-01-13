#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void StringReserse(char *Source, int StartAddr, int EndAddr)
{
  int IdxDstString;
  int IdxSourceString; 
  int Len;
  char tempChar;
  Len = EndAddr - StartAddr + 1;
  IdxSourceString = EndAddr;
  for ( IdxDstString = 0; IdxDstString < (Len/2); IdxDstString++, IdxSourceString--) {
     tempChar = Source[StartAddr+IdxDstString];
	 Source[StartAddr+IdxDstString] = Source[IdxSourceString];
	 Source[IdxSourceString] = tempChar;
  }
}

int main(void)
{

int IdxString;
char InputLine[10000];
int LenInputLine;
int WordStartPtr;
int WordEndPtr;

/*
 freopen("p483_in.txt", "r", stdin);
 freopen("p483_out.txt", "w", stdout);
*/

while ( gets(InputLine) != NULL) {
   LenInputLine = strlen(InputLine);  
   WordStartPtr = WordEndPtr = -1;
   /*printf("%s\n",InputLine );*/
   for ( IdxString = 0; IdxString < LenInputLine; IdxString++) {
      if (InputLine[IdxString] == ' ') {
        if (WordStartPtr != WordEndPtr)  {                        
	       StringReserse(InputLine, WordStartPtr, WordEndPtr);		
        }
		WordStartPtr = WordEndPtr = -1;
	  } else {
	    if ( (WordStartPtr == -1) && (WordEndPtr==-1)) {
		   WordStartPtr = WordEndPtr = IdxString;	
		} else {
		   WordEndPtr++;
		}
	  }
   }
        if (WordStartPtr != WordEndPtr)  {                        
	       StringReserse(InputLine, WordStartPtr, WordEndPtr);		
        }  
   printf("%s\n",InputLine );
}

return 0;
}
