/* @JUDGE_ID:50418EN 10600 C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINK 6000


typedef struct {
	int schoolA;
	int schoolB;
	int cost;
} vertex;

vertex SchoolPowerLink[MAX_LINK];
int MinCostLink[MAX_LINK];
int SchoolGroup[MAX_LINK];

int compare( const void *arg1, const void *arg2 )
{
	vertex a,b;
	a = *(vertex*) arg1;
	b = *(vertex*) arg2;
	if ( a.cost != b.cost) {
		return (a.cost - b.cost);
	} else if (a.schoolA != b.schoolA) {
		return (a.schoolA - b.schoolA);		
	} else {
		return (a.schoolB - b.schoolB);
	}
}

void LinkTwoGroup(int StartNode,int EndNode, int NumNodes)
{	
  int IdxSchool;  
  int Ruler;
  int Beruler;
  
  if ( StartNode < EndNode) {
  	Ruler = SchoolGroup[EndNode];
	Beruler = SchoolGroup[StartNode];  	
  } else if ( StartNode > EndNode) {
    Ruler = SchoolGroup[StartNode];
    Beruler = SchoolGroup[EndNode];
  } else {
    return;
  }
  for ( IdxSchool = 1; IdxSchool <= NumNodes; IdxSchool++) {
  	 if (SchoolGroup[IdxSchool] == Beruler) {
	    SchoolGroup[IdxSchool] = Ruler;
	 }
  }  	  
}

int main(void)
{
	int NumCase;	
	int NumSchool;
	int NumPowerLink;
	int IdxSchool, IdxPowerLink, idxLinkPermu;
	int SourceSchool,DstSchool;
	int MinPowerLinkCost;
	int SubMinPowerLinkCost;
	int TempCost;
	int LinkBeCalculated;

    /*
	freopen("p10600_in.txt", "r", stdin);
	freopen("p10600_out.txt", "w", stdout);
    */

	scanf("%d", &NumCase);	
	while(NumCase--) {	
		
		/* Get Number of School and Number of possible link from Strandard I/O */
		scanf("%d %d", &NumSchool, &NumPowerLink);		
		
		/* Get Link source, destination and cost from Standard I/O */
		for (IdxPowerLink = 0 ; IdxPowerLink < NumPowerLink ; IdxPowerLink++) {
			scanf("%d %d %d", &SourceSchool, &DstSchool, &SchoolPowerLink[IdxPowerLink].cost);						
			if (SourceSchool > DstSchool) {
				SchoolPowerLink[IdxPowerLink].schoolA = DstSchool;
			    SchoolPowerLink[IdxPowerLink].schoolB = SourceSchool;				
			} else {			    
				SchoolPowerLink[IdxPowerLink].schoolA = SourceSchool;
			    SchoolPowerLink[IdxPowerLink].schoolB = DstSchool;							
			}
		}			
		
		/* Sorting Link by cost */
		qsort(SchoolPowerLink, NumPowerLink, sizeof(SchoolPowerLink[0]), compare);		
		
		/* Find Minimum Cost & Patch */
		
	    /* Initialize   Variable */ 	
  	    memset(SchoolGroup, 0, sizeof(SchoolGroup[0]) * MAX_LINK);			
	    memset(MinCostLink, 0, sizeof(MinCostLink[0]) * MAX_LINK); 	    
		for (IdxSchool = 1; IdxSchool <= NumSchool ; IdxSchool++) {
		  SchoolGroup[IdxSchool] = IdxSchool;
		}				
 		MinPowerLinkCost = 0;	LinkBeCalculated = 0;           		
		
		/* Couting Miminum Spanning Tree */
		for (IdxPowerLink = 0 ; IdxPowerLink < NumPowerLink ; IdxPowerLink++) {
		  if ( SchoolGroup[SchoolPowerLink[IdxPowerLink].schoolA] != SchoolGroup[SchoolPowerLink[IdxPowerLink].schoolB]) {                 
                 MinCostLink[IdxPowerLink] = 1;
			     LinkTwoGroup(SchoolPowerLink[IdxPowerLink].schoolA, SchoolPowerLink[IdxPowerLink].schoolB , NumSchool);			    	
				 MinPowerLinkCost += SchoolPowerLink[IdxPowerLink].cost;				
				 LinkBeCalculated++;                
		  }	
		  if ( LinkBeCalculated == (NumSchool-1)) {
        	  break;				
          }
        }                 

		
         memset(SchoolGroup, 0, sizeof(SchoolGroup[0]) * MAX_LINK);	 
		 SubMinPowerLinkCost = 400 * 400;
	    for (idxLinkPermu = 0 ; idxLinkPermu < NumPowerLink ; idxLinkPermu++) {                        
           if  ( MinCostLink[idxLinkPermu] == 0 ) {
               continue;
           }           
                      
  		   memset(SchoolGroup, 0, sizeof(SchoolGroup[0]) * MAX_LINK);	 
  		   
		   for (IdxSchool = 1; IdxSchool <= NumSchool ; IdxSchool++) {
		 	  SchoolGroup[IdxSchool] = IdxSchool;
		   }				
 		  
		   LinkBeCalculated = 0;
		   TempCost = 0;
                      		
		   for (IdxPowerLink = 0 ; IdxPowerLink < NumPowerLink ; IdxPowerLink++) {
             
              if ( idxLinkPermu ==  IdxPowerLink) 
              {
                   continue;
              }
			  if ( SchoolGroup[SchoolPowerLink[IdxPowerLink].schoolA] != SchoolGroup[SchoolPowerLink[IdxPowerLink].schoolB])
			  {             
			     LinkTwoGroup(SchoolPowerLink[IdxPowerLink].schoolA, SchoolPowerLink[IdxPowerLink].schoolB , NumSchool);			    	
				 TempCost += SchoolPowerLink[IdxPowerLink].cost;				
				 LinkBeCalculated++;
			  }	
			  if ( LinkBeCalculated == (NumSchool-1)) {                
				  break;				
              }
           }                
            
           if ( (TempCost < SubMinPowerLinkCost ) && (LinkBeCalculated == (NumSchool-1)) ) {
                SubMinPowerLinkCost = TempCost;               
           }
        }	        
        printf("%d %d\n", MinPowerLinkCost, SubMinPowerLinkCost);  	        		
	}	
	return 0;
}



