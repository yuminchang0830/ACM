#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int Molecular, Denominator ;
    int temp;
    
    while ( scanf("%d %d", &Molecular, &Denominator) == 2) {
          /* print b0 */
          printf("[%d;", Molecular/Denominator); 
          Molecular =  Molecular- (( Molecular/Denominator) * Denominator) ;
      
          temp = Denominator;
          Denominator = Molecular;
          Molecular = temp;
          while ( Denominator != 0) {
              if ( 0 !=  Molecular- (( Molecular/Denominator) * Denominator)) {
                 printf("%d,", Molecular/Denominator);  
              } else {
                 printf("%d]\n", Molecular/Denominator);      
              }
              Molecular =  Molecular- (( Molecular/Denominator) * Denominator) ;
              temp = Denominator;
              Denominator = Molecular;
              Molecular = temp;
          }
    }

    return 0;
}
