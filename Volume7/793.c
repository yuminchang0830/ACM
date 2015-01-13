/* @JUDGE_ID:50418EN 793 C */
#include <stdio.h>
#define MAX 3100

int parent[MAX];
int node[MAX];
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

int main(void)
{
	unsigned long n, i;
	int x, y;
	int Yes, No;
	unsigned long n_case;
	char type;
	char s[100];
	/*
	freopen("input.txt", "r", stdin);
	freopen("output.txt","w", stdout);
	*/
	scanf("%lu", &n_case);
	while (n_case--) {
	scanf("%lu ", &n);	
	for (i = 1; i <= n; i++) {
		parent[i] = i;
		node[i] = height[i] = 0;
	}
	Yes = No = 0;	
	while(gets(s) && sscanf(s," %c %d %d", &type, &x, &y) ==3) {            
        if (type == 'c') {  		
			_union(x, y);
		} else{
			(find_set(x)==find_set(y))?(Yes++):(No++);
		}				
	}	
	if ( n_case > 0 ) {
  	  printf("%d,%d\n\n", Yes, No);
	 }else {
	  printf("%d,%d\n", Yes, No);
	 }
   }	
	return 0;
}
