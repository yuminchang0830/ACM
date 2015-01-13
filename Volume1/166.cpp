/* @JUDGE_ID:50418EN 166 C++ */

#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 600

class MakeChange 
{
 public:
	int dollars;
	int times[6];	
	MakeChange();
};

MakeChange::MakeChange() 
{
  dollars = 0;
  times[0] = 0;
  times[1] = 0;
  times[2] = 0;
  times[3] = 0;
  times[4] = 0;
  times[5] = 0;
}



/************************************ Global Data ************************************/
MakeChange MinCoin[6][MAX];
int Answer[MAX];
int rpay;
int dollars[6];
int money[6] = {1,2,4,10,20,40} ;
int totalmoney;
int DP[6][MAX];
int Result[MAX];
int bound;
/********************************* End Global Data ***********************************/

MakeChange min6_limit(int index, int K)
{
	int i;

	MakeChange value;

    value = MinCoin[0][K];
    value.dollars = 9999; 

	for ( i = 0 ; i < 6 ; i++ ) {
		if ( ( MinCoin[i][K].dollars < value.dollars )  && ( MinCoin[i][K].times[index] < dollars[index]) ) {
            value = MinCoin[i][K];
		} 
	}    
	return value;
}

void find_answer()
{
	int i,j,value;
	for ( i = 1 ; i <= bound ; i++ ) {
	   value = MinCoin[0][i].dollars;
	   for ( j = 1; j < 6 ; j++ ) {
		   if (value > MinCoin[j][i].dollars ) {
			   value = MinCoin[j][i].dollars;
		   }
	   }
	   Answer[i] = value + 1;
	}	
}


void find_min_dollars()
{
	int i,j;

	for ( i = 0 ; i < 6 ; i++ ) {
		for ( j = 1; j <= bound ; j++ ) {
            if ( (j - money[i]) < 0 ) {
				MinCoin[i][j].dollars = 9999;
			} else if (  ((j - money[i]) == 0)) {
				if ( dollars[i] > 0 ) {
                    MinCoin[i][j].times[i] = 1;
					MinCoin[i][j].dollars = 0;
				} else {
					MinCoin[i][j].dollars = 9999;
				}
			} else {
				break;
			}
		}
	}
   

	for ( i = 1 ; i <= bound ; i++ ) {
		for ( j = 0 ; j < 6 ; j++ ) {
			if ( (i - money[j]) > 0 ) {
				MinCoin[j][i] = min6_limit(j, i - money[j] );
                MinCoin[j][i].dollars++ ;
				MinCoin[j][i].times[j]++;
			}
		}
	}

}


int min6(int a, int b, int c, int d, int e, int f)
{
	int array[6];
	int i, value;
    array[0] = a;
	array[1] = b;
	array[2] = c;
	array[3] = d;
	array[4] = e;
	array[5] = f;
	value = a;

	for ( i = 0 ; i < 6 ; i++ ) {
		if ( array[i] < value ) {
			value = array[i] ;
		}
	}

	return value;
}


void GiveMeMoney() 
{
	int i,j;

	for ( i = 0 ; i < 6 ; i++ ) {
		for ( j = 1 ; j <= 100 ; j++ ) {
			if ( (j - money[i]) < 0 ) {
				DP[i][j] = 9999;
			} else if ( (j - money[i]) == 0) {
				DP[i][j] = 0;
			} else {
				break;
			}
		}
	}
    
	for ( i = 1 ; i <= bound ; i++ ) {
		for ( j = 0 ; j < 6 ; j++ ) {
			if ( (i - money[j]) > 0 ) {
				DP[j][i] = min6( DP[0][i - 1], DP[1][i - 1], DP[2][i - 1], DP[3][i - 1], DP[4][i - 1], DP[5][i - 1] ) + 1;
			}
		}
	}

	for ( i = 1 ; i <= bound ; i++ ) {
      Result[i] = min6( DP[0][i], DP[1][i], DP[2][i], DP[3][i], DP[4][i], DP[5][i] ) + 1;	 
	}

	

}

int find_the_bestanswer()
{
	int i;
	int min;

    min = Answer[rpay];

	while (min == 0 ) {
	}

	if ( min == 1 ) {
		return 1;
	}

	for ( i = (rpay + 1) ; i <= bound  ; i++ ) {
		if ( Answer[i] < 999 ) {
			if ( ( Result[i - rpay] + Answer[i] ) < min ) {
				min = Result[i - rpay] + Answer[i];
			}
			if ( min == 2 ) {
				return 2;
			}
		}
	}

	return min;
}



int main(void)
{	
	
	double pay;	
	
	while ( scanf("%d %d %d %d %d %d", &dollars[0], &dollars[1], &dollars[2], &dollars[3], &dollars[4], &dollars[5]) == 6 ) 	
	{

		if (dollars[5] > 10 ) {
			dollars[5] = 3;
		}

		if (dollars[4] > 20 ) {
            dollars[4] = 5;
		}

		if (dollars[3] > 40 ) {
			dollars[3] = 10;
		}

		if (dollars[2] > 80 ) {
			dollars[2] = 25;
		}

		if (dollars[1] > 160 ) {
			dollars[1] = 50;
		}

		if (dollars[0] > 320 ) {
			dollars[0] = 100;
		}




		totalmoney = 1 * dollars[0] + 2 * dollars[1] + 4 * dollars[2] + 10 * dollars[3] + 20 * dollars[4] + 40 * dollars[5];

		if (totalmoney == 0) {
			break;
		}

		scanf("%lf", &pay);

		rpay = (int) (double) (pay * 20);
        

		if ( totalmoney > MAX ) {
			bound = MAX;
		} else {
			bound = totalmoney;
		}

       

		find_min_dollars();
        /*
        for ( i = 0 ; i < 6 ; i++ ) {
		   for ( j = 1; j <= bound ; j++ ) {
		      printf("%4d ", MinCoin[i][j].dollars );          
		   }
		   printf("\n");
		}
		*/
       
		find_answer();        
		
		
        GiveMeMoney();
		
	    
		
		printf("%3d\n", find_the_bestanswer());
	
	}	

	return 0;
}



