/* @JUDGE_ID:50418EN 476 C */
#include <stdio.h>

double xLeft[10]={0}, yLeft[10]={0}, xRight[10]={0}, yRight[10]={0};
int num_r = 0; 
int num_p = 0;
int figin = 0;
char isR; 
int i ;
double px=0, py=0; 
void isPointinRectangles(double x, double y);

int main() 
{
 
 while(1) {
    scanf(" %c", &isR); 
    if ( isR == '*') {    	 
         break;    	         
    } else {  	   
       scanf("%lf %lf %lf %lf", &xLeft[num_r], &yLeft[num_r], &xRight[num_r], &yRight[num_r]);
       num_r++;           
    }  
 }    
 
  
  while(1) {
          scanf("%lf %lf", &px, &py);
          if ( px==9999.9 && py==9999.9 ) {        	             
             break;	
          } else {             
             isPointinRectangles(px, py);	
             num_p++;
          }	    
   }
 return 0;	
}

void isPointinRectangles(double x, double y)
{
 int i, figin = 0;
 	
 for ( i = 0 ; i < num_r; i++ ) {
    if ( x > xLeft[i]  &&  y < yLeft[i]  && x < xRight[i]  && y > yRight[i]  ) {
       printf("Point %d is contained in figure %d\n", num_p+1, i+1);       
       figin=1;
    }	           	
 }
 if (figin == 0) {
    printf("Point %d is not contained in any figure\n", num_p+1);
 }

}