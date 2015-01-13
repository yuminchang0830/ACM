#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define PI 3.14159
#define SPHERE_SURFACE_DIVID_RADIUS  4*PI*PI
#define CIRCLE_FACE_DIVID_RADIUS PI*PI
#define RATIO_SPHERE_SURFACE_DIVID_CIRCLE_FACE 4


int main(void)
{
 long long int NumPartSphere;

/*
 freopen("p10499_in.txt", "r", stdin);
 freopen("p10499_out.txt", "w", stdout);
*/


 while ( scanf("%lld", &NumPartSphere) == 1 )
 {
    if ( NumPartSphere < 0 ) {
	   break;
	} else if ( NumPartSphere == 1) {
	   printf("0%%\n");	
	} else {
	   printf("%lld%%\n", (100*NumPartSphere)/RATIO_SPHERE_SURFACE_DIVID_CIRCLE_FACE );	
	} 
 } 

 return 0;
}
