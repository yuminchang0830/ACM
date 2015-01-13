#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_INPUT_NUM 10001

long long int HLIST[MAX_INPUT_NUM];

long long int H(int n){
      long long int res = 0;
	  int i;
     for( i = 1; i <= n; i=i+1 ){
            res = (res + n/i);           
      }
     return res;
}

int main(void)
{

int NumTestCase;
int IdxCase=0;
int NumInput;

/*

 freopen("p11526_in.txt", "r", stdin);
 freopen("p11526_out.txt", "w", stdout);
*/

HLIST[0] = 0;

for (IdxCase=1; IdxCase<= MAX_INPUT_NUM; IdxCase++)
{
    HLIST[IdxCase] = H(IdxCase);
}

 
 scanf("%d", &NumTestCase);
 
for (IdxCase=0; IdxCase<NumTestCase; IdxCase++)
 { 
    scanf("%d", &NumInput);
    if ( NumInput > MAX_INPUT_NUM) {
          printf("%lld\n", H(NumInput));
    } else {
     printf("%lld\n", HLIST[NumInput]);
    }
  
 } 

 return 0;
}
