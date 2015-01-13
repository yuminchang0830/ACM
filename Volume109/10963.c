#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_INPUT_NUMBER 20

int main(void)
{
 int NumCase;
 int IdxCaseNum;
 int NumColumn;
 int IdxColumn;
 int PosY1, PosY2;
 int NoHoles;
 int MaxDistence;


 /*

 freopen("p10963_in.txt", "r", stdin);
 freopen("p10963_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 scanf("%d", &NumCase);
 for ( IdxCaseNum = 0; IdxCaseNum < NumCase; IdxCaseNum++) {
    scanf("%d", &NumColumn);
	scanf("%d %d", &PosY1, &PosY2);
	NoHoles = 1;
    MaxDistence = PosY1 - PosY2;	

	if ( NumColumn > 1) {
	  for ( IdxColumn = 1; IdxColumn < NumColumn; IdxColumn++) {
	     scanf("%d %d", &PosY1, &PosY2);
         if ( MaxDistence != (PosY1 - PosY2)) {
		    NoHoles = 0;
		 }	 
	  }
	} else {
	  NoHoles = 1;	
	}
	if ( IdxCaseNum > 0 ) {
	   printf("\n");
    }
	if ( NoHoles == 1 ) {
	   printf("yes\n");
	} else {
	   printf("no\n");
	}
 }
 return 0;
}
