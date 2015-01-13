/* @JUDGE_ID:50418EN 10125 C */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int a;
	int b;
	int sum;
} sumofAB;

int compare( const void *arg1, const void *arg2 );
int compare2( const void *arg1, const void *arg2 );

int binary_search( sumofAB data[], sumofAB c, int n);

int isequal(sumofAB a, sumofAB b);

int solution;

int max;

int main(void) 
{
 int n_case ;
 int i,j,k;
 int *set;
 int order;
 sumofAB* recordAB;
 sumofAB recordCD;
 int answer;
 
 while (1) {
 	  if ( scanf("%d", &n_case) != 1 ) {
 	     break;
 	  }
 	  
 	  if ( n_case == 0 ) {
 	     break;
 	  }
 	  
 	  set = (int*) malloc( n_case * sizeof(int) );
 	  recordAB = (sumofAB*) malloc ( n_case * (n_case - 1 ) * sizeof(sumofAB) / 2);
 	  
 	  for ( i = 0 ; i < n_case ; i++ ) {
 	  	scanf("%d", &set[i]);
 	  }
 	  
 	  qsort(set, n_case, sizeof(set[0]), compare2); 
 	  
 	  max = set[n_case - 1]; 
 	  
 	  order = 0;
 	  
 	  for ( i = 0 ; i < n_case - 1; i++ ) { 	    
 	  	for ( j = i + 1; j < n_case ; j++ ) {
 	  	   recordAB[order].a = set[i];
 	  	   recordAB[order].b = set[j];
 	  	   recordAB[order++].sum = set[i] + set[j];
 	  	}
 	  }	  
 	  
 	  qsort(recordAB, n_case * ( n_case - 1 ) / 2, sizeof( recordAB[0] ) , compare); 	
 	  
 	  solution = -1;
 	  
 	  for ( i = n_case - 1 ; i > 0 ; i-- ) {
 	  	for ( j = i - 1 ; j >= 0 ; j-- ) {
 	           recordCD.a = set[i];
 	  	   recordCD.b = set[j];
 	  	   recordCD.sum = set[i] - set[j]; 	  
 	  	   binary_search(recordAB, recordCD, order); 
 	  	   	  	   
 	  	}
 	  }
 	  
 	  if (solution == -1 ) {
 	     printf("no solution\n");
 	  } else {
 	     printf("%d\n", solution);
 	  }	 
 }
  	
 return 0;
}

int compare2( const void *arg1, const void *arg2 )
{
 int a, b;
 a = *(int*) arg1;
 b = *(int*) arg2;
 return a - b;
}

int compare( const void *arg1, const void *arg2 )
{
	sumofAB a, b;
	a = *(sumofAB*) arg1;
	b = *(sumofAB*) arg2;
	return (a.sum - b.sum);
	/*
	if ( a.sum == b.sum ) {
	   return (a.b - b.b);	
	} else {
	   return (a.sum - b.sum);
	}*/
}


int binary_search( sumofAB data[], sumofAB c, int n)
{
  int  lower, midden, upper;	
  int  x , y;
  lower = 0;
  upper = n -1;
  
  while ( lower <= upper ) { 
     midden = (lower + upper) / 2 ;
     if ( c.sum > data[midden].sum ) {
     	lower = midden + 1;
     } else if ( (data[midden].sum - c.sum) == 0 ) {
        x = midden;
        if ( (data[x].a != c.a) && (data[x].a != c.b) && (data[x].b != c.a) && (data[x].b != c.b)) {
           if ( ((data[x].sum + c.b) > solution) && ((data[x].sum + c.b) <= max ) ) {
             solution = data[x].sum + c.b;           	
           }        	     
        }
        return -1;
     } else {
     	upper = midden - 1;
     }
  }
  return (-1);  
}






