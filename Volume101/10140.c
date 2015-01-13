/* @JUDGE_ID:50418EN 10140 C */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 66000

int is_prime_table[MAX];
int prime_table[33000];
int d_table[1000000];
int max =0, min=0;
int num_prime;
void construct_primetable();
void sieve_prime_table(int low,int upp);

int main(void)
{
 
int u, l, i,j,temp;
 construct_primetable();
 /*
 for ( i = 0 ; i < 100 ; i++ )  {
   printf("%d ", prime_table[i]);
 }
  */
 while ( scanf("%d %d", &l, &u) == 2 ) 
 {
  if ( l > u ) {
     temp = l;
     l = u;
     u = temp;
  }
  if ( l == 1 && u != 1) {
    l = 2;
  }
  
  sieve_prime_table(l,u);
  
 }
 
 return 0;
 
}


void construct_primetable()
{
   int i,j;   
   
   num_prime = 0;
   
   memset(is_prime_table, 0, sizeof(is_prime_table) );   
   memset(prime_table, 0, sizeof(prime_table) );
   
   for ( i = 2 ; i < MAX ; i++ ) {
     if ( is_prime_table[i] == 0 ) {
          for ( j = i*2; j < MAX ; j = j + i ) {
             is_prime_table[j] = 1;
          }
          prime_table[num_prime++] = i;
     }
   }  
}

void sieve_prime_table(int low, int upp )
{
 int i,j,k,max_i,max_j, min_i, min_j, m; 
 int temp,flag;
 
  m = (int) sqrt( upp ) + 1;
 /*
 printf("m = %d\n", m);
 */
 memset(d_table, 0, sizeof(d_table));
 
 k = 0;
 
 for ( i = 0 ; prime_table[i] <= m ; i++ ) {
   for ( j = 0 ; j <= (upp - low ) ; j++ ) {
     if ( ((low + j) % prime_table[i] ) == 0 ) {
       if ( prime_table[i] == (low + j) ) {          
          j = j + prime_table[i];
       }       
       for ( ; j <= ( upp - low ) ; j = j + prime_table[i] ) {
         d_table[j] = 1;        
       }     
     }
   }      
 }
 
 for ( i = 0 , k = 0; i <= (upp - low ) ; i++ ) {
   if ( d_table[i] == 0 ) {
      k++;
   }
 }
 
 if ( k < 2 ) {
    printf("There are no adjacent primes.\n");
    return;
 }
 /*
 printf("k = %d\n", k);
 
 for ( i = 0 ; i <= (upp - low); i++ ) {
   if ( d_table[i] == 0 ) {
    
     printf("d_table[%d]= %d\n", i,i+low);
     
   }
 }
 */
 for ( i = 0; i <= (upp - low ) ; i++) {   
   if ( d_table[i] == 0 ) {
      j = i;
      i++;            
      break;
   }   
 } 
  
 for ( ; i <= (upp - low ) ; i++ ) {  
   if ( d_table[i] == 0 ) {                  
      break;      
   }
 } 
 
 
 max = i - j;
 min = max; 
 max_i = i ;
 min_i = i;
 min_j = j;
 max_j = j; 
 j = i;
 i++;
 
 /*
 printf("%d %d_\n", i, j);
 */
 for ( ; i <= (upp - low) ; i++ ) {
    
    if ( d_table[i] == 0 ) {
      /*
      printf("i = %d, d_table[i]=%d, j = %d  , i - j = %d\n", i,d_table[i],j , i - j);
      printf("max = %d, min = %d\n", max, min);
      */
      if ( max < ( i - j ) ) {
        max = (i - j); 
        max_i = i;
        max_j = j;             
      } else if ( min > ( i - j ) ) {       
       min = i - j;
       min_i = i;
       min_j = j;       
      }      
      j = i;
    }
 }  
 /*
 printf("%d %d_\n", i, j);
 */
 printf("%d,%d are closest, %d,%d are most distant.\n", min_j+low, min_i+low, max_j+low, max_i+low);
 
 }

