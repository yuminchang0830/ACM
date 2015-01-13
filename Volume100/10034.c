/* @JUDGE_ID:50418EN 10034 C */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 11000

typedef struct {
	int x;	
	int y;
	double cost;
} point;


double x[110];
double y[110];


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
	if (a.cost > b.cost) {
		return 1;	
	} else if (a.cost < b.cost){
		return -1;
	} else {
		return 0;
	}
}


int main(void)
{
	int TN;
	int n;
	int i,j;
	double result;
	int ne;
	int num;
	/*
	freopen("input1.txt", "r", stdin);
	*/
	scanf("%d\n", &TN);
	while(TN--) {
		scanf("%d", &n);		

		for (i = 0; i < n; i++) {
			scanf("%lf %lf", &x[i] , &y[i]);				
		}		
		
		for (num = 0, i = 0; i < n; i++) {
			for (j = i+1; j < n; j++) {		
				edge[num].x = i;
				edge[num].y = j;
				edge[num].cost = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
				num++;
			}
		}
		qsort(edge, num, sizeof(edge[0]), compare);		
		for (i = 0; i <= n ; i++) {
			parent[i] = i;
			height[i] = 0;
		}
		result = 0.0;
		ne = 0;		
		for (i = 0; i < num; i++) {		
			if (ne == n - 1) break;
			if (find_set(edge[i].x) != find_set(edge[i].y)) {
				_union(edge[i].x,edge[i].y);
				result += edge[i].cost;
				ne++;
			}			
		}
		
		printf("%.2lf\n", result);
		
		if(TN) printf("\n");
		
	}
	return 0; 
}