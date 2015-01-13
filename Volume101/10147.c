/* @JUDGE_ID:50418EN 10147 C */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 290000

typedef struct {
	int x;	
	int y;	
	int cost;
} point;


int x[751];
int y[751];


point edge[MAX];
int parent[MAX];
int height[MAX];

int find_set(int x)
{
	if (x == parent[x] ) return x;		
	else return (parent[x] = find_set(parent[x]));	
}

int _union(int x,int y)
{	
	if ( find_set(x) != find_set(y) ) {
		if ( height[x] > height[y] ) {  
			parent[parent[y]] = parent[x];
	   } else {
	   	parent[parent[x]] = parent[y];
	   	if ( height[parent[x]] == height[parent[y]]) {
	   		height[parent[y]]++;	   		
	   	}	   	  
	   }
   }    
   return 0;   
}

int compare(const void *arg1,const void *arg2)
{
	point a,b;
	
	a = *(point*)arg1;
	b = *(point*)arg2;
        return a.cost - b.cost;
}


int main(void)
{
	int TN;
	int n1,n2;
	int i,j;	
	int ne;
	int num;
	int t1, t2;
	int new_way;
	
	scanf("%d\n", &TN);
	while(TN--) {
		scanf("%d", &n1);		

		for (i = 0; i < n1; i++) {
			scanf("%d %d", &x[i] , &y[i]);				
		}		
		
		for (num = 0, i = 0; i < n1; i++) {
			for (j = i+1; j < n1; j++) {		
				edge[num].x = i;
				edge[num].y = j;
				edge[num].cost = 
(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
				num++;
			}
		}
		qsort(edge, num, sizeof(edge[0]), compare);		
		for (i = 0; i <= n1 ; i++) {
			parent[i] = i;
			height[i] = 0;
		}		
		scanf("%d", &n2);
		ne = 0;
		for ( i = 0; i < n2 ; i++ ) {
			scanf("%d %d", &t1, &t2);
			if (find_set(t1-1) != find_set(t2-1)) {
				_union(t1-1,t2-1);		
				ne++;
			}
		}			
		new_way = 0;			
		for (i = 0; i < num; i++) {		
			if (ne == n1 - 1) break;
			if (find_set(edge[i].x) != find_set(edge[i].y)) {
				printf("%d %d\n", edge[i].x+1, 
edge[i].y+1);
				_union(edge[i].x, edge[i].y);				
				ne++; new_way++;
			}			
		}		
		
		if (!new_way) printf("No new highways need\n");
		
		
		if(TN) printf("\n");
		
	}
	return 0; 
}
