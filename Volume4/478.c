/* @JUDGE_ID:50418EN 478 C */

#include <stdio.h>
#include <math.h>

#define bsize 10

char RCT[bsize], isRCT;
double xleft[bsize]={0}, yleft[bsize]={0}, xright[bsize]={0}, yright[bsize]={0}, ztop[bsize] = {0}, zdown[bsize] = {0};
double px, py;
double T1, T2, T3, bigT;
int num_f = 0, num_p = 0 , isinFig = 0, i;
void isPointinFigure();
void isPointinRectangle();
void isPointinTriangle();
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
   } else if (isRCT == 't') {
      RCT[num_f] = 't';
      scanf("%lf %lf %lf %lf %lf %lf", &xleft[num_f], &yleft[num_f], &xright[num_f], &yright[num_f], &ztop[num_f], &zdown[num_f]);      
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
  } else if (RCT[i] == 't') {    
     isPointinTriangle();
  }
 }
 
 if (isinFig == 0 ) {
  printf("Point %d is not contained in any figure\n", num_p+1);
 }
 isinFig = 0;
}

void isPointinRectangle()
{
 if (  px > xleft[i]  &&  py < yleft[i]  && px < xright[i]  && py > yright[i]   ) {
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

void isPointinTriangle()
{ 
 
 T1 = fabs((px*yright[i] + xright[i]*yleft[i] + xleft[i]*py) - (xright[i]*py + xleft[i]*yright[i] + px*yleft[i]));
 T2 = fabs((px*zdown[i] + ztop[i]*yright[i] + xright[i]*py) - (ztop[i]*py + xright[i]*zdown[i] + px*yright[i]));
 T3 = fabs((px*zdown[i] + ztop[i]*yleft[i] + xleft[i]*py) - (ztop[i]*py + xleft[i]*zdown[i] + px*yleft[i]));
 bigT = fabs((xright[i]*zdown[i] + ztop[i]*yleft[i] + xleft[i]*yright[i]) - (ztop[i]*yright[i] + xleft[i]*zdown[i] + xright[i]*yleft[i]));

 
 if ( fabs(bigT - T1 - T2 - T3) <= 0.00001) {
  printf("Point %d is contained in figure %d\n",num_p+1, i+1);
  isinFig = 1;
 } 

}

