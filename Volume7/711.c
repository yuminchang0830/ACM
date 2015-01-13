/* @JUDGE_ID:50418EN 711 C */

#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int num[6];
int total;

int DP[MAX] = {0};

int isdividable() 
{
	int i,j,k;	
	int value;
	
   value = 0;	
   DP[0] = 1;

   for ( i = 1 ; i <= (total/2) ; i++ ) {
	   DP[i] = 0;
   }
   
   for ( i = 0 ; i < 6 ; i++ ) {
	   if ( i != 0 ) {
   	       value += i * num[i - 1];
	   } 
	   /*
   	printf("i = %d, Value = %d , num[i]=%d \n",i,  value , num[i]);
   	*/
	   
	   if ( num[i] ) {
   	      for ( j = value ;  j >= 0; j-- ) {
   		      if ( DP[j] == 1 ) {
   			     for ( k = 1 ; k <= num[i]; k++ ) {
   				    if ( (j+ k*(i+1) ) <= (total/2) ) { 
   			           DP[j+ k*(i+1)] = 1;
				       }				       
				     }
			      }   				      
		      } 
		      /*
		      for ( j = (i+1) ; j <= (num[i]*(i+1)) && (j <= (total/2)); j += (i+1)) {
		      	DP[j] = 1;		      	      	
		      }
		      */
		      
		      
		      /*
		      for ( j = 0 ; j <= (total/2) ; j++ ) {
		      	 printf("%d ", DP[j] );
		   	}
	         printf("\n"); 
	         */
	   }   
   }    
   /*
   printf("\n");
   for ( i = 0 ; i <= total/2 ; i++ ) {
   	printf("%d ", DP[i]);
   }
   printf("\n");
   */
   
   
   
   return DP[total/2];
   	
}

int main()
{	
	int i;
	int times = 1;
	/*
	freopen("p711_in.txt", "r", stdin);
	freopen("p711_out.txt", "w", stdout);
	*/
	while ( scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]) == 6) 
	{
				

		for ( i = 0 ; i < 6 ; i++ ) {
			if ( num[i] > 6 ) {
				num[i] = 6 + num[i] % 2; 
			}
		}

        total = 0;
		total = num[0] + num[1]*2 + num[2]*3 + num[3]*4 + num[4]*5 + num[5]*6;			
					  
	  	if ( total == 0 ) {
	  		break;
	  	}	  	
	  	if ( total % 2) {
	  		printf("Collection #%d:\nCan't be divided.\n\n", times++ );	  		
	  	} else {	  			  		
	  	   if ( isdividable() ) {	  		
	  		   printf("Collection #%d:\nCan be divided.\n\n", times++ );
	  		} else {
	  			printf("Collection #%d:\nCan't be divided.\n\n", times++ );
	  		}
	  	}
	}
	
   return 0;
}