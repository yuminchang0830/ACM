/* @JUDGE_ID:50418EN 10608 C */
#include <stdio.h>
#define MAX_TOWN 31000

int parent[MAX_TOWN];
int node[MAX_TOWN];
int height[MAX_TOWN];

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

int main(void)
{
	int n_case, n, m;
	int i;
	int x,y;
	int max;	
	
	scanf("%d", &n_case);
	while(n_case--) {
		scanf("%d %d", &n, &m);		
		for (i = 1 ; i <= n ; i++) {
			parent[i] = i;
			node[i] = height[i] = 0;			
		}
		for (i = 0 ; i < m; i++) {
			scanf("%d %d", &x, &y);
			_union(x,y);
	   }
	   
	   for (i = 1; i <= n; i++) {
	   	node[find_set(i)]++;
	   }
	   max = 0;
	   for (i = 1; i <= n; i++) {
	   	if (node[i] > max) {
	   		max = node[i];
	   	}
	   }
	   printf("%d\n", max);				
	}
	return 0;
}
	