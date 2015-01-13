/* @JUDGE_ID:50418EN 10600 C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINK 400

typedef struct {
	int schoolA;
	int schoolB;
	int cost;
} vertex;

vertex SchoolPowerLink[MAX_LINK];
int SchoolGroup[MAX_LINK];


int isPowerLinkCycle(int index, int fromSchool, int targetSchool)
{
	int indexSchool;
	int rs = 0;	
	for (indexSchool = 0 ; indexSchool <= index ;indexSchool++)
	{
		if (SchoolGroup[indexSchool] == 1 && (SchoolPowerLink[indexSchool].schoolA== fromSchool || SchoolPowerLink[indexSchool].schoolB== fromSchool)) 
		{
			if (SchoolPowerLink[indexSchool].schoolA== targetSchool || SchoolPowerLink[indexSchool].schoolB== targetSchool) {
				return 1;
			} else {
			  rs = isPowerLinkCycle(index, SchoolPowerLink[i].schoolB, targetSchool);		
			  if (rs)  {
			    break;	  
			  }
			}
		}		
	}	
	return rs;	
}

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

int main(void)
{
	int NumCase;	
	int NumSchool;
	int NumPowerLink;
	int IdxSchool;
	int SourceSchool,DstSchool;
	int MinLinkCost;
	itn LinkBeCalculated;
	


	freopen("p10600_in.txt", "r", stdin);
	freopen("p10600_out.txt", "w", stdout);


	scanf("%d", &NumCase);	
	while(NumCase--) {		
		
		scanf("%d %d", &NumSchool, &NumPowerLink);		
		
		for (IdxSchool = 0 ; IdxSchool < NumPowerLink ; IdxSchool ++) {
			scanf("%d %d %d", &SourceSchool, &DstSchool, &SchoolPowerLink[IdxSchool].cost);						
			if (SourceSchool > DstSchool) {

				SchoolPowerLink[IdxSchool].schoolA = DstSchool;
			    SchoolPowerLink[IdxSchool].schoolB = SourceSchool;				
			} else {			    
				SchoolPowerLink[IdxSchool].schoolA = SourceSchool;
			    SchoolPowerLink[IdxSchool].schoolB = DstSchool;							
			}
		}			
		qsort(SchoolPowerLink, NumPowerLink, sizeof(SchoolPowerLink[0]), compare);		
		
		printf("---------\n");		
		for ( IdxSchool = 0 ; IdxSchool < NumPowerLink ; IdxSchool++ ) {
			printf("%d %d %d\n", SchoolPowerLink[IdxSchool].schoolA, SchoolPowerLink[IdxSchool].schoolB, SchoolPowerLink[IdxSchool].cost);
		}		
		printf("---------\n");		
		
		MinLinkCost = 0;
		LinkBeCalculated = 0;		
		memset(SchoolGroup, 0, sizeof(SchoolGroup[0])*MAX_LINK);		
		
		for (IdxSchool = 0 ; IdxSchool < NumPowerLink ; IdxSchool++) {
			if ( LinkBeCalculated == (NumSchool - 1) ) 
			{
				break;			
			}
			if (isPowerLinkCycle(IdxSchool, SchoolPowerLink[IdxSchool].schoolB, SchoolPowerLink[IdxSchool].schoolA)== 0 || 
				  isPowerLinkCycle(IdxSchool, SchoolPowerLink[IdxSchool].schoolA, SchoolPowerLink[IdxSchool].schoolB)== 0  ) 
			{
				printf("%d %d %d\n", SchoolPowerLink[IdxSchool].schoolA, SchoolPowerLink[IdxSchool].schoolB, SchoolPowerLink[IdxSchool].cost);
				MinLinkCost += SchoolPowerLink[IdxSchool].cost;
				SchoolGroup[IdxSchool] = 1 ;
				LinkBeCalculated++;				
			}			
		}	
		
		printf("%d\n", MinLinkCost);				
	}
	
	return 0;
}
