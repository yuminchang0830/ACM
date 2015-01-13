/* @JUDGE_ID:50418EN 164 C */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

int DPTable[MAX][MAX];
int TraceTAB[MAX][MAX]; /* same = 0; change = 1; Insert = 2; Delete = 3*/
int order[MAX*2];

int main(void)
{
	char origin[MAX], goal[MAX];
	int i,j,k,m,n,onum,del,temp;	
	
	origin[0] = ' ';  
	goal[0] = ' ';	
	
	
	freopen("164.txt","r",stdin);
	freopen("o164.txt","w",stdout);
	while ( scanf("%s %s", &origin[1], &goal[1]) == 2) {
		m = strlen(origin);
		n = strlen(goal);
		for(i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				DPTable[i][j] = 0;
				TraceTAB[i][j] = 0;
			}
		}
		for (i = 1; i <n ; i++)  {
			DPTable[i][0] = i;
			TraceTAB[i][0] = 2; 
		}
		
		for (j = 1; j <m ; j++) {
			DPTable[0][j] = j;
			TraceTAB[0][j] = 3; 
		}
		
		for (i = 1; i < n; i++) {
			for (j = 1; j < m ; j++) {
				if (origin[j] == goal[i]) {
					DPTable[i][j] = DPTable[i-1][j-1];
					TraceTAB[i][j] = 0;
				} else {
					if (DPTable[i-1][j-1] < DPTable[i-1][j] && DPTable[i-1][j-1] < DPTable[i][j-1]) {
						DPTable[i][j] = DPTable[i-1][j-1] + 1;
						TraceTAB[i][j] = 1;						
					} else if (DPTable[i-1][j-1] <= DPTable[i-1][j] && DPTable[i-1][j-1] >= DPTable[i][j-1]) {
						DPTable[i][j] = DPTable[i][j-1] + 1;
						TraceTAB[i][j] = 3;
					} else {
						DPTable[i][j] = DPTable[i-1][j] + 1;
						TraceTAB[i][j] = 2;
					}					
				}
			}
		}
	
		printf("  ");
		for ( j = 0; j < m ; j++ ) {
		  printf("%c ", origin[j]);
		}
		printf("\n");
		for ( i = 0; i <n ; i++) {
			for ( j = 0; j <m; j++) {
			    if (j==0) printf("%c ", goal[i]);
				printf("%d ", DPTable[i][j]);
			}
			printf("\n");			
		}
		
		printf("  ");
		for ( j = 0; j < m ; j++ ) {
		  printf("%c ", origin[j]);
		}
		printf("\n");
		for ( i = 0; i <n ; i++) {
			for ( j = 0; j <m; j++) {
			    if (j==0) printf("%c ", goal[i]);
				printf("%d ", TraceTAB[i][j]);
			}
			printf("\n");			
		}
	
		onum = 0;
		i = n - 1;
		j = m - 1;
		while ((i>0) || (j>0)) {
			switch(TraceTAB[i][j]) {
				case 0:
				       order[onum] = 0;
				       i--;
				       j--;
				       break;
				case 1:
				       order[onum] = 1;
				       i--;
				       j--;
				       break;
				case 2:
				       order[onum] = 2;
				       i--; 
				       break;
				case 3:
				       order[onum] = 3;
				       j--;
				       break;				
			}
			onum++;
		}
	
		for ( i = onum -1; i >=0; i--) {
			printf("%d ", order[i]);
		}
		printf("\n");
		
		i = j = 1;
		del = 0;
		for (k = onum - 1;k >= 0 ; k--) {
			switch(order[k]) {
				case 0:
				       i++;
				       j++;
				       break;
				case 1:
				       printf("C%c%d%d", goal[i], (j-del)/10, (j-del)%10);
				       i++;
				       j++;
				       break;
				case 2:
				       printf("I%c%d%d", goal[i], (j-del)/10, (j-del)%10);
				       i++;
				       j++;				
				       break;				
				case 3:				
				       printf("D%c%d%d", origin[j], (j-del)/10, (j-del)%10);
				       del++;				
				       j++;
				       break;
			}						
		}
        printf("E\n");		
   }   
	return 0; 
}






