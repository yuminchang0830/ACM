#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 int VelocityOne, Timing;
 int VelocityTwo;
/*
 freopen("p10071_in.txt", "r", stdin);
 freopen("p10071_out.txt", "w", stdout);
*/
 while ( scanf("%d %d", &VelocityOne, &Timing) == 2 )
 {
     VelocityTwo = 2 * VelocityOne * Timing;
	 printf("%d\n", VelocityTwo);
 } 
 return 0;
}



