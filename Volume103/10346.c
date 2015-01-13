#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int main(void)
{
 int NumofCigarettes;
 int NumButtsToCigarettes; 
 int NumofCigarettesSmoke;
  
/*
 freopen("p10346_in.txt", "r", stdin);
 freopen("p10346_out.txt", "w", stdout);
*/
 
 while ( scanf("%d %d", &NumofCigarettes, &NumButtsToCigarettes)!=EOF) {
   
	NumofCigarettesSmoke = NumofCigarettes;
    while (NumofCigarettes >= NumButtsToCigarettes ) {	
       NumofCigarettesSmoke += NumofCigarettes/NumButtsToCigarettes;
	   NumofCigarettes = NumofCigarettes/NumButtsToCigarettes + NumofCigarettes % NumButtsToCigarettes;
    }

	printf("%d\n",NumofCigarettesSmoke);
 }  

 return 0;
}
