/* @JUDGE_ID:50418EN 291 C */
#include <stdio.h>
#include <stdlib.h>

int solution[10];

int GraphHouse[5][5] = {{0,1,1,0,1},
	                     {1,0,1,0,1},
	                     {1,1,0,1,1},
	                     {0,0,1,0,1},
	                     {1,1,1,1,0}};

void PlantHouse(int paths, int now)
{	
	int temp[5][5];
	int row,col,next;
	int i,j;	
	
	if (paths==8) {
	   for ( i = 0 ; i < 9 ; i++ ) {
	   	printf("%d", solution[i]);
	   }
	   printf("\n");
	} else {
		for ( row = 0 ; row < 5 ; row++ ) {
			for ( col = 0 ; col < 5; col++ ) {
				temp[row][col] = GraphHouse[row][col];
			}
		}
		for ( next = 0 ; next < 5 ; next++ ) {
			if (GraphHouse[now][next]) {			
				GraphHouse[now][next] = 0;
				GraphHouse[next][now] = 0;	
				solution[paths+1] = next+1;											
				PlantHouse(paths+1,next);				
				for ( row = 0 ; row < 5 ; row++ ) {
		      	for ( col = 0 ; col < 5; col++ ) {
				      GraphHouse[row][col] = temp[row][col];
			      }
		      }
			}
		}
	}

}

int main(void)
{
   solution[0] = 1;
	PlantHouse(0,0);
	system("pause");
	return 0;
}

