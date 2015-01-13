/* @JUDGE_ID:50418EN 10432 C */


#include <stdio.h>
#include <math.h>
#define pi 3.141592653589

int n;
double radius;
double area;

int main(void)
{
 while (scanf("%lf %d", &radius, &n) != EOF) {   
      area =  n * radius * radius * sin(pi/n) * cos(pi/n) ;
      printf("%.3lf\n", area);   
 }
 
 return 0;
}