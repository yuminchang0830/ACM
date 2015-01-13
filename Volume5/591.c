/* @JUDGE_ID:50418EN 591 C */
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_NUM_STACK 101

int main(void)
{
  int NumStack;
  int IdxStack;
  int BrickInStack[MAX_NUM_STACK];  
  int TotalBrick;
  int WallHeight;
  int HighThanAverage, LowThanAverage;
  int BrickMovedFromHigh, BrickMovedFromLow;
  int currentCase;
  
  /*
  freopen("p591_in.txt", "r", stdin);
  freopen("p591_out.txt", "w", stdout);
  */

  currentCase = 0;
  while(1) 
  {
    scanf("%d", &NumStack);	
	if ( NumStack == 0) {
	   break;
	}
	/*
	if (currentCase != 0) {
      printf("\n");
    }
    */
	currentCase++;
	TotalBrick = 0;
	for ( IdxStack = 0; IdxStack < NumStack; IdxStack++) {
	   scanf("%d", &BrickInStack[IdxStack]);
	   TotalBrick += BrickInStack[IdxStack];
	}
	WallHeight = (TotalBrick/NumStack);	
	HighThanAverage = LowThanAverage = 0;
	BrickMovedFromHigh = BrickMovedFromLow = 0;
	for ( IdxStack = 0; IdxStack < NumStack; IdxStack++) {
	   if ( BrickInStack[IdxStack] > WallHeight) {
	      HighThanAverage++;
	      BrickMovedFromHigh += BrickInStack[IdxStack] - WallHeight;
	   } else if (BrickInStack[IdxStack] < WallHeight) {
	      LowThanAverage++;
	      BrickMovedFromLow += WallHeight - BrickInStack[IdxStack];
	   }	  
	}
	printf( "Set #%d\nThe minimum number of moves is %d.\n\n", currentCase, (HighThanAverage > LowThanAverage)? BrickMovedFromLow:BrickMovedFromHigh);	
  }
  
  return 0;
}
