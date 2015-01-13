/* @JUDGE_ID:50418EN 612 C */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int order;
	int inversion;
} DNA_CODE;



int n, m; /* n -- length of string , m -- number of strings */
int getdna(char code);
int countI(char str[]);

int compare( const void *arg1, const void *arg2 );

int main(void)
{
 char DNA[101][51];
 DNA_CODE  DNA_DATA[101];
 int i, t , testcase;
 scanf("%d",&testcase);

 for ( t = 1; t <= testcase; t++ ) {
 	  if( t > 1) {
 	  	 printf("\n"); 
 	  }
    scanf("%d %d", &n, &m);
    for ( i = 0 ; i < m ; i++ ) {
       scanf("%s", &DNA[i][0]);
       DNA_DATA[i].order = i;
    	 DNA_DATA[i].inversion = countI(DNA[i]); 
    }
           
    qsort(DNA_DATA, m, sizeof(DNA_DATA[0]), compare)  ;         
    
    for ( i = 0 ; i < m ; i++ ) {
       printf("%s\n", DNA[ DNA_DATA[i].order ] );
    } 
 } 
}

int getdna(char code)
{
	switch (code) {
		case 'A': return 0;
		case 'C': return 1;
		case 'G': return 2;
		case 'T': return 3;
		default :
			        exit(1);
	}
}

int countI(char str[])
{
  int i, j ,code, invers=0, count[4] = {0, 0, 0, 0};
  for ( i = 0 ; str[i] ; i++ ) {
     code = getdna( str[i] );   	 
     count[code]++;
     for ( j = code + 1 ; j < 4 ; j++ ) {
     	 invers += count[j];
     }
  }    
  return invers; 
}

int compare( const void *arg1, const void *arg2 )
{
	DNA_CODE a, b;
	a = *(DNA_CODE*) arg1;
	b = *(DNA_CODE*) arg2;
	if ( a.inversion != b.inversion ) {
	   return ( a.inversion - b.inversion );	
	} else {
		 return ( a.order - b.order );
	}
}
