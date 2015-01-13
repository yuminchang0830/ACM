/* @JUDGE_ID:50418EN 750 C */
#include <stdio.h>
#include <stdlib.h>


#define CHESSBOARDSIZE 8
#define CHESSBOARDSIZEPLUSONE CHESSBOARDSIZE+1 

enum BoardGridType {
  CHESS_IS_SAFTY = 0,
  CHESS_IS_DANGEROUS
};

void PlaceNQueen(int ChessBoard[CHESSBOARDSIZEPLUSONE][CHESSBOARDSIZEPLUSONE] )
{
  int IdxQueenPosition;
  int NumQueenOnBoard = 0;
  int IdxColumn, IdxRow; 
  int NewChessBoard[CHESSBOARDSIZEPLUSONE][CHESSBOARDSIZEPLUSONE];
  int IdxHorizontal, IdxVertical;

  NumQueenOnBoard =  ChessBoard[0][0];
  
 if (NumQueenOnBoard == CHESSBOARDSIZE) {	  
  	for ( IdxQueenPosition = 1; IdxQueenPosition <= CHESSBOARDSIZE; IdxQueenPosition++) {
		printf("%d", ChessBoard[0][IdxQueenPosition]);
  	} 
	printf("\n");
  
              //         printf("find solution\n");
    return;
  }  
  
  /* search Valid Space*/
  for ( IdxColumn = 1; IdxColumn <= CHESSBOARDSIZE; IdxColumn++) {
   	if (ChessBoard[0][IdxColumn] == 0) {
		for ( IdxRow = 1; IdxRow <=CHESSBOARDSIZE; IdxRow++) {
			if (ChessBoard[IdxRow][IdxColumn] == CHESS_IS_SAFTY) {
				//memcpy(NewChessBoard, ChessBoard, sizeof(int)*CHESSBOARDSIZEPLUSONE*CHESSBOARDSIZEPLUSONE);
				
			    for ( IdxVertical = 0 ; IdxVertical <= CHESSBOARDSIZE; IdxVertical++) {
                   for ( IdxHorizontal = 0; IdxHorizontal <= CHESSBOARDSIZE; IdxHorizontal++) {
                      NewChessBoard[IdxHorizontal][IdxVertical] =  ChessBoard[IdxHorizontal][IdxVertical];
                   }                        
                }   
				
				NewChessBoard[0][0] = NumQueenOnBoard + 1;
				NewChessBoard[0][IdxColumn] = IdxRow;
  			    //printf("NumQueenOnBoard=%d, IdxRow=%d, IdxColumn=%d\n", NewChessBoard[0][0],IdxRow, IdxColumn);         
				
				/* Horizontal */
				for (IdxHorizontal = 1; IdxHorizontal <= CHESSBOARDSIZE; IdxHorizontal++)
				{
				  NewChessBoard[IdxRow][IdxHorizontal] = CHESS_IS_DANGEROUS;
				}
				/* Vertical*/
				for (IdxVertical = 1; IdxVertical <= CHESSBOARDSIZE; IdxVertical++)
				{
				  NewChessBoard[IdxVertical][IdxColumn] = CHESS_IS_DANGEROUS;
				}
				/* NorthEast */
				for (IdxHorizontal = IdxRow, IdxVertical = IdxColumn; (IdxHorizontal <= CHESSBOARDSIZE) && ( IdxVertical  >= 1  ) ; IdxHorizontal++, IdxVertical--) {
					NewChessBoard[IdxHorizontal][IdxVertical] = CHESS_IS_DANGEROUS;
					 //printf("NE\n");
				}
				/* SouthEast */
				for (IdxHorizontal = IdxRow, IdxVertical = IdxColumn; (IdxHorizontal <= CHESSBOARDSIZE) && ( IdxVertical <= CHESSBOARDSIZE) ; IdxHorizontal++, IdxVertical++) {
					NewChessBoard[IdxHorizontal][IdxVertical] = CHESS_IS_DANGEROUS;
				//	printf("SE\n");
				}
				/* SouthWest*/
				for (IdxHorizontal = IdxRow, IdxVertical = IdxColumn; (IdxHorizontal >= 1) && ( IdxVertical <= CHESSBOARDSIZE) ; IdxHorizontal--, IdxVertical++) {
					NewChessBoard[IdxHorizontal][IdxVertical] = CHESS_IS_DANGEROUS;
				//	printf("SW\n");					
				}
				/* NorthWest*/
				for (IdxHorizontal = IdxRow, IdxVertical = IdxColumn; (IdxHorizontal >= 1) && ( IdxVertical >= 1) ; IdxHorizontal--, IdxVertical--) {
					NewChessBoard[IdxHorizontal][IdxVertical] = CHESS_IS_DANGEROUS;
				//	printf("NW\n");										
				}	
				/* printf("Enter resurvie\n"); */
				/*
				 printf("---------\n");
				for ( IdxVertical = 1 ; IdxVertical <= CHESSBOARDSIZE; IdxVertical++) {
                   for ( IdxHorizontal = 1; IdxHorizontal <= CHESSBOARDSIZE; IdxHorizontal++) {
                      printf("%d ", NewChessBoard[IdxHorizontal][IdxVertical]);
                   }      
                   printf("\n");
                }   
                 printf("---------\n");
                */
				PlaceNQueen( NewChessBoard );
				
			}
		}
     }  	
  }
  
  return;
}

int main()
{
  int IdxColumn, IdxRow; 
  int currentChessBoard[CHESSBOARDSIZEPLUSONE][CHESSBOARDSIZEPLUSONE];

  freopen("p750_in.txt", "r", stdin);
  freopen("p750_out.txt", "w", stdout);
  
  for ( IdxColumn = 0 ; IdxColumn <= CHESSBOARDSIZE; IdxColumn++) {
      for ( IdxRow = 0; IdxRow <= CHESSBOARDSIZE; IdxRow++) {
          currentChessBoard[IdxRow][IdxColumn] = CHESS_IS_SAFTY;
      }      
  } 
  
  PlaceNQueen( currentChessBoard);
  
  return 0;
}


