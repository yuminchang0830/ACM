/* @JUDGE_ID:50418EN 10221 C */

#include <stdio.h>
#include <string.h>
#include <math.h>
#define EARTH_RADIOUS 6440
/*
#define PI 3.141592653589
*/

int main(void)
{

double face2satell_distance, angle ;
char UnitFormat[4];
double core2satell_distance;
double arc_distance, chord_distance;
double PI;

/*
	freopen("p10221_in.txt", "r", stdin);
	freopen("p10221_out.txt", "w", stdout);
*/
	PI = 2.0 * acos(0.0);


  while ( scanf("%lf %lf %s", &face2satell_distance, &angle, UnitFormat)==3 ) {     
    core2satell_distance =  (double) (EARTH_RADIOUS + face2satell_distance);
    if (strcmp(UnitFormat,"deg") == 0) {	       
	   if ( angle < 0 ) {
       	angle = -angle;
       }
       if ( angle > 360. ) {       	
       	angle = angle - ((int) ( angle  / 360.)) * 360.;
       }	
       if ( angle > 180. ) {
       	angle = 360. - angle;
       }	
       arc_distance = ( PI * core2satell_distance * ((double) angle) ) / 180.0;
       chord_distance = 2.0 * core2satell_distance * sin( ( (double) PI*angle)/360.0);
       printf("%.6lf %.6lf\n", arc_distance, chord_distance);
    } else if (strcmp(UnitFormat, "min") == 0) {
       if ( angle < 0 ) {
       	angle = -angle;
       }	
       if ( angle > 21600 ) {
        angle = angle - ((int)(angle / 21600)) * 21600;
       }
       if ( angle > 10800 ) {
        angle = 21600 - angle;
       }
       arc_distance = PI * core2satell_distance  * ( (double) angle) / 10800.0;
       chord_distance = 2.0 * core2satell_distance *sin( ( (double) PI*angle)/21600.0);	
       printf("%.6lf %.6lf\n", arc_distance, chord_distance);
    }    
  }	
  
  return 0; 	
}
