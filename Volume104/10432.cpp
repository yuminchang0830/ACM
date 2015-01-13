/* @JUDGE_ID:50418EN 10432 C */


#include <stdio.h>
#include <math.h>
#define pi 3.141592653589

int n; 
double radius;
double area;

int main(void)
{
 while (1) { 	   
   scanf("%lf %d", &radius, &n);   
   if ( radius > 0.0 ) {
      area =  n * radius * radius * sin(pi/n) * cos(pi/n) ;
      printf("%.3lf\n", area);
   } else {
      break;
   }
 }
 
 return 0;
}
