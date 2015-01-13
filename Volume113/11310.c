#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_CENT 30001 
#define NUM_COIN_TYPE 5

#define MAX_LEN_BOX 41

int main(void)
{
  int NumCase;
  int IdxCase;  
  int IdxPacketLen;
  int PackLen;
  unsigned long long int NumWayPacketage[41];
  
/*
  freopen("p357_in.txt", "r", stdin);
  freopen("p357_out.txt", "w", stdout);
*/
  
  NumWayPacketage[0] = 1;
  NumWayPacketage[1] = 1;
  NumWayPacketage[2] = 5;
  for ( IdxPacketLen = 3; IdxPacketLen < MAX_LEN_BOX; IdxPacketLen++) {
     NumWayPacketage[IdxPacketLen] = NumWayPacketage[IdxPacketLen-1] + 4*NumWayPacketage[IdxPacketLen-2] + 2*NumWayPacketage[IdxPacketLen-3];
  }
  scanf("%d", &NumCase);
    
  for ( IdxCase = 0; IdxCase < NumCase; IdxCase++) {
     scanf("%d", &PackLen);
     printf("%llu\n", NumWayPacketage[PackLen]);
  }
  
  return 0;
}
