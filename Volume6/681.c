/* @JUDGE_ID:50418EN 681 C */
#include <stdio.h>
#include <stdlib.h>
#define MAX 1300

typedef struct {
	int x;
	int y;
} point;

point cord[MAX];

int top = -1;

point myStack[MAX];

void pop() {
	if (top == -1) {
		printf("underflow\n");
	} else {
		top--;
	}	
}

void push(point data) {
	if (top >= MAX - 1 ) {
		printf("overflow");		
	} else {
		myStack[++top] = data;
	}
}

int compare(const void *arg1,const void *arg2)
{
	point a,b;
	int res;
	
	a = *(point*)arg1;
	b = *(point*)arg2;
	
	res = a.x*b.y + b.x*cord[0].y + cord[0].x*a.y -
	      (a.y*b.x + b.y*cord[0].x + cord[0].y*a.x);
	return res;	
}

int nonleftturn(point a, point b, point c)
{
	int res;
	res = a.x*b.y + b.x*c.y + c.x*a.y -
	      (a.y*b.x + b.y*c.x + c.y*a.x);
	return res;
}

int main(void)
{
	int TN;
	int num;
	int i,j;
	int index;	
	int flag;
	point min, temp;
	/*
	freopen("input.txt", "r", stdin);
	*/
	
	scanf("%d", &TN);
	printf("%d\n", TN);
	while(TN--) {
		scanf("%d", &num);	
		index = 0;	
		min.x = 10000;
		min.y = 10000;
		for (i = 0; i < num; i++) {
			scanf("%d %d", &cord[i].x, &cord[i].y);
			if (cord[i].y < min.y) {
				min = cord[i];
				index = i;
			} else if (cord[i].y == min.y && cord[i].x < cord[i].x) {						
				min = cord[i];
				index = i;
			}						
		}		
		
		top = -1;
		
		temp = cord[0];
		cord[0] = cord[index];
		cord[index] = temp;
				
		qsort(&cord[1], num-1, sizeof(cord[1]),compare);		
		
		push(cord[0]);
		push(cord[1]);
		push(cord[2]);
		
		for (i = 3; i < num; i++) {			
			while (nonleftturn(myStack[top-1], myStack[top], cord[i]) >= 0) {
				pop();				
			}
			push(cord[i]); 
		}
	   
		if (myStack[top].x == myStack[0].x && myStack[top].y == myStack[0].y) {
			printf("%d\n", top + 1);						
		} else {						
			printf("%d\n", top + 2);			
			printf("%d %d\n", myStack[0].x, myStack[0].y);
			
		}				
		
		for (i = top; i >= 0; i--) {
			printf("%d %d\n", myStack[i].x, myStack[i].y);
		}		
		
		if (scanf("%d", &num)!=1) break;	 
		if (TN) printf("-1\n");		
	}
	
	return 0;
}
 
 
