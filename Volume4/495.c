#include <stdio.h>

int main(void) 
{
	int n,i;
	 
	__int64 a,b;
	__int64 Fib[2][2] = {{1,1},{1,0}};
	__int64 u_vector[2] = {1, 0};	

    
	freopen("p495_in.txt", "r", stdin);
	freopen("p495_out.txt", "w", stdout);
    
    while ( scanf("%d", &n) == 1 ) {
		u_vector[0] = 1;
		u_vector[1] = 0;
		for ( i = 1 ; i < n ; i++ ) {
		  	a = Fib[0][0]*u_vector[0] + Fib[0][1]*u_vector[1];
			b = Fib[1][0]*u_vector[0] + Fib[1][1]*u_vector[1];
			u_vector[0] = a;
			u_vector[1] = b;			
		}
	    printf("The Fibonacci number for %d is %d\n", n, u_vector[0]);
	}
    return 0;
}
