#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STICK_LEN 1000001 

unsigned long long int TriangleCombin[MAX_STICK_LEN];

int main(void)
{
  unsigned long long int NumStick;
  unsigned long long int IdxStickLen;
  unsigned long long int CombinwithMAXStick;

/*
  freopen("p11401_in.txt", "r", stdin);
  freopen("p11401_out.txt", "w", stdout);
*/
  TriangleCombin[2] = 0;
  TriangleCombin[3] = 0;
  TriangleCombin[4] = 1;
  TriangleCombin[5] = 3;
  for ( IdxStickLen = 6; IdxStickLen < MAX_STICK_LEN; IdxStickLen++) {
      CombinwithMAXStick =  ((IdxStickLen-3) + ( (IdxStickLen%2)+1))* ( (IdxStickLen/2)-1 ) / 2 ;
     
      TriangleCombin[IdxStickLen] = TriangleCombin[IdxStickLen-1] + CombinwithMAXStick;
  }
  
  while (1) {
     scanf("%llu", &NumStick);
     if ( NumStick < 3) {
        break;
     }     
     printf("%llu\n", TriangleCombin[NumStick]);
  }
  
  return 0;
}
