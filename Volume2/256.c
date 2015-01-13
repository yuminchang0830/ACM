#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>




int main(void)
{

 int NDigits;
 int IdxPreDigit;
 int IdxAftDigit;
 int ShiftDigits;
 int SumSquare;
 int DigitCombin;
 
 while ( scanf("%d", &NDigits) == 1) {
    switch (NDigits) {
      case 2:
             ShiftDigits = 10;
             break;
      case 4:
             ShiftDigits = 100;
             break;
      case 6:
             ShiftDigits = 1000;
             break;
      case 8:
             ShiftDigits = 10000;
             break;           
      default:
              break;
    }
       
    for ( IdxPreDigit = 0; IdxPreDigit < ShiftDigits; IdxPreDigit++) {        
      for ( IdxAftDigit = 0; IdxAftDigit < ShiftDigits; IdxAftDigit++) {     
          DigitCombin = (IdxPreDigit*ShiftDigits) +  IdxAftDigit;
          SumSquare = (IdxPreDigit + IdxAftDigit) * (IdxPreDigit + IdxAftDigit);
          if (DigitCombin == SumSquare) {
            switch (NDigits) {
              case 2:
                     printf("%02d\n", DigitCombin);
                     break;
              case 4:
                     printf("%04d\n", DigitCombin);
                     break;
              case 6:
                     printf("%06d\n", DigitCombin);
                     break;
              case 8:
                     printf("%08d\n", DigitCombin);
                     break;           
              default:
                     break;
            }
          }
      }       
    }          
 }
 return 0;
}
