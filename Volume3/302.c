#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
	int x;
	int y;
	int seq;
} edges;

int paths[MAX][MAX];

edges street;

int main(void)
{
	int x,y;
	int i,j;
	int degree;
	int odd, even;
	
	while(scanf("%d %d %d", &street[0].x, &street[0].y, &street[0].seq) == 3) {		
		memset(paths, 0, sizeof(paths[0])*MAX*MAX);
					
	   paths[street[0].x]][street[0].y]++;
		i = 1;		
		while(scanf("%d %d %d", &street[i].x, &street[i].y, &street[0].seq) == 3) {			
			paths[street[i].x]][street[i].y]++;
			i++;
		}		
		scanf("%d %d", &x, &y);		
		
	}
	
	
	return 0;
}