#include <stdio.h>
#include <string.h>

#define MAX_TRIANGLE_BASE 401
#define MAX_ROW 201


int TriangleMatrix[MAX_ROW][MAX_TRIANGLE_BASE];


enum Triangle_Element {
	Triangle_Space = 0,
	Triangle_HashSign,
	Triangle_DashSign
};

int Check_Level_H_DownwardTriange_Exist( int TargetTriangleHeight, int RowPos, int ColPos, int SourceTriangleHeight)
{
  int IdxRow, IdxCol;
  int LenSourceTriangleBase;
  int LenTargetTriangleBase;
  int isDownwardTriageExist;

  LenSourceTriangleBase = 1 + (SourceTriangleHeight-1)*2;
  LenTargetTriangleBase = 1 + (TargetTriangleHeight-1)*2;    
  isDownwardTriageExist = 1;

  if ( ((RowPos + TargetTriangleHeight) > SourceTriangleHeight)  || ((ColPos + LenTargetTriangleBase) > LenSourceTriangleBase)) {
  	isDownwardTriageExist = 0;
	return isDownwardTriageExist;  
  }
 
  for (  IdxRow = 0; IdxRow < TargetTriangleHeight; IdxRow++) {
  	 for (  IdxCol = 0; IdxCol <  (LenTargetTriangleBase- (2*IdxRow)) ; IdxCol++) {
	 	if ( (TriangleMatrix[RowPos+IdxRow][ColPos+IdxRow+IdxCol] == Triangle_HashSign) || (TriangleMatrix[RowPos+IdxRow][ColPos+IdxRow+IdxCol] == Triangle_Space)) {
			isDownwardTriageExist = 0;
			break;				
	 	}	else {
            /*
              printf("TargetTriangleHeight =%d idxrow =%d %d \n",TargetTriangleHeight,  RowPos+IdxRow,  ColPos+IdxCol);    
            */           
        } 	
  	 }
	 if (isDownwardTriageExist == 0) {
	 	break;
	 }
  }  
  return isDownwardTriageExist;  
}


int Check_Level_H_UpwardTriange_Exist( int TargetTriangleHeight, int RowPos, int ColPos, int SourceTriangleHeight)
{
	int IdxRow, IdxCol;
	int LenSourceTriangleBase;
	int LenTargetTriangleBase;
	int isUpwardTriageExist;
	
	LenSourceTriangleBase = 1 + (SourceTriangleHeight-1)*2;
	LenTargetTriangleBase = 1 + (TargetTriangleHeight-1)*2;    
	isUpwardTriageExist = 1;  
    
	
	if (  (ColPos+ LenTargetTriangleBase ) > ((LenSourceTriangleBase- RowPos)) ) {
	  isUpwardTriageExist = 0;
	  /* printf("A IdxRowCol =%d,%d %d %d %d %d\n",  RowPos,  ColPos,TargetTriangleHeight, SourceTriangleHeight, (ColPos+ TargetTriangleHeight ), ((LenSourceTriangleBase- (2*RowPos))) ); */
	  return isUpwardTriageExist;  
	}
	
	if ( TargetTriangleHeight >  (RowPos+1)   )
	{
      isUpwardTriageExist = 0;
      /* printf("B IdxRowCol =%d,%d %d %d\n",  RowPos,  ColPos,TargetTriangleHeight, SourceTriangleHeight ); */
	  return isUpwardTriageExist;  
	}
	
	  /* printf("C IdxRowCol =%d,%d %d %d\n",  RowPos,  ColPos,TargetTriangleHeight, SourceTriangleHeight ); */
	
	
    
	for (  IdxRow = 0; RowPos >= IdxRow ; IdxRow++) {
	   for (  IdxCol = 0; IdxCol <	(LenTargetTriangleBase- (2*IdxRow)) ; IdxCol++) {
		  if ( (TriangleMatrix[RowPos - IdxRow][ColPos+IdxRow+IdxCol] == Triangle_HashSign) || (TriangleMatrix[RowPos - IdxRow][ColPos+IdxRow+IdxCol] == Triangle_Space)) {
			  isUpwardTriageExist = 0;
			   /*printf("#TargetTriangleHeight =%d idxrow =%d idxcol=%d \n",TargetTriangleHeight,  RowPos - IdxRow,  ColPos+IdxRow+IdxCol); */
			  break;			  
		  } else {
               /*printf("TargetTriangleHeight =%d idxrow =%d idxcol=%d \n",TargetTriangleHeight,  RowPos - IdxRow,  ColPos+IdxRow+IdxCol); */
          } 	  
	   }
	   if (isUpwardTriageExist == 0) {
		  break;
	   }
	}	
	
	return isUpwardTriageExist; 
}

int main(void)
{
	
	int currentCase;
	int TriangelHeight;
	int IdxRow, IdxCol;
	int CaseIndex;
	int LenTriangleBase;
	char InputLine[80];
	int IdxHeight;
	int FindLargestTriangle;
	int MaxDownTriangleHeight, MaxUpTriangleHeight;
	int MaxTriangleHeight, MaxTriangleArea;

    /*
	freopen("p585_in.txt", "r", stdin);
	freopen("p585_out.txt", "w", stdout);
    */
	currentCase = 0;
	while ( scanf("%d", &TriangelHeight) == 1 )
	{
		if ( TriangelHeight == 0 ) {
			break;
		}
		/* Count Current Test Case Number */		
		currentCase++;

		/* Calculate Input Triangle Base */		
		LenTriangleBase = 1 + ( TriangelHeight - 1) * 2;			

		/* clear Triangel Matrix record */
		memset (TriangleMatrix, Triangle_Space, sizeof(TriangleMatrix[0][0]) * MAX_ROW * MAX_TRIANGLE_BASE );		
		
        /* Get Input data from standard I/O */		
		for ( IdxRow = 0; IdxRow < TriangelHeight ; IdxRow++ ) {
			scanf("%s",InputLine);
			for (IdxCol = 0 ; IdxCol < ((int) strlen(InputLine)) ; IdxCol++ ) {
				if ( InputLine[IdxCol] == '#' ) {
				   TriangleMatrix[IdxRow][IdxRow+IdxCol] = Triangle_HashSign;
				   /*printf("#");*/
				} else if (InputLine[IdxCol] == '-'){				
  			       TriangleMatrix[IdxRow][IdxRow+IdxCol] = Triangle_DashSign;
   				  /* printf("-"); */
				}
			}	
			/*printf("\n"); */
		}
		
		MaxDownTriangleHeight = 0;
		for ( IdxHeight = TriangelHeight; IdxHeight > 0 ; IdxHeight--) {            
           for (  IdxRow = 0; IdxRow < TriangelHeight; IdxRow++) {
  	          for (  IdxCol = 0; IdxCol <  ( LenTriangleBase - (2*IdxRow)) ; IdxCol+=2) {                          
	 	          if ( Check_Level_H_DownwardTriange_Exist(IdxHeight , IdxRow ,(IdxRow + IdxCol) ,TriangelHeight) == 1) {
                       /*printf("find down %d %d %d\n", IdxHeight, IdxRow, (IdxRow + IdxCol)); */
                       MaxDownTriangleHeight = IdxHeight;
                       break;
                  }	                  
              }   
              if ( MaxDownTriangleHeight != 0) {
                   break;
              }        		
  	       }
  	       if ( MaxDownTriangleHeight != 0) {
                   break;
           }
           
        }   
        
		MaxUpTriangleHeight = 0;
		for ( IdxHeight = TriangelHeight; IdxHeight > 0 ; IdxHeight--) 
        {            
           for (  IdxRow = 0; IdxRow < TriangelHeight; IdxRow++)
           {
  	          for (  IdxCol = 1; IdxCol <  ( LenTriangleBase - (2*IdxRow)) ; IdxCol+=2)
              {                          
                  /* printf("Try %d %d %d\n", IdxHeight, IdxRow, (IdxRow + IdxCol));*/
	 	          if ( Check_Level_H_UpwardTriange_Exist(IdxHeight , IdxRow ,(IdxRow + IdxCol) ,TriangelHeight) == 1) {
                       /*printf("find up %d %d %d\n", IdxHeight, IdxRow, (IdxRow + IdxCol)); */
                       MaxUpTriangleHeight = IdxHeight;
                       break;
                  }	                  
              }   
              if ( MaxUpTriangleHeight != 0) {
                   break;
              }        		
  	       }
  	       if ( MaxUpTriangleHeight != 0) {
                   break;
           }           
        }  

	  /*	printf ("maxd=%d maxu=%d\n", MaxDownTriangleHeight, MaxUpTriangleHeight); */

		MaxTriangleHeight= (MaxDownTriangleHeight > MaxUpTriangleHeight)? MaxDownTriangleHeight:MaxUpTriangleHeight;
      
        		
		printf("Triangle #%d\n", currentCase);
        printf("The largest triangle area is %d.\n\n",  (1+ (1 + ( MaxTriangleHeight - 1) * 2))*MaxTriangleHeight/2);
	}
	
	return 0;	
}
