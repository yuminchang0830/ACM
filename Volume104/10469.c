#include <stdio.h>
#include <stdlib.h>


int main(void)
{

unsigned long long int Adder, Beadder;
unsigned long long int noCarrySum;

/*
freopen("p10469_in.txt", "r", stdin);
freopen("p10469_out.txt", "w", stdout);
*/


while ( scanf("%llu %llu", &Adder, &Beadder) ==2)  {
      printf("%llu\n",  (Adder | Beadder) - (Adder & Beadder)  );
}

return 0;
}

