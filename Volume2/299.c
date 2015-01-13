/* @JUDGE_ID:50418EN 299 C */

#include <stdio.h>


void bubblesort(int *data, int n);
void swap(int *a, int *b);
int stimes;

int main(void)
{ 
 int times,i,j,k,n;
 int *data;
 scanf("%d",&times);
 for (k = 0 ; k < times ; k++) {
  scanf("%d", &n);
  data = (int*) malloc(n * sizeof(int));
  for (i = 0 ; i < n ; i++) {
   scanf("%d", &data[i]);
  }
  stimes = 0;
  bubblesort(data, n);
    
  free(data);
  
  printf("Optimal train swapping takes %d swaps.\n", stimes); 
 } 
}

void bubblesort(int *data, int n)
{
 int i, j, flag;
 for ( i = 0; i < n ; i++ )
 {  
  flag = 0;
  for( j = n -1 ; j > i   ; j--)
  {   
   if ( data[j-1] > data[j] ) {
    swap(&data[j-1], &data[j]);   
    flag = 1;
    stimes++;
   } 
  }
  if (flag == 0) {
   return;
  }
 } 
}

void swap(int *a, int *b)
{
 int c;
 c = *a;
 *a = *b;
 *b = c;
}
