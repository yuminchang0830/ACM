#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{

unsigned long long int BraveWarrior, OpponentArmy;

/*
 freopen("p10055_in.txt", "r", stdin);
 freopen("p10055_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 while ( scanf("%llu %llu", &BraveWarrior, &OpponentArmy) != EOF)
 { 
    printf("%llu\n", (OpponentArmy > BraveWarrior)?  ( OpponentArmy - BraveWarrior): (BraveWarrior - OpponentArmy));        
 }
 
 return 0;
}
