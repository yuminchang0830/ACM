#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
 int NumCase;
 int IdxTestCase;
 char InputNumber[80];
 char NonReverseString[80];
 char ReverseString[80];
 int CountingTimes;
 unsigned long NonReverseNumber, ReverseNumber;

/*
 freopen("p10018_in.txt", "r", stdin);
 freopen("p10018_out.txt", "w", stdout);
*/
 scanf("%d", &NumCase); 
 
 for ( IdxTestCase = 1; IdxTestCase <= NumCase; IdxTestCase++) {
    memset(NonReverseString, '\0', sizeof(NonReverseString[0])*80);
	memset(ReverseString, '\0', sizeof(ReverseString[0])*80);
	memset(InputNumber,'\0', sizeof(InputNumber[0])*80); 
    scanf("%s", InputNumber);		
	strncpy (NonReverseString, InputNumber, strlen(InputNumber));	
	NonReverseNumber = atol(NonReverseString);
	StringReserse (ReverseString ,NonReverseString);
	ReverseNumber =  atol (ReverseString);
	CountingTimes = 0;
	while ( NonReverseNumber != ReverseNumber)	{
       /*
	    printf("%llu\n", NonReverseNumber); 
      		 printf("%llu\n",  ReverseNumber); 
   		 printf("---------\n"); 
  	    */
	    CountingTimes++;
	    NonReverseNumber += ReverseNumber;
    	memset(ReverseString, '\0', sizeof(ReverseString[0])*80);
		sprintf(NonReverseString,"%lu",NonReverseNumber);
		StringReserse (ReverseString ,NonReverseString);
     	ReverseNumber =  atol (ReverseString);	
        /* 	
     	if ( CountingTimes >= 1001) {
             break;
        }
        */
	}
	printf("%d %lu\n", CountingTimes, NonReverseNumber);
  }
 
 
 return 0;
}
