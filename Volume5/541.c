#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXMATRIXSIZE 100

int BooleanMatrix[MAXMATRIXSIZE][MAXMATRIXSIZE];


int main(void)
{

int InputMatrixSize;
int IdxRow, IdxCol;
int MatrixElement;
int SumEachRow[MAXMATRIXSIZE];
int SumEachCol[MAXMATRIXSIZE];
int NumOddRow, OddInRow;
int NumOddCol, OddInCol;

/*
 freopen("p541_in.txt", "r", stdin);
 freopen("p541_out.txt", "w", stdout);
*/

while (1) {      
   memset(BooleanMatrix, 0, sizeof(BooleanMatrix[0][0])* MAXMATRIXSIZE*MAXMATRIXSIZE);
   memset(SumEachRow, 0, sizeof(SumEachRow[0])* MAXMATRIXSIZE);
   memset(SumEachCol, 0, sizeof(SumEachCol[0])* MAXMATRIXSIZE);
   NumOddRow = NumOddCol = OddInRow = OddInCol = 0;
   scanf("%d", &InputMatrixSize);    
   if (   InputMatrixSize == 0) {
      break;
   }
   for (IdxRow = 0; IdxRow < InputMatrixSize; IdxRow++) {
      for (IdxCol = 0; IdxCol < InputMatrixSize; IdxCol++) {
         scanf("%d", &MatrixElement);
         BooleanMatrix[IdxRow][IdxCol] = MatrixElement;
      }
   }      
   for (IdxRow = 0; IdxRow < InputMatrixSize; IdxRow++) {
      for (IdxCol = 0; IdxCol < InputMatrixSize; IdxCol++) {
          if ( BooleanMatrix[IdxRow][IdxCol] == 1) {
             SumEachRow[IdxRow]++;
          }
      }   
      if ( ( SumEachRow[IdxRow] % 2) == 1) {
         NumOddRow++;
         if (  NumOddRow == 1) {
            OddInRow = IdxRow+1;
         }         
      }
   }      
   for (IdxCol = 0; IdxCol < InputMatrixSize; IdxCol++) {
      for (IdxRow = 0; IdxRow < InputMatrixSize; IdxRow++) { 
          if ( BooleanMatrix[IdxRow][IdxCol] == 1) {
             SumEachCol[IdxCol]++;
          }                          
      }
      if ( ( SumEachCol[IdxCol] % 2) == 1) {
         NumOddCol++;
         if (  NumOddCol == 1) {
            OddInCol = IdxCol+1;
         }         
      }      
   }
   
   if (  (NumOddRow == 0) & (NumOddCol==0)) {
      printf("OK\n");
   } else if ((NumOddRow == 1) & (NumOddCol==1)) {
      printf("Change bit (%d,%d)\n",OddInRow,  OddInCol);   
   } else {
      printf("Corrupt\n");          
   }
  
} 


 return 0;
}
