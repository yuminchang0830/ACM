/* @JUDGE_ID:50418EN 477 C */

#include <stdio.h>
#include <math.h>
#define bsize 10


char RCT[bsize];
double xleft[bsize]={0}, yleft[bsize]={0}, xright[bsize]={0}, yright[bsize]={0};
double px, py;
char isRCT;
int num_f = 0, num_p = 0 , isinFig = 0;
int i;
void isPointinFigure();
void isPointinRectangle();
void isPointinCircle();

int main(void)
{
	
 while (1) {
  scanf(" %c", &isRCT);
  if (isRCT == '*' ) {
   break;
  } else {
   if (isRCT == 'r') {
      RCT[num_f] = 'r';
      scanf("%lf %lf %lf %lf", &xleft[num_f], &yleft[num_f], &xright[num_f], &yright[num_f]);
   } else if (isRCT == 'c') { 
      RCT[num_f] = 'c';
      scanf("%lf %lf %lf", &xleft[num_f], &yleft[num_f], &xright[num_f]);             
   }
   num_f++;
  }
 }
 
  
 while (1) {
  scanf("%lf %lf", &px, &py);
  if (px == 9999.9 && py == 9999.9) {
   break;
  } else {
   isPointinFigure();
   num_p++;
  }
 } 
 
 return 0;
}

void isPointinFigure()
{
 
 for ( i = 0 ; i < num_f ; i++) 
 {
  if (RCT[i] == 'r') {
     isPointinRectangle();
  } else if (RCT[i] == 'c') {
     isPointinCircle();  
  }
 }
 
 if (isinFig == 0 ) {
  printf("Point %d is not contained in any figure\n", num_p+1);
 }
 isinFig = 0;
}

void isPointinRectangle()
{
 if (px > xleft[i]  &&  py < yleft[i]  && px < xright[i]  && py > yright[i]) {
  printf("Point %d is contained in figure %d\n", num_p+1 , i+1);
  isinFig = 1;
 }
}

void isPointinCircle()
{
 
 if ( ( (xleft[i] - px)*(xleft[i] - px) + (yleft[i] - py)*(yleft[i] - py) - xright[i]*xright[i] ) < 0.000001) {
  printf("Point %d is contained in figure %d\n",num_p+1, i+1);
  isinFig = 1;
 }
 
}


