#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159265

int main(void)
{


int SoyaMilkBoxLen;
int SoyaMilkBoxWidth;
int SoyaMilkBoxHight;
double SoyaMilkVolume;
int TiltAngle;
double Rangle;
double Tangle;
double LeakHigh;
double LeakVolume;

/*

 freopen("p11909_in.txt", "r", stdin);
 freopen("p11909_out.txt", "w", stdout);
*/
 
 
 while ( scanf("%d %d %d %d", &SoyaMilkBoxLen, &SoyaMilkBoxWidth, &SoyaMilkBoxHight, &TiltAngle) == 4) 
 { 
    Rangle = ((double) TiltAngle) * acos(-1.0) / 180.0;
    Tangle = ((double)  (90-TiltAngle)) * acos(-1.0) / 180.0;
	SoyaMilkVolume =  (double) (SoyaMilkBoxLen * SoyaMilkBoxWidth * SoyaMilkBoxHight);	  
	if ( (SoyaMilkBoxLen*tan(Rangle)) <= SoyaMilkBoxHight) 	{
	    printf("%.3lf mL\n", SoyaMilkVolume - SoyaMilkBoxWidth*0.5*SoyaMilkBoxLen*SoyaMilkBoxLen*tan(Rangle));	    
	} else {
	    printf("%.3lf mL\n", SoyaMilkBoxWidth*0.5*SoyaMilkBoxHight*SoyaMilkBoxHight*tan(Tangle));	 	
	}
 } 

 return 0;
}
