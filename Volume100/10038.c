#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_NUMBER 4000

int main(void)
{

int NumJollyNumber;
int JollyNumberSeries[MAX_NUMBER];
int DiffentRecord[MAX_NUMBER];
int Diffent;
int IdxDiffentRecord;
int IdxNumSeries;
int isJollyNumber;
int TotalDifferent;

/*
 freopen("p10038_in.txt", "r", stdin);
 freopen("p10038_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 while ( scanf("%d", &NumJollyNumber) != EOF)
 { 
    memset (JollyNumberSeries, 0, sizeof(JollyNumberSeries[0])* MAX_NUMBER);
	memset (DiffentRecord, 0, sizeof(DiffentRecord[0])* MAX_NUMBER);
    
    for ( IdxNumSeries = 0; IdxNumSeries < NumJollyNumber; IdxNumSeries++) {
        scanf("%d", &JollyNumberSeries[IdxNumSeries]);        
    }	
	isJollyNumber = 1;   
    DiffentRecord[0] = 1;   	
	for ( IdxNumSeries = 1; IdxNumSeries < NumJollyNumber; IdxNumSeries++) {        
        Diffent = abs (JollyNumberSeries[IdxNumSeries -1] - JollyNumberSeries[IdxNumSeries]);
		if ( Diffent >= NumJollyNumber) {
		   isJollyNumber == 0;
		   break;
		} else if (  Diffent == 0 ) {
		   isJollyNumber == 0;
		   break;
        } else if ( DiffentRecord[Diffent] != 0 ) {
		   isJollyNumber == 0;
		   break;
        }		
		DiffentRecord[Diffent] = 1;
    }
             
    if ( isJollyNumber ) {
	   TotalDifferent = 0;
	   for ( IdxDiffentRecord = 1; IdxDiffentRecord < NumJollyNumber ; IdxDiffentRecord++) {
	      if ( DiffentRecord[IdxDiffentRecord] == 1) {
		     TotalDifferent++;
		  }
	   }
	   if ( TotalDifferent == (NumJollyNumber-1)) {
	       printf("Jolly\n");
	   } else {
           printf("Not jolly\n");          
       }
    } else {
       printf("Not jolly\n");     
    }
 }
 
 return 0;
}
