#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN_EACH_LINE 1002

typedef struct {
int FREQ;
int ASCIIVALUE;       
} ASCIIFREQ;

int compare( const void *arg1, const void *arg2 )
{
	ASCIIFREQ a,b;
	a = *(ASCIIFREQ*) arg1;
	b = *(ASCIIFREQ*) arg2;
	if ( a.FREQ==b.FREQ) {
       return (  b.ASCIIVALUE -  a.ASCIIVALUE) ;
    } else {
	   return (a.FREQ-b.FREQ);
    }
}

int main(void)
{
 char InputLine[MAX_LEN_EACH_LINE];
 ASCIIFREQ ASCIICHARFEQ[128];
 int LEN;
 int IdxString, IdxASCIITABLE;
 int CaseNumber;

/*
 freopen("p10062_in.txt", "r", stdin);
 freopen("p10062_out.txt", "w", stdout);
*/
 /* Get input From from standard I/O */
 
 CaseNumber = 0; 
memset(InputLine, '\0', sizeof(InputLine[0])*MAX_LEN_EACH_LINE);
 while ( gets(InputLine) )
 { 
    if ( CaseNumber == 0 ) {
    } else {
        printf("\n");		   
    }
	CaseNumber++;
    LEN = strlen(InputLine);
    memset (ASCIICHARFEQ, 0, sizeof(ASCIICHARFEQ[0])* 128);	
	for ( IdxString = 0; IdxString < LEN; IdxString++){
	   ASCIICHARFEQ[ (int) InputLine[IdxString]].FREQ = ASCIICHARFEQ[(int) InputLine[IdxString]].FREQ + 1;
	   ASCIICHARFEQ[ (int) InputLine[IdxString]].ASCIIVALUE = (int) InputLine[IdxString];
	}
    
    qsort(ASCIICHARFEQ, 128, sizeof(ASCIICHARFEQ[0]), compare);
    	
	for ( IdxASCIITABLE = 0; IdxASCIITABLE < 128; IdxASCIITABLE++) {
	   if ( ASCIICHARFEQ[ IdxASCIITABLE].FREQ != 0) {
	      printf("%d %d\n", ASCIICHARFEQ[ IdxASCIITABLE].ASCIIVALUE , ASCIICHARFEQ[ IdxASCIITABLE].FREQ );
	   }
	}		   
	memset(InputLine, '\0', sizeof(InputLine[0])*MAX_LEN_EACH_LINE);
	  
 }
 
 return 0;
}


