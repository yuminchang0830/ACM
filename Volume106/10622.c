/* @JUDGE_ID:50418EN 10622 C */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 66000
#define range 6600


int is_prime_table[MAX];
int plist[range];
int num_prime;

void construct_primetable();
void factorial(int num);
void find_max_power();


int gcd(int a, int b);

int num_fact;
int ppow[range] ={0};
int result;

int main(void) 
{
  int i;
  int n, m;
  int flag;
  construct_primetable();  
 
  while (1)
  {
    flag = 0;
    scanf("%d", &n ) ;
    
	if ( n == 0 ) 
    {
        break;       	        
	} 
    else   
    {
	  if ( n < 0 )
      {
	    flag = 1;
        if ( n == -2147483648 )
        {           
           flag = 2;
        } 	         
        n = 0 -n;
	  }
	  memset(ppow, 0, sizeof(ppow));
      factorial( n );  
      
	  find_max_power();
	  
	  if ( flag == 1 ) 
      { 	   
	     while ( (result % 2) == 0 ) 
         {		   
	        result = result / 2;
	     }
	  } else if ( flag == 2 ) {
	     result = 31;
	  } 
      printf("%d\n", result);
    }
  }  
  return 0;
}

void construct_primetable()
{
   int i,j;   
   
   memset(is_prime_table, 0, sizeof(is_prime_table) );   
   
   for ( i = 2 ; i < MAX ; i++ ) {
     if ( is_prime_table[i] == 0 ) {
          for ( j = i*2; j < MAX ; j = j + i ) {
             is_prime_table[j] = 1;
          }
     }
   }
   j = 0;
   for ( i = 2 ; i < MAX ; i++ ) {
     if ( is_prime_table[i] == 0) {
	   j++;
     }
   }
   num_prime = j;	
}

void factorial(int num)
{
 int i,m;  
 
 num_fact = 0;
 
 for ( i = 2 ; i < MAX ; i++) { 	         
    if ( is_prime_table[i] == 0 && (num % i) == 0 ) {              
      plist[num_fact] = i;     
      while ( num % i == 0 ) {
         ppow[num_fact]++;
         num = num / i;
      }
      num_fact++;
    }
    if ( num == 0 ) {
     break;
    }
 }
 if (num_fact == 0) {
    plist[0] = num;
    ppow[0] = 1;
    num_fact = 1;
 } 
}

void find_max_power()
{
  int i, temp;
  if (num_fact == 1) {
    result = ppow[0];
  } else {
      temp = ppow[0];
    for ( i = 1 ; i < num_fact ; i++ ) {
      temp = gcd(temp, ppow[i] );    
    }
    result = temp;
  }
}

int gcd(int a, int b)
{ 
 int temp;
 if ( a < b ) {
  temp = b;
  b = a;
  a = temp;
 }
 while ( (a % b) != 0 ) {
   temp = a;
   a = b;
   b = temp % b;
 }
 return b;
}
