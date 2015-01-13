#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>


int main(void)
{

 int NumCase;
 int IdxCase;
 unsigned long long int ValueIntegerX, ValueIntegerK; 
 unsigned long long int FloorXdvidK, CeilXdividK;
 unsigned long long int ValueP, ValueQ;
 unsigned long long int IdxP, IdxQ;
 
 
/*
 freopen("p10696_in.txt", "r", stdin);
 freopen("p10696_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 scanf("%d", &NumCase);
 
 for ( IdxCase = 0; IdxCase < NumCase; IdxCase++) {
    scanf("%llu %llu", &ValueIntegerX, &ValueIntegerK);
	CeilXdividK = (unsigned long long int) ceil( (double) ValueIntegerX / (double) ValueIntegerK);
	FloorXdvidK = (unsigned long long int) floor( (double) ValueIntegerX / (double) ValueIntegerK);
	if (  ValueIntegerX < ValueIntegerK) {        
	    ValueP = 0;
		ValueQ = ValueIntegerX;
	} else if (FloorXdvidK == CeilXdividK) {           
	    ValueP = 0;
		ValueQ = ValueIntegerX/CeilXdividK;
	} else {          
	    if (  ((ValueIntegerX % FloorXdvidK) % CeilXdividK) == 0) {
		   ValueP = ValueIntegerX/FloorXdvidK;
		   ValueQ = (ValueIntegerX % FloorXdvidK)/CeilXdividK;
		} else if (  ((ValueIntegerX % CeilXdividK) % FloorXdvidK) == 0) {
		   ValueP =(ValueIntegerX % CeilXdividK)/FloorXdvidK;
		   ValueQ =  ValueIntegerX/CeilXdividK;
		} else {
		   for ( IdxQ =  (ValueIntegerX/CeilXdividK), IdxP=1; IdxQ > 0; IdxQ--, IdxP++) {
               if ( ValueIntegerX ==  ((IdxP *FloorXdvidK) + (IdxQ*CeilXdividK)) ) {
                    ValueP = IdxP;
                    ValueQ = IdxQ;
                    break;
               }
           }
		}
	}
    /*
	printf("%llu =  %lluX%llu + %lluX%llu\n",ValueIntegerX, ValueP, FloorXdvidK,ValueQ, CeilXdividK );
	*/
	printf("%llu %llu\n", ValueP, ValueQ );
 }
 
 return 0;
}
