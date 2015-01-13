#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(void)
{
  unsigned long long int UnTaxBound;
  unsigned long long int TaxRate;
  unsigned long long int EffectiveIncome;
  

  freopen("p11247_in.txt", "r", stdin);
  freopen("p11247_out.txt", "w", stdout);

  while ( scanf("%llu %llu", &UnTaxBound, &TaxRate) == 2)  {
    if ( UnTaxBound == 0 &&  TaxRate == 0) {
	   break;
	}
	if ( UnTaxBound == 1 || TaxRate == 0 || TaxRate == 100) {
      	printf("Not found\n");
     
    } else {
	   EffectiveIncome =(100*(UnTaxBound-1)) /  (100-TaxRate);
	   if ((100*(UnTaxBound-1)) %  (100-TaxRate) == 0) {
	      EffectiveIncome--;
	   }
	   if ( EffectiveIncome < UnTaxBound) {
	     printf("Not found\n");
	   } else {
	     printf("%llu\n", EffectiveIncome);
	   }
    }
 
  }

  
  return 0;
}
