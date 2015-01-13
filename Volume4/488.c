/* @JUDGE_ID:50418EN 272 C */
#include <stdio.h>
#include <string.h>

char TriangleWave[10][10] =
{
 "0",
 "1",
 "22",
 "333",
 "4444",
 "55555",
 "666666",
 "7777777",
 "88888888",
 "999999999"
};

int main(void)
{
  int NumCase;
  int WaveFrequency, WaveAmplitude;
  int PeriodTime;
  int IdxFreq;
  int IdxAmp;
  
    /*
	freopen("p488_in.txt", "r", stdin);
	freopen("p488_out.txt", "w", stdout);
   */
  
  scanf("%d\n", &NumCase);  
  while ( NumCase--)    
  {
    scanf("%d\n", &WaveAmplitude);
	scanf("%d\n", &WaveFrequency);
	for ( IdxFreq = 1; IdxFreq <= WaveFrequency; IdxFreq++) {
	  for ( IdxAmp = 1; IdxAmp <= WaveAmplitude; IdxAmp++ ) {
	     printf("%s\n", TriangleWave[IdxAmp]);
	  }
	  for ( IdxAmp = (WaveAmplitude - 1); IdxAmp >=1; IdxAmp--) {
	     printf("%s\n", TriangleWave[IdxAmp]);
	  }
	  
	  if (  NumCase == 0 &&  IdxFreq ==WaveFrequency) {	  
      } else {
           printf("\n");
      }
     
	}	

  }
  
  return 0;
}
