#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
 int NumCase;    
 int Value1, Value2;
 int IdxNumCase;
  
 /*
 freopen("p11172_in.txt", "r", stdin);
 freopen("p11172_out.txt", "w", stdout);
*/
 
 /* Get input From from standard I/O */
 scanf("%d", &NumCase);
 for ( IdxNumCase = 1; IdxNumCase <= NumCase; IdxNumCase++) {
    scanf("%d %d", &Value1, &Value2);
	if ( Value1 > Value2) {
	  printf(">\n");
	} else if ( Value1 < Value2) {
	  printf("<\n");
	} else {
	   printf("=\n");
	}
 } 
 return 0;
}
