#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

int main(void)
{
 int Parray[6];
 
 int GreenBottleBinOne;
 int BrownBottleBinOne;
 int ClearBottleBinOne;
 int GreenBottleBinTwO;
 int BrownBottleBinTwo;
 int ClearBottleBinTwo;
 int GreenBottleBinThree;
 int BrownBottleBinThree;
 int ClearBottleBinThree;
 
 int MovGB2B1;
 int MovBB2B1;
 int MovCB2B1;
 int MovGB2B2;
 int MovBB2B2;
 int MovCB2B2;
 int MovGB2B3;
 int MovBB2B3;
 int MovCB2B3;
 
 int TMBCG;
 int TMBGC; 
 int TMCBG;
 int TMCGB;
 int TMGBC;
 int TMGCB; 
 
 int MinMovement;
 int IdxPemut;
 int PerNum;

/*
 freopen("p102_in.txt", "r", stdin);
 freopen("p102_out.txt", "w", stdout);
*/

/* Got Each Color Bottles Number in Each Bin */

while ( scanf("%d %d %d %d %d %d %d %d %d", &BrownBottleBinOne, &GreenBottleBinOne,&ClearBottleBinOne, &BrownBottleBinTwo,&GreenBottleBinTwO, &ClearBottleBinTwo,&BrownBottleBinThree, &GreenBottleBinThree, &ClearBottleBinThree) == 9) {

/* Calculate the times of Movement to move Green Bottle to Bin One */
MovGB2B1 = GreenBottleBinTwO + GreenBottleBinThree;
MovBB2B1 = BrownBottleBinTwo + BrownBottleBinThree;
MovCB2B1 = ClearBottleBinTwo + ClearBottleBinThree;
MovGB2B2 = GreenBottleBinOne + GreenBottleBinThree;
MovBB2B2 = BrownBottleBinOne + BrownBottleBinThree;
MovCB2B2 = ClearBottleBinOne + ClearBottleBinThree;
MovGB2B3 = GreenBottleBinOne + GreenBottleBinTwO;
MovBB2B3 = BrownBottleBinOne + BrownBottleBinTwo;
MovCB2B3 = ClearBottleBinOne + ClearBottleBinTwo;

/* Calculate Each Possible Permutation */
Parray[0] = TMBCG =  MovBB2B1 + MovCB2B2 + MovGB2B3;
Parray[1] = TMBGC =  MovBB2B1 + MovGB2B2 + MovCB2B3;
Parray[2] = TMCBG =  MovCB2B1 + MovBB2B2 + MovGB2B3;
Parray[3] = TMCGB =  MovCB2B1 + MovGB2B2 + MovBB2B3;
Parray[4] = TMGBC =  MovGB2B1 + MovBB2B2 + MovCB2B3;
Parray[5] = TMGCB =  MovGB2B1 + MovCB2B2 + MovBB2B3;

MinMovement = Parray[0];
PerNum = 0;
/*
printf("%d ", Parray[0]);
*/
for ( IdxPemut = 1; IdxPemut < 6; IdxPemut++) {
    /*
    printf("%d ", Parray[IdxPemut]);
    */
  if ( Parray[IdxPemut] < MinMovement) {
     MinMovement = Parray[IdxPemut];
	 PerNum = IdxPemut;
  }
}
/*
    printf("\n");
    */

switch (PerNum) {
 case 0:
        printf("BCG %d\n", MinMovement);
		break;
 case 1:
        printf("BGC %d\n", MinMovement);
		break;
 case 2:
        printf("CBG %d\n", MinMovement);
		break;

 case 3:
        printf("CGB %d\n", MinMovement);
		break;

 case 4:
        printf("GBC %d\n", MinMovement);
		break;

 case 5:
        printf("GCB %d\n", MinMovement);
		break; 
 default:
         break;
}
}
 return 0;
}
