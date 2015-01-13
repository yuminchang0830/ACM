/* @JUDGE_ID:50418EN 579 C */
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
 
  int Hour; 
  int Minute; 
  double MinuteDegree, HourDegree;
  double ClockAngleDegree;
   
  /*    
  freopen("p579_in.txt", "r", stdin);
  freopen("p579_out.txt", "w", stdout);
  */
  while(1)
  { 
    scanf("%d:%02d", &Hour, &Minute);	
    /*printf("%d %d \n", Hour, Minute);*/
	if ( Hour == 0 && Minute == 0) {
	   break;
	}
	MinuteDegree = 6.0 * ((double) Minute);
	HourDegree = 30.0 * ( (double) Hour) + 0.50 * ((double) Minute);
	/*printf("%.3lf %.3lf\n", HourDegree, MinuteDegree);	*/
	if ( HourDegree > MinuteDegree) {
	   ClockAngleDegree = HourDegree - MinuteDegree;
	} else {
	   ClockAngleDegree =  MinuteDegree - HourDegree;	   
	}
	if ( ClockAngleDegree > 180.0) {
	   ClockAngleDegree = 360.0 - ClockAngleDegree;
	}	
	printf("%.3lf\n", ClockAngleDegree);	
  } 
  
  return 0;
}
