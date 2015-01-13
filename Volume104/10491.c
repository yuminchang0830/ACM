#include <stdio.h>
#include <stdlib.h>

int main(void)
{
 int NumCows;
 int NumCars;
 int NumDoors;
 int NumDoorsBeShowed;
 double WinProbNoChange;
 double WinProbWithChange;
 double WinProb;
 
/*
 freopen("p10491_in.txt", "r", stdin);
 freopen("p10491_out.txt", "w", stdout);
*/


 while ( scanf("%d %d %d", &NumCows, &NumCars, &NumDoorsBeShowed) == 3 )
 {
     NumDoors = NumCows + NumCars;
     /*WinProbNoChange = 0.5 * ( (double) NumCars/ (double) NumDoors);*/
     WinProbWithChange = ((double) (NumDoors-1.0)/ (double) NumDoors) * ( (double) NumCars / (double) (NumDoors - NumDoorsBeShowed -1 ));
     WinProb =  WinProbWithChange;
     printf("%0.5lf\n", WinProb); 
 } 

 return 0;
}
