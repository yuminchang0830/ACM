#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGIT_LEN 102

int TwoCycle[4] = {6, 2,4, 8};
int ThreeCycle[4] = {1, 3, 9, 7};
int FourCycle[2] = {6,4};
int SevenCycle[4] = {1, 7, 9, 3};
int EightCycle[4] = {6,8,4,2};
int NightCycle[2] = {1,9};

int main(void)
{
   char MLinearString[MAX_DIGIT_LEN], NSquareString[MAX_DIGIT_LEN];
   int LenM, LenN;
   int MLinear;
   int CarryDigit;
   int NSquare;
   int IdxPower;
   int result;
     
    
/*
   freopen("p10515_in.txt", "r", stdin);
   freopen("p10515_out.txt", "w", stdout);
*/
  
   while ( scanf("%s %s", MLinearString, NSquareString)) {
         LenM = strlen(MLinearString);
         LenN = strlen(NSquareString);
         if ( LenM ==1 && LenN==1 && MLinearString[0] == '0' && NSquareString[0] == '0') {
               break;            
         }
         if ( LenM == 1 && MLinearString[0] == '0') {
               printf("0\n");
               continue; 
         }
         if ( LenN == 1) {
            if (NSquareString[0] == '0') {
               printf("1\n");
               continue;
            }
         }
         CarryDigit = MLinearString[LenM-1] - '0' ;
		 
         /*NSquare = atoi(NSquareString);*/
		 if ( LenN >=2) {
		    NSquare = (NSquareString[LenN-2] -'0') * 10 +  (NSquareString[LenN-1] -'0');
		 } else {
		    NSquare = atoi(NSquareString);
		 }
		 if ( NSquare != 0) {
            result = CarryDigit;
		    for ( IdxPower = 1; IdxPower < NSquare; IdxPower++) {
               result = result * CarryDigit;
               result = result % 10;
            }
         } else {
            result = CarryDigit;
		    for ( IdxPower = 1; IdxPower < 100; IdxPower++) {
               result = result * CarryDigit;
               result = result % 10;
            }                
         }
          printf("%d\n", result%10);    
		 
		 /*

         if (CarryDigit == 0 || CarryDigit == 1 || CarryDigit == 5 || CarryDigit == 6) {                
                   printf("%d\n", CarryDigit);
         } else if ( CarryDigit == 2) {
                   printf("%d\n", TwoCycle[(NSquare)%4]);
         } else if ( CarryDigit == 3) {
                   printf("%d\n", ThreeCycle[(NSquare)%4]);
         } else if ( CarryDigit == 7) {              
                   printf("%d\n", SevenCycle[(NSquare)%4]);
         } else if ( CarryDigit == 8) {          
                   printf("%d\n", EightCycle[(NSquare)%4]);
         } else if ( CarryDigit == 4) {                                   
                   printf("%d\n", FourCycle[(NSquare)%2]);    
         } else if ( CarryDigit == 9) {       
                   printf("%d\n", NightCycle[(NSquare)%2]);    
         }
         */
   }      
   

   
   return 0;
}
