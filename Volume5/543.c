/* @JUDGE_ID:50418EN 543 C */

#include <stdio.h>
#include <math.h>

int is_prime(long num);


int main(void) 
{
 int flag = 0;
 long i;
 long n;
 while (1) {
    scanf("%d", &n);
    if ( n == 0 ) {
      break;
    } else if ( n == 6) { 
	   printf("6 = 3 + 3\n");
	} else if ( ( n % 2 ) == 1 ) {
	   printf("Goldbach's conjecture is wrong.\n"); 
	} else {
    
    flag = 0;
    for ( i = n - 3 ; i > ( n / 2 ) ; i-=2 ) {       
       if ( is_prime( i ) == 1 ) {
         if ( is_prime( n - i ) == 1 ) {
           printf("%d = %d + %d\n", n, n - i, i ) ;
           flag = 1;
           break;
         }
       }
    }

    if ( flag == 0 ) {
       printf("Goldbach's conjecture is wrong.\n"); 
    }   
    }
     
 }
 return 0;
}


int is_prime(long num)
{
 long i,m;
 m = (long) sqrt(num);
 for ( i = 2 ; i <= m ; i++ ) {
  if ( (num % i) == 0 ) {
      return 0;
  }
 }
 return 1;
}




