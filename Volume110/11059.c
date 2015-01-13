#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_INPUT_NUMBER 20

int main(void)
{
 int NumSequence;
 int CaseNum;
 int IdxNumSeq, IdxProdctNum;
 int NumNegativeValue;
 int LeftNegativeValue;
 int RemiNegativeValue;
 int NumContinuousSeq;
 int SeqStartPos;
 int SeqEndPos;
 long long int SeqProduct;
 long long int TheMaxProduct;
 long long int IntegerSequence[MAX_INPUT_NUMBER];

/*
 freopen("p11059_in.txt", "r", stdin);
 freopen("p11059_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 CaseNum = 0;
 while (  scanf("%d", &NumSequence) == 1 )
 { 
 /*
    if ( CaseNum != 0) {
	   printf("\n");
	}
	*/
	CaseNum++;
	NumNegativeValue = 0;
	for ( IdxNumSeq = 0; IdxNumSeq < NumSequence; IdxNumSeq++) {
	   scanf("%lld", &IntegerSequence[IdxNumSeq]);	
       if (  IntegerSequence[IdxNumSeq] < 0 ) {
          NumNegativeValue++;
       }
	}	
    TheMaxProduct = 0;
    LeftNegativeValue = NumNegativeValue;
    for ( IdxNumSeq = 0; IdxNumSeq < NumSequence; IdxNumSeq++) {
         SeqProduct = 1; 
         NumContinuousSeq = 0;
         RemiNegativeValue = LeftNegativeValue;
         SeqStartPos = IdxNumSeq;
         SeqEndPos = IdxNumSeq;
         for ( IdxProdctNum = IdxNumSeq; IdxProdctNum < NumSequence; IdxProdctNum++) {
             if ( IntegerSequence[IdxProdctNum] == 0) { 
                 break;            
             } else if ( (IntegerSequence[IdxProdctNum] < 0) && (RemiNegativeValue < 2) && (SeqProduct>0)) {
                 break;     
             } else if ( IntegerSequence[IdxProdctNum] < 0) {
                RemiNegativeValue--;    
             }
             NumContinuousSeq++;
             SeqProduct = SeqProduct * IntegerSequence[IdxProdctNum];
             if ( SeqProduct > 0 ) {
                  SeqEndPos = IdxProdctNum;
             }             
         }
         if ( IntegerSequence[IdxNumSeq] < 0 ) {
              LeftNegativeValue --;
         }         
         if ( NumContinuousSeq > 0) {
            SeqProduct = 1;  
            for ( IdxProdctNum = SeqStartPos; IdxProdctNum <= SeqEndPos; IdxProdctNum++) { 
               SeqProduct = SeqProduct * IntegerSequence[IdxProdctNum];
            }
         } else {
            SeqProduct = 0;    
         }
         if ( SeqProduct > TheMaxProduct) {
              TheMaxProduct = SeqProduct;
         }
    }	   
    printf("Case #%d: The maximum product is %lld.\n\n", CaseNum, TheMaxProduct);                     	
 } 
 return 0;
}
