/* @JUDGE_ID:50418EN 10221 C */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define radius 6440


double s ,a;
char string[4];
double S , pi;

double ad, rd;

int main(void)
{  
  
  pi = acos(-1);	
  while ( scanf("%lf %lf %s", &s, &a, string) == 3 ) {  	
    S = radius + s;       
    if (strcmp(string,"deg") == 0) {      	    	
       if ( a < 0 ) {
       	a = -a;
       }
       if ( a > 360 ) {       	
       	a = a - ((int) ( a  / 360)) * 360;
       }	
       if ( a > 180 ) {
       	a = 360 - a;
       }		       
       ad = pi * S * a/180;
       rd = 2*S*sin(pi*a/360);
       printf("%lf %lf\n", ad, rd);
       
    } else if (strcmp(string, "min") == 0) {
       if ( a < 0 ) {
       	a = -a;
       }	
       if ( a > 21600 ) {
        a = a - ((int)(a / 21600)) * 21600;
       }
       if ( a > 10800 ) {
        a = 21600 - a;
       }
       ad = pi * S * a / 10800;
       rd = 2*S*sin(pi*a/21600);	
       printf("%lf %lf\n", ad, rd);
    }    
    
  }
 
	
 return 0;
 	
}
